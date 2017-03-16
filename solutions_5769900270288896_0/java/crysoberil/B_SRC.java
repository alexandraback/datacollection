import java.io.File;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(new File("/home/crysoberil/a"));
        new Main().run(in);
        in.close();
    }

    int best;
    boolean[][] used;
    int n, r, c;

    private void run(Scanner in) {
        int testCase = in.nextInt();

        for (int kase = 1; kase <= testCase; kase++) {
            r = in.nextInt();
            c = in.nextInt();
            n = in.nextInt();
            used = new boolean[r][c];
            best = Integer.MAX_VALUE;
            f(0, 0, n, 0);
            System.out.println(String.format("Case #%d: %d", kase, best));
        }
    }

    private void f(int i, int j, int left, int clashes) {
        if (left == 0) {
            best = Math.min(best, clashes);
            return;
        }

        if (i == r)
            return;

        int nextI = j == c - 1 ? i + 1 : i;
        int nextj = j == c - 1 ? 0 : j + 1;

        f(nextI, nextj, left, clashes);

        used[i][j] = true;

        int newClashes = 0;

        if (j != 0 && used[i][j - 1])
            newClashes++;

        if (i != 0 && used[i - 1][j])
            newClashes++;

        f(nextI, nextj, left - 1, clashes + newClashes);

        used[i][j] = false;
    }
}
