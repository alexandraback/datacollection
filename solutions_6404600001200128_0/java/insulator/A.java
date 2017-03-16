package Round1A2015;

import java.util.Scanner;

public class A {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for (int testCase = 1; testCase <= T; ++testCase) {
            int n = sc.nextInt();
            int[] m = new int[n];
            for (int i = 0; i < n; ++i)
                m[i] = sc.nextInt();
            int current = m[0];
            int s1 = 0;
            int rate = 0;
            for (int i = 1; i < n; ++i) {
                if (m[i] < m[i - 1]) {
                    s1 += m[i - 1] - m[i];
                    rate = Math.max(rate, m[i - 1] - m[i]);
                }
            }
            int s2 = 0;
            for (int i = 1; i < n; ++i) {
                s2 += Math.min(rate, m[i - 1]);
            }
            System.out.printf("Case #%d: %d %d\n", testCase, s1, s2);
        }
    }
}