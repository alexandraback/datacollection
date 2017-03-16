import java.io.*;
import java.util.*;
import java.math.*;


public class Main {
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	
	static void solve() throws Exception {		
		int t = nextInt();
		for (int tt = 1; tt <= t; tt++) {
			int[] cnt = new int[17];
			for (int k = 0; k < 2; k++) {
				int row = nextInt();
				for (int i = 1; i <= 4; i++) {
					for (int j = 1; j <= 4; j++) {
						int v = nextInt();
						if (i == row) {
							cnt[v]++;
						}
					}
				}
			}
			int res = 0;
			for (int i = 1; i <= 16; i++) {
				if (cnt[i] == 2) {
					if (res == 0) {
						res = i;
					} else {
						res = -1;
						break;
					}
				}
			}
			out.print("Case #" + tt + ": ");
			if (res == -1) {
				out.println("Bad magician!");
			} else if (res == 0) {
				out.println("Volunteer cheated!");
			} else {
				out.println(res);
			}
		}
	}

	static int sqr(int x) {
		return x*x;
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
		try {
			//in = new BufferedReader(new InputStreamReader(System.in));
			//out = new PrintWriter(new OutputStreamWriter(System.out));
			in = new BufferedReader(new FileReader("1.in"));
			out = new PrintWriter(new FileWriter("1.out"));
			solve();
			in.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			java.lang.System.exit(1);
		}
	}
}