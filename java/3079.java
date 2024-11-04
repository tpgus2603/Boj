import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        // 입력을 빠르게 받기 위해 BufferedReader 사용
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // 첫 번째 줄에서 n과 m을 읽어옵니다.
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());        // 심사대 수 (1 ≤ n ≤ 100,000)
        long m = Long.parseLong(st.nextToken());         // 사람 수 (1 ≤ m ≤ 1,000,000,000)

        // 각 심사대에서 한 사람을 심사하는 데 걸리는 시간 t[i]를 저장하는 배열
        long[] t = new long[n];
        long maxn = 0; // 심사대 중 가장 오래 걸리는 시간을 저장

        // 심사대별로 심사 시간을 입력받고, 가장 큰 값을 찾습니다.
        for (int i = 0; i < n; i++) {
            t[i] = Long.parseLong(br.readLine());
            if (t[i] > maxn) {
                maxn = t[i];
            }
        }

        // 이분 탐색을 위한 시작점과 끝점 설정
        long left = 1;
        long en = maxn * m; // 최대 시간 (오버플로우 주의)

        // 이분 탐색 실행
        while (left < en) {
            long mid = (left + en) / 2;
            long total = 0;
            boolean flag = false;

            // 각 심사대에서 mid 시간 동안 처리할 수 있는 사람 수를 계산
            for (int i = 0; i < n; i++) {
                total += mid / t[i];
                if (total >= m) {
                    flag = true; // 필요한 인원 수 m명을 처리할 수 있으면 true
                    break;       // 더 이상 계산하지 않고 반복문 종료
                }
            }

            if (flag) {
                en = mid; // 더 작은 시간에서 탐색
            } else {
                st = mid + 1; // 더 큰 시간에서 탐색
            }
        }

        // 결과 출력
        System.out.println(en);
    }
}
