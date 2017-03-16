package gcj2015.r1a;

import java.io.*;
import java.util.*;

public class BSmall3 implements Runnable {
    private static final char PROB = BSmall3.class.getSimpleName().charAt(0);
    private static boolean ENABLE_PARALLEL = true;
    private static File DIR = new File("gcj/src/main/java/gcj2015/r1a");
    private static boolean TEST_ALL = true;

    private static class Solver {
        private static final double EPS = 1e-12;
        private static final int INF = 1 << 20;
        private static final int[] di = {-1, 0, 0, 1};
        private static final int[] dj = {0, -1, 1, 0};
        private final int num;
        private final int N, B, M[];

        // parse
        public Solver(final int num, final Scanner sc) {
            this.num = num;
            this.B = sc.nextInt();
            this.N = sc.nextInt();
            this.M = new int[B];
            for (int i = 0; i < B; i++)
                M[i] = sc.nextInt();
        }

        // solve
        @Override
        public String toString() {
            double rate = 0.;
            for (int i = 0; i < B; i++)
                rate += 1. / M[i];
            final long time = (long) Math.floor((N - 1) / rate) - 1;

            final PriorityQueue<Integer> que = new PriorityQueue<>();
            final TreeMap<Long, ArrayList<Integer>> map = new TreeMap<>();
            int customers = 0;
            for (int i = 0; i < B; i++) {
                final long num = time / M[i];
                customers += (int) num;
                final long next = num * M[i];
                if (!map.containsKey(next))
                    map.put(next, new ArrayList<>());
                map.get(next).add(i);
            }
            debug(num, N - 1, rate, time, customers);

            long now = 0;
            for (int i = customers; i < N; i++) {
                if (que.isEmpty()) {
                    now = map.firstKey();
                    que.addAll(map.pollFirstEntry().getValue());
                }

                final int b = que.poll();
                if (i == N - 1)
                    return format(b + 1);
                final long next = now + M[b];
                if (!map.containsKey(next))
                    map.put(next, new ArrayList<>());
                map.get(next).add(b);
            }

            throw null;
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
                new BSmall3().run();
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
            new BSmall3().run();
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
        System.err.println(Arrays.deepToString(os));
    }
}
