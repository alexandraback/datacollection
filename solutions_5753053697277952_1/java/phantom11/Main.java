import java.io.OutputStream;
import java.io.FilenameFilter;
import java.util.Locale;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.File;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.io.BufferedReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
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
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        TaskA solver = new TaskA();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class TaskA {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int N = in.nextInt(), i, j;
            int a[] = new int[N];
            int total = 0;
            for (i = 0; i < N; i++) {
                a[i] = in.nextInt();
                total += a[i];
            }
            StringBuffer ans = new StringBuffer("");
            while (total > 0) {
                boolean stat = false;
                int count = 0, ind1 = -1, ind2 = -1;
                for (i = 0; i < N; i++) {
                    if (a[i] > 0) {
                        count++;
                        if (ind1 == -1) {
                            ind1 = i;
                        } else {
                            ind2 = i;
                        }
                    }
                }
                if (count == 2) {
                    if (a[ind1] == a[ind2]) {
                        stat = true;
                    }
                }
                if (!stat) {
                    //Find highest
                    int max = 0, index = 0;
                    for (i = 0; i < N; i++) {
                        if (a[i] > max) {
                            max = a[i];
                            index = i;
                        }
                    }

                    ans.append((char) ('A' + index));

                    a[index]--;
                    total--;
                    ans.append(" ");
                } else {
                    ans.append((char) (ind1 + 'A'));
                    ans.append((char) (ind2 + 'A'));
                    a[ind1]--;
                    a[ind2]--;
                    total -= 2;
                    ans.append(" ");
                }
            }
            String x = ans.toString().trim();
            out.printLine("Case #" + testNumber + ": " + x);
        }

    }

    static class OutputWriter {
        private final PrintWriter writer;

        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }

        public void print(Object... objects) {
            for (int i = 0; i < objects.length; i++) {
                if (i != 0)
                    writer.print(' ');
                writer.print(objects[i]);
            }
        }

        public void printLine(Object... objects) {
            print(objects);
            writer.println();
        }

        public void close() {
            writer.close();
        }

    }

    static class InputReader {
        BufferedReader in;
        StringTokenizer tokenizer = null;

        public InputReader(InputStream inputStream) {
            in = new BufferedReader(new InputStreamReader(inputStream));
        }

        public String next() {
            try {
                while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                    tokenizer = new StringTokenizer(in.readLine());
                }
                return tokenizer.nextToken();
            } catch (IOException e) {
                return null;
            }
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}

