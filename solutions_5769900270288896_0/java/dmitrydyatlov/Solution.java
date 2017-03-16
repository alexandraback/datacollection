import java.io.*;
import java.util.*;

public class Solution {
    // TODO: do not forget
    private static final int READ_FROM_FILE = 1;
    private static final int WRITE_TO_FILE = 1;
    private static final String INPUT_FILE = "B-small-attempt0.in";
    private static final String OUTPUT_FILE = "B-small-attempt0.out";

    private void run(InputReader in, PrintWriter out) {
        int r = in.nextInt(), c = in.nextInt(), n = in.nextInt();

        int ans = 10000000;
        for(int i = 0; i < (1 << (r * c)); ++i) {
            int t[][] = new int[r][c];
            int cnt = 0;
            for(int j = 0; j < r * c; ++j) {
                int x = (i & (1 << j)) > 0 ? 1 : 0;
                t[j / c][j % c] = x;
                cnt += x;
            }
            if(cnt != n) {
                continue;
            }

            int res = 0;
            for(int j = 0; j < r; ++j)
                for(int k = 0; k < c - 1; ++k)
                    if((t[j][k] & t[j][k + 1]) > 0) {
                        res++;
                    }
            for(int j = 0; j < r - 1; ++j)
                for(int k = 0; k < c; ++k)
                    if((t[j][k] & t[j + 1][k]) > 0) {
                        res++;
                    }

            ans = Math.min(ans, res);
        }
        out.print(ans);
    }

    public static void main(String[] args) {
        InputReader in;
        PrintWriter out;
        try {
            if (READ_FROM_FILE == 1) {
                in = new InputReader(new FileInputStream(INPUT_FILE));
            } else {
                in = new InputReader(System.in);
            }
            if (WRITE_TO_FILE == 1) {
                out = new PrintWriter(OUTPUT_FILE);
            } else {
                out = new PrintWriter(System.out);
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }

        Solution solution = new Solution();
        int cases = in.nextInt();
        for(int i = 1; i <= cases; ++i) {
            out.print("Case #" + i + ": ");
            solution.run(in, out);
            out.println();
        }

        out.println();
        out.flush();
        out.close();
    }

    private static class InputReader {
        private BufferedReader reader;
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

        public long nextLong() {
            return Long.parseLong(next());
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }

        public char nextCharacter() {
            return next().charAt(0);
        }
    }
}