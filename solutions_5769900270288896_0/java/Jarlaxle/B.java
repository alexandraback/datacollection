import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class B {
    private static final String inFile = "B-small-attempt0.in";
    private static final String outFile = "B-out.txt";

    public static void main(String args[]) throws IOException {
        Scanner scanner = new Scanner(new FileReader(inFile));
        int T = scanner.nextInt();
        FileWriter fw = new FileWriter(outFile);

        for (int t = 1; t <= T; ++t) {
            int r = scanner.nextInt();
            int c = scanner.nextInt();
            int n = scanner.nextInt();
            fw.write(String.format("Case #%d: %s\n", t, solve(r, c, n)));
        }
        fw.close();
    }

    static int solve(int r, int c, int n) {
        boolean[][] b = new boolean[r][c];
        int m = r * c;
        int l = 1 << m;
        int res = Integer.MAX_VALUE;
        for (int i = 0; i < l; ++i) {
            int set = 0;
            for (int j = 0; j < m; ++j) {
                int rr = j % r;
                int cc = j / r;
                b[rr][cc] = (i & (1 << j)) == 0;
                if (b[rr][cc]) ++set;
            }
            if (set != n) continue;
            res = Math.min(res, get(b));
        }
        return res;
    }

    static int get(boolean[][] b) {
        int r = b.length;
        int c = b[0].length;
        int res = 0;
        for (int i = 0; i < r; ++i) {
            for (int j = 1; j < c; ++j) {
                if (b[i][j] && b[i][j - 1]) ++res;
            }
        }
        for (int i = 1; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (b[i][j] && b[i - 1][j]) ++res;
            }
        }
        return res;
    }
}
