//package denxx;

import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        for (int t = 1; t <= T; ++t) {
            int r, c, n;
            r = in.nextInt();
            c = in.nextInt();
            n = in.nextInt();

            int[] dp = new int[r * c + 1];
            Arrays.fill(dp, Integer.MAX_VALUE);
            for (int mask = 0; mask <= 1 << (r * c); ++mask) {
                int cur = Integer.bitCount(mask);
                dp[cur] = Math.min(dp[cur], count(r, c, mask));
            }

            System.out.println("Case #" + t + ": " + dp[n]);
        }
    }

    private static int count(int r, int c, int mask) {
        int res = 0;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (has(i, j, mask, r, c)) {
                    res += (has(i - 1, j, mask, r, c) ? 1 : 0) +
                            (has(i + 1, j, mask, r, c) ? 1 : 0) +
                            (has(i, j - 1, mask, r, c) ? 1 : 0) +
                            (has(i, j + 1, mask, r, c) ? 1 : 0);
                }
            }
        }
        return res / 2;
    }

    private static boolean has(int i, int j, int mask, int r, int c) {
        if (i < 0 || i >= r || j < 0 || j >= c) return false;
        int coord = i * c + j;
        return (mask & (1 << coord)) != 0;
    }

}
