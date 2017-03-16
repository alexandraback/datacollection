import org.omg.CORBA.CODESET_INCOMPATIBLE;

import java.io.*;
import java.util.*;
import java.util.List;

public class Main {
    private static StringTokenizer st;
    private static BufferedReader br;
    public static long MOD = 1000000007;
    private static double EPS = 0.000001;

    public static void print(Object x) {
        System.out.println(x + "");
    }
    public static void printArr(long[] x) {
        StringBuilder s = new StringBuilder();
        for (int i = 0; i < x.length; i++) {
            s.append(x[i] + " ");
        }
        print(s);
    }
    public static void printArr(int[] x) {
        StringBuilder s = new StringBuilder();
        for (int i = 0; i < x.length; i++) {
            s.append(x[i] + " ");
        }
        print(s);
    }
    public static String join(Collection<?> x, String space) {
        if (x.size() == 0) return "";
        StringBuilder sb = new StringBuilder();
        boolean first = true;
        for (Object elt : x) {
            if (first) first = false;
            else sb.append(space);
            sb.append(elt);
        }
        return sb.toString();
    }

    public static String nextToken() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            String line = br.readLine();
            st = new StringTokenizer(line.trim());
        }
        return st.nextToken();
    }
    public static int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }
    public static long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }
    public static List<Integer> nextInts(int N) throws IOException {
        List<Integer> ret = new ArrayList<Integer>();
        for (int i = 0; i < N; i++) {
            ret.add(nextInt());
        }
        return ret;
    }

    public static class Tree {
        long x;
        long y;

        public Tree(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public String toString() {
            return x + "," + y;
        }
    }

    //Minimum number of trees on one side of the line defined by t1, t2
    public static int minSide(Tree t1, Tree t2) {
        int left = 0;
        int right = 0;
        for (Tree t : trees) {
            if (orient2d(t1, t2, t) > 0) left += 1;
            else if (orient2d(t1, t2, t) < 0) right += 1;
        }
        return Math.min(left, right);
    }
    public static long orient2d(Tree a, Tree b, Tree c) {
        return (a.x - c.x) * (b.y - c.y) - (a.y - c.y) * (b.x - c.x);
    }

    public static double angleFor(long dx, long dy) {
        if (dx < 0) {
            dx = -dx;
            dy = -dy;
        }
        return ((double) dy) / dx;
    }

    public static long[] minCut() {
        int n = trees.length;
        long[] cuts = new long[n];
        for (int i = 0; i < n; i++) cuts[i] = n;

        for (int i = 0; i < n; i++) {
            //print("Testing " + i);
            Tree t = trees[i];

            Map<Double, Integer> left = new HashMap<Double, Integer>();
            Map<Double, Integer> right = new HashMap<Double, Integer>();
            Set<Double> values = new HashSet<Double>();

            double START = -1000000000;

            int curLeft = 0;
            int curRight = 0;
            left.put(START, 0);
            right.put(START, 0);
            for (Tree t2 : trees) {
                if (t == t2) continue;
                long dx = t2.x - t.x;
                long dy = t2.y - t.y;
                if (dx < 0) curLeft += 1;
                else if (dx > 0) curRight += 1;

                double angle = (dx == 0) ? START : angleFor(dx, dy);
                if (!values.contains(angle)) {
                    left.put(angle, 0);
                    right.put(angle, 0);
                    if (angle != START) values.add(angle);
                }

                if (dx < 0 || (dx == 0 && dy > 0)) {
                    //print("  Left " + angle);
                    left.put(angle, left.get(angle) + 1);
                }
                else {
                    //print("  Right " + angle);
                    right.put(angle, right.get(angle) + 1);
                }
            }

            double last = START;
            int best = Math.min(curLeft, curRight);
            List<Double> sortedValues = new ArrayList<Double>(values);
            Collections.sort(sortedValues);
            for (double val : sortedValues) {
                //print("  LR " + curLeft + "," + curRight + " at " + val);
                curRight += left.get(last);
                curRight -= right.get(val);
                curLeft += right.get(last);
                curLeft -= left.get(val);
                best = Math.min(best, Math.min(curLeft, curRight));
                last = val;
            }
            cuts[i] = best;
        }

        return cuts;
    }

    public static Tree[] trees;

    public static void main(String[] args) throws IOException {
        //br = new BufferedReader(new InputStreamReader(System.in));
        br = new BufferedReader(new FileReader("input.txt"));

        int T = nextInt();
        for (int t = 1; t <= T; t++) {
            int n = nextInt();
            trees = new Tree[n];
            for (int i = 0; i < n; i++) trees[i] = new Tree(nextInt(), nextInt());

            System.out.printf("Case #%d:%n", t);
            if (n == 1) print(0);
            else {
                long[] cuts = minCut();
                for (long x : cuts) print(x);
            }
        }
    }
}
