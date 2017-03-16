import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        new Main().solve();
    }

    //String iFile = "sample";
    String iFile = "A-small-attempt0.in";
    String oFile = "out" + System.currentTimeMillis() % (1000 * 60 * 60) + ".txt";

    void solve() {
        FastScanner in = null;
        PrintWriter out = null;
        try {
            in = new FastScanner(new FileInputStream(iFile));
            out = new PrintWriter(new FileOutputStream(oFile));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        System.out.println("Input : " + iFile);
        System.out.println("Output : " + oFile);

        int T = in.nextInt();
        for (int ti = 0; ti < T; ti++) {
            int N = in.nextInt();
            int[] m = new int[N];
            for (int i = 0; i < N; i++) {
                m[i] = in.nextInt();
            }

            int ans1 = 0;
            for (int i = 1; i < N; i++) {
                if (m[i - 1] > m[i]) {
                    ans1 += m[i - 1] - m[i];
                }
            }
            int ans2 = Integer.MAX_VALUE;
            L:
            for (int rate = 0; rate <= 20010; rate++) {
                int eat = 0;
                int cur = m[0];
                for (int i = 1; i < N; i++) {
                    if (cur - rate > m[i]) {
                        // ng
                        continue L;
                    }
                    if (cur - rate <= 0) {
                        eat += cur;
                    } else {
                        eat += rate;
                    }
                    cur = m[i];
                }
                if (ans2 > eat) {
                    System.out.println((ti + 1) + " eat " + eat + " rate " + rate);
                }
                ans2 = Math.min(ans2, eat);
            }
            out.println(outs(ti, ans1 + " " + ans2));
        }
        out.close();
    }

    String outs(int ti, String ret) {
        return "Case #" + (ti + 1) + ": " + ret;
    }

    class FastScanner {
        private InputStream _stream;
        private byte[] _buf = new byte[1024];
        private int _curChar;
        private int _numChars;
        private StringBuilder _sb = new StringBuilder();

        FastScanner(InputStream stream) {
            this._stream = stream;
        }

        public int read() {
            if (_numChars == -1) throw new InputMismatchException();
            if (_curChar >= _numChars) {
                _curChar = 0;
                try {
                    _numChars = _stream.read(_buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (_numChars <= 0) return -1;
            }
            return _buf[_curChar++];
        }

        public String next() {
            int c = read();
            while (isWhitespace(c)) {
                c = read();
            }
            _sb.setLength(0);
            do {
                _sb.appendCodePoint(c);
                c = read();
            } while (!isWhitespace(c));
            return _sb.toString();
        }

        public int nextInt() {
            return (int) nextLong();
        }

        public long nextLong() {
            int c = read();
            while (isWhitespace(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            long res = 0;
            do {
                if (c < '0' || c > '9') throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isWhitespace(c));
            return res * sgn;
        }

        public boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }
    }
}
