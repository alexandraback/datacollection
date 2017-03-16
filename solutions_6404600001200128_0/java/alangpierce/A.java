package round1a;

import com.google.common.collect.ImmutableList;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.List;
import java.util.Scanner;

public class A {
    private static final String PROBLEM = "round1a/A-small-attempt0";
    private final Scanner in;
    public A(Scanner in) {
        this.in = in;
    }

    private String runCase() {
        int n = in.nextInt();
        List<Integer> vals = nextIntList(n);

        int maxDiff = 0;
        long result1 = 0;
        for (int i = 1; i < vals.size(); i++) {
            int diff = vals.get(i - 1) - vals.get(i);
            maxDiff = Math.max(maxDiff, diff);
            if (diff > 0) {
                result1 += diff;
            }
        }

        long result2 = 0;
        for (int i = 0; i < vals.size() - 1; i++) {
            result2 += Math.min(maxDiff, vals.get(i));
        }

        return String.format("%d %d", result1, result2);
    }

    private List<Integer> nextIntList(int n) {
        ImmutableList.Builder<Integer> builder = ImmutableList.builder();
        for (int i = 0; i < n; i++) {
            builder.add(in.nextInt());
        }
        return builder.build();
    }

    private void runCases() throws FileNotFoundException {
        int numCases = in.nextInt();
        PrintWriter writer = new PrintWriter(PROBLEM + ".out");
        for (int casenum = 1; casenum <= numCases; casenum++) {
            String result = runCase();
            System.out.printf("Case #%d: %s%n", casenum, result);
            writer.printf("Case #%d: %s%n", casenum, result);
            writer.flush();
        }
    }

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File(PROBLEM + ".in"));
        new A(in).runCases();
    }
}
