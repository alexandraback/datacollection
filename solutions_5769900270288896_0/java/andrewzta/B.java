import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;
import static java.lang.Math.*;

public class B {
    FastScanner in;
    PrintWriter out;

    public void solve() throws IOException {
        int testNo = in.nextInt();
        for (int test = 1; test <= testNo; test++) {
            int ans = 0;
            int r = in.nextInt();
            int c = in.nextInt();
            int n = in.nextInt();
            int[] dx = {-1, 0, 1, 0};
            int[] dy = {0, -1, 0, 1};

            boolean[][] a = new boolean[r][c];
            int best = Integer.MAX_VALUE;
            for (int mask = 0; mask < (1 << (r * c)); mask++) {
                if (Integer.bitCount(mask) == n) {
                    int k = 0;
                    for (int i = 0; i < r; i++) {
                        for (int j = 0; j < c; j++) {
                            a[i][j] = (mask & (1 << k)) != 0;
                            k++;
                        }
                    }

                    int cnt = 0;
                    for (int i = 0; i < r; i++) {
                        for (int j = 0; j < c; j++) {
                            for (int d = 0; d < 4; d++) {
                                int ni = i + dx[d];
                                int nj = j + dy[d];
                                if (0 <= ni && ni < r && 0 <= nj && nj < c) {
                                    if (a[i][j] && a[ni][nj]) {
                                        cnt++;
                                    }
                                }
                            }
                        }
                    }
                    if (cnt < best) {
                        best = cnt;
                    }
                }
            }

            out("Case #%d: %d\n", test, best / 2);
        }
    }

    public void run() {
        try {
            in = new FastScanner(new File("B-small-attempt0.in"));
            out = new PrintWriter(new File("B-small-attempt0.out"));

            solve();

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] arg) {
        new B().run();
    }

    void out(String format, Object... s) {
        System.out.printf(format, s);
        out.printf(format, s);
        out.flush();
    }

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(File file) throws IOException {
            br = new BufferedReader(new FileReader(file));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                    return "";
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }
        long nextLong() {
            return Long.parseLong(next());
        }
    }
}