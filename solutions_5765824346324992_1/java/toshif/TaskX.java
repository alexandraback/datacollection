package gcj1a.b;

import java.io.*;
import java.net.URL;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;

/**
 * @author fuku
 */
public class TaskX {
    public static void main(String[] args) throws IOException {
        String inFile = "B-large.in";
        // String inFile = "X-small.in";

        URL inFileUrl = TaskX.class.getResource(inFile);
        InputStream inputStream = new BufferedInputStream(new FileInputStream(inFileUrl.getFile()));
        Scanner in = new Scanner(inputStream);

        String outFile = inFile + ".out";
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(outFile)));

        System.out.printf("Input File = [%s]\n", inFile);
        System.out.printf("Output File = [%s]\n", outFile);

        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            System.err.println("------------------");
            System.err.println("test " + (i + 1));
            Solver solver = new Solver();
            String ans = solver.solve(i, in, out);
            out.println("Case #" + (i+1) + ": " + ans);
            System.err.println("Case #" + (i + 1) + ": " + ans);
        }
        out.close();
    }

    static class Solver {

        class P implements Comparable<P> {
            long time;
            int b;

            public int compare(P o1, P o2) {
                if (o1.time != o2.time) {
                    return Long.signum(o1.time - o2.time);
                }
                return o1.b - o2.b;
            }

            public P(long time, int b) {
                this.time = time;
                this.b = b;
            }

            @Override
            public int compareTo(P o) {
                return compare(this, o);
            }
        }

        public String solve(int testNumber, Scanner in, PrintWriter out) {
            int B = in.nextInt();
            long N = in.nextLong();
            System.err.printf("B=%s, N=%s\n", B, N);
            long[] M = new long[B];
            long[] M2 = new long[B];
            long[] M3 = new long[B];

            for (int i = 0; i < B; i++) {
                M[i] = in.nextLong();
            }

            if (N <= B) {
                return "" + N;
            }

            long g = M[0];
            for (int i = 1; i < B; i++) {
                g = gcd(g, M[i]);
            }
            for (int i = 0; i < B; i++) {
                M2[i] = M[i] / g;
            }

            long hi = 1000_000_000_000_000_000L;
            long lo = 0;
            int cnt = 0;
            if (N - (B + 10) > 10) {
                while (hi != lo && cnt < 100000) {
                    cnt++;

                    long mi = (hi + lo) / 2;
                    long tot = 0;
                    for (int i = 0; i < B; i++) {
                        tot += mi / M2[i];
                    }
                    if (tot >= N - (B + 10)) {
                        if (hi == mi) break;
                        hi = mi;
                    } else {
                        if (lo == mi) break;
                        lo = mi;
                    }
                }
            }

            System.err.printf("cnt=%s\n", cnt);
            System.err.printf("lo=%s, hi=%s\n", lo, hi);

            long tot = 0;
            for (int i = 0; i < B; i++) {
                tot += lo / M2[i];
            }

            final PriorityQueue<P> q = new PriorityQueue<>();
            for (int i = 0; i < B; i++) {
                long rem = M2[i] - (lo % M2[i]);
                q.add(new P(rem, i));
            }

            long N2 = N - tot - B;
            System.err.printf("N2=%s, testNum=%s, N=%s, \n", N2, testNumber, N);
            int cb = 0;
            for (int i = 0; i < N2; i++) {
                P p = q.poll();
                cb = p.b;
                p.time += M[p.b];
                q.add(p);
            }

            return "" + (cb+1);
        }

        /**
         * @return the greatest common divisor
         */
        public static long gcd(long a, long b) {
            if (b == 0) return a;
            return gcd(b, a % b);
        }

        /**
         * the least common multiple (LCM)
         */
        public static long lcm(long a, long b){
            return a * b / gcd(a, b);
        }
    }
}


