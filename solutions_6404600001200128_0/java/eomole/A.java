package gcj2015.r1a;

import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class A implements Runnable {
    private static final char PROB = A.class.getSimpleName().charAt(0);
    private static boolean ENABLE_PARALLEL = true;
    private static File DIR = new File("gcj/src/main/java/gcj2015/r1a");
    private static boolean TEST_ALL = false;

    private static class Solver {
        private static final double EPS = 1e-12;
        private static final int INF = 1 << 20;
        private static final int[] di = {-1, 0, 0, 1};
        private static final int[] dj = {0, -1, 1, 0};
        private final int num;
        private final int N, m[];

        // parse
        public Solver(final int num, final Scanner sc) {
            this.num = num;
            this.N = sc.nextInt();
            this.m = new int[N];
            for (int i = 0; i < N; i++)
                m[i] = sc.nextInt();

        }

        // solve
        @Override
        public String toString() {
            int first = 0;
            for (int i = 1; i < N; i++)
                first += Math.max(m[i - 1] - m[i], 0);
            int second = 0;
            int max = 0;
            for (int i = 1; i < N; i++)
                max = Math.max(max, Math.max(m[i - 1] - m[i], 0));
            for (int i = 1; i < N; i++)
                second += Math.min(m[i - 1], max);
            return format(first + " " + second);
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
                System.setOut(new PrintStream(DIR + "/" + input + ".out"));
                new A().run();
            }
        } else {
            final String input = seekInputFile();
            debug("INPUT", input);
            if (input != null) {
                System.setIn(new BufferedInputStream(new FileInputStream(new File(DIR, input))));
                System.setOut(new PrintStream(DIR + "/" + input + ".out"));
            } else {
                ENABLE_PARALLEL = false;
                System.setOut(new PrintStream("/dev/null"));
            }
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

        for (int k = 2; k >= 0; k--)
            for (int i = 0; new File(DIR, PROB + "-small" + (k > 0 ? "-" + k : "") + "-attempt" + i + ".in").exists(); i++)
                ret.add(PROB + "-small" + (k > 0 ? "-" + k : "") + "-attempt" + i + ".in");
        return ret;
    }

    private static void debug(Object... os) {
        System.err.println(java.util.Arrays.deepToString(os));
    }
}
