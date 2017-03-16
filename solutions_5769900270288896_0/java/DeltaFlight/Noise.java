package mb;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * @author fly
 */
public class Noise {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner scanner = new Scanner(new FileInputStream(args[0]));
        try (PrintWriter out = new PrintWriter(new FileOutputStream(args[0].replaceAll("\\.in", ".out")))) {
            int nTestCases = scanner.nextInt();
            for (int i = 1; i <= nTestCases; ++i) {
                R = scanner.nextInt();
                C = scanner.nextInt();
                int N = scanner.nextInt();
                out.println(String.format("Case #%d: %d", i, solve(N)));
            }
        }
    }

    static int R;
    static int C;
    static boolean m[];

    private static int solve(int n) {
        if (n <= 1) return 0;
        int area = R * C;
        int well = (area + 1) / 2;
        if (n <= well) return 0;
        m = new boolean[area];
        well = fill(false);
        int res1 = place(n - well);
        well = fill(true);
        int res2 = place(n - well);
        return Math.min(res1, res2);
    }

    private static int place(int n) {
        if (n == 0) return walls();
        int best = Integer.MAX_VALUE;
        for (int i = 0; i < R * C; ++i) {
            if (!m[i]) {
                m[i] = true;
                int cand = place(n - 1);
                if (cand < best) {
                    best = cand;
                }
                m[i] = false;
            }
        }
        return best;
    }

    private static int walls() {
        int count = 0;
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (get(i, j)) {
                    if (j < C - 1 && get(i, j + 1)) count++;
                    if (i < R - 1 && get(i + 1, j)) count++;
                }
            }
        }
        return count;
    }

    private static int fill(boolean odd) {
        int count = 0;
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                boolean s = ((j & 1) == 1) == odd;
                set(i, j, s);
                count += s ? 1 : 0;
            }
            odd = !odd;
        }
        return count;
    }

    private static void set(int i, int j, boolean s) {
        m[i * C + j] = s;
    }

    private static boolean get(int i, int j) {
        return m[i * C + j];
    }

}
