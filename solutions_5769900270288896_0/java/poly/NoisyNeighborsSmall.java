import java.util.Scanner;

/**
 * Created by poly on 5/3/15.
 */
public class NoisyNeighborsSmall {
    static boolean isAdj(int i, int j, int r, int c) {
        int y1 = i / c;
        int x1 = i % c;
        int y2 = j / c;
        int x2 = j % c;
        if (Math.abs(y1 - y2) + Math.abs(x1 - x2) == 1) return true;
        else return false;
    }

    public static void main(String argv[]) {
        Scanner scanner = new Scanner(System.in);
        int T = scanner.nextInt();
        for (int t = 0; t < T; t++) {
            int r = scanner.nextInt();
            int c = scanner.nextInt();
            int n = scanner.nextInt();
            int rc = r * c;
            int ans = Integer.MAX_VALUE;
            for (int b = 0; b < (1 << rc); ++b) {
                if (Integer.bitCount(b) != n) {
                    continue;
                }
                int tmp = 0;
                for (int i = 0; i < rc; i++) {
                    if (((1 << i) & b) == 0) continue;
                    for (int j = i + 1; j < rc; j++) {
                        if (((1 << j) & b) == 0) continue;
                        if (isAdj(i, j, r, c)) {
                            tmp++;
                        }
                    }
                }
                ans = Math.min(ans, tmp);
            }
            System.out.println("Case #" + (t + 1) + ": " + ans);
        }
    }
}
