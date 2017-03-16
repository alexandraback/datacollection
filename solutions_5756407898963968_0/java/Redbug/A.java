package contest;

import java.text.*;
import java.util.*;

public class A {

	public Object solve() {
		int a = sc.nextInt() - 1;
		int [][] A = sc.nextInts(4);
		int b = sc.nextInt() - 1;
		int [][] B = sc.nextInts(4);

		int [] V = new int [17];
		for (int j : rep(4))
			++V[A[a][j]];
		for (int j : rep(4))
			++V[B[b][j]];

		int C = 0, res = -1;
		for (int c : req(16))
			if (V[c] == 2) {
				++C; res = c;
			}

		if (C == 1)
			return res;

		for (int x : A[a])
			for (int y : B[b])
				if (x == y)
					return "Bad magician!";

		return "Volunteer cheated!";
	}

	private static int [] rep(int N) { return rep(0, N); }
	private static int [] rep(int S, int T) { if (T <= S) return new int [0]; int [] res = new int [T-S]; for (int i = S; i < T; ++i) res[i-S] = i; return res; }
	private static int [] req(int N) { return req(0, N); }
	private static int [] req(int S, int T) { return rep(S, T+1); }
	////////////////////////////////////////////////////////////////////////////////////
	private static IOUtils.MyScanner sc = new IOUtils.MyScanner();
	private static class IOUtils {
		public static class MyScanner {
			public int nextInt() { return sc.nextInt(); }
			public String nextLine() {
				String line = sc.nextLine().trim();
				if ("".equals(line)) // If at end of line, read next line
					line = sc.nextLine();
				return line;
			}
			public String[] nextStrings() {return nextLine().split(" "); }
			public int[] nextInts() {
				String[] L = nextStrings();
				int[] res = new int[L.length];
				for (int i = 0; i < L.length; ++i)
					res[i] = Integer.parseInt(L[i]);
				return res;
			}
			public int[][] nextInts(int N) {
				int[][] res = new int[N][];
				for (int i = 0; i < N; ++i)
					res[i] = nextInts();
				return res;
			}
			private final Scanner sc;
			private MyScanner() {
				sc = new Scanner(System.in);
				sc.hasNext();
				start();
			}
		}
		private static String build(Object o, Object... a) { return buildDelim(" ", o, a); }
		private static String buildDelim(String delim, Object o, Object... a) {
			StringBuilder b = new StringBuilder();
			append(b, o, delim);
			for (Object p : a)
				append(b, p, delim);
			return b.substring(delim.length());
		}
		//////////////////////////////////////////////////////////////////////////////////
		private static void start() { if (t == 0) t = millis(); }
		private static void append(StringBuilder b, Object o, String delim) {
			if (o.getClass().isArray()) {
				int len = java.lang.reflect.Array.getLength(o);
				for (int i = 0; i < len; ++i)
					append(b, java.lang.reflect.Array.get(o, i), delim);
			} else if (o instanceof Iterable<?>)
				for (Object p : (Iterable<?>) o)
					append(b, p, delim);
			else {
				if (o instanceof Double)
					o = new DecimalFormat("#.#########").format(o);
				b.append(delim).append(o);
			}
		}
		private static void print(Object o) {
			err(o, '(', time(), ')');
			if (PRINT)
				System.out.println(o);
		}
		private static void err(Object ...o) { System.err.println(build(o)); }
		private static long t;
		private static long millis() { return System.currentTimeMillis(); }
		private static String time() { return "Time: " + (millis() - t) / 1000.0; }
		private static final boolean PRINT = System.getProperties().containsKey("PRINT");
		private static void run(int N) {
			for (int n = 1; n <= N; ++n)
				print("Case #" + n + ": " + build(new A().solve()));
			err("------------------");
			err(time());
		}
	}
	public static void main(String[] args) {
		int N = sc.nextInt();
		IOUtils.run(N);
	}
}
