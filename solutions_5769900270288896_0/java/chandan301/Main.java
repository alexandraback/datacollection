package codejam.y2015.r1b.prob2;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main {

    static String BASE = "/Users/chandangiri/contest/src/main/java/codejam/y2015/r1b/prob2/";
    public static void main(String args[]) throws FileNotFoundException {
        InputStream inputStream = new FileInputStream(new File(BASE + "in.txt"));
        OutputStream outputStream = new FileOutputStream(new File(BASE + "out.txt"));
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        Solver solver = new Solver();
        int testCount = in.nextInt();
        for (int i = 1; i <= testCount; i++) {
            out.printf("Case #%d: ", i);
            solver.solve(in, out);
        }
        out.close();
    }

    private static class Solver {

        static int bit[] = new int[17];

        {
            bit[0] = 1;
            for (int i=1; i<=16; i++) {
                bit[i] = bit[i-1] << 1;
            }
        }

        public void solve(InputReader in, PrintWriter out) {
            int r = in.nextInt();
            int c = in.nextInt();
            int n = in.nextInt();

            int sq = r*c;

            int happiness = Integer.MAX_VALUE;
            for (int i=0; i<(1 << sq); i++) {
                int num = 0;
                int arr[][] = new int[r][c];
                for (int j=0; j<sq; j++) {
                    int x = j / c;
                    int y = j % c;
                    if ((i & bit[j]) > 0) {
                        arr[x][y] = 1;
                        num++;
                    }
                }
                if (num == n) {
                    int happy = happy(arr, r, c);
                    happiness = Math.min(happiness, happy);
                }
            }
            out.println(happiness);
        }

        private int happy(final int[][] arr, int n, int m) {
            int happy = 0;
            for (int i=0; i<n-1; i++) {
                for (int j=0; j<m; j++) {
                    if (arr[i][j] + arr[i+1][j] > 1) {
                        happy++;
                    }
                }
            }

            for (int i=0; i<m-1; i++) {
                for (int j=0; j<n; j++) {
                    if (arr[j][i] + arr[j][i+1] > 1) {
                        happy++;
                    }
                }
            }

//            for (int i=1; i<=n; i++) {
//                for (int j=1; j<=m; j++) {
//                    if (arr[i][j] == 1 && (arr[i-1][j] + arr[i+1][j] + arr[i][j-1] + arr[i][j+1]) > 0) {
//                        happy++;
//                    }
//                }
//            }
            return happy;
        }

    }

    private static class InputReader {
        private final BufferedReader reader;
        private StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream));
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }
    }
}
