import java.io.*;
import java.util.*;

public class Main {

    // 클래스 변수로 선언하여 func 메서드에서 접근 가능하도록 함
    static boolean[] vis;
    static boolean[] vis2;
    static int[] arr;
    static int n;
    static ArrayList<Integer> temp;

    /**
     * 순환을 찾는 재귀 함수
     *
     * @param first 순환의 시작점
     * @param nxt 현재 탐색 중인 노드
     * @return 순환이 발견되면 true, 그렇지 않으면 false
     */
    public static boolean func(int first, int nxt) {
        if (nxt == first) {
            return true;
        }
        if (nxt > n || vis[nxt] || vis2[nxt]) {
            return false;
        }
        vis2[nxt] = true;
        temp.add(nxt);
        return func(first, arr[nxt]);
    }

    public static void main(String[] args) throws IOException {
        // BufferedReader와 BufferedWriter를 사용하여 빠른 입출력 구현
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        // n 입력 받기
        n = Integer.parseInt(br.readLine());
        arr = new int[n + 1];

        // 두 번째 줄부터 N개의 줄에 걸쳐 배열 arr[1]부터 arr[n]까지 입력 받기
        for (int i = 1; i <= n; i++) {
            String line = br.readLine();
            if (line == null || line.isEmpty()) {
                // 입력이 부족할 경우 예외 처리
                arr[i] = 0; // 또는 적절한 기본값 설정
            } else {
                arr[i] = Integer.parseInt(line.trim());
            }
        }

        vis = new boolean[n + 1];
        vis2 = new boolean[n + 1];
        temp = new ArrayList<>();
        ArrayList<Integer> ans = new ArrayList<>();

        // 모든 노드에 대해 순환 탐색
        for (int i = 1; i <= n; i++) {
            if (vis[i]) continue; // 이미 방문한 노드는 건너뜀
            Arrays.fill(vis2, false); // vis2 배열 초기화
            vis2[i] = true;
            temp.clear();
            temp.add(i);
            boolean flag = func(i, arr[i]);
            if (flag) {
                for (Integer t : temp) {
                    vis[t] = true; // 순환에 속하는 노드는 vis 배열에 표시
                    ans.add(t); // 결과 리스트에 추가
                }
            }
        }

        // 결과 리스트 정렬
        Collections.sort(ans);

        // 결과 출력
        bw.write(ans.size() + "\n");
        for (Integer num : ans) {
            bw.write(num + "\n");
        }

        // 출력 버퍼 비우기
        bw.flush();
        bw.close();
        br.close();
    }
}