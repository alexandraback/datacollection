import java.util.Locale;
import java.io.BufferedReader;
import java.util.Comparator;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.File;
import java.io.FilenameFilter;
import java.util.List;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.ArrayList;
import java.io.FileOutputStream;
import java.io.FileInputStream;
import java.util.StringTokenizer;
import java.math.BigInteger;
import java.util.Collections;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author AlexFetisov
 */
public class Main {
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		InputStream inputStream;
		try {
			final String regex = "C-(small|large).*[.]in";
			File directory = new File(".");
			File[] candidates = directory.listFiles(new FilenameFilter() {
				public boolean accept(File dir, String name) {
					return name.matches(regex);
				}
			});
			File toRun = null;
			for (File candidate : candidates) {
				if (toRun == null || candidate.lastModified() > toRun.lastModified())
					toRun = candidate;
			}
			inputStream = new FileInputStream(toRun);
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("c.txt");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskC solver = new TaskC();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskC {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        out.println("Case #" + testNumber + ":");
        int countPoints = in.nextInt();
        Point[] points = new Point[countPoints];
        for (int i = 0; i < countPoints; ++i) {
            points[i] = new Point(in);
            points[i].id = i;
        }
        int[] res = new int[countPoints];
        Arrays.fill(res, countPoints-1);
        for (int set = 1; set < (1 << countPoints); ++set) {
            List<Point> leftPoints = new ArrayList<Point>();
            for (int j = 0; j < countPoints; ++j) {
                if (BitUtils.checkBit(set, j)) {
                    leftPoints.add(points[j]);
                }
            }
            Point[] p = new Point[leftPoints.size()];
            for (int i = 0; i < leftPoints.size(); ++i) {
                p[i] = leftPoints.get(i);
            }
            Polygon poly = Polygon.convexHull(p);
            for (Point pp : poly.v) {
                res[pp.id] = Math.min(res[pp.id], countPoints - Integer.bitCount(set));
            }
        }
        for (int i = 0; i < countPoints; ++i) {
            out.println(res[i]);
        }
    }
}

class InputReader {
    private BufferedReader reader;
    private StringTokenizer stt;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream));
    }

    public String nextLine() {
        try {
            return reader.readLine();
        } catch (IOException e) {
            return null;
        }
    }

    public String nextString() {
        while (stt == null || !stt.hasMoreTokens()) {
            stt = new StringTokenizer(nextLine());
        }
        return stt.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(nextString());
    }

    public double nextDouble() {
        return Double.parseDouble(nextString());
    }

    public String next() {
        return nextString();
    }
}

class Point implements Comparable<Point> {
    public double x, y;
    public int id;

    public Point(InputReader in) {
        this.x = in.nextDouble();
        this.y = in.nextDouble();
    }

    public String toString() {
        return "(" + x + ", " + y + " )";
    }

    public boolean equals(Object o) {
        Point p = (Point) o;
        return DoubleUtils.compareTo(x, p.x) == 0 && DoubleUtils.compareTo(y, p.y) == 0;
    }

    public int hashCode() {
        int result;
        long temp;
        temp = x != +0.0d ? Double.doubleToLongBits(x) : 0L;
        result = (int) (temp ^ (temp >>> 32));
        temp = y != +0.0d ? Double.doubleToLongBits(y) : 0L;
        result = 31 * result + (int) (temp ^ (temp >>> 32));
        return result;
    }

    /*public double distanceToLine(Line l) {
        if (l.hasPoints()) {
            return distanceToLine(l.p1, l.p2);
        }
        Line normLine = l.norm();
        return normLine.a * x + normLine.b * y + normLine.c;
    } */

    public int compareTo(Point o) {
        int temp = DoubleUtils.compareTo(x, o.x);
        if (temp == 0) {
            return DoubleUtils.compareTo(y, o.y);
        }
        return temp;
    }
}

class BitUtils {
    public static boolean checkBit(int mask, int bit) {
        return (mask & (1 << bit)) > 0;
    }

}

class Polygon {
    public final Point[] v;

    // Used for convex hulls
    private Point[] upCover;
    private Point[] downCover;

    public Polygon(Point... v) {
        this.v = v.clone();
    }

    public Polygon(Point[] v, List<Point> up, List<Point> down) {
        this.v = v.clone();
        Collections.sort(up);
        Collections.sort(down);
        while (up.size() > 2 && DoubleUtils.compareTo(up.get(0).x, up.get(2).x) == 0) {
            up.remove(1);
        }
        while (up.size() > 2 && DoubleUtils.compareTo(up.get(0).x, up.get(1).x) == 0) {
            up.remove(0);
        }
        while (up.size() > 2 && DoubleUtils.compareTo(up.get(up.size()-1).x, up.get(up.size()-3).x) == 0) {
            up.remove(up.size()-2);
        }
        while (up.size() > 2 && DoubleUtils.compareTo(up.get(up.size()-1).x, up.get(up.size()-2).x) == 0) {
            up.remove(up.size()-1);
        }
        while (down.size() > 2 && DoubleUtils.compareTo(down.get(0).x, down.get(2).x) == 0) {
            down.remove(1);
        }
        while (down.size() > 2 && DoubleUtils.compareTo(down.get(0).x, down.get(1).x) == 0) {
            down.remove(0);
        }
        while (down.size() > 2 && DoubleUtils.compareTo(down.get(down.size()-1).x, down.get(down.size()-3).x) == 0) {
            down.remove(down.size()-2);
        }
        while (down.size() > 2 && DoubleUtils.compareTo(down.get(down.size()-1).x, down.get(down.size()-2).x) == 0) {
            down.remove(down.size()-1);
        }
        upCover = new Point[up.size()];
        for (int i = 0; i < up.size(); ++i) {
            upCover[i] = up.get(i);
        }
        downCover = new Point[down.size()];
        for (int i = 0; i < down.size(); ++i) {
            downCover[i] = down.get(i);
        }
    }

    public static boolean over(Point a, Point b, Point c) {
        return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) < -DoubleUtils.EPS;
    }

    private static boolean under(Point a, Point b, Point c) {
        return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) > DoubleUtils.EPS;
    }

    public static Polygon convexHull(Point[] points) {
        if (points.length == 1) {
            return new Polygon(points);
        }
        Arrays.sort(points, new Comparator<Point>() {
            public int compare(Point o1, Point o2) {
                int value = Double.compare(o1.x, o2.x);
                if (value != 0) {
                    return value;
                }
                return Double.compare(o1.y, o2.y);
            }
        });
        Point left = points[0];
        Point right = points[points.length - 1];
        List<Point> up = new ArrayList<Point>();
        List<Point> down = new ArrayList<Point>();
        for (Point point : points) {
            if (point == left || point == right || !under(left, point, right)) {
                while (up.size() >= 2 && under(up.get(up.size() - 2), up.get(up.size() - 1), point)) {
                    up.remove(up.size() - 1);
                }
                up.add(point);
            }
            if (point == left || point == right || !over(left, point, right)) {
                while (down.size() >= 2 && over(down.get(down.size() - 2), down.get(down.size() - 1), point)) {
                    down.remove(down.size() - 1);
                }
                down.add(point);
            }
        }
        Point[] result = new Point[up.size() + down.size() - 2];
        int index = 0;
        for (Point point : up) {
            result[index++] = point;
        }
        for (int i = down.size() - 2; i > 0; i--) {
            result[index++] = down.get(i);
        }
        return new Polygon(result, up, down);
    }

}

class DoubleUtils {
    public static final double EPS = 1e-10;

    public static int compareTo(double a, double b) {
        if (doubleEqual(a, b)) {
            return 0;
        }
        if (a < b) {
            return -1;
        }
        return 1;
    }

    private static boolean doubleEqual(double a, double b) {
        return Math.abs(a - b) < EPS;
    }

}

