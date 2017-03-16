import java.io.*;
import java.util.Arrays;
import java.util.Locale;
import java.util.StringTokenizer;

public class ProblemA {

    public static void main(String[] args) throws Exception {
        Locale.setDefault(Locale.UK);
        new ProblemA();
    }

    private BufferedReader in = null;
    private PrintWriter out = null;
    private StringTokenizer tok = new StringTokenizer("");
    private String fileName = "A-small-attempt0";

    public ProblemA() throws Exception {
        init();
        solve();
        in.close();
        out.close();
    }

    private void solve() throws Exception {
        int T = nextInt();
        nextcase:
        for (int ii = 0; ii < T; ++ii) {
            out.printf("Case #%d: ", ii + 1);
            int N = nextInt();
            char[][] a = new char[N][];
            for (int i = 0; i < N; ++i) {
                a[i] = in.readLine().toCharArray();
            }
            int M = 110;
            char[] b = new char[M];
            {
                int c = 0;
                for (int j = 0; j < a[0].length; ++j) {
                    if (j != 0 && a[0][j - 1] != a[0][j]) {
                        c++;
                    }
                    b[c] = a[0][j];
                }
                M = c + 1;
            }
            for (int i = 1; i < N; ++i) {
                int c = 0;
                for (int j = 0; j < a[i].length; ++j) {
                    if (j != 0 && a[i][j - 1] != a[i][j]) {
                        c++;
                    }
                    if (c >= M || a[i][j] != b[c]) {
                        out.println("Fegla Won");
                        continue nextcase;
                    }
                }
                if (c != M - 1) {
                    out.println("Fegla Won");
                    continue nextcase;
                }
            }
            int[][] cnt = new int[M][N];
            for (int i = 0; i < N; ++i) {
                int c = 0;
                for (int j = 0; j < a[i].length; ++j) {
                    if (j != 0 && a[i][j - 1] != a[i][j]) {
                        c++;
                    }
                    cnt[c][i]++;
                }
            }
            int ans = 0;
            for (int i = 0; i < M; ++i) {
                Arrays.sort(cnt[i]);
                for (int j = 0; j < N; ++j) {
                    ans += Math.abs(cnt[i][j] - cnt[i][N / 2]);
                }
            }
            out.println(ans);
        }
    }


    private void init() throws FileNotFoundException {
        if (fileName.equals("#Console")) {
            in = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out);
        } else if (fileName.equals("#IOtxt")) {
            in = new BufferedReader(new FileReader("input.txt"));
            out = new PrintWriter("output.txt");
        } else {
            in = new BufferedReader(new FileReader(fileName + ".in"));
            out = new PrintWriter(fileName + ".out");
        }
    }


    private int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    private long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }


    private String nextToken() throws IOException {
        while (!tok.hasMoreTokens()) {
            String s = in.readLine();
            if (s == null) {
                return null;
            }
            tok = new StringTokenizer(s);
        }
        return tok.nextToken();
    }

}
            