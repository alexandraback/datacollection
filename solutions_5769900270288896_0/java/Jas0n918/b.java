import java.util.Scanner;

/**
 * @Author Jason918
 */
public class Main {


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int caseNo = 1; caseNo <= t; caseNo++) {
            int r = sc.nextInt();
            int c = sc.nextInt();
            int n = sc.nextInt();

            System.out.printf("Case #%d: %d%n", caseNo, solve(r, c, n));
        }


    }

    private static int solve(int r, int c, int n) {
        if (n == 0) {
            return 0;
        }
        if (r > c) {
            int tmp = c;
            c = r;
            r = tmp;
        }
        int rp = 1 << r;
        int[][][] f = new int[c][n + 1][rp];
        for (int j = 0; j < c; j++) {
            for (int i = 0; i <= n; i++) {
                for (int s = 0; s < rp; s++) {
                    f[j][i][s] = 4 * n;
                }
            }
        }

        for (int s = 0; s < rp; s++) {
            if (countOnes(s) <= n)
                f[0][countOnes(s)][s] = calcNeighborVertical(s);
        }
        for (int j = 1; j < c; j++) {
            for (int i = 0; i <= n; i++) {
                if (i > (j + 1) * r) {
                    break;
                }
                for (int s = 0; s < rp; s++) {
                    int sones = countOnes(s);
                    if (sones > i) {
                        continue;
                    }
                    for (int t = 0; t < rp; t++) {
                        f[j][i][s] = Math.min(f[j][i][s], f[j - 1][i - sones][t] + calcNeighborHorizontal(s, t));
                    }
                    f[j][i][s] += calcNeighborVertical(s);
//                    System.out.printf("j=%s,i=%d,s=%d,f[j][i][s]=%d\n", j, i, s, f[j][i][s]);
                }
            }
        }
        int ans = 4 * n;
        for (int s = 0; s < rp; s++) {
            ans = Math.min(f[c - 1][n][s], ans);
        }
        return ans;
    }

    private static int calcNeighborHorizontal(int s, int t) {
        int ans = 0;
        while (s > 0 && t > 0) {
            if ((s & 1) == 1 && (t & 1) == 1) {
                ans++;
            }
            s >>= 1;
            t >>= 1;
        }
        return ans;
    }


    private static int countOnes(int s) {
        int ans = 0;
        while (s > 0) {
            if ((s & 1) == 1) {
                ans++;
            }
            s >>= 1;
        }
        return ans;
    }

    private static int calcNeighborVertical(int s) {
        int ans = 0;
        int last = 0;
        while (s > 0) {
            if ((s & 1) == 1 && last == 1) {
                ans++;
            }
            last = s & 1;
            s >>= 1;
        }
        return ans;
    }


}
