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
import java.util.Scanner;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author safadurimo
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
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskA solver = new TaskA();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class TaskA {
        String s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int n = in.nextInt();
            PriorityQueue<E> pq = new PriorityQueue<E>();
            for (int i = 0; i < n; i++) {
                E e = new E();
                e.p = s.charAt(i);
                e.count = in.nextInt();
                pq.add(e);
            }
            out.printf("Case #%d: ", testNumber);
            while (!pq.isEmpty()) {
                if (pq.size() == 2) {
                    E e1 = pq.poll();
                    E e2 = pq.poll();
                    if (e1.count == e2.count) {
                        out.print(e1.p + "" + e2.p + " ");
                        e1.count--;
                        if (e1.count > 0) pq.add(e1);
                        e2.count--;
                        if (e2.count > 0) pq.add(e2);
                    } else {
                        e1.count--;
                        out.print(e1.p + " ");
                        if (e1.count > 0) pq.add(e1);
                        pq.add(e2);
                    }

                } else {
                    E e = pq.poll();
                    e.count--;
                    out.print(e.p + " ");
                    if (e.count > 0) pq.add(e);
                }
            }
            out.println();

        }

        class E implements Comparable<E> {
            char p;
            int count;


            public int compareTo(E o) {
                return -(Integer.valueOf(count).compareTo(Integer.valueOf(o.count)));
            }

        }

    }
}

