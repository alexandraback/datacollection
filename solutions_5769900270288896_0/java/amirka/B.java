import java.util.*;
import java.io.*;

public class B {
    FastScanner in;
    PrintWriter out;
    boolean systemIO = false;

    public void solve() throws IOException {
        int tests = in.nextInt();
        for (int test = 0; test < tests; test++) {
            int n = in.nextInt();
            int m = in.nextInt();
            int k = in.nextInt();
            int ans = 100000000;
            for (int i = 0; i < (1 << (n * m)); i++) {
                int l = 0;
                int f = 0;
                int[][] a = new int[n][m];
                for (int x = 0; x < n; x++) {
                    for (int y = 0; y < m; y++) {
                        if ((i & (1 << l)) != 0) {
                            a[x][y] = 1;
                            f++;
                        }
                        l++;
                    }
                }
                if (f == k) {
                    int cans = 0;
                    for (int x = 0; x < n; x++) {
                        for (int y = 0; y < m; y++) {
                            if (a[x][y] == 1) {
                                if (x < n - 1 && a[x + 1][y] == 1) cans++;
                                if (y < m - 1 && a[x][y + 1] == 1) cans++;
                            }
                        }
                    }
                    ans = Math.min(ans, cans);
                }
            }
            //for (int i = 0; i < n; i++) {
            //    for (int j = 0; j < m; j++) {
            //        out.print(a[i][j] + " ");
            //    }
            //    out.println();
           // }
            out.print("Case #" + (test + 1) + ": ");
            out.println(ans);
        }
    }

    public void run() {
        try {
            if (systemIO) {
                in = new FastScanner(System.in);
                out = new PrintWriter(System.out);
            } else {
                in = new FastScanner(new File("a.in"));
                out = new PrintWriter(new File("a.out"));
            }
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

        FastScanner(InputStream f) {
            br = new BufferedReader(new InputStreamReader(f));
        }

        String nextLine() {
            try {
                return br.readLine();
            } catch (IOException e) {
                return null;
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

        long nextLong() {
            return Long.parseLong(next());
        }

    }

    public static void main(String[] arg) {
        new B().run();
    }
}