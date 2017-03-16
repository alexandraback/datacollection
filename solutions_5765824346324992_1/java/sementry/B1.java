/**
 * Created by sementry on 18-Apr-15.
 */
import java.io.*;
import java.util.*;

public class B1 {

    MyScanner in;
    PrintWriter out;

    public static void main(String[] args) throws Exception {
        new B1().run();
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

    long check(long x, long[] m) {
        long ans = 0;
        for (int i = 0; i < m.length; i++) {
            ans += 1 + x / m[i];
        }
        return ans;
    }

    public void solve() throws Exception {
        int b = in.nextInt();
        int n = in.nextInt();
        long[] m = new long[b];
        long mmax = 0;
        for (int i = 0; i < b; i++) {
            m[i] = in.nextLong();
            mmax = Math.max(m[i], mmax);
        }

        if (n <= b) {
            out.println(n);
            return;
        }
        long l = 0;
        long r = n * mmax * 4 / b;
        while (l < r - 1) {
            long mid = (l + r) / 2;
            if (check(mid, m) > n - 1) {
                r = mid;
            } else {
                l = mid;
            }
        }
        while (check(r, m) < n) {
            r++;
        }
        int t = (int) check(r, m);
        int i = b;

        while (t >= n) {
            if (i == 0) {
                r--;
            }
            i = (i + b - 1) % b;
            while (r % m[i] != 0) {
                if (i == 0) {
                    r--;
                }
                i = (i + b - 1) % b;
            }
            t--;
        }
        out.println(i + 1);
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