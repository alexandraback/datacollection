import java.io.*;

public class B {

    private static final boolean DEBUG = true;
    private static final boolean TEST = true;

    private final void solve(final InputReader in, final OutputWriter out) throws Exception {

//        if (TEST) {
//
//            for (int i = 1; i <= 4; ++i) {
//                for (int j = 1; j <= 1; ++j) {
//                    for (int cnt = 0; cnt <= i * j; ++cnt) {
//
//                        int result0 = Integer.MAX_VALUE;
//
//                        int m = i * j;
//                        for (int q = 0; q < (1 << m); ++q) {
//
//                            int t = q;
//                            int count = 0;
//                            while (t > 0) {
//                                t &= t - 1;
//                                ++count;
//                            }
//
//                            if (count != cnt) {
//                                continue;
//                            }
//
//                            t = q;
//                            int[][] a = new int[i][j];
//                            for (int ii = 0; ii < i; ++ii) {
//                                for (int jj = 0; jj < j; ++jj) {
//
//                                    if (t % 2 == 0) {
//                                        a[ii][jj] = 1;
//                                    }
//
//                                    t >>= 1;
//                                }
//                            }
//
//                            count = 0;
//                            for (int ii = 0; ii < i; ++ii) {
//                                for (int jj = 0; jj < j; ++jj) {
//
//                                    if (a[ii][jj] != 1) {
//                                        continue;
//                                    }
//
//                                    if (ii > 0 && a[ii - 1][jj] == 1) {
//                                        ++count;
//                                    }
//                                    if (jj > 0 && a[ii][jj - 1] == 1) {
//                                        ++count;
//                                    }
//                                    if (ii + 1 < i && a[ii + 1][jj] == 1) {
//                                        ++count;
//                                    }
//                                    if (jj + 1 < j && a[ii][jj + 1] == 1) {
//                                        ++count;
//                                    }
//                                }
//                            }
//                        }
//                    }
//                }
//            }
//        }

        for (int caseIndex = 1, caseCount = in.nextInt(); caseIndex <= caseCount; ++caseIndex) {

            int n = in.nextInt();
            int m = in.nextInt();
            int k = in.nextInt();


//            calc1(1, 16, 9);

            int result = Math.min(calc0(n, m, k), calc0(m, n, k));
            int result1 = Math.min(calc1(n, m, k), calc1(m, n, k));

            if (result != result1){
                int test = 1;
            }

            out.writeln(String.format("Case #%d: %d", caseIndex, result1));
        }
    }

    int calc1(int i, int j, int k) {

        int result = Integer.MAX_VALUE;

        int m = i * j;
        for (int q = 0; q < (1 << m); ++q) {

            int t = q;
            int count = 0;
            while (t > 0) {
                t &= t - 1;
                ++count;
            }

            if (count != k) {
                continue;
            }

            t = q;
            int[][] a = new int[i][j];
            for (int ii = 0; ii < i; ++ii) {
                for (int jj = 0; jj < j; ++jj) {

                    if (t % 2 == 1) {
                        a[ii][jj] = 1;
                    }

                    t >>= 1;
                }
            }

            count = 0;
            for (int ii = 0; ii < i; ++ii) {
                for (int jj = 0; jj < j; ++jj) {

                    if (a[ii][jj] != 1) {
                        continue;
                    }

                    if (ii > 0 && a[ii - 1][jj] == 1) {
                        ++count;
                    }
                    if (jj > 0 && a[ii][jj - 1] == 1) {
                        ++count;
                    }
                    if (ii + 1 < i && a[ii + 1][jj] == 1) {
                        ++count;
                    }
                    if (jj + 1 < j && a[ii][jj + 1] == 1) {
                        ++count;
                    }
                }
            }

            result = Math.min(result, count / 2);
        }

        return result;
    }


    int calc0(int n, int m, int k) {

        int total = (n - 1) * m + (m - 1) * n;
        int rest = n * m - k;

        if (rest == 0) {
            return total;
        }

        int[][] a = new int[n][m];

        for (int sub = 4; sub >= 0; --sub) {

            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (a[i][j] == 1) {
                        continue;
                    }

                    int count = 0;
                    if (i > 0 && a[i - 1][j] == 0) {
                        ++count;
                    }
                    if (j > 0 && a[i][j - 1] == 0) {
                        ++count;
                    }
                    if (i + 1 < n && a[i + 1][j] == 0) {
                        ++count;
                    }
                    if (j + 1 < m && a[i][j + 1] == 0) {
                        ++count;
                    }

                    if (count == sub) {
                        a[i][j] = 1;
                        total -= count;
                        --rest;
                        if (rest == 0) {
                            return total;
                        }
                    }
                }
            }
        }

        return 0;
    }

    public static void main(String[] _args) {
        final String[] args = _args;
        Thread th = new Thread(null, new Runnable() {
            @Override
            public void run() {
                runMain(args);
            }
        }, "test", 32 << 20);
        th.setPriority(Thread.MAX_PRIORITY);
        th.start();
        try {
            th.join();
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }
    }

    private static final void runMain(String[] args) {
        try {

            final InputReader in;
            final OutputWriter out;

            if (DEBUG) {

                final String fileIn = B.class.getSimpleName().toLowerCase() + ".in";
                final String fileOut = B.class.getSimpleName().toLowerCase() + ".out";

                in = new InputReader(new FileInputStream(fileIn));
                out = new OutputWriter(new FileWriter(fileOut));
            } else {

                in = new InputReader(System.in);
                out = new OutputWriter(new OutputStreamWriter(System.out));
            }

            new B().solve(in, out);

            out.close();

        } catch (Exception ex) {

            throw new RuntimeException(ex);
        }
    }

    private static final class InputReader {

        private static final byte ZERO = '0';
        private static final byte NINE = '9';

        private static final int BUFFER_SIZE = 32 << 20;

        private final BufferedInputStream in;

        private final byte[] buffer = new byte[BUFFER_SIZE];
        private int bufferSize = 0;
        private int offset = buffer.length;
        private final StringBuilder sb = new StringBuilder(1 << 20);

        private InputReader(final InputStream in) {
            this.in = (in instanceof BufferedInputStream) ? ((BufferedInputStream) in) : (new BufferedInputStream(in));
        }

        private final int read() throws Exception {
            if (offset >= bufferSize) {
                bufferSize = in.read(buffer);
                if (bufferSize <= 0) {
                    return -1;
                }
                offset = 0;
            }
            return buffer[offset++];
        }

        private final boolean isWhiteSpace(final int c) {
            return c == ' ' || c == '\r' || c == '\t' || c == '\n' || c == -1;
        }

        public final String next() throws Exception {
            sb.setLength(0);
            int c = read();
            while (isWhiteSpace(c)) {
                c = read();
            }
            while (!isWhiteSpace(c)) {
                sb.append((char) c);
                c = read();
            }
            return sb.toString();
        }

        public final char nextChar() throws Exception {
            int c = read();
            while (isWhiteSpace(c)) {
                c = read();
            }
            return (char) c;
        }

        public final int nextInt() throws Exception {
            int result = 0;
            boolean negative = false;
            int c = read();
            while (isWhiteSpace(c)) {
                c = read();
            }
            if (c == '-') {
                negative = true;
                c = read();
            }
            while (!isWhiteSpace(c)) {
                result = result * 10 - '0' + c;
                c = read();
            }
            return negative ? -result : result;
        }

        public final long nextLong() throws Exception {
            long result = 0;
            boolean negative = false;
            int c = read();
            while (isWhiteSpace(c)) {
                c = read();
            }
            if (c == '-') {
                negative = true;
                c = read();
            }
            while (!isWhiteSpace(c)) {
                result = result * 10 - '0' + c;
                c = read();
            }
            return negative ? -result : result;
        }
    }

    private static final class OutputWriter {

        private static final String NEW_LINE = String.format("%n");

        private final Writer output;
        private final StringBuilder buffer = new StringBuilder(32 << 20);

        public OutputWriter(final Writer output) {

            this.output = output;
        }

        public void write(final int i) {

            buffer.append(i);
        }

        public void write(final String s) {

            buffer.append(s);
        }

        public void writeln(final String s) {

            buffer.append(s);
            buffer.append(NEW_LINE);
        }

        public void writeln(final long l) {

            buffer.append(l);
            buffer.append(NEW_LINE);
        }

        public void writeln(final int i) {

            buffer.append(i);
            buffer.append(NEW_LINE);
        }

        public void close() throws Exception {

            output.write(buffer.toString());
            output.flush();
            output.close();
        }
    }
}
