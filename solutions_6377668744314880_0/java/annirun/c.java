import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

public class c {
	static class Point {
		long x, y;

		public Point(long x, long y) {
			this.x = x;
			this.y = y;
		}
	}

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in);
		int cases = in.nextInt();
		int cn = 0;

		while (cn++ < cases) {
			int points = in.nextInt();
			Point[] input = new Point[points];
			for (int i = 0; i < input.length; i++) {
				input[i] = new Point(in.nextInt(), in.nextInt());
			}

			int[] best = new int[points];
			Arrays.fill(best, Integer.MAX_VALUE);
			
			for (int bm = 1; bm < (1 << points); bm++) {
				int using = Integer.bitCount(bm);
				if (using <= 3) {
					for (int i = 0; i < points; i++) {
						if ((bm & (1 << i)) != 0) {
							best[i] = Math.min(best[i], points - using);
						}
					}
					continue;
				}
				
				int idx = 0;
				Point[] attempt = new Point[using];
				for (int i = 0; i < points; i++) {
					if ((bm & (1 << i)) != 0) {
						attempt[idx++] = input[i];
					}
				}

				ArrayDeque<Vector> answer = convexHull(attempt);
				line[] checker = new line[answer.size()];
				idx = 0;
				
				Point last = null;
				for (Vector v : answer) {
					if (last != null && last != v.a)
						throw new Exception();
					last = v.b;
					checker[idx++] = new line(v.a, v.b);
				}

				for (int i = 0; i < points; i++) {
					if ((bm & (1 << i)) != 0) {
						for (line line : checker) {
							if (line.on(input[i])) {
								best[i] = Math.min(best[i], points - using);
							}
						}
					}
				}
			}

			System.out.printf("Case #%d:\n", cn);
			for (int i : best) {
				System.out.println(i);
			}
		}
	}

	// points cannot have duplicates
	public static ArrayDeque<Vector> convexHull(Point[] points) {
		Point best = points[0];
		for (int i = 1; i < points.length; i++) {
			if (points[i].x == best.x ? points[i].y < best.y
					: points[i].x < best.x)
				best = points[i];
		}

		ArrayList<Vector> vectors = new ArrayList<Vector>(points.length - 1);
		for (Point p : points) {
			if (p != best)
				vectors.add(new Vector(best, p));
		}

		Collections.sort(vectors, new Comparator<Vector>() {
			@Override
			public int compare(Vector a, Vector b) {
				return Long.signum(a.crossProduct(b));
			}
		});

		ArrayDeque<Vector> hull = new ArrayDeque<Vector>();
		for (Vector v : vectors) {

			Vector newV;
			while (true) {
				if (hull.size() == 0) {
					newV = new Vector(best, v.b);
				} else {
					newV = new Vector(hull.peekLast().b, v.b);
				}

				if (hull.size() > 0 && hull.peekLast().crossProduct(newV) > 0) {
					hull.pollLast();
				} else {
					break;
				}
			}

			hull.add(newV);
		}

		// close polygon if needed
		if (hull.size() > 0)
			hull.add(new Vector(hull.peekLast().b, best));

		return hull;
	}

	public static class Vector {
		long h, w;
		Point a, b;

		public Vector(Point one, Point two) {
			a = one;
			b = two;
			h = two.y - one.y;
			w = two.x - one.x;
		}

		// cross/dot = tan
		/*
		 * + is left - is right 0 paralell two magnitudes times cosin
		 */
		long crossProduct(Vector v) {
			return (w * v.h) - (h * v.w);
		}

		/*
		 * + is same direction - is other 0 perpendicular two magnitudes times
		 * sin 3d version: x = y1z2 - z1y2 y = z1x2 - z2x1 z = x1y2 - y2x1
		 */
		long dotProduct(Vector v) {
			return (h * v.h) + (w * v.w);
		}
	}

	// Represents a line as Ax + By = C
	static class line {
		Vector v;
		Point a, b;
		long A, B, C;

		public boolean inBounds(Point Point) {
			return (Point.x <= Math.max(a.x, b.x)
					&& Point.x >= Math.min(a.x, b.x)
					&& Point.y <= Math.max(a.y, b.y) && Point.y >= Math.min(
					a.y, b.y));
		}

		public line(Point f, Point e) {
			a = f;
			b = e;
			A = b.y - a.y;
			B = a.x - b.x;
			C = A * a.x + B * a.y;
			v = new Vector(a, b);
		}

		boolean on(Point p) {
			return (inBounds(p) && (((A * p.x) + (B * p.y)) == C));
		}
	}
}
