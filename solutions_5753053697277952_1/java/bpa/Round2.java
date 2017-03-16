import java.io.*;
import java.util.ArrayList;
import java.util.Locale;
import java.util.StringTokenizer;

public class Round2 implements Runnable {
    private static FastIO io;
    private static final String FILE_NAME = "A-large";

    void solveMultiTest() throws IOException {
        int testCases = io.readInt();
        for (int testCase = 1; testCase <= testCases; testCase++) {
            io.println(String.format(Locale.US, "Case #%d: %s", testCase, solveOneTest()));
        }
    }

    String solveOneTest() throws IOException {
        int n = io.readInt();
        int[] a = new int[n];
        int m = 0;
        for (int i = 0; i < n; i++) {
            a[i] = io.readInt();
            m += a[i];
        }
        StringBuilder sb = new StringBuilder();
        while (m > 0) {
            int m1 = a[0];
            int m2 = a[n - 1];
            int m1i = 0;
            int m2i = n - 1;
            for (int i = 0; i < n; i++) {
                if (m1 < a[i]) {
                    m1 = a[i];
                    m1i = i;
                }
            }
            if (m1 == 1 && m == 3) {
                sb.append((char) ('A' + m1i)).append(' ');
                m--;
                a[m1i]--;
                continue;
            }
            for (int i = n - 1; i >= 0; i--) {
                if (m2 < a[i]) {
                    m2 = a[i];
                    m2i = i;
                }
            }
            if (m1i == m2i) {
                sb.append((char) ('A' + m1i)).append(' ');
                m--;
                a[m1i]--;
            } else {
                sb.append((char) ('A' + m1i)).append((char) ('A' + m2i)).append(' ');
                m -= 2;
                a[m1i]--;
                a[m2i]--;
            }
        }
        return sb.toString();
    }

    public void run() {
        try (FastIO fastIO = new FastIO(FILE_NAME)) {
            io = fastIO;
            solveMultiTest();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        new Thread(new Round2()).start();
    }
}

class FastIO implements AutoCloseable {
    BufferedReader in;
    PrintWriter out;
    StringTokenizer st;

    public FastIO() {
        in = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
    }

    public FastIO(String file) throws FileNotFoundException {
        if (file == null) {
            in = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out);
        } else {
            in = new BufferedReader(new FileReader(file + ".in"));
            out = new PrintWriter(file + ".out");
        }
    }

    public String readLine() throws IOException {
        st = null;
        return in.readLine();
    }

    public String readToken() throws IOException {
        return nextToken();
    }

    public int readInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    private String nextToken() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(in.readLine());
        }
        return st.nextToken();
    }

    public void print(Object o) {
        out.print(o.toString());
    }

    public void println(Object o) {
        out.println(o.toString());
    }

    @Override
    public void close() throws IOException {
        in.close();
        out.close();
    }
}