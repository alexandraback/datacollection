import java.io.*;
import java.util.*;
import java.math.*;


public class Main implements Runnable {
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static int n, m, res;
	static boolean[][] used;
	
	static void solve() throws Exception {
		int t = nextInt();
		for (int tt = 1; tt <= t; ++tt) {
			n = nextInt();
			m = nextInt();
			int cnt = nextInt();
			res = Integer.MAX_VALUE;
			used = new boolean[n][m];
			f(0, 0, cnt);
			out.println("Case #" + tt + ": " + res);
		}
	}
	
	static void f(int x, int y, int left) {
		if (x == n) {
			if (left == 0) {
				int tmp = 0;
				for (int i = 0; i < n; ++i) {
					for (int j = 0; j < m; ++j) {
						if (i + 1 < n && used[i][j] && used[i + 1][j]) {
							++tmp;
						}
						if (j + 1 < m && used[i][j] && used[i][j + 1]) {
							++tmp;
						}
					}
				}
				res = Math.min(tmp, res);
			}
		} else {
			if (y + 1 == m) {
				f(x + 1, 0, left);
			} else {
				f(x, y + 1, left);
			}
			if (left > 0) {
				used[x][y] = true;
				if (y + 1 == m) {
					f(x + 1, 0, left - 1);
				} else {
					f(x, y + 1, left - 1);
				}
				used[x][y] = false;
			}
		}
	}
	
	static int nextInt() throws IOException {
		return Integer.parseInt(next());
	}

	static long nextLong() throws IOException {
		return Long.parseLong(next());
	}

	static double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}

	static BigInteger nextBigInteger() throws IOException {
		return new BigInteger(next());
	}
	
	static String next() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine());
		}
		return tok.nextToken();
	}
	
	static String nextLine() throws IOException {
		tok = new StringTokenizer("");
		return in.readLine();
	}

	static boolean hasNext() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			String s = in.readLine();
			if (s == null) {
				return false;
			}
			tok = new StringTokenizer(s);
		}
		return true;
	}
	
	public static void main(String args[]) {
		new Thread(null, new Main(), "Main", 1 << 28).start();
	}
	
	public void run() {
		try {
			//in = new BufferedReader(new InputStreamReader(System.in));
			//out = new PrintWriter(new OutputStreamWriter(System.out));
			in = new BufferedReader(new FileReader("input.in"));
			out = new PrintWriter(new FileWriter("output.out"));
			Locale.setDefault(Locale.US);
			solve();
			in.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			java.lang.System.exit(1);
		}
	}
}