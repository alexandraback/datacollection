import java.util.*;

/**
 * Created by poly on 4/18/15.
 */
public class Logging {
    public static void main(String argv[]) {
        Scanner scanner = new Scanner(System.in);
        int T = scanner.nextInt();
        for (int t = 0; t < T; t++) {
            int n = scanner.nextInt();
            Point2D[] points = new Point2D[n];
            for (int i = 0; i < n; i++) {
                int x = scanner.nextInt();
                int y = scanner.nextInt();
                points[i] = new Point2D(x, y);
            }
            GrahamScan graham = new GrahamScan(points);
            List<Point2D> hull = new ArrayList<Point2D>(graham.hull);
            // System.out.println(hull);

            int[] ans = new int[n];
            for (int i = 0; i < n; i++) {
                if (hull.contains(points[i])) {
                    ans[i] = 0;
                    continue;
                }
                Point2D target = points[i];
                Point2D base = hull.get(0);
                int size = hull.size();
                int totalCount1 = 0;
                int totalCount2 = 0;
                for (int j = 0; j < n; j++) {
                    if (j == i) {
                        continue;
                    }
                    if (Point2D.ccw(base, target, points[j]) < 0) {
                        totalCount1 ++;
                    }
                    if (Point2D.ccw(base, target, points[j]) > 0) {
                        totalCount2 ++;
                    }
                }
                ans[i] = Math.min(totalCount1, totalCount2);
            }
            System.out.println("Case #" + (t + 1) + ":");
            for (int i = 0; i < n; i++) {
                System.out.println(ans[i]);
            }
        }
    }
}


class GrahamScan {
    Stack<Point2D> hull = new Stack<Point2D>();

    // return extreme points on convex hull in counterclockwise order as an Iterable
    Iterable<Point2D> hull() {
        Stack<Point2D> s = new Stack<Point2D>();
        for (Point2D p : hull) s.push(p);
        return s;
    }

    GrahamScan(Point2D[] pts) {

        // defensive copy
        int N = pts.length;
        Point2D[] points = new Point2D[N];
        for (int i = 0; i < N; i++)
            points[i] = pts[i];

        // preprocess so that points[0] has lowest y-coordinate; break ties by x-coordinate
        // points[0] is an extreme point of the convex hull
        // (alternatively, could do easily in linear time)
        Arrays.sort(points);

        // sort by polar angle with respect to base point points[0],
        // breaking ties by distance to points[0]
        Arrays.sort(points, 1, N, points[0].POLAR_ORDER);

        hull.push(points[0]);       // p[0] is first extreme point

        // find index k1 of first point not equal to points[0]
        int k1;
        for (k1 = 1; k1 < N; k1++)
            if (!points[0].equals(points[k1])) break;
        if (k1 == N) return;        // all points equal

        // find index k2 of first point not collinear with points[0] and points[k1]
//        int k2;
//        for (k2 = k1 + 1; k2 < N; k2++)
//            if (Point2D.ccw(points[0], points[k1], points[k2]) != 0) break;
        int k2 = k1 + 1;
        hull.push(points[k2 - 1]);    // points[k2-1] is second extreme point

        // Graham scan; note that points[N-1] is extreme point different from points[0]
        for (int i = k2; i < N; i++) {
            Point2D top = hull.pop();
            while (Point2D.ccw(hull.peek(), top, points[i]) < 0) {
                top = hull.pop();
            }
            hull.push(top);
            hull.push(points[i]);
        }

        assert isConvex();
    }


    // check that boundary of hull is strictly convex
    private boolean isConvex() {
        int N = hull.size();
        if (N <= 2) return true;

        Point2D[] points = new Point2D[N];
        int n = 0;
        for (Point2D p : hull()) {
            points[n++] = p;
        }

        for (int i = 0; i < N; i++) {
            if (Point2D.ccw(points[i], points[(i + 1) % N], points[(i + 2) % N]) <= 0) {
                return false;
            }
        }
        return true;
    }
}

final class Point2D implements Comparable<Point2D> {

    public static final Comparator<Point2D> X_ORDER = new XOrder();

    public static final Comparator<Point2D> Y_ORDER = new YOrder();

    public static final Comparator<Point2D> R_ORDER = new ROrder();

    public final Comparator<Point2D> POLAR_ORDER = new PolarOrder();

    public final Comparator<Point2D> ATAN2_ORDER = new Atan2Order();

    public final Comparator<Point2D> DISTANCE_TO_ORDER = new DistanceToOrder();

    private final double x;    // x coordinate
    private final double y;    // y coordinate

    public Point2D(double x, double y) {
        if (x == 0.0) x = 0.0;  // convert -0.0 to +0.0
        if (y == 0.0) y = 0.0;  // convert -0.0 to +0.0
        this.x = x;
        this.y = y;
    }

    public double x() {
        return x;
    }

    public double y() {
        return y;
    }

    public double r() {
        return Math.sqrt(x * x + y * y);
    }

    public double theta() {
        return Math.atan2(y, x);
    }

    private double angleTo(Point2D that) {
        double dx = that.x - this.x;
        double dy = that.y - this.y;
        return Math.atan2(dy, dx);
    }

    public static int ccw(Point2D a, Point2D b, Point2D c) {
        double area2 = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
        if (area2 < 0) return -1;
        else if (area2 > 0) return +1;
        else return 0;
    }

    public static double area2(Point2D a, Point2D b, Point2D c) {
        return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    }

    public double distanceTo(Point2D that) {
        double dx = this.x - that.x;
        double dy = this.y - that.y;
        return Math.sqrt(dx * dx + dy * dy);
    }

    public double distanceSquaredTo(Point2D that) {
        double dx = this.x - that.x;
        double dy = this.y - that.y;
        return dx * dx + dy * dy;
    }

    public int compareTo(Point2D that) {
        if (this.y < that.y) return -1;
        if (this.y > that.y) return +1;
        if (this.x < that.x) return -1;
        if (this.x > that.x) return +1;
        return 0;
    }

    // compare points according to their x-coordinate
    private static class XOrder implements Comparator<Point2D> {
        public int compare(Point2D p, Point2D q) {
            if (p.x < q.x) return -1;
            if (p.x > q.x) return +1;
            return 0;
        }
    }

    // compare points according to their y-coordinate
    private static class YOrder implements Comparator<Point2D> {
        public int compare(Point2D p, Point2D q) {
            if (p.y < q.y) return -1;
            if (p.y > q.y) return +1;
            return 0;
        }
    }

    // compare points according to their polar radius
    private static class ROrder implements Comparator<Point2D> {
        public int compare(Point2D p, Point2D q) {
            double delta = (p.x * p.x + p.y * p.y) - (q.x * q.x + q.y * q.y);
            if (delta < 0) return -1;
            if (delta > 0) return +1;
            return 0;
        }
    }

    // compare other points relative to atan2 angle (bewteen -pi/2 and pi/2) they make with this Point
    private class Atan2Order implements Comparator<Point2D> {
        public int compare(Point2D q1, Point2D q2) {
            double angle1 = angleTo(q1);
            double angle2 = angleTo(q2);
            if (angle1 < angle2) return -1;
            else if (angle1 > angle2) return +1;
            else return 0;
        }
    }

    private class PolarOrder implements Comparator<Point2D> {
        public int compare(Point2D q1, Point2D q2) {
            double dx1 = q1.x - x;
            double dy1 = q1.y - y;
            double dx2 = q2.x - x;
            double dy2 = q2.y - y;

            if (dy1 >= 0 && dy2 < 0) return -1;    // q1 above; q2 below
            else if (dy2 >= 0 && dy1 < 0) return +1;    // q1 below; q2 above
            else if (dy1 == 0 && dy2 == 0) {            // 3-collinear and horizontal
                if (dx1 >= 0 && dx2 < 0) return -1;
                else if (dx2 >= 0 && dx1 < 0) return +1;
                    // else return 0;
                else return distCompare(q1, q2);
            } else return -ccw(Point2D.this, q1, q2);     // both above or below

            // Note: ccw() recomputes dx1, dy1, dx2, and dy2
        }

        int distCompare(Point2D p, Point2D q) {
            double dist1 = distanceSquaredTo(p);
            double dist2 = distanceSquaredTo(q);
            if (dist1 < dist2) return -1;
            else if (dist1 > dist2) return +1;
            else return 0;
        }
    }

    private class DistanceToOrder implements Comparator<Point2D> {
        public int compare(Point2D p, Point2D q) {
            double dist1 = distanceSquaredTo(p);
            double dist2 = distanceSquaredTo(q);
            if (dist1 < dist2) return -1;
            else if (dist1 > dist2) return +1;
            else return 0;
        }
    }

    public boolean equals(Object other) {
        if (other == this) return true;
        if (other == null) return false;
        if (other.getClass() != this.getClass()) return false;
        Point2D that = (Point2D) other;
        return this.x == that.x && this.y == that.y;
    }

    public String toString() {
        return "(" + x + ", " + y + ")";
    }

    public int hashCode() {
        int hashX = ((Double) x).hashCode();
        int hashY = ((Double) y).hashCode();
        return 31 * hashX + hashY;
    }
}