package CodeJam._2016.R1C;
import java.io.*;
import java.util.*;

/**
 *
 * Created by locheng on 5/8/16.
 *
 */

public class ProblemASenateEvacuation {
    private static Scanner in;
    private static PrintStream out;
    private int n;
    private int p[] = new int[30];
    private char q[] = new char[30];
    
    public static void main(String[] args) throws IOException {
        initIO();
        int T = in.nextInt();
        for (int t = 1; t <= T; ++t) {
            ProblemASenateEvacuation solver = new ProblemASenateEvacuation();
            solver.getInput(in);
            out.println("Case #" + t + ": " + solver.solve());
        }
        out.close();
    }
    
    private static void initIO() throws IOException {
        File inputFile = new File("Resources/CodeJam/_2016/R1C/AInput.002");
        in = new Scanner(new FileInputStream(inputFile));
        File outputFile = new File("Resources/CodeJam/_2016/R1C/AOutput.002");
        out = new PrintStream(outputFile);
    }
    
    private void getInput(Scanner in) {
        n = in.nextInt();
        String S = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        for (int i = 0; i < n; ++i) {
            p[i] = in.nextInt();
            q[i] = S.charAt(i);
        }
    }
    
    private String solve() {
        StringBuffer result = new StringBuffer();
        int total = 0;
        for (int i = 0; i < n; ++i) {
            total += p[i];
        }
        while (total > 0) {
            for (int i = 0; i < n - 1; ++i) {
                for (int j = i + 1; j < n; ++j) {
                    if (p[i] < p[j]) {
                        int tmp = p[i];
                        p[i] = p[j];
                        p[j] = tmp;
                        char tmpc = q[i];
                        q[i] = q[j];
                        q[j] = tmpc;
                    }
                }
            }
            result.append(q[0]);
            p[0]--; total--;
            if (total != 2) {
                if (p[0] + p[1] != total && p[0] >= p[1]) {
                    result.append(q[0]);
                    p[0]--;
                    total--;
                } else {
                    result.append(q[1]);
                    p[1]--;
                    total--;
                }
            }
            if (total != 0) {
                result.append(" ");
            }
        }
        return result.toString();
    }
}
       