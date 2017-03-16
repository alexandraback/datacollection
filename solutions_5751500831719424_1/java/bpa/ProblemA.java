import java.io.*;
import java.util.*;

public class ProblemA implements Runnable {

    void solveMultiTest() throws IOException {
        int testCases = nextInt();
        for (int testCase = 1; testCase <= testCases; testCase++) {
            out.println("Case #" + testCase + ": " + solveOneTest());
        }
    }

    boolean check(String s, String p) {
        String ps = "" + s.charAt(0);
        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i - 1) != s.charAt(i))
                ps += s.charAt(i);
        }
        return p.equals(ps);
    }

    String solveOneTest() throws IOException {
        int n = nextInt();
        String[] s = new String[n];
        for (int i = 0; i < n; i++)
            s[i] = nextToken();
        String patternString = "" + s[0].charAt(0);
        for (int i = 1; i < s[0].length(); i++) {
            if (s[0].charAt(i - 1) != s[0].charAt(i))
                patternString += s[0].charAt(i);
        }
        boolean f = true;
        for (int i = 0; i < n; i++) {
            f &= check(s[i], patternString);
        }

        if (!f)
            return "Fegla Won";

        int ans = 0;
        for (int i = 0; i < n; i++)
            s[i] += '$';
        for (int k = 0; k < patternString.length(); k++) {
            int[] l = new int[n];
            char ch = patternString.charAt(k);
            for (int i = 0; i < n; i++) {
                for (int x = 0; s[i].charAt(x) == ch; x++)
                    l[i]++;
                s[i] = s[i].substring(l[i]);
            }
            int min = Integer.MAX_VALUE;
            for (int i = 1; i <= 100; i++) {
                int x = 0;
                for (int j = 0; j < n; j++)
                    x += Math.abs(i - l[j]);
                if (x < min)
                    min = x;
            }
            ans += min;
        }
        return ans + "";
    }

    BufferedReader br;
    StringTokenizer st;
    PrintWriter out;

    public void run() {
        try {
            InputStream input = System.in;
            PrintStream output = System.out;
            File file = new File("a.in");
            if (file.exists() && file.canRead()) {
                input = new FileInputStream(file);
                output = new PrintStream(new File("a.out"));
            }
            br = new BufferedReader(new InputStreamReader(input));
            out = new PrintWriter(output);
            solveMultiTest();
            out.close();
        } catch (IOException e) {
        }
    }

    long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    String nextToken() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            String line = br.readLine();
            if (line == null) {
                return null;
            }
            st = new StringTokenizer(line);
        }
        return st.nextToken();
    }

    public static void main(String[] args) {
        new Thread(new ProblemA()).run();
    }
}