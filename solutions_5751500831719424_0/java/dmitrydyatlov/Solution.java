import java.io.*;
import java.util.*;

public class Solution {
    // TODO: do not forget
    private static final int READ_FROM_FILE = 1;
    private static final int WRITE_TO_FILE = 1;
    private static final String INPUT_FILE = "A-small-attempt1.in";
    private static final String OUTPUT_FILE = "A-small-attempt1.out";

    private void run(InputReader in, PrintWriter out) {
        int n;
        n = in.nextInt();
        String mas[] = new String[100];
        for(int i = 0; i < n; ++i) {
            mas[i] = in.next();
        }
        String mask[] = new String[100];
        for(int i = 0; i < n; ++i) {
            String s = String.valueOf(mas[i].charAt(0));
            for(int j = 1; j < mas[i].length(); ++j) {
                if(mas[i].charAt(j) != s.charAt(s.length() - 1)) {
                    s += mas[i].charAt(j);
                }
            }
            mask[i] = s;
        }

        for(int i = 1; i < n; ++i) {
            if(!mask[i].equals(mask[0])) {
                out.println("Fegla Won");
                return;
            }
        }

        int cnt[][] = new int[100][100];
        for(int i = 0; i < n; ++i) {
            int ind = 0;
            for(int j = 0; j < mas[i].length(); ++j) {
                if(mas[i].charAt(j) == mask[0].charAt(ind)) {
                    cnt[i][ind]++;
                } else {
                    ind++;
                    cnt[i][ind]++;
                }
            }
        }
        int res = 0;
        for(int i = 0; i < mask[0].length(); ++i) {
            int add = Integer.MAX_VALUE;
            for(int j = 1; j <= 100; ++j) {
                int tmp = 0;
                for(int k = 0; k < n; ++k) {
                    tmp += Math.abs(cnt[k][i] - j);
                }
                add = Math.min(add, tmp);
            }
            res += add;
        }
        out.println(res);
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