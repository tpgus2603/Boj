import java.io.*;
import java.util.*;
 
public class Main2 {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
 
        int N = Integer.parseInt(st.nextToken());
        long[] arr = new long[N];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            arr[i] = Long.parseLong(st.nextToken());
        }
 
        Arrays.sort(arr);
 
        long best = 3000000001L;  // 3 * 1,000,000,000보다 크게 초기화
        long ans1 = 0, ans2 = 0, ans3 = 0;
 
        // 배열에서 한 용액을 고정하고 나머지 두 용액에 대해 투포인터 탐색
        for (int i = 0; i < N - 2; i++) {
            int left = i + 1;
            int right = N - 1;
            while (left < right) {
                long sum = arr[i] + arr[left] + arr[right];
                if (Math.abs(sum) < best) {
                    best = Math.abs(sum);
                    ans1 = arr[i];
                    ans2 = arr[left];
                    ans3 = arr[right];
                }
                // 합이 0이면 최적해이므로 바로 출력 후 종료
                if (sum == 0) {
                    printAns(ans1, ans2, ans3);
                    return;
                }
                if (sum < 0) {
                    left++;
                } else {
                    right--;
                }
            }
        }
 
        printAns(ans1, ans2, ans3);
    }
 
    // 오름차순 정렬하여 출력하는 메서드
    static void printAns(long a, long b, long c) {
        long[] ans = {a, b, c};
        Arrays.sort(ans);
        StringBuilder sb = new StringBuilder();
        for (long x : ans) {
            sb.append(x).append(" ");
        }
        System.out.println(sb.toString().trim());
    }
}
