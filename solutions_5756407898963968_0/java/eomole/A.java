package gcj2014.qual;

import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class A implements Runnable {
    private static final char PROB = A.class.getSimpleName().charAt(0);
    private static boolean ENABLE_PARALLEL = true;
    private static File DIR = new File("contest/gcj2014/qual");
    private static boolean TEST_ALL = false;

    private static class Solver {
        private static final String BAD = "Bad magician!";
        private static final String CHEAT = "Volunteer cheated!";

        private final int[][] rows = new int[2][];
        private final int num;

        // parse
        public Solver(final int num, final Scanner sc) {
            this.num = num;
            for (int i = 0; i < 2; i++) {
                final int r = sc.nextInt() - 1;
                for (int j = 0; j < 4; j++) {
                    final int[] row = new int[4];
                    for (int k = 0; k < 4; k++)
                        row[k] = sc.nextInt();
                    if (j == r)
                        rows[i] = row;
                }
            }
        }

        // solve
        @Override
        public String toString() {
            final int[] num = new int[16];
            for (int i = 0; i < 2; i++)
                for (int j = 0; j < 4; j++)
                    num[rows[i][j] - 1]++;
            int ans = -1;
            for (int i = 0; i < 16; i++)
                if (num[i] == 2) {
                    if (ans >= 0)
                        return format(BAD);
                    ans = i + 1;
                }
            if (ans == -1)
                return format(CHEAT);
            return format(ans);
        }

        private String format(final Object result) {
            return String.format("Case #%s: %s", num, result);
        }
    }

    // Template
    @Override
    public void run() {
        try (final Scanner sc = new Scanner(System.in)) {
            final int T = sc.nextInt();
            final List<Solver> list = new ArrayList<>();
            for (int i = 1; i <= T; i++)
                list.add(new Solver(i, sc));
            (ENABLE_PARALLEL ? list.parallelStream() : list.stream())
                    .map((Solver s) -> s.toString())
                    .forEachOrdered((String s) -> {
                        debug(s);
                        System.out.println(s);
                    });
            debug("done.");
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }

    public static void main(String... args) throws IOException {
        if (TEST_ALL) {
            for (final String input : seekInputFiles()) {
                debug("INPUT", input);
                System.setIn(new BufferedInputStream(new FileInputStream(new File(DIR, input))));
                System.setOut(new PrintStream(input + ".out"));
                new A().run();
            }
        } else {
            final String input = seekInputFile();
            debug("INPUT", input);
            if (input != null) {
                System.setIn(new BufferedInputStream(new FileInputStream(new File(DIR, input))));
                System.setOut(new PrintStream(input + ".out"));
            } else
                ENABLE_PARALLEL = false;
            new A().run();
        }
    }

    private static String seekInputFile() {
        final String[] names = new String[]{PROB + "-large-practice-2.in", PROB + "-large-practice-1.in",
                PROB + "-large-practice.in", PROB + "-large-2.in", PROB + "-large-1.in", PROB + "-large.in",
                PROB + "-small-practice-2.in", PROB + "-small-practice-1.in", PROB + "-small-practice.in"};
        for (final String s : names)
            if (new File(DIR, s).exists())
                return s;
        for (int k = 2; k >= 0; k--) {
            int max = -1;
            for (int i = 0; new File(DIR, PROB + "-small" + (k > 0 ? "-" + k : "") + "-attempt" + i + ".in").exists(); i++)
                max = i;
            if (max >= 0)
                return PROB + "-small" + (k > 0 ? "-" + k : "") + "-attempt" + max + ".in";
        }
        return null;
    }

    private static List<String> seekInputFiles() {
        final List<String> ret = new ArrayList<>();
        final String[] names = new String[]{PROB + "-large-practice-2.in", PROB + "-large-practice-1.in",
                PROB + "-large-practice.in", PROB + "-large-2.in", PROB + "-large-1.in", PROB + "-large.in",
                PROB + "-small-practice-2.in", PROB + "-small-practice-1.in", PROB + "-small-practice.in"};
        for (final String s : names)
            if (new File(DIR, s).exists())
                ret.add(s);
        for (int k = 2; k >= 0; k--) {
            int max = -1;
            for (int i = 0; new File(DIR, PROB + "-small" + (k > 0 ? "-" + k : "") + "-attempt" + i + ".in").exists(); i++)
                max = i;
            if (max >= 0)
                ret.add(PROB + "-small" + (k > 0 ? "-" + k : "") + "-attempt" + max + ".in");
        }
        return ret;
    }

    private static void debug(Object... os) {
        System.err.println(Arrays.deepToString(os));
    }
}
