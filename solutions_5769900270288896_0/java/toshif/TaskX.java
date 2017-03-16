package gcj_1b.b;

import java.io.*;
import java.net.URL;
import java.util.Scanner;

/**
 * @author fuku
 */
public class TaskX {
    public static void main(String[] args) throws IOException {
        String inFile = "B-small-attempt0.in";

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

        public String solve(int testNumber, Scanner in, PrintWriter out) {
            int R = in.nextInt();
            int C = in.nextInt();
            int N = in.nextInt();

            int M = R * C;
            int mi = 100000000;
            for (int i = 0; i < (1<<M); i++) {
                int cnt = 0;
                for (int j = 0; j < M; j++) {
                    if (((1<<j) & i) > 0) cnt++;
                }
                if (cnt != N) continue;

                int loud = 0;
                for (int j = 0; j < M; j++) {
                    if (((1<<j) & i ) == 0) continue;

                    if ((j+1) % C != 0) {
                        // check the right neigber
                        if (((1<<(j+1)) & i ) > 0) loud++;
                    }

                    // check the below neigber
                    if (((1<<(j+C)) & i ) > 0) loud++;
                }

                mi = Math.min(mi, loud);
            }

            return "" + mi;
        }
    }
}


