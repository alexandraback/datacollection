import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;

public class B {

	private void work() throws Exception {
		Scanner sc = new Scanner(new BufferedReader(
				new FileReader("B-large.in")));
		PrintWriter pw = new PrintWriter(new FileWriter("B-large.out"));

		int nc = sc.nextInt();
		for (int tc = 1; tc <= nc; tc++) {
			int r = sc.nextInt();
			int c = sc.nextInt();
			int n = sc.nextInt();
			int best;

			if ((c & 1) != 0) {
				int t = r;
				r = c;
				c = t;
			}
			if ((c & 1) != 0 && c < r) {
				int t = r;
				r = c;
				c = t;
			}

			if (r == 1 && c == 1) {
				best = 0;
			} else {
				if ((c & 1) == 0) {
					best = 0;
					n -= r * c / 2;
					if (r == 1) {
						if (n > 0) {
							n--;
							best++;
						}
						if (n > 0) {
							best += n * 2;
						}
					} else {
						if (n > 0) {
							n--;
							best += 2;
						}
						if (n > 0) {
							n--;
							best += 2;
						}
						if (n > 0) {
							int t = r / 2 + (r + 1) / 2 + c - 4;
							if (t < n) {
								best += t * 3 + (n - t) * 4;
							} else {
								best += n * 3;
							}
						}
					}
				} else {
					best = Math.min(calc0(r, c, n), calc1(r, c, n));
				}
			}

			pw.printf("Case #%d: %d\n", tc, best);
		}
		sc.close();
		pw.close();
	}

	// these assume r,c odd

	private int calc0(int r, int c, int n) {
		int ret = 0;
		if (r == 1) {
			n -= c / 2;
			if (n > 0) {
				n--;
				ret++;
			}
			if (n > 0) {
				n--;
				ret++;
			}
			if (n > 0)
				ret += 2 * n;
		} else {
			n -= r * (c / 2) + r / 2;
			if (n > 0) {
				if (n > 4) {
					n -= 4;
					ret += 8;
					int t = 2 * (r / 2 + c / 2) - 4;
					if (t < n) {
						ret += t * 3 + (n - t) * 4;
					} else {
						ret += n * 3;
					}
				} else {
					ret = n * 2;
				}
			}
		}
		return ret;
	}

	private int calc1(int r, int c, int n) {
		int ret = 0;
		if (r == 1) {
			n -= (c + 1) / 2;
			if (n > 0)
				ret = 2 * n;
		} else {
			n -= r * (c / 2) + (r + 1) / 2;
			if (n > 0) {
				int t = 2 * (r / 2 + c / 2);
				if (t < n) {
					ret += t * 3 + (n - t) * 4;
				} else {
					ret += n * 3;
				}
			}
		}
		return ret;
	}

	public static void main(String[] args) throws Exception {
		new B().work();
	}

}
