package Qualification.A;

import java.io.*;
import java.util.*;
import java.math.*;

/**
 * Created by mtian on 4/12/14.
 */
public class MagicTrick {

    public void solve(ContestReader cr, PrintWriter pw) throws Exception {
        int ans1 = cr.nextInt();
        HashSet<Integer> row1 = new HashSet<Integer>();
        for (int i = 0; i < 16; i++) {
            int n = cr.nextInt();
            if (i >= (ans1 - 1) * 4 && i < ans1 * 4) {
                row1.add(n);
            }
        }

        int ans2 = cr.nextInt();
        ArrayList<Integer> common = new ArrayList<Integer>();
        for (int i = 0; i < 16; i++) {
            int n = cr.nextInt();
            if (i >= (ans2 - 1) * 4 && i < ans2 * 4) {
                if (row1.contains(n)) {
                    common.add(n);
                }
            }
        }

        if (common.size() == 0) {
            pw.println("Volunteer cheated!");
        } else if (common.size() > 1) {
            pw.println("Bad magician!");
        } else {
            pw.println(common.get(0));
        }
    }

    public static void main(String[] args) throws Exception {
        ContestReader cr = new ContestReader(new FileInputStream("A-small-attempt0.in"));
        PrintWriter pw = new PrintWriter(new FileWriter("A-small-attempt0.out"));
        MagicTrick solver = new MagicTrick();
        int T = cr.nextInt();
        for (int caseNum = 1; caseNum <= T; caseNum++) {
            System.out.println("Processing test case " + caseNum);
            pw.print("Case #" + caseNum + ": ");
            solver.solve(cr, pw);
        }
        pw.flush();
        pw.close();
    }
}

class ContestReader {
    static BufferedReader reader;
    static StringTokenizer tokenizer;

    public ContestReader(InputStream input) {
        reader = new BufferedReader(new InputStreamReader(input));
        tokenizer = new StringTokenizer("");
    }

    public String next() throws IOException {
        while (!tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }

    public int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    public double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }
}