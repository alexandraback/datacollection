import java.io.*;
import java.util.*;

public class A {

    void solve() throws IOException {
        in = new InputReader("A-large.in");
        out = new OutputWriter("A-large.out");

        int testCount = in.readInt();
        for (int test = 1; test <= testCount; ++test) {
            int n = in.readInt();
            int[] l = new int[n];
            char[][] w = new char[n][];
            int[][] c = new int[n][];
            for (int i = 0; i < n; ++i) {
                char[] s = in.readToken().toCharArray();
                w[i] = new char[s.length];
                c[i] = new int[s.length];
                w[i][0] = s[0];
                c[i][0] = 1;
                l[i] = 1;
                for (int j = 1; j < s.length; ++j) {
                    if (s[j] == w[i][l[i] - 1]) {
                        ++c[i][l[i] - 1];
                    } else {
                        w[i][l[i]] = s[j];
                        c[i][l[i]] = 1;
                        ++l[i];
                    }
                }
            }
            boolean flag = true;
            for (int i = 1; i < n && flag; ++i) {
                flag = l[i] == l[0];
                for (int j = 0; j < l[i] && flag; ++j) {
                    flag = w[i][j] == w[0][j];
                }
            }
            if (flag) {
                int sum = 0;
                for (int j = 0; j < l[0]; ++j) {
                    int best = Integer.MAX_VALUE;
                    for (int i = 0; i < n; ++i) {
                        int res = 0;
                        for (int k = 0; k < n; ++k) {
                            res += Math.abs(c[i][j] - c[k][j]);
                        }
                        if (res < best) best = res;
                    }
                    sum += best;
                }
                out.println("Case #" + test + ": " + sum);
            } else {
                out.println("Case #" + test + ": Fegla Won");
            }
        }

        exit();
    }

    void exit() {
        //System.err.println((System.currentTimeMillis() - startTime) + " ms");
        out.close();
        System.exit(0);
    }

    InputReader in;
    OutputWriter out;

    //long startTime = System.currentTimeMillis();

    public static void main(String[] args) throws IOException {
        new A().solve();
    }

    class InputReader {

        private InputStream stream;

        private byte[] buffer = new byte[1024];
        private int pos, len;

        private int cur;

        private StringBuilder sb = new StringBuilder(32);

        InputReader(String name) throws IOException {
            if (name.equals("__std")) {
                stream = System.in;
            } else {
                stream = new FileInputStream(name);
            }
            cur = read();
        }

        private int read() throws IOException {
            if (len == -1) {
                throw new EOFException();
            }
            if (pos >= len) {
                pos = 0;
                len = stream.read(buffer);
                if (len == -1) return -1;
            }
            return buffer[pos++];
        }

        char readChar() throws IOException {
            if (cur == -1) {
                throw new EOFException();
            }
            char res = (char) cur;
            cur = read();
            return res;
        }

        int readInt() throws IOException {
            if (cur == -1) {
                throw new EOFException();
            }
            while (whitespace()) {
                cur = read();
            }
            if (cur == -1) {
                throw new EOFException();
            }
            int sign = 1;
            if (cur == '-') {
                sign = -1;
                cur = read();
            }
            int res = 0;
            while (!whitespace()) {
                if (cur < '0' || cur > '9') {
                    throw new NumberFormatException();
                }
                res *= 10;
                res += cur - '0';
                cur = read();
            }
            return res * sign;
        }

        long readLong() throws IOException {
            if (cur == -1) {
                throw new EOFException();
            }
            return Long.parseLong(readToken());
        }

        double readDouble() throws IOException {
            if (cur == -1) {
                throw new EOFException();
            }
            return Double.parseDouble(readToken());
        }

        String readLine() throws IOException {
            if (cur == -1) {
                throw new EOFException();
            }
            sb.setLength(0);
            while (cur != -1 && cur != '\r' && cur != '\n') {
                sb.append((char) cur);
                cur = read();
            }
            if (cur == '\r') {
                cur = read();
            }
            if (cur == '\n') {
                cur = read();
            }
            return sb.toString();
        }

        String readToken() throws IOException {
            if (cur == -1) {
                throw new EOFException();
            }
            while (whitespace()) {
                cur = read();
            }
            if (cur == -1) {
                throw new EOFException();
            }
            sb.setLength(0);
            while (!whitespace()) {
                sb.append((char) cur);
                cur = read();
            }
            return sb.toString();
        }

        boolean whitespace() {
            return cur == ' ' || cur == '\t' || cur == '\r' || cur == '\n' || cur == -1;
        }

        boolean eof() {
            return cur == -1;
        }
    }

    class OutputWriter {

        private PrintWriter writer;

        OutputWriter(String name) throws IOException {
            if (name.equals("__std")) {
                writer = new PrintWriter(System.out);
            } else {
                writer = new PrintWriter(name);
            }
        }

        void print(String format, Object ... args) {
            writer.print(new Formatter(Locale.US).format(format, args));
        }

        void println(String format, Object ... args) {
            writer.println(new Formatter(Locale.US).format(format, args));
        }

        void print(Object value) {
            writer.print(value);
        }

        void println(Object value) {
            writer.println(value);
        }

        void println() {
            writer.println();
        }

        void close() {
            writer.close();
        }
    }
}
