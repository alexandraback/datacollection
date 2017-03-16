import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
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
        int r = nextInt();
        int c = nextInt();
        int n = nextInt();
        boolean[][] mas = new boolean[r][c];
        int comb = 1 << (r*c);
        int minSusid = Integer.MAX_VALUE;
        for(int i = 0; i < comb; i++) {
            int ones = calcOnes(i);
            if(ones == n) {
                int value = i;
                for(int j = 0; j < r; j++) {
                    for(int k = 0; k < c; k++) {
                        mas[j][k] = (value & 1) == 1;
                        value /= 2;
                    }
                }
                int curSusid = 0;
                for(int j = 0; j < r; j++) {
                    for(int k = 0; k < c; k++) {
                        if(k < c-1 && mas[j][k] && mas[j][k+1]) {
                            ++curSusid;
                        }
                        if(j < r - 1 && mas[j][k] && mas[j+1][k]) {
                            ++curSusid;
                        }
                    }
                }
                minSusid = Math.min(minSusid, curSusid);
            }
        }

        printCase();
        out.println(minSusid);
    }

    private static int calcOnes(int i) {
        int result = 0;
        while(i > 0) {
            if((i & 1) == 1) {
                ++result;
            }
            i/=2;
        }
        return result;
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
