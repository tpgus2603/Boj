import java.io.*;

public class LCS {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String a = br.readLine();
        String b = br.readLine();
        br.close();

        int alen = a.length();
        int blen = b.length();

        int[][] dp = new int[alen + 1][blen + 1];

        // LCS DP 테이블 채우기
        for (int i = 1; i <= alen; i++) {
            for (int j = 1; j <= blen; j++) {
                if (a.charAt(i - 1) == b.charAt(j - 1)) {
                    dp[i][j] = Math.max(dp[i - 1][j - 1] + 1, dp[i][j - 1]);
                } else {
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // LCS 길이가 0이면 0 출력 후 종료
        if (dp[alen][blen] == 0) {
            System.out.println(0);
            return;
        }

        // LCS 문자열 찾기 (역추적)
        StringBuilder ans = new StringBuilder();
        while (alen > 0 && blen > 0) {
            if (dp[alen][blen] == dp[alen][blen - 1]) {
                blen--;
            } else if (dp[alen][blen] == dp[alen - 1][blen]) {
                alen--;
            } else {
                ans.append(a.charAt(alen - 1));
                alen--;
                blen--;
            }
        }

        // 결과 출력
        System.out.println(ans.length());
        System.out.println(ans.reverse()); // LCS는 뒤에서부터 찾아서 저장했으므로 뒤집기
    }
}