import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

// this uses convex hull from http://en.wikibooks.org/wiki/Algorithm_Implementation/Geometry/Convex_hull/Monotone_chain
// although it turns out i didn't even need convex hull =/
public class C {

	public static void main(String[] args) throws Exception {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(bf.readLine());
		for (int tc = 1; tc <= T; tc++) {

			int n = Integer.parseInt(bf.readLine());
			Point[] p = new Point[n];
			for (int i = 0; i < n; i++) {
				StringTokenizer st = new StringTokenizer(bf.readLine());
				p[i] = new Point();
				p[i].x = Integer.parseInt(st.nextToken()); // Read X coordinate
				p[i].y = Integer.parseInt(st.nextToken()); // Read y coordinate
			}

			System.out.println("Case #" + tc + ":");
			if (n <= 3) {
				for (int i = 0; i < n; i++) {
					System.out.println("0");
				}
			} else {

				Point[][] sortedPoints = new Point[n][n - 1];
				for (int i = 0; i < n; i++) {
					// System.out.println("analyzing point " + i + "...");
					for (int j = 0; j < i; j++) {
						sortedPoints[i][j] = p[j];
						p[j].angle = Math.atan2(p[j].y - p[i].y, p[j].x - p[i].x);
					}
					for (int j = i + 1; j < n; j++) {
						sortedPoints[i][j - 1] = p[j];
						p[j].angle = Math.atan2(p[j].y - p[i].y, p[j].x - p[i].x);
					}

					Arrays.sort(sortedPoints[i], new Comparator<Point>() {
						@Override
						public int compare(Point first, Point second) {
							return (int) Math.signum(first.angle - second.angle);
						}
					});

					// System.out.println("other points sorted in order: " + Arrays.toString(sortedPoints[i]));

					int first = 0, second = 0;
					int count = 1;
					int minCount = n;
					for (; first < sortedPoints[i].length; first++, count--) {
//						System.out.println("first angle is " + sortedPoints[i][first]);
						// increment second until we're just over 180 degrees--but no further!
						while (true) {
							// this condition is broken down into several lines for readability
							double firstAngle = sortedPoints[i][first].angle;
							double secondAngle = sortedPoints[i][second].angle;
							double totalAngle = (secondAngle - firstAngle + 4 * Math.PI) % (2 * Math.PI);
							double epsilon = 0.0000001;
//							System.out.println("at secondAngle=" + second + "," + sortedPoints[i][second] + ", total is " + totalAngle
//									+ ", count is " + count);
							if (totalAngle + epsilon >= Math.PI) {
								break;
							}
							if (((second + 1) % sortedPoints[i].length == first)) {
								// this is actually a degenerate case, we reached all the way around
								minCount = 2;
								break;
							}
							second++;
							count++;
							second %= sortedPoints[i].length;
						}
						if (count < minCount) {
							minCount = count;
						}
					}
					minCount -= 2;
					System.out.println(minCount);
				}
			}

			// Point[] hull = ConvexHull.convex_hull(p);
			//
			// // after calculating the hull, make sure it's sorted in clockwise order
			// double xMedian = 0, yMedian = 0;
			// for (int i = 0; i < hull.length; i++) {
			// xMedian += hull[i].x;
			// yMedian += hull[i].y;
			// }
			// xMedian = xMedian / hull.length;
			// yMedian = yMedian / hull.length;
			//
		}

	}

	private static class Point implements Comparable<Point> {
		int x, y;
		double angle;

		public int compareTo(Point p) {
			if (this.x == p.x) {
				return this.y - p.y;
			} else {
				return this.x - p.x;
			}
		}

		public String toString() {
			return "(" + x + "," + y + "; " + angle + ")";
		}

	}

	// private static class ConvexHull {
	//
	// public static long cross(Point O, Point A, Point B) {
	// return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
	// }
	//
	// public static Point[] convex_hull(Point[] P) {
	//
	// if (P.length > 1) {
	// int n = P.length, k = 0;
	// Point[] H = new Point[2 * n];
	//
	// Arrays.sort(P);
	//
	// // Build lower hull
	// for (int i = 0; i < n; ++i) {
	// while (k >= 2 && cross(H[k - 2], H[k - 1], P[i]) < 0)
	// k--;
	// H[k++] = P[i];
	// }
	//
	// // Build upper hull
	// for (int i = n - 2, t = k + 1; i >= 0; i--) {
	// while (k >= t && cross(H[k - 2], H[k - 1], P[i]) < 0)
	// k--;
	// H[k++] = P[i];
	// }
	// if (k > 1) {
	// H = Arrays.copyOfRange(H, 0, k - 1); // remove non-hull vertices after k; remove k - 1 which is a duplicate
	// }
	// return H;
	// } else if (P.length <= 1) {
	// return P;
	// } else {
	// return null;
	// }
	// }
	//
	// }
}
