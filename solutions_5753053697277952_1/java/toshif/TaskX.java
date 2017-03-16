package gcj1c.task1;

import java.io.*;
import java.net.URL;
import java.util.*;

/**
 * @author fuku
 */
public class TaskX {
    public static void main(String[] args) throws IOException {
        String inFile = "A-large.in";

        URL inFileUrl = TaskX.class.getResource(inFile);
        InputStream inputStream = new BufferedInputStream(new FileInputStream(inFileUrl.getFile()));
        Scanner in = new Scanner(inputStream);

        String outFile = inFile + ".out";
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(outFile)));

        System.err.printf("Class = [%s]\n", TaskX.class);
        System.err.printf("Input File = [%s]\n", inFileUrl);
        System.err.printf("Output File = [%s]\n", outFile);

        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            System.err.println("------------------");
            System.err.println("test " + (i+1));
            Solver solver = new Solver();
            String ans = solver.solve(i, in, out);
            out.println("Case #" + (i+1) + ": " + ans);
            System.err.println("Case #" + (i+1) + ": " + ans);
        }
        out.close();
    }

    static class Solver {

        class P implements Comparable<P>{
            int n;
            char c;

            @Override
            public int compareTo(P o) {
                return Integer.compare(this.n, o.n);
            }
        }

        public String solve(int testNumber, Scanner in, PrintWriter out) {
            StringBuilder sb = new StringBuilder();

            int N = in.nextInt();
            // int[] p = new int[N];
            LinkedList<P> ps = new LinkedList<>();
            for (int i = 0; i < N; i++) {
                int num = in.nextInt();
                P p = new P();
                p.c = (char)('A' + i);
                p.n = num;
                ps.add(p);
            }

            while(ps.size() > 0) {
                Collections.sort(ps);

                P p1 = ps.getLast();
                P p2 = ps.get(ps.size()-2);

                String s = "";
                if (p1.n == p2.n && ps.size() != 3) {
                    s += "" + p1.c + p2.c + " ";
                    p1.n--;
                    p2.n--;
                } else {
                    s += "" + p1.c + " ";
                    p1.n--;
                }

                // System.err.printf("%s\n", s);
                sb.append(s);

                if (p1.n == 0) ps.remove(p1);
                if (p2.n == 0) ps.remove(p2);
            }

            return sb.toString();
        }
    }
}


