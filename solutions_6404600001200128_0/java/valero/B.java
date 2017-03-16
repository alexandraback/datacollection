import java.io.*;
import java.util.StringTokenizer;

import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

/**
 * User: vryzhuk
 * Date: 4/18/15
 * Time: 3:58 AM
 */
public class B {

    static BufferedReader in;
    static PrintWriter out;
    static StringTokenizer tok;
    static int test;

    static void solve() throws Exception {
        int n = nextInt();
        int[] mas = new int[n];
        for(int i = 0; i < n; i++) {
            mas[i] = nextInt();
        }
        long res1 = 0;
        long res2 = 0;
        int maxRazn = 0;
        for(int i = 1; i < n; i++) {
            if(mas[i] < mas[i-1]) {
                res1 += mas[i-1] - mas[i];
                maxRazn = Math.max(maxRazn, mas[i-1] - mas[i]);
            }
        }
        for(int i = 1; i < n; i++) {
            res2 += Math.min(maxRazn, mas[i-1]);
        }

        printCase();
        out.println(res1 + " " + res2);
    }

    static void printCase() {
        out.print("Case #" + test + ": ");
    }

    static void printlnCase() {
        out.println("Case #" + test + ":");
    }

    static int nextInt() throws IOException {
        return parseInt(next());
    }

    static long nextLong() throws IOException {
        return parseLong(next());
    }

    static double nextDouble() throws IOException {
        return parseDouble(next());
    }

    static String next() throws IOException {
        while (tok == null || !tok.hasMoreTokens()) {
            tok = new StringTokenizer(in.readLine());
        }
        return tok.nextToken();
    }

    public static void main(String[] args) {
        try {
            in = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(new OutputStreamWriter(System.out));
            int tests = nextInt();
            for (test = 1; test <= tests; test++) {
                solve();
            }
            in.close();
            out.close();
        } catch (Throwable e) {
            e.printStackTrace();
            exit(1);
        }
    }
}
