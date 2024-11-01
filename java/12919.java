import java.util.*;
import java.io.*;

public class Main {
    static String S;
    static HashSet<String> vis = new HashSet<>();

    public static boolean solve(String cur) {
        vis.add(cur);
        if (S.equals(cur)) return true;
        if (S.length() > cur.length()) return false;
        int len = cur.length();

        // If the last character is 'A', remove it and recurse
        if (cur.charAt(len - 1) == 'A') {
            String temp = cur.substring(0, len - 1);
            if (!vis.contains(temp)) {
                if (solve(temp)) return true;
            }
        }

        // If the first character is 'B', remove it, reverse the remaining string, and recurse
        if (cur.charAt(0) == 'B') {
            String temp = new StringBuilder(cur.substring(1)).reverse().toString();
            if (!vis.contains(temp)) {
                if (solve(temp)) return true;
            }
        }

        return false;
    }

    public static void main(String[] args) throws IOException {
        // Fast input reading
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        S = br.readLine();
        String T = br.readLine();
        boolean result = solve(T);
        System.out.print(result ? 1 : 0);
    }
}