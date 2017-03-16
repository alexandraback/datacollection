import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * @author Aydar Gizatullin a.k.a. lightning95, aydar.gizatullin@gmail.com
 *         Created on 4/16/16.
 */

public class ProbA {
    private RW rw;

    public static void main(String[] args) {
        new ProbA().run();
    }

    private void run() {
        rw = new RW("input.txt", "output.txt");
        solve();
        rw.close();
    }

    private class RW {
        private StringTokenizer st;
        private PrintWriter out;
        private BufferedReader br;
        private boolean eof;

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

        private String nextLine() {
            String s = "";
            try {
                s = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return s;
        }

        private String next() {
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

        private int nextInt() {
            return Integer.parseInt(next());
        }

        private void println() {
            out.println();
        }

        private void println(Object o) {
            out.println(o);
        }

        private void print(Object o) {
            out.print(o);
        }

        private void close() {
            try {
                br.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
            out.close();
        }
    }

    class Pair {
        int x, id;

        Pair(int x, int id) {
            this.x = x;
            this.id = id;
        }
    }

    private void solve() {
        int testNum = rw.nextInt();
        for (int testId = 1; testId <= testNum; ++testId) {
            rw.print("Case #" + testId + ": ");
            System.err.println(testId);
            int n = rw.nextInt();
            Pair[] a = new Pair[n];
            int all = 0;
            for (int i = 0; i < n; ++i) {
                a[i] = new Pair(rw.nextInt(), i);
                all += a[i].x;
            }
            while (all > 0) {
                Arrays.sort(a, (o1, o2) -> Integer.compare(o1.x, o2.x));

                int x = a[n - 1].x - a[n - 2].x;
                if (x >= 2) {
                    rw.print("" + (char) (a[n - 1].id + 'A') + (char) (a[n - 1].id + 'A') + " ");
                    all -= 2;
                    a[n - 1].x -= 2;
                } else if (x == 0 && all - 2 != 1) {
                    rw.print("" + (char) (a[n - 1].id + 'A') + (char) (a[n - 2].id + 'A') + " ");
                    all -= 2;
                    a[n - 1].x -= 1;
                    a[n - 2].x--;
                } else {
                    rw.print((char) (a[n - 1].id + 'A') + " ");
                    all -= 1;
                    a[n - 1].x -= 1;
                }
            }
            rw.println();
        }
    }
}
