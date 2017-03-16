import java.io.IOException;
import java.util.Arrays;
import java.util.Locale;
import java.util.InputMismatchException;
import java.util.Comparator;
import java.io.OutputStream;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.io.File;
import java.io.FilenameFilter;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Vaibhav Mittal
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
			outputStream = new FileOutputStream("c.out");
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

    final int INF = 10000;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.readInt();
        Point[] points = new Point[n];
        for(int i = 0; i < n; ++i) {
            int x = in.readInt();
            int y = in.readInt();
            points[i] = new Point(x, y);
        }
        int[] minTrees = new int[n];
        Arrays.fill(minTrees, INF);
        for (long mask = 1L; mask < (1L << n); ++mask) {
            int numTrees = Long.bitCount(mask);
            int cutTrees = n - numTrees;
            Point[] currentPoints = new Point[numTrees];
            for (int i = 0, j = 0; i < n; ++i) if ((mask & (1L << i)) != 0L) {
                currentPoints[j++] = new Point(points[i].x, points[i].y);
            }
            Point[] hull = convexHull(currentPoints);
            for (Point i : hull) {
                for (int j = 0; j < n; ++j) if (i.equals(points[j]))
                    minTrees[j] = Math.min(minTrees[j], cutTrees);
            }
        }
        out.println("Case #" + testNumber + ": ");
        for (int trees : minTrees)
            out.println(trees);
    }

    public static class Point {
        int x;
        int y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public String toString() {
            return "Point{" + "x=" + x + ", y=" + y + '}';
        }

        public boolean equals(Object o) {
            if (this == o) return true;
            if (!(o instanceof Point)) return false;

            Point point = (Point) o;

            if (x != point.x) return false;
            if (y != point.y) return false;

            return true;
        }

        public int hashCode() {
            int result = x;
            result = 31 * result + y;
            return result;
        }
    }

    public static final Comparator<Point> X = new Comparator<Point>() {
        public int compare(Point a, Point b) {
            if (a.x < b.x) return -1;
            else if (a.x > b.x) return 1;
            else if (a.y < b.y) return -1;
            else if (a.y > b.y) return 1;
            else return 0;
        }
    };

    public static boolean turnTest(Point a, Point b, Point c) {
        return (c.x - a.x) * (long) (b.y - a.y) - (b.x - a.x) * (long) (c.y - a.y) >= 0;
    }

    public static Point[] convexHull(Point[] points) {
        if (points.length <= 2)
            return points;
        Arrays.sort(points, X);
        Point[] hull = new Point[2 * points.length];
        int k = 0, start = 0;
        for(int i = 0; i < points.length; ++i) {
            while(k - start >= 2 && !turnTest(hull[k - 2], hull[k - 1], points[i])) {
                k--;
            }
            hull[k++] = points[i];
        }
        k--;
        start = k;
        for(int i = points.length - 1; i >= 0; --i) {
            while(k - start >= 2 && !turnTest(hull[k - 2], hull[k - 1], points[i])) {
                k--;
            }
            hull[k++] = points[i];
        }
        k--;
        return Arrays.copyOf(hull, k);
    }
}

class InputReader {

    private InputStream stream;
    private byte[] buffer = new byte[1024];
    private int curChar;
    private int numChars;

    public InputReader(InputStream stream) {
        this.stream = stream;
    }

    private int read() {
        if (numChars == -1)
            throw new InputMismatchException();
        if (curChar >= numChars) {
            curChar = 0;
            try {
                numChars = stream.read(buffer);
            } catch (IOException e) {
                throw new InputMismatchException();
            }
            if (numChars <= 0)
                return -1;
        }
        return buffer[curChar++];
    }

    public int readInt() {
        int c = read();
        while (isWhiteSpace(c))
            c = read();
        int sign = 1;
        if (c == '-') {
            sign = -1;
            c = read();
        }
        int res = 0;
        do {
            if (c < '0' || c > '9')
                throw new InputMismatchException();
            res *= 10;
            res += c - '0';
            c = read();
        } while (!isWhiteSpace(c));
        return res * sign;
    }

    public String readString() {
        int c = read();
        while (isWhiteSpace(c))
            c = read();
        StringBuilder res = new StringBuilder();
        do {
            res.appendCodePoint(c);
            c = read();
        } while (!isWhiteSpace(c));
        return res.toString();
    }

    public String next() {
        return readString();
    }

    private boolean isWhiteSpace(int c) {
        return c == ' ' || c == '\n' || c == '\t' || c == '\r' || c == -1;
    }
}

