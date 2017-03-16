import java.util.Scanner;

public class B {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int ntests = in.nextInt();
		for (int test = 1; test <= ntests; test++) {
			int r = in.nextInt();
			int c = in.nextInt();
			int n = in.nextInt();
			System.out.println("Case #" + test + ": " + solve(r, c, n));
		}
	}

	private static int solve(int r, int c, int n) {
		if (n <= 1)
			return 0;
		if (r > c)
			return solve(c, r, n);
		if (r == 1) {
			if (c % 2 == 0) {
				if (n <= c / 2)
					return 0;
				if (n == c / 2 + 1)
					return 1;
				return 1 + 2 * (n - c / 2 - 1);
			} else {
				if (n <= c / 2 + 1)
					return 0;
				return 2 * (n - c / 2 - 1);
			}
		}

		int m1 = solve1(r, c, n);
		int m2 = solve2(r, c, n);

		return Math.min(m1, m2);
	}
	
	private static int fillByOne(int l, boolean firstUsed)
	{
		if(!firstUsed)
			return fillByOne(l-1, true);
		return 1+(l-1)/2;
	}

	private static int solve2(int r, int c, int n) {
		int m2 = fillByOne(c, false) * ((r+1) / 2) + fillByOne(c, true) * (r / 2);
		if (n <= m2)
			return 0;
		int m2Corner = 1;
		if (c % 2 == 1)
			m2Corner++;
		if (r % 2 == 1)
			m2Corner++;
		if (c % 2 == r % 2)
			m2Corner++;
		if (n <= m2 + m2Corner)
			return 2 * (n - m2);
		int edge1 = onedge(c, false);
		int edge2 = onedge(r, false);
		int edge3 = c % 2 == 1 ? onedge(r, false) : onedge(r, true);
		int edge4 = r % 2 == 1 ? onedge(c, false) : onedge(c, true);

		int edge = edge1 + edge2 + edge3 + edge4;

		if (n <= m2 + m2Corner + edge)
			return 2 * m2Corner + 3 * (n - m2 - m2Corner);

		return 2 * m2Corner + 3 * edge + 4 * (n - m2 - m2Corner - edge);
	}

	private static int solve1(int r, int c, int n) {
		int m1 = fillByOne(c, true) * ((r+1) / 2) + fillByOne(c, false) * (r / 2);
		if (n <= m1)
			return 0;

		int m1Corner = 0;
		if (c % 2 == 0)
			m1Corner++;
		if (r % 2 == 0)
			m1Corner++;
		if (c % 2 != r % 2)
			m1Corner++;

		if (n <= m1 + m1Corner)
			return 2 * (n - m1);

		int edge1 = onedge(c, true);
		int edge2 = onedge(r, true);
		int edge3 = c % 2 == 0 ? onedge(r, false) : onedge(r, true);
		int edge4 = r % 2 == 0 ? onedge(c, false) : onedge(c, true);

		int edge = edge1 + edge2 + edge3 + edge4;

		if (n <= m1 + m1Corner + edge)
			return 2 * m1Corner + 3 * (n - m1 - m1Corner);

		return 2 * m1Corner + 3 * edge + 4 * (n - m1 - m1Corner - edge);
	}

	static int onedge(int l, boolean firstUsed) {
		if (firstUsed) {
			if (l % 2 == 0)
				return l / 2 - 1;
			return l / 2;
		} else {
			return onedge(l - 1, true);
		}
	}

}
