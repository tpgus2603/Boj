import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

        int t = Integer.parseInt(br.readLine().trim());

        while (t-- > 0) {
            String w = br.readLine();
            int k = Integer.parseInt(br.readLine().trim());

            List<List<Integer>> arr = new ArrayList<>();
            for (int i = 0; i < 26; i++) {
                arr.add(new ArrayList<>());
            }

            int len = w.length();
            for (int i = 0; i < len; i++) {
                arr.get(w.charAt(i) - 'a').add(i);
            }

            int minn = Integer.MAX_VALUE;
            int maxn = 0;

            for (int cur = 0; cur < 26; cur++) {
                int tSize = arr.get(cur).size();
                for (int j = k - 1; j < tSize; j++) {
                    int diff = arr.get(cur).get(j) - arr.get(cur).get(j - k + 1) + 1;
                    minn = Math.min(diff, minn);
                    maxn = Math.max(diff, maxn);
                }
            }

            if (maxn == 0) {
                pw.println(-1);
            } else {
                pw.println(minn + " " + maxn);
            }
        }

        pw.flush();  // Ensure all output is printed efficiently
        br.close();
        pw.close();
    }
}