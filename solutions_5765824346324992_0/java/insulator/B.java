package Round1A2015;

import java.util.Scanner;

public class B {
    private static long proc(long time, final int[] m) {
        long done = 0;
        for (int k: m)
            done += time / k + 1;
        return done;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for (int testCase = 1; testCase <= T; ++testCase) {
            int b = sc.nextInt();
            int n = sc.nextInt();
            int[] m = new int[b];
            for (int i = 0; i < b; ++i)
                m[i] = sc.nextInt();
            long low = -1;
            long hi = 1000000L * Integer.MAX_VALUE;
            while (low < hi - 1) {
                long test = (low + hi) / 2;
                if (proc(test, m) < n) {
                    low = test;
                } else {
                    hi = test;
                }
            }
            n -= proc(low, m);
            int i = 0;
            while (true) {
                if (hi % m[i] == 0) {
                    n--;
                }
                if (n == 0)
                    break;
                ++i;
            }
            System.out.printf("Case #%d: %d\n", testCase, i + 1);
        }
    }
}