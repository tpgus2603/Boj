import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        // 정점의 개수 n, 간선(경로) 개수 m 입력
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        
      
        // 정점 번호 0부터 n까지 사용하므로 n+1 크기의 인접 리스트 배열 생성
        ArrayList<Integer>[] adj = new ArrayList[n + 1];
        for (int i = 0; i <= n; i++) {
            adj[i] = new ArrayList<>();
        }
        
        // 각 정점의 진입차수를 저장할 배열
        int[] degree = new int[n + 1];
        for (int i = 1; i <= m; i++) {
            st = new StringTokenizer(br.readLine());
            int t = Integer.parseInt(st.nextToken());
            int prev = 0;
            for (int j = 0; j < t; j++) {
                int v = Integer.parseInt(st.nextToken());
                // prev에서 v로 간선 추가
                adj[prev].add(v);
                prev = v;
            }
        }
        
        for (int i = 1; i <= n; i++) {
            for (int v : adj[i]) {
                degree[v]++;
            }
        }
        
        // 위상 정렬을 위한 큐와 결과 저장 리스트
        Queue<Integer> q = new LinkedList<>();
        ArrayList<Integer> toporder = new ArrayList<>();
        
        // 진입차수가 0인 정점을 큐에 삽입 (정점 번호 1부터 n까지)
        for (int i = 1; i <= n; i++) {
            if (degree[i] == 0) {
                q.add(i);
            }
        }
        
        // Kahn 알고리즘: 큐가 빌 때까지
        while (!q.isEmpty()) {
            int cur = q.poll();
            toporder.add(cur);
            for (int next : adj[cur]) {
                degree[next]--;
                if (degree[next] == 0) {
                    q.add(next);
                }
            }
        }
        
        // 만약 위상 정렬한 정점의 개수가 n개보다 작으면 사이클이 존재하는 것으로 판단
        if (toporder.size() < n) {
            System.out.println(0);
            return;
        }
        
        // 위상 정렬 결과를 한 줄에 한 정점씩 출력
        StringBuilder sb = new StringBuilder();
        for (int vertex : toporder) {
            sb.append(vertex).append("\n");
        }
        System.out.print(sb.toString());
    }
}