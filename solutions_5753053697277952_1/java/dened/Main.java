import java.io.OutputStream;
import java.io.FilenameFilter;
import java.util.Locale;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.File;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.StringReader;
import java.io.IOException;
import java.io.Reader;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Denis Nedelyaev
 */
public class Main {
    public static void main(String[] args) throws Exception {
        Locale.setDefault(Locale.US);
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
        InputStream inputStream = new FileInputStream(toRun);
        OutputStream outputStream = new FileOutputStream("a.out");
        FastScanner in = new FastScanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskA solver = new TaskA(in, out);
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i);
        out.close();
    }

    static class TaskA {
        private final FastScanner in;
        private final PrintWriter out;

        public TaskA(FastScanner in, PrintWriter out) {
            this.in = in;
            this.out = out;
        }

        public void solve(int testNumber) throws IOException {
            int n = in.nextInt();
            int[] count = in.nextInts(n);
            out.println("Case #" + testNumber + ": " + realSolve(count));
        }

        private String realSolve(int[] count) {
            StringBuilder sb = new StringBuilder();
            while (true) {
                int max1 = -1;
                int max2 = -1;
                int total = 0;
                for (int i = 0; i < count.length; i++) {
                    if (max1 == -1 || count[max1] <= count[i]) {
                        max2 = max1;
                        max1 = i;
                    } else if (max2 == -1 || count[max2] < count[i]) {
                        max2 = i;
                    }
                    total += count[i];
                }
                if (count[max1] == 0) {
                    break;
                }
                if (total == 3) {
                    sb.append((char) ('A' + max1));
                    count[max1]--;
                } else if (count[max1] > count[max2]) {
                    sb.append((char) ('A' + max1));
                    count[max1]--;
                    if (count[max1] > 0) {
                        sb.append((char) ('A' + max1));
                        count[max1]--;
                    }
                } else {
                    sb.append((char) ('A' + max1));
                    count[max1]--;
                    if (count[max2] > 0) {
                        sb.append((char) ('A' + max2));
                        count[max2]--;
                    }
                }
                sb.append(' ');
            }
            return sb.toString();
        }

    }

    static class FastScanner {
        private final BufferedReader br;
        private String line;
        private int pos;

        public FastScanner(String s) throws IOException {
            this(new StringReader(s));
        }

        public FastScanner(InputStream is) throws IOException {
            this(new InputStreamReader(is, "UTF-8"));
        }

        public FastScanner(Reader reader) throws IOException {
            this(new BufferedReader(reader));
        }

        public FastScanner(BufferedReader reader) throws IOException {
            br = reader;
            line = br.readLine();
            pos = 0;
        }

        public String next() throws IOException {
            if (!skipWhitespace()) {
                return null;
            }

            int start = pos;

            while (pos < line.length()) {
                char c = line.charAt(pos);

                if (c == ' ' || c == '\t') {
                    break;
                }

                pos++;
            }

            return line.substring(start, pos);
        }

        public int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        public int[] nextInts(int n) throws IOException {
            int[] res = new int[n];
            for (int i = 0; i < n; i++) {
                res[i] = nextInt();
            }
            return res;
        }

        private boolean skipWhitespace() throws IOException {
            while (line != null) {
                while (pos < line.length()) {
                    char c = line.charAt(pos);

                    if (c != ' ' && c != '\t') {
                        return true;
                    }

                    pos++;
                }

                line = br.readLine();
                pos = 0;
            }

            return false;
        }

    }
}

