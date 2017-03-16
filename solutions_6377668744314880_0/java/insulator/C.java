package Round1A2015;

import java.util.Scanner;

public class C {

    private static long vec(long ax, long ay, long bx, long by) {
        return ax * by - ay * bx;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for (int testCase = 1; testCase <= T; ++testCase) {
            int n = sc.nextInt();
            long[] x = new long[n];
            long[] y = new long[n];
            for (int i = 0; i < n; ++i) {
                x[i] = sc.nextLong();
                y[i] = sc.nextLong();
            }
            System.out.printf("Case #%d:\n", testCase);
            for (int i = 0; i < n; ++i) {
                int best = n + 1;
                if (n <= 3)
                    best = 0;
                for (int j = 0; j < n; ++j) {
                    if (i == j)
                        continue;
                    int plus = 0;
                    int minus = 0;
                    for (int k = 0; k < n; ++k) {
                        long v = vec(x[k] - x[i], y[k] - y[i], x[j] - x[i], y[j] - y[i]);
                        if (v > 0)
                            plus++;
                        else if (v < 0)
                            minus++;
                    }
                    best = Math.min(best, Math.min(plus, minus));
                }
                System.out.println(best);
            }
        }
    }
}