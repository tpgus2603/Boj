import java.io.*;
import java.util.*;

public class Main {
    // 방향 벡터: 상, 하, 좌, 우
    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};
    
    // 그리드 크기 및 시간 제한
    static int n, m, t;
    
    // 그리드 정보, 시간, 방문 여부
    static short[][] arr;
    static int[][] tim;
    static boolean[][] vis;
    
    // BFS 노드를 나타내는 클래스
    static class Node {
        int x, y, b;
        Node(int x, int y, int b) {
            this.x = x;
            this.y = y;
            this.b = b;
        }
    }
    
    public static void main(String[] args) throws IOException {
        // 빠른 입력을 위한 BufferedReader 사용
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        // 그리드 크기 및 시간 제한 입력
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        t = Integer.parseInt(st.nextToken());
        
        // 배열 초기화
        arr = new short[n][m];
        tim = new int[n][m];
        vis = new boolean[n][m];
        
        // 그리드 입력 및 초기화
        for(int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < m; j++) {
                arr[i][j] = Short.parseShort(st.nextToken());
                tim[i][j] = -1; // 초기 시간 설정
            }
        }
        
        // BFS를 위한 큐 초기화 및 시작점 추가
        Queue<Node> q = new LinkedList<>();
        q.add(new Node(0, 0, 0));
        tim[0][0] = 0; // 시작점 시간 설정
        
        // BFS 수행
        while(!q.isEmpty()) {
            Node cur = q.poll();
            int x = cur.x;
            int y = cur.y;
            int b = cur.b;
            
            // 도착점에 도달하면 종료
            if(x == n-1 && y == m-1) break;
            
            // 4방향 탐색
            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                // 그리드 범위 밖이면 무시
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                
                int nb = b;
                if(arr[nx][ny] == 2) nb = 1; // 특정 아이템 획득
                
                // 장애물 처리
                if(nb == 0 && arr[nx][ny] == 1) continue;
                
                // 이미 방문한 상태라면 무시
                if(nb == 0 && tim[nx][ny] != -1) continue;
                if(nb == 1 && vis[nx][ny]) continue;
                
                // 시간 업데이트
                tim[nx][ny] = tim[x][y] + 1;
                
                // 아이템을 획득한 경우 방문 처리
                if(nb == 1) vis[nx][ny] = true;
                
                // 다음 노드 큐에 추가
                q.add(new Node(nx, ny, nb));
            }
        }
        
        // 결과 출력
        if(tim[n-1][m-1] <= t && tim[n-1][m-1] != -1) {
            System.out.println(tim[n-1][m-1]);
        } else {
            System.out.println("Fail");
        }
    }
}