package round1a;

import com.google.common.collect.ImmutableList;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.List;
import java.util.Scanner;

public class B {
    private static final String PROBLEM = "round1a/B-small-attempt0";
    private final Scanner in;
    public B(Scanner in) {
        this.in = in;
    }

    private String runCase() {
        int numBarbers = in.nextInt();
        long placeInLine = in.nextLong();

        List<Integer> barbers = nextIntList(numBarbers);

        long timeLow = -1;
        long timeHigh = Long.MAX_VALUE >> 18;

        while (timeHigh > timeLow + 1) {
            long timeMid = (timeLow + timeHigh) / 2;

            long cutsStarted = numCutsStarted(barbers, timeMid);

            if (cutsStarted >= placeInLine) {
                timeHigh = timeMid;
            } else {
                timeLow = timeMid;
            }
        }

        long resultTime = timeHigh;

        long cutsStartedBefore = numCutsStarted(barbers, resultTime - 1);
        long cutsStartedAfter = numCutsStarted(barbers, resultTime);

        long numBefore = placeInLine - cutsStartedBefore - 1;
        if (numBefore < 0) {
            throw new RuntimeException("Error 1!");
        }

        for (int i = 0; i < barbers.size(); i++) {
            int barber = barbers.get(i);
            if (resultTime % barber == 0) {
                if (numBefore > 0) {
                    numBefore--;
                } else {
                    return String.format("%d", i + 1);
                }
            }
        }
        throw new RuntimeException("Error 2!");
    }

    private long numCutsStarted(List<Integer> barbers, long time) {
        long result = 0;
        for (int barber : barbers) {
            result += (time / barber) + 1;
        }
        return result;
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
        new B(in).runCases();
    }
}
