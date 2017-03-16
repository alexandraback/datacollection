import java.io.*;
import java.util.StringTokenizer;

/**
 * Created by kraskevich on 5/2/15.
 */
public class B {

    final int INF = 1_000_000;

    int[] dx = {-1, 1, 0, 0};
    int[] dy = {0, 0, -1, 1};

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        out.printf("Case #%d: ", testNumber);
        int rows = in.nextInt();
        int cols = in.nextInt();
        int n = in.nextInt();
        int res = INF;
        for (int mask = 0; mask < (1 << rows * cols); mask++)
            if (Integer.bitCount(mask) == n) {
                boolean[][] field = new boolean[rows][cols];
                int cnt = 0;
                for (int i = 0; i < rows; i++)
                    for (int j = 0; j < cols; j++) {
                        if ((mask & (1 << cnt)) != 0) {
                            field[i][j] = true;
                        }
                        cnt++;
                    }
                int cur = 0;
                for (int i = 0; i < rows; i++)
                    for (int j = 0; j < cols; j++)
                        for (int d = 0; d < 4; d++) {
                            int x = i + dx[d];
                            int y = j + dy[d];
                            if (x >= 0 && x < rows && y >= 0 && y < cols && field[i][j] && field[x][y])
                                cur++;
                        }
                res = Math.min(res, cur / 2);
            }
        out.println(res);
    }

    public static void main(String[] args)throws IOException {
        FastScanner in = new FastScanner(new FileInputStream("input.txt"));
        PrintWriter out = new PrintWriter("output.txt");
        int t = in.nextInt();
        for (int test = 1; test <= t; test++)
            new B().solve(test, in, out);
        in.close();
        out.close();
    }

    static class FastScanner {
        private StringTokenizer tokenizer;
        private BufferedReader reader;

        public FastScanner(InputStream inputStream) {
            reader = new BufferedReader(new InputStreamReader(inputStream));
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                String line;
                try {
                    line = reader.readLine();
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
                if (line == null)
                    return null;
                tokenizer = new StringTokenizer(line);
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }

        public String nextLine() {
            String line;
            try {
                line = reader.readLine();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
            tokenizer = null;
            return line;
        }

        public void close() {
            try {
                reader.close();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
    }

}
