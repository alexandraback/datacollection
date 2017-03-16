import java.io.*;
import java.util.StringTokenizer;

public class ProblemA {

    public static void main(String[] args) throws Exception {
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
        for (int ii = 0; ii < T; ++ii) {
            int[] was = new int[16];
            for (int l = 0; l < 2; ++l) {
                int k = nextInt() - 1;
                for (int i = 0; i < 4; ++i) {
                    for (int j = 0; j < 4; ++j) {
                        int a = nextInt();
                        if (i == k) {
                            was[a - 1]++;
                        }
                    }
                }
            }
            int cnt = 0;
            int ans = 0;
            for (int i = 0; i < 16; ++i) {
                if (was[i] == 2) {
                    cnt++;
                    ans = i + 1;
                }
            }
            if (cnt == 1) {
                out.printf("Case #%d: %d\n", ii + 1, ans);
            } else if (cnt == 0) {
                out.printf("Case #%d: Volunteer cheated!\n", ii + 1);
            } else {
                out.printf("Case #%d: Bad magician!\n", ii + 1);
            }

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
            