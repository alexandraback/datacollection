import java.util.*;
import java.io.*;

public class B {
    FastScanner in;
    PrintWriter out;

    public int count;

    public static final int[] di = {1, -1, 0, 0};
    public static final int[] dj = {0, 0, 1, -1};

    public void gen(int[][] a, int i, int j, int n) {
        if (i == a.length) {
            int c = 0;
            for (int k = 0; k < a.length; k++) {
                for (int l = 0; l < a[0].length; l++) {
                    if (a[k][l] == 1) {
                        c++;
                    }
                }
            }
            if (c == n) {
                int current = 0;
                for (int k = 0; k < a.length; k++) {
                    for (int l = 0; l < a[0].length; l++) {
                        if (a[k][l] == 1) {
                            for (int m = 0; m < 4; m++) {
                                int ni = k + di[m];
                                int nj = l + dj[m];
                                if (0 <= ni && ni < a.length && 0 <= nj && nj < a[0].length && a[ni][nj] == 1) {
                                    current++;
                                }
                            }
                        }
                    }
                }
                current /= 2;
                count = Math.min(current, count);
            }
        } else {
            int ni = i;
            int nj = j + 1;
            if (nj == a[0].length) {
                ni++;
                nj = 0;
            }
            a[i][j] = 1;
            gen(a, ni, nj, n);
            a[i][j] = 0;
            gen(a, ni, nj, n);
        }
    }

    public void solveTest() throws IOException {
        int r = in.nextInt();
        int c = in.nextInt();
        int n = in.nextInt();
        count = 1000000000;
        gen(new int[r][c], 0, 0, n);
        out.println(count);
    }

    public void solve() throws IOException {
        int tests = in.nextInt();
        for (int test = 0; test < tests; test++) {
            out.print("Case #" + (test + 1) + ": ");
            System.out.println("test " + (test + 1));
            solveTest();
        }
    }

    public void run() {
        try {
            in = new FastScanner(new File("B-small-attempt0.in"));
            out = new PrintWriter(new File("B-small-attempt0.out"));
            Locale.setDefault(Locale.US);

            solve();

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
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
        new B().run();
    }
}