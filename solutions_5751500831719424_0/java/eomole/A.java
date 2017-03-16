import java.util.*;
import java.util.stream.Stream;

public class A {
    private final int N;
    private final char[][] cs;

    // parse
    public A(final Scanner sc) {
        N = sc.nextInt();
        cs = new char[N][];
        for (int i = 0; i < N; i++)
            cs[i] = sc.next().toCharArray();
    }

    // solve
    @Override
    public String toString() {
        final List<Character> list = new ArrayList<>();
        for (int i = 0; i < cs[0].length; ) {
            final char c = cs[0][i];
            list.add(c);
            while (i < cs[0].length && cs[0][i] == c)
                i++;
        }
        final int M = list.size();
        final int[][] cnt = new int[N][M];
        for (int k = 0; k < N; k++)
            for (int i = 0, j = 0; i < cs[k].length; j++) {
                final char c = cs[k][i];
                if (j >= M || c != list.get(j))
                    return "Fegla Won";
                while (i < cs[k].length && cs[k][i] == c) {
                    i++;
                    cnt[k][j]++;
                }
            }
        int ans = 0;
        for (int i = 0; i < M; i++) {
            int min = Integer.MAX_VALUE;
            for (int m = 1; m <= 100; m++) {
                int cost = 0;
                for (int j = 0; j < N; j++) {
                    if (cnt[j][i] == 0)
                        return "Fegla Won";
                    cost += Math.abs(cnt[j][i] - m);
                }
                min = Math.min(min, cost);
            }
            ans += min;
        }

        return "" + ans;
    }

    // Template

    public static void main(String... args) throws Exception {
        try (final Scanner sc = new Scanner(System.in)) {
            final int T = sc.nextInt();
            final Object[] solvers = new Object[T];
            for (int i = 0; i < T; i++)
                solvers[i] = new A(sc);
            final Iterator<String> results = Arrays.stream(solvers)
                    .parallel()
                    .map(s -> s.toString())
                    .map(Stream::of)
                    .reduce((stream1, stream2) -> Stream.concat(stream1, stream2))
                    .orElse(Stream.empty())
                    .iterator();
            debug();
            for (int i = 1; i <= T; i++) {
                final String format = String.format("Case #%s: %s", i, results.next());
                debug(format);
                System.out.println(format);
            }
            debug("done.");
        }
    }

    private static void debug(Object... os) {
        System.err.println(Arrays.deepToString(os));
    }
}
