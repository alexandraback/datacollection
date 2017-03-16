import java.io.IOException;
import java.util.Locale;
import java.util.Scanner;

public class NoisyNeighbors {

    private void processInput() throws IOException {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();

        for (int testCase = 1; testCase <= T; testCase++) {
            int R = in.nextInt();
            int C = in.nextInt();
            int N = in.nextInt();

            solve(testCase, R, C, N);

        }

        in.close();
    }

    private void solve(int testCase, int R, int C, int N) {
        int res = Integer.MAX_VALUE;

        int rc = R * C;
        for (int mask = 0; mask < 1<<rc; mask++) {
            if (Integer.bitCount(mask) == N) {
                res = Math.min(res, go(mask, R, C));
            }
        }

        System.out.printf(Locale.ENGLISH, "Case #%d: %d\n", testCase, res);
    }

    private int go(int mask, int R, int C) {
        boolean[][] board = new boolean[R][C];
        int res = 0;
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                int idx = r * C + c;
                if (((1<<idx) & mask) != 0) {
                    board[r][c] = true;
                }
            }
        }

        for (int r = 0; r < R; r++) {
            for (int c = 1; c < C; c++) {
                if (board[r][c] && board[r][c-1]) {
                    res++;
                }
            }
        }
        for (int r = 1; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (board[r][c] && board[r-1][c]) {
                    res++;
                }
            }
        }
        return res;
    }
    public static void main(String[] args) throws Exception {
        NoisyNeighbors main = new NoisyNeighbors();
        main.processInput();
    }
}
