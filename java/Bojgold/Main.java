import java.io.*;
import java.util.*;

public class Main {
    static class Edge implements Comparable<Edge> {
        int u, v, relevance;
        public Edge(int u, int v, int relevance) {
            this.u = u;
            this.v = v;
            this.relevance = relevance;
        }
        
        @Override
        public int compareTo(Edge o) {
            return o.relevance - this.relevance; // 내림차순 정렬
        }
    }
    
    static class Query implements Comparable<Query> {
        int k, v, idx;
        public Query(int k, int v, int idx) {
            this.k = k;
            this.v = v;
            this.idx = idx;
        }
        
        @Override
        public int compareTo(Query o) {
            return o.k - this.k; // 내림차순 정렬
        }
    }
    
    static int[] parent;
    static int[] size;
    
    static int find(int a) {
        if (parent[a] == a) return a;
        return parent[a] = find(parent[a]);
    }
    
    static void union(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;
        if (size[a] < size[b]) {
            int temp = a;
            a = b;
            b = temp;
        }
        parent[b] = a;
        size[a] += size[b];
    }
    
    public static void main(String[] args) throws IOException {
        // BufferedReader 및 BufferedWriter를 사용한 빠른 입출력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int Q = Integer.parseInt(st.nextToken());
        
        Edge[] edges = new Edge[N - 1];
        for (int i = 0; i < N - 1; i++) {
            st = new StringTokenizer(br.readLine());
            int p = Integer.parseInt(st.nextToken());
            int q = Integer.parseInt(st.nextToken());
            int r = Integer.parseInt(st.nextToken());
            // 인덱스는 1부터 시작한다고 가정
            edges[i] = new Edge(p, q, r);
        }
        
        // 간선을 내림차순 정렬
        Arrays.sort(edges);
        
        Query[] queries = new Query[Q];
        for (int i = 0; i < Q; i++) {
            st = new StringTokenizer(br.readLine());
            int k = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            queries[i] = new Query(k, v, i);
        }
        // 쿼리 내림차순 정렬
        Arrays.sort(queries);
        
        // union-find 초기화
        parent = new int[N + 1];
        size = new int[N + 1];
        for (int i = 1; i <= N; i++) {
            parent[i] = i;
            size[i] = 1;
        }
        
        int[] ans = new int[Q];
        int edgeIdx = 0;
        // 쿼리를 순회하면서 relevance가 k 이상인 간선을 union
        for (Query query : queries) {
            while (edgeIdx < edges.length && edges[edgeIdx].relevance >= query.k) {
                union(edges[edgeIdx].u, edges[edgeIdx].v);
                edgeIdx++;
            }
            // 해당 노드가 속한 집합의 크기에서 시작 노드 1을 제외한 값
            ans[query.idx] = size[find(query.v)] - 1;
        }
        
        for (int i = 0; i < Q; i++) {
            out.println(ans[i]);
        }
        out.flush();
        out.close();
    }
}