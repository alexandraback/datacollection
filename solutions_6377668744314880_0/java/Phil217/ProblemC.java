package Round1A;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Locale;
import java.util.Scanner;

public class ProblemC {

	public static void solve(Scanner sc) {
		int N = sc.nextInt();
		Point[] trees = new Point[N];
		for (int i = 0; i < trees.length; i++) {
			trees[i] = new Point();
			trees[i].x = sc.nextInt();
			trees[i].y = sc.nextInt();
		}
		for (int i = 0; i < trees.length; i++) {
			int min = Integer.MAX_VALUE;
			for (int j = 0; j < trees.length; j++) {
				if (j == i) {
					continue;
				}
				int above = 0;
				int below = 0;
				for (int k = 0; k < trees.length; k++) {
					if (k == i || k == j) {
						continue;
					}
					long s = ccw(trees[i],trees[j],trees[k]);
					if (s > 0) {
						above++;
					}
					if (s < 0) {
						below++;
					}
				}
				min = Math.min(min, above);
				min = Math.min(min, below);
			}
			if (min == Integer.MAX_VALUE) {
				min = 0;
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
		long x;
		long y;
	}

	public static void main(String[] args) throws FileNotFoundException {
		// Scanner sc = new Scanner(new File("C-practice.in"));
		Scanner sc = new Scanner(new File("C-small-attempt3.in"));
		// Scanner sc = new Scanner(new File("C-large.in"));
		sc.useLocale(Locale.US);
		int cases = sc.nextInt();

		for (int i = 1; i <= cases; i++) {
			System.out.format(Locale.US, "Case #%d:\n", i);
			solve(sc);
		}
		sc.close();
	}
}
