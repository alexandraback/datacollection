package R1A;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Scanner;

public class C {

	static Scanner reader;
	static PrintWriter writer;

	public static void main(String[] args) throws IOException {
		reader = new Scanner(new FileReader("input"));
		writer = new PrintWriter(new FileWriter("output"));
		int nt = reader.nextInt();
		for(int tc = 1; tc <= nt; tc++) {
			solve(tc);
		}
		writer.close();
		reader.close();
	}

	static void solve(int tc) {
		int n = reader.nextInt();
		Point[] points = new Point[n];
		for(int i = 0; i < n; i++) {
			points[i] = new Point(reader.nextInt(), reader.nextInt());
		}
		int[] log = new int[n];
		writer.println("Case #" + tc + ":");
		for(int i = 0; i < n; i++) {
			int min = Integer.MAX_VALUE;
			// s is the subset that is kept (we cut all the others)
			for(int s = 1; s < (1 << n); s++) {
				if(get(s, i) == 1) {
					LinkedList<Integer> L = list(n, s);
					Point[] sub = new Point[L.size()];
					int k = 0;
					for(int j : L) {
						sub[k++] = points[j];
					}
					Point[] hullS = convexHull(sub);
					if(isOnHull(points[i], hullS)) {
						min = Math.min(min, n - k);
					}
				}
			}
			log[i] = min;
		}			
		for(int i = 0; i < n; i++) {
			writer.println(log[i]);
		}
	}

	static LinkedList<Integer> list(int n, int s) {
		LinkedList<Integer> L = new LinkedList<Integer>();
		for(int i = 0; i < n; i++) {
			if(get(s, i) == 1) {
				L.add(i);
			}
		}
		return L;
	}

	static int get(int s, int i) {
		return (s >> i) & 1;
	}

	static boolean isOnHull(Point p, Point[] hull) {
		for(Point q : hull) {
			if(p.x == q.x && p.y == q.y) {
				return true;
			}
		}
		for(int i = 0; i < hull.length; i++) {
			if(orient(p, hull[i], hull[(i + 1) % hull.length]) == 0) {
				return true;
			}
		}
		return false;
	}

	static Point[] convexHull(Point[] points) {
		if(points.length <= 3) return points;
		Point[] cp = new Point[points.length];
		for(int i = 0; i < points.length; i++) {
			cp[i] = new Point(points[i].x, points[i].y);
		}
		// sort points by increasing x coordinates
		Arrays.sort(cp);
		// build upper chain
		Point[] upChain = buildChain(cp, 1);
		// build lower chain
		Point[] loChain = buildChain(cp, -1);
		Point[] hull = new Point[upChain.length + loChain.length - 2];
		int i;
		// build convex hull from upper and lower chain
		for(i = 0; i < upChain.length; i++) {
			hull[i] = upChain[i];
		}
		for(int j = loChain.length - 2; j >= 1; j--, i++) {
			hull[i] = loChain[j];
		}
		return hull;
	}

	static Point[] buildChain(Point[] points, int sgn) {
		Point[] S = new Point[points.length];
		int k = 0;
		S[k++] = points[0]; // push points[0]
		S[k++] = points[1]; // push points[1]
		// build chain
		for(int i = 2; i < points.length; i++) {
			//double orient = orient(S[k - 2], S[k - 1], points[i]);
			while(k >= 2 && sgn * orient(S[k - 2], S[k - 1], points[i]) >= 0) {
				S[k - 1] = null; // pop
				k--;
			}
			S[k++] = points[i]; // push points[i]
		}
		return Arrays.copyOf(S, k);
	}

	static class Point implements Comparable<Point> {
		double x, y;
		public Point(double x, double y) {
			this.x = x;
			this.y = y;
		}
		public int compareTo(Point other) {
			return Double.compare(x, other.x);
		}
		public String toString() {
			return String.format("(%.3f %.3f)", x, y);
		}
	}

	static double orient(Point p, Point q, Point r) {
		return q.x * r.y - r.x * q.y - p.x * (r.y - q.y) + p.y * (r.x - q.x);
	}


}
