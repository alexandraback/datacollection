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
import java.util.ArrayList;
import java.util.AbstractCollection;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.Collections;
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
        PrintWriter out = new PrintWriter(outputStream);
        TaskA solver = new TaskA();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class TaskA {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            PriorityQueue<Pair> pq = new PriorityQueue<>();
            ArrayList<Pair> arr = new ArrayList<>();
            for (int i = 0; i < n; ++i) {
                arr.add(new Pair((char) ('A' + i), in.nextInt()));
            }

            Collections.sort(arr);

            for (int i = 2; i < n; ++i) {
                pq.add(arr.get(i));
            }

            String res = "Case #" + (testNumber) + ":";

            while (arr.get(0).size > arr.get(1).size) {
                if (arr.get(0).size - arr.get(1).size > 1) {
                    res += " " + arr.get(0).name + arr.get(0).name;
                    arr.get(0).size -= 2;
                } else {
                    res += " " + arr.get(0).name;
                    arr.get(0).size--;
                }
            }

            while (!pq.isEmpty()) {
                Pair cur = pq.poll();

                String toOut = " ";
                toOut += cur.name;

                cur.size--;
                if (cur.size > 0) {
                    pq.add(cur);
                }

                if (!pq.isEmpty()) {
                    cur = pq.poll();
                    toOut += cur.name;

                    cur.size--;
                    if (cur.size > 0) {
                        pq.add(cur);
                    }
                }
                res += toOut;
            }

            while (arr.get(0).size > 0) {
                res += " " + arr.get(0).name + arr.get(1).name;
                arr.get(0).size--;
                arr.get(1).size--;
            }
            out.println(res);
        }

    }

    static class Pair implements Comparable<Pair> {
        char name;
        int size;

        Pair(char _name, int _size) {
            name = _name;
            size = _size;
        }


        public int compareTo(Pair o) {
            return Integer.compare(o.size, size);
        }

    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}

