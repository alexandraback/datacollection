import java.io.File;
import java.io.PrintStream;
import java.util.Locale;
import java.util.Scanner;

public class B {

	private static int calc(boolean[][] ap, int i, int j) {
		int c = 0;
		if ((i > 0) && (ap[i - 1][j])) {
			c++;
		}
		if ((i < ap.length - 1) && (ap[i + 1][j])) {
			c++;
		}

		if ((j > 0) && (ap[i][j - 1])) {
			c++;
		}
		if ((j < ap[i].length - 1) && (ap[i][j + 1])) {
			c++;
		}

		return c;
	}

	private static int check(boolean v, int r, int c, int n) {
		boolean[][] ap = new boolean[r][c];

		int res = 0;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (v) {
					if ((i & 1) == (j & 1)) {
						ap[i][j] = true;
						n--;
					}
				} else {
					if ((i & 1) != (j & 1)) {
						ap[i][j] = true;
						n--;
					}
				}
			}
		}

		if (n > 0) {
			if (!ap[0][c - 1]) {
				res += calc(ap, 0, c - 1);
				ap[0][c - 1] = true;
				n--;
			}
		}
		if (n > 0) {
			if (!ap[r - 1][0]) {
				res += calc(ap, r - 1, 0);
				ap[r - 1][0] = true;
				n--;
			}
		}
		if (n > 0) {
			if (!ap[r - 1][c - 1]) {
				res += calc(ap, r - 1, c - 1);
				ap[r - 1][c - 1] = true;
				n--;
			}
		}
		int j = 0;
		while (n > 0 && j < c) {
			if (!ap[0][j]) {
				n--;
				res += calc(ap, 0, j);
				ap[0][j] = true;
			}
			j++;
		}
		j = 0;
		while (n > 0 && j < c) {
			if (!ap[r - 1][j]) {
				n--;
				res += calc(ap, r - 1, j);
				;
				ap[r - 1][j] = true;
			}
			j++;
		}
		int i = 0;
		while (n > 0 && i < r) {
			if (!ap[i][0]) {
				n--;
				res += calc(ap, i, 0);
				ap[i][0] = true;
			}
			i++;
		}
		i = 0;
		while (n > 0 && i < r) {
			if (!ap[i][c - 1]) {
				n--;
				res += calc(ap, i, c - 1);
				ap[i][c - 1] = true;
			}
			i++;
		}
		if (n > 0) {
			for (i = 0; i < r; i++) {
				for (j = 0; j < c; j++) {
					if (!ap[i][j]) {
						res += calc(ap, i, j);
						n--;
					}
					if (n == 0) {
						break;
					}
				}
				if (n == 0) {
					break;
				}
			}
		}
		return res;

	}

	public static void main(String[] args) throws Exception {
		Locale.setDefault(Locale.US);

		Scanner in = new Scanner(new File("problem.in"));
		PrintStream out = new PrintStream(new File("problem.out"));

		int T = in.nextInt();
		for (int test = 1; test <= T; test++) {
			int r = in.nextInt();
			int c = in.nextInt();

			int n = in.nextInt();
			int res1 = check(true, r, c, n);
			int res2 = check(false, r, c, n);

			out.println("Case #" + test + ": " + Math.min(res1, res2));
		}

		in.close();
		out.close();
	}
}
