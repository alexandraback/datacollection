import java.io.OutputStream;
import java.io.FilenameFilter;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.File;
import java.io.InputStream;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.io.OutputStream;
import java.io.IOException;
import java.util.InputMismatchException;
import java.io.InputStreamReader;
import java.io.Writer;
import java.io.BufferedReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Chamath Kumarasinghe
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream;
        try {
            final String regex = ".*in";
            File directory = new File(".");
            File[] candidates = directory.listFiles(new FilenameFilter() {
                public boolean accept(File dir, String name) {
                    return name.matches(regex);
                }
            });
            File toRun = null;
            for (File candidate : candidates) {
                if (toRun == null || candidate.lastModified() > toRun.lastModified())
                    toRun = candidate;
            }
            inputStream = new FileInputStream(toRun);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        OutputStream outputStream;
        try {
            outputStream = new FileOutputStream("output.out");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        FastScanner in = new FastScanner(inputStream);
        FastPrinter out = new FastPrinter(outputStream);
        TR1B solver = new TR1B();
        solver.solve(1, in, out);
        out.close();
    }

    static class TR1B {
        public void solve(int testNumber, FastScanner in, FastPrinter out) {
            int t = in.nextInt();
            int cc = 0;
            while (t-- > 0) {
                cc++;
                System.out.print("Case #" + cc + ": ");
                out.print("Case #" + cc + ": ");
                int n = in.nextInt();
                int[] a = in.readIntArray(n);
                int sum = 0;
                for (int i : a) {
                    sum += i;
                }
                int m1 = -1, m1p = 0;
                int m2 = -1, m2p = 0;
                if (sum % 2 == 1) {
                    for (int i = 0; i < n; i++) {
                        if (m1 <= a[i]) {
                            m1 = a[i];
                            m1p = i;
                        }


                    }

                    System.out.print((char) (m1p + 'A') + " ");
                    out.print((char) (m1p + 'A') + " ");
                    a[m1p]--;
                    sum--;
                }
                while (sum > 0) {
                    m1 = -1;
                    m2 = -1;
                    for (int i = 0; i < n; i++) {
                        if (a[i] > m1) {
                            m2 = m1;
                            m2p = m1p;
                            m1 = a[i];
                            m1p = i;

                        } else if (a[i] > m2) {
                            m2 = a[i];
                            m2p = i;
                        }
                    }
                    System.out.print((char) ('A' + m1p) + "" + (char) ('A' + m2p) + " ");
                    out.print((char) ('A' + m1p) + "" + (char) ('A' + m2p) + " ");
                    a[m1p]--;
                    a[m2p]--;
                    sum -= 2;
                }

                System.out.println();
                out.println();

            }
        }

    }

    static class FastScanner extends BufferedReader {
        public FastScanner(InputStream is) {
            super(new InputStreamReader(is));
        }


        public int read() {
            try {
                int ret = super.read();
//            if (isEOF && ret < 0) {
//                throw new InputMismatchException();
//            }
//            isEOF = ret == -1;
                return ret;
            } catch (IOException e) {
                throw new InputMismatchException();
            }
        }

        static boolean isWhiteSpace(int c) {
            return c >= 0 && c <= 32;
        }

        public int nextInt() {
            int c = read();
            while (isWhiteSpace(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int ret = 0;
            while (c >= 0 && !isWhiteSpace(c)) {
                if (c < '0' || c > '9') {
                    throw new NumberFormatException("digit expected " + (char) c
                            + " found");
                }
                ret = ret * 10 + c - '0';
                c = read();
            }
            return ret * sgn;
        }

        public String readLine() {
            try {
                return super.readLine();
            } catch (IOException e) {
                return null;
            }
        }

        public int[] readIntArray(int n) {
            int[] ret = new int[n];
            for (int i = 0; i < n; i++) {
                ret[i] = nextInt();
            }
            return ret;
        }

    }

    static class FastPrinter extends PrintWriter {
        public FastPrinter(OutputStream out) {
            super(out);
        }

        public FastPrinter(Writer out) {
            super(out);
        }

        public void close() {
            super.close();
        }

    }
}

