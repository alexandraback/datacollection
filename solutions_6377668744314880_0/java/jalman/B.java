import java.io.*;
import java.util.*;

//convex hull code used from http://en.wikibooks.org/wiki/Algorithm_Implementation/Geometry/Convex_hull/Monotone_chain#Java

public class B{
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new FileReader("in.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("out.txt"));

		int N = Integer.parseInt(br.readLine());



		for(int pp = 0; pp < N; pp++) {
			int n = Integer.parseInt(br.readLine());
			Point[] p = new Point[n];
			for(int i = 0; i < n; i++) {
				String[] s = br.readLine().split(" ");
				p[i] = new Point();
				p[i].x = Integer.parseInt(s[0]);
				p[i].y = Integer.parseInt(s[1]);
			}
			//Point[] hull = convex_hull(p).clone();


			int[] ret = new int[n];
			int at = 0;

			for(Point t : p) {
				int rr = 20;
				for(Point q : p) {
					if(t.x == q.x && t.y == q.y) continue;

					int dx = - t.x + q.x;
					int dy = - t.y + q.y;

					int count = 0;
					for(Point v : p) {
						if(t.x == v.x && t.y == v.y) continue;

						int dtx = - t.x + v.x;
						int dty = - t.y + v.y;

						if(dx*dtx + dy*dty > 0) count++;
					}
					//System.out.println("count" + count + " " + dx + " " + dy);
					rr = Math.min(rr, count);
					rr = Math.min(rr, n-count-1);


				}




				for(Point q : p) {
					if(t.x == q.x && t.y == q.y) continue;

					int d2x = - t.x + q.x;
					int d2y = - t.y + q.y;

					int dx = -d2y;
					int dy = d2x;

					int count = 0;
					for(Point v : p) {
						if(t.x == v.x && t.y == v.y) continue;

						int dtx = - t.x + v.x;
						int dty = - t.y + v.y;

						if(dx*dtx + dy*dty > 0) count++;
					}
					rr = Math.min(rr, count);
					rr = Math.min(rr, n-count-1);


				}

				ret[at++] = rr;
			}


			pw.println("Case #" + (pp+1) + ": ");
			for(int r : ret) pw.println(r);

		}


		pw.flush();
		pw.close();

	}

		public static long cross(Point O, Point A, Point B) {
			return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
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