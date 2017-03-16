package gcj2015.r1a;

import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class CSmall implements Runnable {
    private static final char PROB = CSmall.class.getSimpleName().charAt(0);
    private static boolean ENABLE_PARALLEL = true;
    private static File DIR = new File("gcj/src/main/java/gcj2015/r1a");
    private static boolean TEST_ALL = false;

    private static class Solver {
        private static final double EPS = 1e-6;
        private static final int INF = 1 << 20;
        private static final int[] di = {-1, 0, 0, 1};
        private static final int[] dj = {0, -1, 1, 0};
        private final int num;
        private final int N, X[], Y[];

        // parse
        public Solver(final int num, final Scanner sc) {
            this.num = num;
            this.N = sc.nextInt();
            this.X = new int[N];
            this.Y = new int[N];
            for (int i = 0; i < N; i++) {
                X[i] = sc.nextInt();
                Y[i] = sc.nextInt();
            }
        }

        // solve
        @Override
        public String toString() {
            final P[] ps = new P[N];
            for (int i = 0; i < N; i++)
                ps[i] = new P(X[i], Y[i]);
            final StringBuilder sb = new StringBuilder();
            for (int c = 0; c < N; c++) {
                int ans = N - 3;

                final Polygon pp = Polygon.convexHull(ps);
                if (pp.contains(ps[c]) == 0)
                    ans = 0;
                else
                    loop:for (int i = 0; i < 1 << N; i++)
                        if ((i & 1 << c) > 0 && Integer.bitCount(i) > 3) {
                            final int n = Integer.bitCount(i);
                            final P[] ps1 = new P[n];
                            for (int j = 0, k = 0; j < n; k++)
                                if ((i & 1 << k) > 0)
                                    ps1[j++] = ps[k];
                            final Polygon p = Polygon.convexHull(ps1);
                            for (int j = 0; j < n; j++)
                                if (p.contains(ps1[j]) != 0)
                                    continue loop;
                            ans = Math.min(ans, N - n);
                        }
                sb.append('\n').append(ans);
            }

            return format(sb);
        }

        private String format(final Object result) {
            return String.format("Case #%s:%s", num, result);
        }


        static int sgn(double d) {
            return d < -EPS ? -1 : d > EPS ? 1 : 0;
        }

        static boolean eq(double a, double b) {
            return sgn(a - b) == 0;
        }

        public static class P implements Comparable<P> {
            final double x, y;

            P(double x, double y) {
                this.x = x;
                this.y = y;
            }

            P add(P p) {
                return new P(x + p.x, y + p.y);
            }

            P sub(P p) {
                return new P(x - p.x, y - p.y);
            }

            P mul(double d) {
                return new P(x * d, y * d);
            }

            P div(double d) {
                return new P(x / d, y / d);
            }

            double dot(P p) {
                return x * p.x + y * p.y;
            }

            double det(P p) {
                return x * p.y - y * p.x;
            }

            double norm() {
                return sqrt(x * x + y * y);
            }

            double norm2() {
                return x * x + y * y;
            }

            double dist(P p) {
                return sub(p).norm();
            }

            // optional
            P rot90() {
                return new P(-y, x);
            }

            P rot(double t) {// verified
                return new P(x * cos(t) - y * sin(t), x * sin(t) + y * cos(t));
            }

            double arg() {// verified.
                return atan2(y, x);// [-PI,PI].
            }

            double arg(P p) {
                double d = dot(p) / (norm() * p.norm());
                return acos(abs(d) > 1 ? signum(d) : d);
            }

            P unit(double d) {
                return div(d / norm());
            }

            int contained(P r1, P r2) {
                if (equals(r1) || equals(r2))
                    return 0;
                if (eq(r1.dist(r2), dist(r1) + dist(r2)))
                    return 1;
                return -1;
            }

            int ccw(P b, P c) {
                b = sub(b);
                c = sub(c);
                if (b.det(c) > EPS)
                    return 1;
                if (b.det(c) < EPS)
                    return -1;
                if (b.dot(c) < EPS)
                    return 2;
                if (b.norm() + EPS < c.norm())
                    return -2;
                return 0;
            }

            //
            public int compareTo(P o) {
                return sgn(x - o.x) != 0 ? sgn(x - o.x) : sgn(y - o.y);
            }

            public boolean equals(Object o) {
                return compareTo((P) o) == 0;
            }

            public int hashCode() {
                throw new UnsupportedOperationException();
            }

            public String toString() {
                return x + " " + y;
            }
        }

        public static class Polygon {
            final P[] ps;

            public Polygon(P[] ps) {
                this.ps = ps;
            }

            static Polygon convexHull(P[] ps) { // O(n logn).
                ps = ps.clone();
                int n = ps.length;
                Arrays.sort(ps);
                P[] ds = new P[n];// ds[0] = us[un-1] = ps[0].
                P[] us = new P[n];// ds[dn-1] = us[0] = ps[n-1].
                int dn = 0;
                int un = 0;
                for (int i = 0; i < n; ds[dn++] = ps[i++])
                    while (dn >= 2 && sgn(ds[dn - 1].sub(ds[dn - 2]).det(ps[i].sub(ds[dn - 2]))) <= 0)
                        dn--;
                for (int i = n - 1; i >= 0; us[un++] = ps[i--])
                    while (un >= 2 && sgn(us[un - 1].sub(us[un - 2]).det(ps[i].sub(us[un - 2]))) <= 0)
                        un--;
                P[] res = new P[dn + un - 2];
                System.arraycopy(ds, 0, res, 0, dn - 1);
                System.arraycopy(us, 0, res, dn - 1, un - 1);
                return new Polygon(res);
            }

            // verified: pku3525.
            int contains(P p) {// 点、多角形包含判定 OUT,ON,IN = -1, 0, 1.
                int n = ps.length;
                int res = -1;
                for (int i = 0; i < n; i++) {
                    P a = ps[i].sub(p), b = ps[(i + 1) % n].sub(p);
                    if (a.y > b.y) {
                        P t = a;
                        a = b;
                        b = t;
                    }
                    if (a.y <= 0 && 0 < b.y && a.det(b) < 0)
                        res *= -1;
                    if (a.det(b) == 0 && a.dot(b) <= 0)
                        return 0;
                }
                return res;
            }


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
                new CSmall().run();
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
            new CSmall().run();
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
