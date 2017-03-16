package gcj1a.a;

import java.io.*;
import java.net.URL;
import java.util.Scanner;

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

        System.out.printf("Input File = [%s]\n", inFile);
        System.out.printf("Output File = [%s]\n", outFile);

        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            System.out.println("------------------");
            System.out.println("test " + (i+1));
            Solver solver = new Solver();
            String ans = solver.solve(i, in, out);
            out.println("Case #" + (i+1) + ": " + ans);
            System.out.println("Case #" + (i+1) + ": " + ans);
        }
        out.close();
    }

    static class Solver {

        public String solve(int testNumber, Scanner in, PrintWriter out) {
            int N = in.nextInt();
            int[] m = new int[N];
            for (int i = 0; i < N; i++) {
                m[i] = in.nextInt();
            }

            int first = 0;
            int ma = 0;
            for (int i = 1; i < N; i++) {
                int d = m[i-1] - m[i];
                if (d > 0) {
                    first += d;
                }
                ma = Math.max(ma, d);
            }

            int second = 0;
            for (int i = 1; i < N; i++) {
                int d = ma;
                if (m[i-1] <= ma) {
                    d = m[i-1];
                }
                second += d;
            }

            return "" + first + " " + second;
        }
    }
}


