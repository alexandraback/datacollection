import java.io.*;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Artem Gilmudinov
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream;
        try {
            inputStream = new FileInputStream("A-small-attempt1.in");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        OutputStream outputStream;
        try {
            outputStream = new FileOutputStream("output.txt");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        Task solver = new Task();
        solver.solve(1, in, out);
        out.close();
    }

    static class Task {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int T = in.readInt();
            for (int t = 1; t <= T; t++) {
                int n = in.readInt();
                PairInt[] pairs = new PairInt[n];
                for (int i = 0; i < n; i++) {
                    pairs[i] = new PairInt(i, in.readInt());
                }
                Comparator<PairInt> cmp = new Comparator<PairInt>() {

                    public int compare(PairInt o1, PairInt o2) {
                        return o1.y - o2.y;
                    }
                };

                StringBuilder ans = new StringBuilder();
                while (true) {
                    Arrays.sort(pairs, cmp);
                    if (pairs[n - 1].y == 0) {
                        break;
                    }
                    int max = pairs[n - 1].y;
                    int cnt = 0;
                    for (int i = n - 1; i >= 0; i--) {
                        if (max == pairs[i].y) {
                            ++cnt;
                        }
                    }
                    if (cnt == 1) {
                        ans.append((char) ('A' + pairs[n - 1].x) + " ");
                        pairs[n - 1].y--;
                    } else if (cnt == 2) {
                        ans.append((char) ('A' + pairs[n - 1].x) + "" + (char) ('A' + pairs[n - 2].x) + " ");
                        pairs[n - 1].y--;
                        pairs[n - 2].y--;
                    } else {
                        ans.append((char) ('A' + pairs[n - 1].x) + " ");
                        pairs[n - 1].y--;
                    }
                }
                out.println(String.format("Case #%d: %s", t, ans));

            }
        }

    }

    static class PairInt {
        public int x;
        public int y;

        public PairInt(int x, int y) {
            this.x = x;
            this.y = y;
        }


        public boolean equals(Object obj) {
            PairInt pairInt = (PairInt) obj;
            return pairInt.x == x && pairInt.y == y;
        }

        public String toString() {
            return x + " " + y;
        }

        public PairInt clone() {
            return new PairInt(x, y);
        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private SpaceCharFilter filter;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
            if (numChars == -1)
                throw new InputMismatchException();
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars <= 0)
                    return -1;
            }
            return buf[curChar++];
        }

        public int readInt() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public boolean isSpaceChar(int c) {
            if (filter != null)
                return filter.isSpaceChar(c);
            return isWhitespace(c);
        }

        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);

        }

    }
}

