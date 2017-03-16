import java.io.OutputStream;
import java.io.FilenameFilter;
import java.util.Locale;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.File;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.PriorityQueue;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.AbstractCollection;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.FileReader;
import java.util.Comparator;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Kartik Singal (ka4tik)
 */
public class Main {
    public static void main(String[] args) {
        Locale.setDefault(Locale.US);
        InputStream inputStream;
        try {
            final String regex = "A-(small|large).*[.]in";
            File directory = new File(".");
            File[] candidates = directory.listFiles(new FilenameFilter() {
                public boolean accept(File dir, String name) {
                    return name.matches(regex);
                }
            });
            File toRun = null;
            for (File candidate : candidates) {
                if (toRun == null || candidate.lastModified() > toRun.lastModified())
                    toRun = candidate;
            }
            inputStream = new FileInputStream(toRun);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        OutputStream outputStream;
        try {
            outputStream = new FileOutputStream("a.out");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        FastScanner in = new FastScanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskA solver = new TaskA();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class TaskA {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int n = in.nextInt();
            int a[] = new int[n];
            PriorityQueue<TaskA.Pair> q = new PriorityQueue<TaskA.Pair>(new Comparator<TaskA.Pair>() {

                public int compare(TaskA.Pair o1, TaskA.Pair o2) {
                    return o2.q - o1.q;
                }
            });
            for (int i = 0; i < n; i++) {
                a[i] = in.nextInt();
                q.add(new TaskA.Pair(i, a[i]));
            }
            out.print("Case #" + testNumber + ": ");


            while (!q.isEmpty()) {
                assert q.size() != 1;
                TaskA.Pair t = q.peek();
                if (t.q == 1) {
                    if (q.size() % 2 == 1) {
                        out.print((char) (q.poll().x + 'A') + " ");
                        continue;
                    }
                }
                if (q.size() >= 2) {
                    TaskA.Pair f = q.poll();
                    TaskA.Pair s = q.poll();
                    if (f.q == s.q) {
                        out.print((char) (f.x + 'A'));
                        out.print((char) (s.x + 'A') + " ");
                        if (f.q - 1 > 0)
                            q.add(new TaskA.Pair(f.x, f.q - 1));
                        if (s.q - 1 > 0)
                            q.add(new TaskA.Pair(s.x, s.q - 1));
                        continue;
                    } else {
                        q.add(f);
                        q.add(s);
                    }
                }
                t = q.poll();
                out.print((char) (t.x + 'A') + " ");
                if (t.q - 1 > 0)
                    q.add(new TaskA.Pair(t.x, t.q - 1));

            }
            out.println();

        }

        static class Pair {
            public int x;
            public int q;

            public Pair(int x, int q) {
                this.x = x;
                this.q = q;
            }

        }

    }

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public FastScanner(InputStream f) {
            br = new BufferedReader(new InputStreamReader(f));
        }

        public String next() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return null;
                st = new StringTokenizer(s);
            }
            return st.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}

