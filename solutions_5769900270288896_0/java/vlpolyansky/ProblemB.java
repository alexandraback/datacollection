import java.io.*;
import java.util.Locale;
import java.util.StringTokenizer;

public class ProblemB {

    public static void main(String[] args) throws Exception {
        Locale.setDefault(Locale.UK);
        new ProblemB();
    }

    private BufferedReader in = null;
    private PrintWriter out = null;
    private StringTokenizer tok = new StringTokenizer("");
    private String fileName = "B-small-attempt1";

    public ProblemB() throws Exception {
        init();
        solve();
        in.close();
        out.close();
    }

    private int solve1(int r, int c, int n) {
        int ans = r * c * r * c;
        int[] dx = {1, 0, -1, 0};
        int[] dy = {0, 1, 0, -1};
        for (int m = 0; m < 1 << (r * c); m++) {
            if (Integer.bitCount(m) != n) {
                continue;
            }
            int cnt = 0;
            for (int y = 0; y < r; y++) {
                for (int x = 0; x < c; x++) {
                    if (((m >> ((y * c) + x)) & 1) == 0) {
                        continue;
                    }
                    for (int i = 0; i < 4; i++) {
                        int x2 = x + dx[i];
                        int y2 = y + dy[i];
                        if (x2 < 0 || y2 < 0 || x2 >= c || y2 >= r) {
                            continue;
                        }
                        if (((m >> ((y2 * c) + x2)) & 1) == 1) {
                            cnt++;
                        }
                    }
                }
            }
            cnt /= 2;
            ans = Math.min(ans, cnt);
        }
        return ans;
    }

    private void solve() throws Exception {
        int T = nextInt();
        for (int ii = 1; ii <= T; ii++) {
            int r = nextInt();
            int c = nextInt();
            int n = nextInt();

            out.println("Case #" + ii + ": " + solve1(r, c, n));
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
            