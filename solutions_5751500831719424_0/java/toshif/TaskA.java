package gcj.round1B;

import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

/**
 * @author fuku
 */
public class TaskA {
    public static void main(String[] args) throws FileNotFoundException {
        InputStream inputStream = TaskA.class.getResourceAsStream("A-small-attempt0.in");
        Scanner in = new Scanner(inputStream);

        PrintWriter out = new PrintWriter(new FileOutputStream("./out.txt"));

        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            System.out.println("------------------");
            System.out.println("test " + (i+1));
            SolA solver = new SolA();
            String ans = solver.solve(i, in, out);
            out.println("Case #" + (i+1) + ": " + ans);
            System.out.println("Case #" + (i+1) + ": " + ans);
        }
        out.close();
    }
}

class SolA {

    public String solve(int testNumber, Scanner in, PrintWriter out) {
        int N = in.nextInt(); in.nextLine();
        String[] ss = new String[N];
        for (int i = 0; i < N; i++) {
            ss[i] = in.nextLine();
        }
        System.out.println("ss = " + Arrays.toString(ss));

        int[][] co = new int[N][110];

        String iden = null;
        for (int i = 0; i < N; i++) {
            int idx = -1;
            String t = "";
            String s = ss[i];
            char prev = '@';
            for (int j = 0; j < s.length(); j++) {
                char c = s.charAt(j);
                if (c != prev) { t += c; idx++; }
                co[i][idx]++;
                prev = c;
            }
            if (iden == null) iden = t;
            if (!iden.equals(t)) return "Fegla Won";

            // System.out.println("Arrays.toString(co[i]) = " + Arrays.toString(co[i]));
        }

        int ret = 0;
        for (int i = 0; i < 110; i++) {
            if (co[0][i] == 0) break;

            // find best
            int mi = 100000;
            for (int b = 0; b < 110; b++) {
                int tot = 0;
                for (int j = 0; j < N; j++) {
                    tot += Math.abs(co[j][i] - b);
                }
                mi = Math.min(mi, tot);
            }

            ret += mi;
        }

        String ans = "" + ret;
        return ans;
    }
}
