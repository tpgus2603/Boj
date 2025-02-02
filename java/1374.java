import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine().trim());
        
        // 시작시간(s), 종료시간(e)를 저장할 배열
        int[][] room = new int[n][2];
        
        for(int i = 0; i < n; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int t = Integer.parseInt(st.nextToken()); // 강의번호(실제 로직에는 사용 안 함)
            int s = Integer.parseInt(st.nextToken());
            int e = Integer.parseInt(st.nextToken());
            room[i][0] = s;
            room[i][1] = e;
        }
        
        // 시작 시간을 기준으로 정렬
        Arrays.sort(room, (a, b) -> a[0] - b[0]);
        
        // 종료시간 기준 최소 힙
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        
        int ans = 0;
        for(int[] temp : room) {
            if(!pq.isEmpty() && pq.peek() <= temp[0]) {
                pq.poll();
            }
            pq.offer(temp[1]);
            ans = Math.max(ans, pq.size());
        }
        
        System.out.println(ans);
    }
}