import java.io.OutputStream;
import java.io.FilenameFilter;
import java.util.Locale;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.File;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.List;
import java.util.Scanner;
import java.util.Collections;
import java.util.ArrayList;

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
                if (toRun == null || candidate.lastModified() > toRun.lastModified()) {
                    toRun = candidate;
                }
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
        for (int i = 1; i <= testCount; i++) {
            solver.solve(i, in, out);
        }
        out.close();
    }

    static class TaskA {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            out.print("Case #" + testNumber + ": ");
            int n = in.nextInt();
            int[] A = new int[n];
            int total = 0;
            List<TaskA.PartyCount> list = new ArrayList<>(n);
            for (int i = 0; i < n; i++) {
                A[i] = in.nextInt();
                total += A[i];
                TaskA.PartyCount pc = new TaskA.PartyCount('A' + i, A[i]);
                list.add(pc);
            }
            String result = "";
            while (total > 0) {
//            System.out.println(list);
                String current = "";
                Collections.sort(list);

                if (list.size() > 2) {
                    TaskA.PartyCount bigger = list.get(list.size() - 1);
                    TaskA.PartyCount secondbigger = list.get(list.size() - 2);
                    if (bigger.count == secondbigger.count) {
                        current += (char) bigger.id;

                        bigger.count--;
                        total--;
                        if (bigger.count == 0) {
                            list.remove(bigger);
                        }
                        if (secondbigger.count > 1) {
                            current += (char) secondbigger.id;
                            secondbigger.count--;
                            total--;
                            if (secondbigger.count == 0) {
                                list.remove(secondbigger);
                            }
                        }
                    } else {
                        current += (char) bigger.id;
                        bigger.count--;
                        total--;
                        if (bigger.count > 0) {
                            current += (char) bigger.id;
                            bigger.count--;
                            total--;
                        }
                        if (bigger.count == 0) {
                            list.remove(bigger);
                        }
                    }
                } else {
                    TaskA.PartyCount small = list.get(0);
                    TaskA.PartyCount big = list.get(1);
                    if (big.count == small.count) {
                        current += (char) big.id;
                        current += (char) small.id;
                        big.count--;
                        small.count--;
                        total -= 2;
                        if (big.count == 0) {
                            list.remove(big.count);
                        }
                        if (small.count == 0) {
                            list.remove(small.count);
                        }
                    } else {
                        current += (char) big.id;
                        big.count--;
                        total--;
                    }
                }
                if (result.equals("")) {
                    result = current;
                } else {
                    result += " " + current;
                }
            }
            out.println(result);
        }

        static class PartyCount implements Comparable<TaskA.PartyCount> {
            int id;
            int count;

            PartyCount(int id1, int count1) {
                id = id1;
                count = count1;
            }


            public int compareTo(TaskA.PartyCount o) {
                return this.count - o.count;
            }


            public String toString() {
                return "PartyCount{" +
                        "count=" + count +
                        ", id=" + id +
                        '}';
            }

        }

    }
}

