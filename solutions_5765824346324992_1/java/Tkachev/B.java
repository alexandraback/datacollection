import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Locale;
import java.util.StringTokenizer;

public class B {

	private void solve() throws Exception {
		int barbers = nextInt();
		int n = nextInt();
		int[] a = new int[barbers];
		for (int i = 0; i < a.length; ++i) {
			a[i] = nextInt();
		}
		long lo = -1, hi = Long.MAX_VALUE / 3;
		while (hi - lo > 1) {
			long mid = (lo + hi) / 2;
			long count = 0;
			for (int b : a) {
				count += mid / b + 1;
				if (count >= n) {
					break;
				}
			}
			if (count >= n) {
				hi = mid;
			} else {
				lo = mid;
			}
		}
		long count = 0;
		long countEq = 0;
		for (int b : a) {
			count += hi / b + 1;
			if (hi % b == 0) {
				countEq += 1;
			}
		}
		//out.println(hi);
		count -= countEq;
		for (int i = 0; i < a.length; ++i) {
			if (hi % a[i] == 0) {
				++count;
			}
			if (count == n) {
				out.println(i + 1);
				return;
			}
		}
	}

	public void run() {
		try {
			int tc = nextInt();
			for (int it = 1; it <= tc; ++it) {
				System.err.println(it);
				out.print("Case #" + it + ": ");
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

	private B(String name) {
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
		new B("B").run();
		System.err.println("Done in " + (System.currentTimeMillis() - start) + "ms");
	}
}
