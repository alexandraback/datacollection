import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class A {
    FastScanner in;
    PrintWriter out;

    public void solve() throws IOException {
        int cases = in.nextInt();
        for (int testcase = 1; testcase <= cases; testcase++) {
            out.print("Case #" + testcase + ": ");
            int n = in.nextInt();

            String[] s = new String[n];
            for (int i = 0; i < n; i++) {
                s[i] = in.next();
            }

            List<Uniq> u = new ArrayList<>();
            for (String st : s) {
                u.add(uniq(st));
            }

            boolean success = true;
            for (Uniq un : u) {
                if (!un.res.equals(u.get(0).res)) {
                    success = false;
                }
            }

            if (!success) {
                out.println("Fegla won");
            } else {
                int res = 0;
                for (int idx = 0; idx < u.get(0).occ.size(); idx++) {
                    List<Integer> a = new ArrayList<>();
                    for (Uniq un : u) {
                        a.add(un.occ.get(idx));
                    }
                    res += minDiff(a);
                }
                out.println(res);
            }
        }
    }

    private int minDiff(List<Integer> a) {
        int min = Integer.MAX_VALUE / 2;
        for (int cand : a) {
            int res = 0;
            for (int o : a) {
                res += Math.abs(o - cand);
            }
            min = Math.min(res, min);
        }
        return min;
    }

    private Uniq uniq(String s) {
        List<Integer> occ = new ArrayList<>();
        StringBuilder sb = new StringBuilder();
        char prev = 0;
        int cnt = 0;
        for (char ch : s.toCharArray()) {
            if (prev != ch) {
                sb.append(ch);
                if (cnt > 0) {
                    occ.add(cnt);
                }
                cnt = 1;
                prev = ch;
            } else {
                cnt++;
            }
        }
        occ.add(cnt);
        return new Uniq(sb.toString(), occ);
    }

    class Uniq {
        String res;
        List<Integer> occ;

        Uniq(String res, List<Integer> occ) {
            this.res = res;
            this.occ = occ;
        }
    }

    public void run() {
        try {
            in = new FastScanner(new FileInputStream("a-small-attempt0.in"));
            out = new PrintWriter(new FileOutputStream("a-small.out"));

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