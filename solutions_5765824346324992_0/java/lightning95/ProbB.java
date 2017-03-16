import javafx.util.Pair;

import java.io.*;
import java.util.Comparator;
import java.util.StringTokenizer;
import java.util.TreeSet;

/**
 * @author Aydar Gizatullin a.k.a. lightning95, aydar.gizatullin@gmail.com
 *         Created on 4/18/15.
 */

public class ProbB {
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
        new ProbB().run();
    }

    private void run() {
        rw = new RW("input.txt", "output.txt");
        solve();
        rw.close();
    }

    int nod(int x, int y) {
        while (x > 0 && y > 0) {
            if (x > y) {
                x %= y;
            } else {
                y %= x;
            }
        }
        return x + y;
    }

    private void solve() {
        int t_num = rw.nextInt();

        Comparator comp = new Comparator<Pair<Integer, Integer>>() {
            @Override
            public int compare(Pair<Integer, Integer> o1, Pair<Integer, Integer> o2) {
                if (o1.getKey().equals(o2.getKey())) {
                    return Integer.compare(o1.getValue(), o2.getValue());
                }
                return Integer.compare(o1.getKey(), o2.getKey());
            }
        };

        TreeSet<Pair<Integer, Integer>> tree;

        for (int t_id = 0; t_id < t_num; ++t_id) {
            System.err.println("========TEST " + t_id + " RUNNING");
            int n = rw.nextInt();
            int m = rw.nextInt();
            int[] a = new int[n];
            int nok = 1;
            for (int i = 0; i < n; ++i) {
                a[i] = rw.nextInt();
                nok = (int) (((long) nok * a[i]) / nod(nok, a[i]));
            }
            tree = new TreeSet<>(comp);
            for (int i = 0; i < n; ++i) {
                tree.add(new Pair<>(0, i));
            }
            System.err.println("NOK " + nok);
            int[] mas = new int[1_000_000];
            int pos = 0;
            for (;;) {
                Pair<Integer, Integer> p = tree.pollFirst();
                mas[pos++] = p.getValue();
                tree.add(new Pair<>(p.getKey() + a[p.getValue()], p.getValue()));
                if (p.getKey() == nok) {
                    --pos;
                    break;
                }
            }
            System.err.println("POS " + pos);
            int ans = mas[m % pos + (m % pos == 0 ? pos - 1 : -1)] + 1;

            rw.println("Case #" + (t_id + 1) + ": " + ans);
        }
    }
}

