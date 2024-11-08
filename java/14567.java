import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        // BufferedReader를 사용하여 빠른 입력을 처리
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        // 강의 수 n과 선수과목 관계 수 m 입력
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        
        // 인접 리스트 초기화
        ArrayList<Integer>[] adj = new ArrayList[n + 1];
        for(int i = 1; i <= n; i++) {
            adj[i] = new ArrayList<>();
        }
        
        // 진입 차수 배열과 학기 배열 초기화
        int[] indegree = new int[n + 1];
        int[] sem = new int[n + 1];
        Arrays.fill(sem, 1); // 모든 강의의 기본 학기를 1로 설정
        
        // m개의 선수과목 관계 입력
        for(int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            adj[u].add(v);
            indegree[v]++;
        }
        
        // 진입 차수가 0인 강의를 큐에 추가
        Queue<Integer> q = new LinkedList<>();
        for(int i = 1; i <= n; i++) {
            if(indegree[i] == 0) {
                q.offer(i);
            }
        }
        
        // 위상 정렬을 이용하여 학기 계산
        while(!q.isEmpty()) {
            int current = q.poll();
            for(int next : adj[current]) {
                indegree[next]--;
                if(indegree[next] == 0) {
                    q.offer(next);
                }
                sem[next] = Math.max(sem[next], sem[current] + 1);
            }
        }
        
        // 결과 출력
        StringBuilder sb = new StringBuilder();
        for(int i = 1; i <= n; i++) {
            sb.append(sem[i]).append(' ');
        }
        System.out.println(sb.toString());
    }
}

