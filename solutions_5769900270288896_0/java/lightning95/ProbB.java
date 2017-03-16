import java.io.*;
import java.util.StringTokenizer;

/**
 * @author Aydar Gizatullin a.k.a. lightning95, aydar.gizatullin@gmail.com
 *         Created on 4/18/15.
 */

public class ProbB {
    RW rw;

    class RW {
        private boolean eof;
        StringTokenizer st;
        PrintWriter out;
        BufferedReader br;

        RW(String inputFile, String outputFile) {
            br = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(new OutputStreamWriter(System.out));

            File f = new File(inputFile);
            if (f.exists() && f.canRead()) {
                try {
                    br = new BufferedReader(new FileReader(inputFile));
                    out = new PrintWriter(new FileWriter(outputFile));
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    eof = true;
                    return "-1";
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        void println() {
            out.println();
        }

        void println(Object o) {
            out.println(o);
        }

        void print(Object o) {
            out.print(o);
        }

        void close() {
            try {
                br.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
            out.close();
        }

        public long nextLong() {
            return Long.parseLong(next());
        }
    }

    public static void main(String[] args) {
        new ProbB().run();
    }

    private void run() {
        rw = new RW("input.txt", "output.txt");
        solve();
        rw.close();
    }

    private void solve() {
        int t_num = rw.nextInt();
        int[] h = {1, 0};

        for (int t_id = 0; t_id < t_num; ++t_id) {
            int r = rw.nextInt();
            int c = rw.nextInt();
            int n = rw.nextInt();

            int m = r * c;

            int ans = Integer.MAX_VALUE;
            for (int mask = 0; mask <= (1 << m); ++mask) {
                if (Integer.bitCount(mask) != n) {
                    continue;
                }
                int[][] a = new int[r][c];
                for (int i = 0; i < m; ++i) {
                    a[i / c][i % c] = ((1 << i) & mask) > 0 ? 1 : 0;
                }
                int cur = 0;
                for (int i = 0; i < r; ++i) {
                    for (int j = 0; j < c; ++j) {
                        if (a[i][j] == 1) {
                            for (int k = 0; k < 2; ++k) {
                                int x = i + h[k];
                                int y = j + h[1 - k];
                                if (x >= 0 && y >= 0 && x < r && y < c && a[x][y] == 1) {
                                    ++cur;
                                }
                            }
                        }
                    }
                }
                ans = Math.min(ans, cur);
            }
            rw.println("Case #" + (t_id + 1) + ": " + ans);
        }
    }
}

