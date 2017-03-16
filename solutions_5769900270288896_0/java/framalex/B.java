package gcj.c2015.r1b;


import java.util.*;
import java.io.*;
import java.lang.*;
import java.math.*;

public class B implements Runnable {

    public void run() {
        int tests = nextInt();
        for (int iter = 1; iter <= tests; ++iter) {

            int r = nextInt();
            int c = nextInt();
            int n = nextInt();

            int maxUnHappy = Integer.MAX_VALUE;
            boolean[][] f = new boolean[r][c];
            for (int i = 0; i < (1 << (r*c)); ++i) {
                if (Integer.bitCount(i) == n) {
                    for (int rr = 0; rr < r; ++rr) {
                        for (int cc = 0; cc < c; ++cc) {
                            if ((i & (1 << (rr*c + cc))) != 0){
                                f[rr][cc] = true;
                            } else {
                                f[rr][cc] = false;
                            }
                        }
                    }

                    int curUnHappy = 0;
                    for (int rr = 0; rr < r; ++rr) {
                        for (int cc = 0; cc < c; ++cc) {
                            if (f[rr][cc]) {
                                if (rr < r - 1 && f[rr+1][cc]) {
                                    ++curUnHappy;
                                }
                                if (cc < c - 1 && f[rr][cc+1]) {
                                    ++curUnHappy;
                                }
                            }
                        }
                    }

                    if (curUnHappy < maxUnHappy) {
                        maxUnHappy = curUnHappy;
                    }
                }
            }

            out.println("Case #" + iter + ": " + maxUnHappy);
        }
        out.flush();
    }

    private static BufferedReader br = null;
    private static PrintWriter out = null;
    private static StringTokenizer stk = null;
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new FileReader(new File("B.txt")));
        out = new PrintWriter("BB.txt");
        (new B()).run();
    }

    private void loadLine() {
        try {
            stk = new StringTokenizer(br.readLine());
        }
        catch (IOException e) {
            e.printStackTrace();
        }
    }

    private String nextLine() {
        try {
            return (br.readLine());
        }
        catch (IOException e) {
            e.printStackTrace();
        }
        return null;
    }

    private int nextInt() {
        while (stk == null || !stk.hasMoreElements()) loadLine();
        return Integer.parseInt(stk.nextToken());
    }

    private long nextLong() {
        while (stk == null || !stk.hasMoreElements()) loadLine();
        return Long.parseLong(stk.nextToken());
    }

    private double nextDouble() {
        while (stk == null || !stk.hasMoreElements()) loadLine();
        return Double.parseDouble(stk.nextToken());
    }

    private String nextWord() {
        while (stk == null || !stk.hasMoreElements()) loadLine();
        return (stk.nextToken());
    }
}
