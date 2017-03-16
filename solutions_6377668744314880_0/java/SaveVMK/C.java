import java.io.*;
import java.util.*;

class Point implements Comparable<Point> {
	int x, y;
 
	public int compareTo(Point p) {
		if (this.x == p.x) {
			return this.y - p.y;
		} else {
			return this.x - p.x;
		}
	}
 
	public String toString() {
		return "("+x + "," + y+")";
	}
 
}

public class C {
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(new FileInputStream("src/C-small.in"))));

		String output = "";
		int t = sc.nextInt();
		sc.nextLine();
		for (int i = 1; i <= t; i++) {
			int n = sc.nextInt();
			Point[] p = new Point[n];
			for (int j = 0; j < n; j++) {
				p[j] = new Point();
				p[j].x = sc.nextInt();
				p[j].y = sc.nextInt();
			}
			int max = 1;
			int[] results = new int[n];
			for (int j = 0; j < n; j++) {
				results[j] = Integer.MAX_VALUE;
				max <<= 1;
			}
			for (int j = 0; j < max; j++) {
				int count = 0;
				int temp = j;
				for (int k = 0; k < n; k++) {
					if (temp%2==1) {
						count++;
					}
					temp /= 2;
				}
				Point[] points = new Point[count];
				temp = j;
				int m = 0;
				for (int k = 0; k < n; k++) {
					if (temp%2==1) {
						points[m++] = p[k];
					}
					temp /= 2;
				}
				Point[] hull = convex_hull(points);
				for (int k = 0; k < n; k++) {
					Point point = p[k];
					for (int a = 0; a < hull.length; a++) {
						Point hullPoint = hull[a];
						if (point.x == hullPoint.x && point.y == hullPoint.y) {
							results[k] = Math.min(results[k], n-count);
						}
						int otherIndex = a-1;
						if (otherIndex < 0)
							otherIndex += hull.length;
						if (isPointOnLine(point,hullPoint,hull[otherIndex])) {
							results[k] = Math.min(results[k], n-count);
						}
					}
				}
			}
			output += "Case #" + i + ":\n";
			for (int j = 0; j < n; j++) {
				output += results[j]+"\n";
			}
		}
		
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("src/C-small.out"), "utf-8"));
		bw.write(output);
		bw.close();
	}
	
	public static boolean isPointOnLine(Point O, Point A, Point B) {
		return cross(O,A,B)==0;
	}
	
	public static double dist(Point A, Point B) {
		return Math.sqrt(Math.pow(A.x-B.x,2)+Math.pow(A.y-B.y,2));
	}
	
	public static long cross(Point O, Point A, Point B) {
		return (long)(A.x - O.x) * (long)(B.y - O.y) - (long)(A.y - O.y) * (long)(B.x - O.x);
	}
 
	public static Point[] convex_hull(Point[] P) {
 
		if (P.length > 1) {
			int n = P.length, k = 0;
			Point[] H = new Point[2 * n];
 
			Arrays.sort(P);
 
			// Build lower hull
			for (int i = 0; i < n; ++i) {
				while (k >= 2 && cross(H[k - 2], H[k - 1], P[i]) <= 0)
					k--;
				H[k++] = P[i];
			}
 
			// Build upper hull
			for (int i = n - 2, t = k + 1; i >= 0; i--) {
				while (k >= t && cross(H[k - 2], H[k - 1], P[i]) <= 0)
					k--;
				H[k++] = P[i];
			}
			if (k > 1) {
				H = Arrays.copyOfRange(H, 0, k - 1); // remove non-hull vertices after k; remove k - 1 which is a duplicate
			}
			return H;
		} else if (P.length <= 1) {
			return P;
		} else{
			return null;
		}
	}
}