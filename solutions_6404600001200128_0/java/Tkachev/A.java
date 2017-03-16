import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.*;

public class A {

	private void solve() throws Exception {
		int n = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; ++i) {
			a[i] = nextInt();
		}
		int sumA = 0;
		for (int i = 1; i < n; ++i) {
			if (a[i] < a[i - 1]) {
				sumA += a[i - 1] - a[i];
			}
		}
		int sumB = Integer.MAX_VALUE;
		for (int perS = 0; perS <= 10000; ++perS) {
			boolean good = true;
			int cur = 0;
			for (int i = 1; i < n; ++i) {
				if (a[i - 1] - a[i] > perS) {
					good = false;
					break;
				}
				int tmp = Math.max(a[i - 1] - perS, 0);
				cur += a[i - 1] - tmp;
			}
			if (good) {
				sumB = Math.min(sumB, cur);
			}
		}
		out.println(sumA + " " + sumB);
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

	private A(String name) {
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
		new A("A").run();
		System.err.println("Done in " + (System.currentTimeMillis() - start) + "ms");
	}
}
