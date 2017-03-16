import java.util.*;
import java.io.*;

public class A {
    FastScanner in;
    PrintWriter out;

    int n;
    int[] p;

    public void solve() throws IOException {
        int tests = in.nextInt();
        for (int test = 1; test <= tests; test++) {
            n = in.nextInt();
            p = new int[n];
            for (int i = 0; i < n; i++) {
                p[i] = in.nextInt();
            }
            out.print("Case #" + test + ": ");
            if (n == 2) {
                if (p[0] != p[1]) {
                    throw new IllegalStateException();
                }
                while (p[0] > 0) {
                    out.print("AB ");
                    p[0]--;
                    p[1]--;
                }
                out.println();
            } else {
                while (true) {
                    int max = -1;
                    for (int i = 0; i < n; i++) {
                        if (p[i] > 1) {
                            if (max == -1 || p[max] < p[i]) {
                                max = i;
                            }
                        }
                    }
                    if (max == -1) {
                        break;
                    } else {
                        out.print((char) ('A' + max) + " ");
                        p[max]--;
                    }
                }
                if (n % 2 == 0) {
                    for (int i = 0; i < n; i += 2) {
                        out.print((char) ('A' + i) + "" + (char) ('A' + (i + 1)) + " ");
                    }
                } else {
                    out.print('A' + " ");
                    for (int i = 1; i < n; i += 2) {
                        out.print((char) ('A' + i) + "" + (char) ('A' + (i + 1)) + " ");
                    }
                }
                out.println();
            }
        }
    }

    public void run() {
        try {
            in = new FastScanner(System.in);
            out = new PrintWriter(System.out);

            solve();

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(InputStream is) {
            br = new BufferedReader(new InputStreamReader(is));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }
    }

    public static void main(String[] arg) {
        new A().run();
    }
}