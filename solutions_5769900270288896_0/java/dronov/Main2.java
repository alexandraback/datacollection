import java.util.*;
import java.io.*;

public class Main2 {
    FastScanner in;
    PrintWriter out;

    public void solve() throws IOException {

        int test = in.nextInt();
        for (int t = 1; t <= test; t++) {

            int R = in.nextInt();
            int C = in.nextInt();
            int N = in.nextInt();

            int p = R * C;
            int ans = Integer.MAX_VALUE;
            for (int mask = 1; mask < (1 << p); mask++) {
                int count = 0;
                for (int i = 0; i < p; i++)
                    if ((mask & (1 << i)) != 0) {
                        count++;
                    }

                if (count == N) {
                    Map<Integer, Boolean> map = new HashMap<Integer, Boolean>();
                    for (int i = 0; i < p; i++) {
                        if ((mask & (1 << i)) != 0) {
                            map.put(i, true);
                        }
                    }

                    boolean[][] matrix = new boolean[R][C];
                    for (int i = 0; i < p; i++) {
                        if (map.containsKey(i)) {
                            int row = i / C;
                            int col = i - row * C;

                            matrix[row][col] = true;
                        }
                    }

                    int badness = 0;
                    for (int i = 0; i < R; i++) {
                        for (int j = 0; j < C; j++) {
                            if (!matrix[i][j]) {
                                continue;
                            }
                            if (j + 1 < C) {
                                if (matrix[i][j + 1]) {
                                    badness++;
                                }
                            }
                            if (i + 1 < R) {
                                if (matrix[i + 1][j]) {
                                    badness++;
                                }
                            }
                        }
                    }

                    ans = Math.min(ans, badness);
                }
            }

            if (ans == Integer.MAX_VALUE) {
                ans = 0;
            }
            out.println("Case #" + t + ": " + ans);
        }
    }

    public void run() {
        try {
            in = new FastScanner(new File("input.txt"));
            out = new PrintWriter(new File("output.txt"));

            solve();

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
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

    public static void main(String[] arg) {
        new Main2().run();
    }
}