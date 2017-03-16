import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.*;

public class C {

	Random rand = new Random();

	private void solve() throws Exception {
		int n = nextInt();
		//int n = 3000;
		int[] x = new int[n], y = new int[n];
		for (int i = 0; i < n; ++i) {
			x[i] = nextInt();
			y[i] = nextInt();
			//x[i] = rand.nextInt();
			//y[i] = rand.nextInt();
		}
		if (n == 1) {
			out.println(0);
			return;
		}
		int[][] dx = new int[n][n];
		int[][] dy = new int[n][n];
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				dx[i][j] = x[i] - x[j];
				dy[i][j] = y[i] - y[j];
			}
		}
		int[] best = new int[n];
		Arrays.fill(best, Integer.MAX_VALUE);
		for (int first = 0; first < n; ++first) {
			for (int second = first + 1; second < n; ++second) {
				int countLess = 0, countMore = 0;
				int cX = dx[first][second];
				int cY = dy[first][second];
				for (int i = 0; i < n; ++i) {
					long val = psSc(cX, cY, dx[first][i], dy[first][i]);
					if (val < 0) {
						++countLess;
					} else if (val > 0) {
						++countMore;
					}
				}
				countLess = Math.min(countLess, countMore);
				best[first] = Math.min(best[first], countLess);
				best[second] = Math.min(best[second], countLess);
			}
		}
		for (int i = 0; i < n; ++i) {
			out.println(best[i]);
		}
    }

	private long psSc(long x1, long y1, long x2, long y2) {
		return x1 * y2 - x2 * y1;
	}

	public void run() {
		try {
            int tc = nextInt();
			//tc = 1;
			for (int it = 1; it <= tc; ++it) {
				System.err.println(it);
				out.println("Case #" + it + ":");
				solve();
			}
		} catch (Exception e) {
			NOO(e);
		} finally {
			out.close();
		}
	}

	PrintWriter out;
	BufferedReader in;
	StringTokenizer St;

	void NOO(Exception e) {
		e.printStackTrace();
		System.exit(42);
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}

	String nextToken() {
		while (!St.hasMoreTokens()) {
			try {
				String line = in.readLine();
				if (line == null)
					return null;
				St = new StringTokenizer(line);
			} catch (Exception e) {
				NOO(e);
			}
		}
		return St.nextToken();
	}

	private C(String name) {
		try {
			in = new BufferedReader(new FileReader(name + ".in"));
			St = new StringTokenizer("");
			out = new PrintWriter(new FileWriter(name + ".out"));
		} catch (Exception e) {
			NOO(e);
		}
	}

	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		long start = System.currentTimeMillis();
		new C("C").run();
		System.err.println("Done in " + (System.currentTimeMillis() - start) + "ms");
	}
}
