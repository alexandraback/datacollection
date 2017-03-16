import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        new Main().solve();
    }

    String iFile = "C-small-attempt0.in";
    //String iFile = "B-large.in";
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
            int[] x = new int[N];
            int[] y = new int[N];
            for (int i = 0; i < N; i++) {
                x[i] = in.nextInt();
                y[i] = in.nextInt();
            }
            out.println("Case #" + (ti + 1) + ":");

            double[] rad = new double[N];
            for (int z = 0; z < N; z++) {
                int ans = N;
                for (int mask = 0; mask < 1 << N; mask++) {
                    if ((mask >> z & 1) == 1) {
                        continue;
                    }
                    int rn = 0;
                    for (int i = 0; i < N; i++) {
                        if ((mask >> i & 1) == 0 && i != z) {
                            double th = Math.atan2(x[i] - x[z], y[i] - y[z]);
                            rad[rn++] = th;
                        }
                    }
                    if (rn <= 2) {
                        ans = Math.min(ans, Integer.bitCount(mask));
                        continue;
                    }
                    Arrays.sort(rad, 0, rn);
                    boolean ok = true;
                    for (int ri = 0; ri < rn - 1; ri++) {
                        if (rad[(ri + 1)] - rad[ri] > Math.PI) {
                            // NG!!
                            ok = false;
                        }
                    }
                    if (rad[0] - rad[rn - 1] + 2 * Math.PI < Math.PI) {
                        ok = false;
                    }
                    if (ok) {
                        ans = Math.min(ans, Integer.bitCount(mask));
                    }
                }
                out.println(ans);
            }

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
