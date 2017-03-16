package gcj2016.r1c;

import java.util.*;

public class A {
    final int N, P[];

    // parse
    public A(final Scanner sc) {
        N = sc.nextInt();
        P = new int[N];
        for (int i = 0; i < N; i++)
            P[i] = sc.nextInt();
    }

    static class Pair implements Comparable<Pair> {
        final int id, value;

        public Pair(int id, int value) {
            this.id = id;
            this.value = value;
        }

        @Override
        public int compareTo(Pair o) {
            return value == o.value ? id - o.id : o.value - value;
        }

        @Override
        public String toString() {
            return "" + value;
        }
    }

    // solve
    @Override
    public String toString() {
        final TreeSet<Pair> set = new TreeSet<>();
        for (int i = 0; i < N; i++)
            set.add(new Pair(i, P[i]));
        final StringBuilder sb = new StringBuilder();
        while (!set.isEmpty()) {
            final Pair p1 = set.pollFirst();
            final int c1 = 'A' + p1.id;
            if (p1.value == 1 && set.size() == 2) {
                sb.append(' ').appendCodePoint(c1).append(' ')
                        .appendCodePoint(set.pollFirst().id + 'A')
                        .appendCodePoint(set.pollFirst().id + 'A');
                break;
            }
            if (p1.value > 1)
                set.add(new Pair(p1.id, p1.value - 1));
            final Pair p2 = set.pollFirst();
            final int c2 = 'A' + p2.id;
            if (p2.value > 1)
                set.add(new Pair(p2.id, p2.value - 1));
            if (sb.length() > 0)
                sb.append(' ');
            sb.appendCodePoint(c1).appendCodePoint(c2);
//            debug(set);
        }

        return sb.toString();
    }

    // Template
    public static void main(String... args) throws Exception {
        try (final Scanner sc = new Scanner(System.in)) {
            final int T = sc.nextInt();
            final Object[] solvers = new Object[T];
            for (int i = 0; i < T; i++)
                solvers[i] = new A(sc);
            final Iterator<String> results = Arrays.stream(solvers)
                    .map(Object::toString)
                    .iterator();
            for (int i = 1; i <= T; i++)
                System.out.printf("Case #%s: %s\n", i, results.next());
        }
    }

    private static void debug(Object... os) {
        System.err.println(Arrays.deepToString(os));
    }
}
