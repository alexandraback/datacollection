package round1a;

import com.google.common.collect.*;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.*;

public class C {
    private static final String PROBLEM = "round1a/C-small-attempt1";
    private final Scanner in;
    public C(Scanner in) {
        this.in = in;
    }

    private String runCase() {
        int numTrees = in.nextInt();
        List<Point> trees = Lists.newArrayList();
        for (int i = 0; i < numTrees; i++) {
            trees.add(new Point(in.nextLong(), in.nextLong()));
        }

        List<Integer> results = solve(trees);
        StringBuilder sb = new StringBuilder();
        for (int result : results) {
            sb.append(String.format("%n%d", result));
        }
        return sb.toString();
    }

    private List<Integer> solve(List<Point> trees) {
        if (trees.size() == 1) {
            return ImmutableList.of(0);
        }

        Map<Point, Integer> minPointsTakenAway = Maps.newHashMap();
        for (int i = 0; i < (1 << trees.size()); i++) {
            int numTakenAway = Integer.bitCount(i);

            List<Point> reducedTrees = Lists.newArrayList();
            for (int j = 0; j < trees.size(); j++) {
                if ((i & (1 << j)) == 0) {
                    reducedTrees.add(trees.get(j));
                }
            }
            if (reducedTrees.isEmpty()) {
                continue;
            }

            List<Point> hull = convexHull(reducedTrees);
            for (Point p : hull) {
                if (!minPointsTakenAway.containsKey(p) || numTakenAway < minPointsTakenAway.get(p)) {
                    minPointsTakenAway.put(p, numTakenAway);
                }
            }
        }
        List<Integer> result = Lists.newArrayList();
        for (Point tree : trees) {
            result.add(minPointsTakenAway.get(tree));
        }
        if (result.contains(null)) {
            System.out.println("crap");
        }
        return result;
    }

    private List<Point> convexHull(List<Point> points) {
        List<Point> sortedPoints = Ordering.natural().sortedCopy(points);
        List<Point> result = Lists.newArrayList();

        for (int i = 0; i < sortedPoints.size(); i++) {
            result.add(sortedPoints.get(i));
            while (result.size() >= 3 && isLeftTurn(
                    result.get(result.size() - 3),
                    result.get(result.size() - 2),
                    result.get(result.size() - 1))) {
                result.remove(result.size() - 2);
            }
        }
        result.remove(result.size() - 1);

        for (int i = sortedPoints.size() - 1; i >= 0; i--) {
            result.add(sortedPoints.get(i));
            while (result.size() >= 3 && isLeftTurn(
                    result.get(result.size() - 3),
                    result.get(result.size() - 2),
                    result.get(result.size() - 1))) {
                result.remove(result.size() - 2);
            }
        }
        result.remove(result.size() - 1);
        return result;
    }

    private boolean isLeftTurn(Point p1, Point p2, Point p3) {
        return ((p2.x * p3.y - p2.y * p3.x)  -
                (p1.x * p3.y - p1.y * p3.x) +
                (p1.x * p2.y - p1.y * p2.x)) > 0;
    }

    public static class Point implements Comparable<Point> {
        public final long x;
        public final long y;
        public Point(long x, long y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public int compareTo(Point o) {
            return ComparisonChain.start()
                    .compare(x, o.x)
                    .compare(y, o.y)
                    .result();
        }

        @Override
        public String toString() {
            return "Point{" +
                    "x=" + x +
                    ", y=" + y +
                    '}';
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            Point point = (Point) o;

            if (x != point.x) return false;
            return y == point.y;

        }

        @Override
        public int hashCode() {
            int result = (int) (x ^ (x >>> 32));
            result = 31 * result + (int) (y ^ (y >>> 32));
            return result;
        }
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
        new C(in).runCases();
    }
}
