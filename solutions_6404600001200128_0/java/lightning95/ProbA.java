import java.io.*;
import java.util.StringTokenizer;

/**
 * @author Aydar Gizatullin a.k.a. lightning95, aydar.gizatullin@gmail.com
 *         Created on 4/18/15.
 */

public class ProbA {
    RW rw;

    class RW {
        private boolean eof;
        StringTokenizer st;
        PrintWriter out;
        BufferedReader br;

        RW(String inputFile, String outputFile) {
            br = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(new OutputStreamWriter(System.out));

            File f = new File(inputFile);
            if (f.exists() && f.canRead()) {
                try {
                    br = new BufferedReader(new FileReader(inputFile));
                    out = new PrintWriter(new FileWriter(outputFile));
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    eof = true;
                    return "-1";
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        void println() {
            out.println();
        }

        void println(Object o) {
            out.println(o);
        }

        void print(Object o) {
            out.print(o);
        }

        void close() {
            try {
                br.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
            out.close();
        }
    }

    public static void main(String[] args) {
        new ProbA().run();
    }

    private void run() {
        rw = new RW("input.txt", "output.txt");
        solve();
        rw.close();
    }

    private void solve() {
        int t_num = rw.nextInt();

        for (int t_id = 0; t_id < t_num; ++t_id) {
            int n = rw.nextInt();
            int[] a = new int[n];

            for (int i = 0; i < n; ++i){
                a[i]= rw.nextInt();

            }
            int ans1 = 0;
            int ans2 = 0;
            int max = 0;
            for (int i = 1; i < n; ++i){
                ans1 += a[i] < a[i - 1] ? a[i - 1] - a[i] : 0;
                max = Math.max(max, a[i] < a[i - 1] ? a[i - 1] - a[i] : 0);
            }
            if (max > 0){
                for (int i = 0; i < n - 1; ++i){
                    ans2 += Math.min(max, a[i]);
                }
            }
            rw.println("Case #" + (t_id + 1) + ": " + ans1 + " " + ans2);
        }
    }
}

