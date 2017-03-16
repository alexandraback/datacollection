import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
	static BufferedReader reader;
	static StringTokenizer tokenizer;
	static PrintWriter writer;

	static int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	static long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	static double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	static boolean eof = false;

	static String nextToken() throws IOException {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			tokenizer = new StringTokenizer(reader.readLine());
		}
		return tokenizer.nextToken();
	}

	public static void main(String[] args) throws IOException {
		tokenizer = null;
		reader = new BufferedReader(new FileReader("input.txt"));
		writer = new PrintWriter(new FileWriter("output.txt"));
		// reader = new BufferedReader(new InputStreamReader(System.in,
		// "ISO-8859-1"));
		// writer = new PrintWriter(System.out);
		banana();
		reader.close();
		writer.close();
	}

	static class Point {
		int x, y, index;

		public Point(int _x, int _y, int _index) {
			x = _x;
			y = _y;
			index = _index;
		}
	}

	static Point a[];

	static boolean check(Point a[], int v) {
		boolean ret = false;
		for (int i = 0; i < a.length; ++i) {
			if (i != v) {
				ret = ret || oneSideCheck(a, v, i);
			}
		}

		return ret;
	}

	static boolean oneSideCheck(Point p[], int v, int w) {
		int a = p[v].y - p[w].y;
		int b = p[w].x - p[v].x;
		int c = -a * p[v].x - b * p[v].y;

		int valval = 0;
		for (int i = 0; i < p.length; ++i) {
			int val = a * p[i].x + b * p[i].y + c;

			if (valval * val < 0)
				return false;
			if (valval * val == 0) {
				if (valval == 0)
					valval = val;
			}
		}
		return true;
	}

	static void banana() throws IOException {
		int tests = nextInt();
		for (int ttt = 0; ttt < tests; ++ttt) {
			int n = nextInt();

			a = new Point[n];

			for (int i = 0; i < n; ++i) {
				a[i] = new Point(nextInt(), nextInt(), i);
			}

			int x[] = new int[n];
			if (n > 3) {
				Arrays.fill(x, n);

				for (int i = 0; i < (1 << n); ++i) {
					List<Integer> nums = new ArrayList<Integer>();
					for (int j = 1, counter = 0; j < i; j *= 2, ++counter)
						if ((i & j) != 0)
							nums.add(counter);

					Point c[] = new Point[nums.size()];

					for (int j = 0; j < c.length; ++j) {
						c[j] = a[nums.get(j)];
					}

					int deleted = n - nums.size();
					for (int j = 0; j < c.length; ++j) {
						if (check(c, j)) {
							x[c[j].index] = Math.min(x[c[j].index], deleted);
						}
					}
				}
			} else {
				if (n <= 2)
					for (int i = 0; i < n; ++i) {
						x[i] = n;
					}
			}
			writer.println("Case #" + (ttt + 1) + ":");
			for (int i = 0; i < n; ++i) {
				writer.println(x[i]);
			}
		}
	}
}