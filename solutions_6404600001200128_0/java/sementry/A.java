/**
 * Created by sementry on 18-Apr-15.
 */
import java.io.*;
import java.util.*;

public class A {

    MyScanner in;
    PrintWriter out;

    public static void main(String[] args) throws Exception {
        new A().run();
    }

    public void run() throws Exception {
        in = new MyScanner();
        out = new PrintWriter(System.out);

        int tests = in.nextInt();
        for (int test = 0; test < tests; test++) {
            out.print("Case #" + (test + 1) + ": ");
            solve();
        }
        out.close();
    }

    public void solve() throws Exception {
        int n = in.nextInt();
        int[] m = new int[n];
        for (int i = 0; i < n; i++) {
            m[i] = in.nextInt();
        }

        int y = 0;
        for (int i = 0; i < n - 1; i++) {
            y += Math.max(0, m[i] - m[i + 1]);
        }

        int z = 0;
        int ratemin = 0;
        for (int i = 0; i < n - 1; i++) {
            ratemin = Math.max(ratemin, Math.max(0, m[i] - m[i + 1]));
        }
        for (int i = 0; i < n - 1; i++) {
            z += Math.min(m[i], ratemin);
        }
        out.println(y + " " + z);
    }

    class MyScanner {

        BufferedReader br;
        StringTokenizer st;

        public MyScanner() throws Exception {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() throws Exception {
            while ((st == null) || (!st.hasMoreTokens())) {
                String t = br.readLine();
                if (t == null) {
                    return null;
                }
                st = new StringTokenizer(t);
            }
            return st.nextToken();
        }

        int nextInt() throws Exception {
            return Integer.parseInt(next());
        }

        double nextDouble() throws Exception {
            return Double.parseDouble(next());
        }

        boolean nextBoolean() throws Exception {
            return Boolean.parseBoolean(next());
        }

        long nextLong() throws Exception {
            return Long.parseLong(next());
        }
    }
}