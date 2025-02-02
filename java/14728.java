import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int[] d = new int[m+1];

        for (int i = 1; i <= n; i++) {
            st = new StringTokenizer(br.readLine());
            int t = Integer.parseInt(st.nextToken());
            int s = Integer.parseInt(st.nextToken());

            for (int j = m; j >= t; j--) {
                d[j] = Math.max(d[j], d[j-t]+s);
            }
        }

        bw.write(d[m]+"");
        bw.flush();
        bw.close();
    }
}