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
        int b = nextInt();
        long n = nextInt();
        long[] mas = new long[b];
        long mMax = 1;
        for(int i = 0; i < b; i++) {
            mas[i] = nextInt();
            mMax = Math.max(mMax, mas[i]);
        }
        long right = n*mMax;
        long left = 0;

        boolean isNotComplete = true;
        long t = 1;
        long nt = calc(t, mas);
        long ntprev = calc(t-1,mas);
        while(isNotComplete && right > left) {
            t = (right + left + 1)/2;
            nt = calc(t, mas);
            ntprev = calc(t-1, mas);
            if(nt >= n && ntprev < n ){
                isNotComplete = false;
            } else {
                if(nt >= n) {
                    right = t - 1;
                } else {
                    left = t;
                }
            }

        }
        --t;
        int place = 0;
        while(ntprev < n) {
            if(t%mas[place] == 0)
                ++ntprev;
            ++place;
        }

        printCase();
        out.println(place);
    }

    private static long calc(long t, long[] mas) {
        long res = 0;
        for(int i = 0; i < mas.length; i++) {
            res += t/mas[i];
            if(t % mas[i] > 0)
                ++res;
        }
        return res;
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
