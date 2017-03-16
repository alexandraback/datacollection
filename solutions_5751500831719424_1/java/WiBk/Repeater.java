import java.io.*;
import java.util.StringTokenizer;

/**
 * Created by Daniyar Itegulov on 03-05-2014.
 */

public class Repeater {
    FastScanner in;
    PrintWriter out;

    public void solve() throws IOException {
        int t = in.nextInt();
        for (int test = 0; test < t; test++) {
            int n = in.nextInt();
            String[] s = new String[n];
            for (int i = 0; i < n; i++) {
                s[i] = in.next();
            }
            char[] template = new char[100];
            int k = 0;

            for (int i = 0; i < s[0].length(); i++) {
                if (i == 0 || s[0].charAt(i) != s[0].charAt(i - 1)) {
                    template[k++] = s[0].charAt(i);
                }
            }

            boolean ok = true;

            for (int i = 0; i < n; i++) {
                char[] newTemplate = new char[100];
                int newK = 0;
                for (int j = 0; j < s[i].length(); j++) {
                    if (j == 0 || s[i].charAt(j) != s[i].charAt(j - 1)) {
                        newTemplate[newK++] = s[i].charAt(j);
                    }
                }

                if (k != newK) {
                    ok = false;
                }

                for (int j = 0; j < k; j++) {
                    if (template[j] != newTemplate[j]) {
                        ok = false;
                    }
                }
            }

            out.print("Case #" + (test + 1) + ": ");

            if (!ok) {
                out.println("Fegla won");
                continue;
            }

            int[][] cnt = new int[n][k];

            for (int i = 0; i < n; i++) {
                int counter = 0;
                for (int j = 0; j < s[i].length(); j++) {
                    if (j != 0 && s[i].charAt(j) != s[i].charAt(j - 1)) {
                        counter++;
                    }
                    cnt[i][counter]++;
                }
            }
            int ans = 0;
            for (int i = 0; i < k; i++) {
                int maxCnt = 0;
                for (int j = 0; j < n; j++) {
                    maxCnt = Math.max(maxCnt, cnt[j][i]);
                }
                int lans = 1000000000;
                for (int j = 0; j <= maxCnt; j++) {
                    int cans = 0;
                    for (int cc = 0; cc < n; cc++) {
                        cans += Math.abs(cnt[cc][i] - j);
                    }
                    lans = Math.min(lans, cans);
                }
                ans += lans;
            }
            out.println(ans);
        }
    }

    public void run() {
        try {
            in = new FastScanner(new File("repeater.in"));
            out = new PrintWriter(new File("repeater.out"));

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
        new Repeater().run();
    }
}