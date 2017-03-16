import javafx.scene.layout.Priority;
import sun.reflect.generics.tree.Tree;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.*;

public class Logging {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("C-small-attempt1.in"));
        int loopvar = in.nextInt();
        PrintWriter out = new PrintWriter(new File("logs.out"));
        for (int loop = 0; loop < loopvar; loop++) {
            out.printf("Case #%d:%n", loop + 1);

            int numPoints = in.nextInt();
            Point[] points = new Point[numPoints];
            Point[] oldPoints = new Point[numPoints];
            Point min = new Point(Integer.MIN_VALUE, Integer.MAX_VALUE);
            for (int i = 0; i < numPoints; i++) {
                points[i] = new Point(in.nextInt(), in.nextInt());
                oldPoints[i] = points[i];
                if (min.y > points[i].y || min.y == points[i].y && points[i].x < min.x) {
                    min = points[i];
                }
            }

            Arrays.sort(points, Point.sortBy(min));

            for (int id =  (1 << (numPoints)) - 1; id > 0; id--) {
                int cp = id;
                int cost = 0;
                for (int j = 0; j < numPoints; j++) {
                    if ((cp & 1) == 0)
                        cost++;
                    cp >>= 1;
                }

                ArrayList<Point> hull = new ArrayList<Point>();
                for (int i = 0; i < numPoints; i++) {
                    if ((1 << i & id) > 0)
                        hull.add(points[i]);
                }

                for (int i = 2; i < hull.size(); i++) {
                    while (i >= 2 && hull.get(i - 1).angle(hull.get(i)) < hull.get(i - 2).angle(hull.get(i - 1))) {
                        hull.remove(i - 1);
                        i--;
                    }
                }

                for (Point p : hull) {
                    p.score = Math.min(p.score, cost);
                }

                /*****

                 for (Point p : hull) {
                 p.isHull = true;
                 }

                 Point lastHull = hull.get(0);
                 for (Point p : all) {
                 if (p.isHull) {
                 p.score = 0;
                 lastHull = p;
                 } else {
                 ArrayList<Point> friends = new ArrayList<>();
                 //                    int i = lastHull.index;
                 int i = 0;
                 int cut = 0;
                 Point tail;
                 do {
                 friends.add(all.get(i));
                 int s = friends.size() - 1;
                 while (s >= 2 && friends.get(s - 1).angle(friends.get(s)) < friends.get(s - 2).angle(friends.get(s - 1))) {
                 if (friends.get(s - 1).equals(p)) {
                 cut++;
                 friends.remove(s);
                 } else friends.remove(s - 1);


                 s = friends.size() - 1;
                 }

                 i++;
                 tail = friends.get(friends.size() - 1);
                 } while ((tail.index < p.index || !tail.isHull)&& i < numPoints);
                 p.score = cut;

                 }
                 }

                 ****/
            }

            for (Point p : oldPoints) {
                out.println(p.score);
            }


        }
        out.close();
    }
}

class Point {
    int x;
    int y;
    int score;
    int index;
    boolean isHull;

    public Point(int x, int y) {
        this.x = x;
        this.y = y;
        score = Integer.MAX_VALUE;
    }

    public double angle(Point other) {
        double a = Math.atan2(other.y - y, other.x - x);
        if (a < 0) {
            a += 2 * Math.PI;
        }
        return a;
    }


    public static Comparator<Point> sortBy(final Point p) {
        return new Comparator<Point>() {
            @Override
            public int compare(Point o1, Point o2) {
                if (o1.equals(p))
                    return -1;
                if (o2.equals(p)) {
                    return 1;
                }
                double ang = p.angle(o1);
                int ret = Double.compare(ang, p.angle(o2));
                if (ret == 0) {
                    if (ang < Math.PI / 2) {
                        return o1.y - o2.y;
                    } else return o2.y - o1.y;
                }
                return ret;
            }
        };
    }

    public String toString() {
        return x + " " + y;
    }
}