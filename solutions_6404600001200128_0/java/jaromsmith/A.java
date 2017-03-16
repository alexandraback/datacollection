import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.*;
import java.util.logging.Level;
import java.util.logging.Logger;

class A {

    private static final String BASE = "C:\\cygwin\\home\\jsmith\\codejam\\2015\\Round1A\\A\\";
    //    private static final String PROBLEM = "deceitful_test";
    private static final String PROBLEM = "A-small-attempt0";

    public static void main(String[] args) {
        String input = BASE + PROBLEM + ".in";
        String output = BASE + PROBLEM + ".out";

        try {
            Scanner sc = new Scanner(new FileReader(input));
            PrintWriter pw = new PrintWriter(output);

            int mumCases = sc.nextInt();
            sc.nextLine();
            for (int caseNumber = 0; caseNumber < mumCases; caseNumber++) {
                System.out.println("Test case " + (caseNumber + 1) + "...");
                pw.print("Case #" + (caseNumber + 1) + ": ");
                solve(sc, pw);
                pw.println();
            }
            pw.println();
            pw.flush();
            pw.close();
            sc.close();
        } catch (FileNotFoundException ex) {
            Logger.getLogger(A.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

    private static void solve(Scanner sc, PrintWriter pw) {
        final int N = sc.nextInt();
        int[] mushrooms = new int[N];

        for (int i = 0; i < N; i++) {
            mushrooms[i] = sc.nextInt();
        }

        int method1 = eatAnyNumber(mushrooms);
        int method2 = eatConstantRate(mushrooms);

        pw.print(method1 + " " + method2);
    }

    private static int eatConstantRate(int[] mushrooms) {
        // find the largest difference between successive values.  This must be the min rate.
        int prev = mushrooms[0];
        int maxDiff = 0;
        for (int i = 1; i < mushrooms.length; i++) {
            if (mushrooms[i] < prev) {
                int diff = prev - mushrooms[i];
                if (diff > maxDiff) {
                    maxDiff = diff;
                }
            }
            prev = mushrooms[i];
        }

        // starting at the beginning, eat min(maxdiff, mushrooms) at each interval.
        int result = Math.min(maxDiff, mushrooms[0]);
        for (int i = 1; i < mushrooms.length-1; i++) {
            result += Math.min(maxDiff, mushrooms[i]);
        }

        return result;
    }

    private static int eatAnyNumber(int[] mushrooms) {
        int prev = mushrooms[0];
        int result = 0;
        for (int i = 1; i < mushrooms.length; i++) {
            if (mushrooms[i] < prev) {
                result += prev - mushrooms[i];
            }
            prev = mushrooms[i];
        }
        return result;
    }


}
