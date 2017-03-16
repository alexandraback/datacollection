package Round1A;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Locale;
import java.util.Scanner;

public class ProblemCLarge2 {

	public static void solve(Scanner sc) {
		int N = sc.nextInt();
		Point[] trees = new Point[N];
		for (int i = 0; i < trees.length; i++) {
			trees[i] = new Point();
			trees[i].x = sc.nextInt();
			trees[i].y = sc.nextInt();
			trees[i].order = i;
		}
		if (N < 4) {
			for (int i = 0; i < trees.length; i++) {
				System.out.println(0);
			}
			return;
		}
		for (int i = 0; i < trees.length; i++) {
			Arrays.sort(trees, new Comparator<Point>() {
				@Override
				public int compare(Point o1, Point o2) {
					return o1.order - o2.order;
				}
			});
			for (int j = 0; j < trees.length; j++) {
				trees[j].angle = Math.atan2(trees[j].y - trees[i].y, trees[j].x
						- trees[i].x);
			}
			// shift curr point to end
			Point tmp = trees[i];
			trees[i] = trees[N - 1];
			trees[N - 1] = tmp;
			Arrays.sort(trees, 0, N - 1, trees[N - 1].POLAR_ORDER);
			int start = 0;
			int end = start;
			int min = Integer.MAX_VALUE;
			// double eps = 1e-5;
			outer: while (start != N - 1) {

				while (ccw(trees[start], trees[N - 1], trees[end]) <= 0) {
					end++;
					end %= N - 1;
					if (end == start) {
						min = 0;
						break outer;
					}
				}

				int diff = end - start;
				if (diff < 0) {
					diff += N - 1;
				}
				min = Math.min(min, diff);
				min = Math.min(min, N - 1 - diff);

				start++;
			}
			System.out.println(min);
		}
	}

	/**
	 * Is a->b->c a counterclockwise turn?
	 */
	public static int ccw(Point a, Point b, Point c) {
		long area2 = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
		if (area2 < 0)
			return -1;
		else if (area2 > 0)
			return +1;
		else
			return 0;
	}

	static class Point {

		public final Comparator<Point> POLAR_ORDER = new PolarOrder();

		long x;
		long y;
		double angle;
		int order;

		@Override
		public String toString() {
			return "(" + x + "," + y + ") angle: " + angle;
		}

		private class PolarOrder implements Comparator<Point> {
			public int compare(Point q1, Point q2) {
				long dx1 = q1.x - x;
				long dy1 = q1.y - y;
				long dx2 = q2.x - x;
				long dy2 = q2.y - y;

				if (dy1 >= 0 && dy2 < 0)
					return -1; // q1 above; q2 below
				else if (dy2 >= 0 && dy1 < 0)
					return +1; // q1 below; q2 above
				else if (dy1 == 0 && dy2 == 0) { // 3-collinear and horizontal
					if (dx1 >= 0 && dx2 < 0)
						return -1;
					else if (dx2 >= 0 && dx1 < 0)
						return +1;
					else
						return 0;
				} else
					return -ccw(Point.this, q1, q2); // both above or below

				// Note: ccw() recomputes dx1, dy1, dx2, and dy2
			}
		}
	}

	public static void main(String[] args) throws FileNotFoundException {
		// Scanner sc = new Scanner(new File("C-practice.in"));
//		Scanner sc = new Scanner(new File("C-small-attempt3.in"));
		 Scanner sc = new Scanner(new File("C-large.in"));
		sc.useLocale(Locale.US);
		int cases = sc.nextInt();

		for (int i = 1; i <= cases; i++) {
			System.out.format(Locale.US, "Case #%d:\n", i);
			solve(sc);
		}
		sc.close();
	}
}
