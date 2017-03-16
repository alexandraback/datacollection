import java.io.OutputStream;
import java.io.FilenameFilter;
import java.util.Locale;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.File;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Scanner;

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
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskA solver = new TaskA();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class TaskA {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int n = in.nextInt();
            int[] p = new int[n];
            int sum = 0;

            for (int i = 0; i < n; i++) {
                p[i] = in.nextInt();
                sum += p[i];
            }

            out.print("Case #" + testNumber + ": ");
            String tmp = "";
            int max = findMax(p);
            while (max != -1) {
                int c = 65 + max;
                tmp += (char) c;
                p[max]--;
                sum--;
                int flag = 0;
                for (int i = 0; i < n; i++) {
                    if (p[i] * 2 > sum) {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0) {
                    out.print(tmp + " ");
                    tmp = "";
                }
                max = findMax(p);
            }
            out.println();
        }

        public int findMax(int[] p) {
            int max = 0;
            int index = -1;
            for (int i = 0; i < p.length; i++) {
                if (p[i] > max) {
                    max = p[i];
                    index = i;
                }
            }
            return index;
        }

    }
}

