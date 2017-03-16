import java.io.*;
import java.util.*;

public class ProbA {
    boolean eof;
    BufferedReader br;
    StringTokenizer st;
    PrintWriter out;

    public static void main(String[] args) throws IOException {
        new ProbA().run();
    }

    public String nextToken() {
        while (st == null || !st.hasMoreTokens()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (Exception e) {
                eof = true;
                return "-1";
            }
        }
        return st.nextToken();
    }

    void run() throws IOException {
        InputStream input = System.in;
        PrintStream output = System.out;
        String name = "name";
        try {
            File f = new File(name + ".in");
            if (f.exists() && f.canRead()) {
                input = new FileInputStream(f);
                output = new PrintStream(name + ".out");
            }
        } catch (Throwable e) {
            e.printStackTrace();
        }
        br = new BufferedReader(new InputStreamReader(input));
        out = new PrintWriter(output);
        solve();
        br.close();
        out.close();
    }

    public int nextInt() {
        return Integer.parseInt(nextToken());
    }

    void solve() {
        main:
        for (int test_id = 1, test_num = nextInt(); test_id <= test_num; ++test_id, out.println()) {
            out.print("Case #" + test_id + ": ");
            int n = nextInt();
            String[] a = new String[n];
            for (int i = 0; i < n; ++i) {
                a[i] = nextToken();
            }
            StringBuilder sb = new StringBuilder();
            String t = a[0] + '.';
            for (int i = 0; i < t.length() - 1; ++i) {
                if (t.charAt(i) != t.charAt(i + 1)) {
                    sb.append(t.charAt(i));
                }
            }
            t = sb.toString();
            long ans = 0;
            int[] uk = new int[n];
            int[] b = new int[n];
            for (int i = 0; i < t.length(); ++i) {
                for (int j = 0; j < n; ++j) {
                    if (uk[j] >= a[j].length() || uk[j] < a[j].length() && t.charAt(i) != a[j].charAt(uk[j])) {
                        out.print("Fegla Won");
                        continue main;
                    }
                    int last = uk[j];
                    while (a[j].length() > uk[j] && t.charAt(i) == a[j].charAt(uk[j])) {
                        ++uk[j];
                    }
                    b[j] = uk[j] - last;
                }
                Arrays.sort(b);
                int cur = Integer.MAX_VALUE;
                for (int j = 1; j <= b[n - 1]; ++j) {
                    int kol = 0;
                    for (int k = 0; k < n; ++k) {
                        kol += Math.abs(j - b[k]);
                    }
                    cur = Math.min(cur, kol);
                }
                ans += cur;
            }
            for (int i = 0; i < n; ++i) {
                if (uk[i] < a[i].length()) {
                    out.print("Fegla Won");
                    continue main;
                }

            }
            out.print(ans);
        }
    }
}