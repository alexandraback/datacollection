
public class B {

	long [] T;

	public Object solve() {
		int B = sc.nextInt();
		long N = sc.nextLong();
		T = sc.nextLongs();

		if (N <= B)
			return B;

		long P = 0, Q = LINF, m;
		while (Q - P > 1) {
			m = (P + Q) / 2;
			if (eval(m) >= N)
				Q = m;
			else
				P = m;
		}

		long Z = eval(P);
		long D = N - Z;
		for (int i : rep(B))
			if (Q % T[i] == 0) {
				--D;
				if (D == 0)
					return i+1;
			}

		throw new Error();
	}

	long eval(long m) {
		int B = T.length;
		long res = B;
		for (int i : rep(B))
			res += m / T[i];
		return res;
	}

	private static final long LINF = (long) 2e14;
	private static int [] rep(int N) { return rep(0, N); }
	private static int [] rep(int S, int T) { if (T <= S) return new int [0]; int [] res = new int [T-S]; for (int i = S; i < T; ++i) res[i-S] = i; return res; }
	////////////////////////////////////////////////////////////////////////////////////
	private static IOUtils.MyScanner sc = new IOUtils.MyScanner();
	private static class IOUtils {
		public static class MyScanner {
			public int nextInt() { return sc.nextInt(); }
			public long nextLong() { return sc.nextLong(); }
			public String nextLine() {
				String line = sc.nextLine().trim();
				if ("".equals(line)) // If at end of line, read next line
					line = sc.nextLine();
				return line;
			}
			public String[] nextStrings() {return nextLine().split(" "); }
			public long[] nextLongs() {
				String[] L = nextStrings();
				long[] res = new long[L.length];
				for (int i = 0; i < L.length; ++i)
					res[i] = Long.parseLong(L[i]);
				return res;
			}
			private final java.util.Scanner sc;
			private MyScanner() {
				sc = new java.util.Scanner(System.in);
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
					o = new java.text.DecimalFormat("#.#########").format(o);
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
				print("Case #" + n + ": " + build(new B().solve()));
			err("------------------");
			err(time());
		}
	}
	public static void main(String[] args) {
		int N = sc.nextInt();
		IOUtils.run(N);
	}
}
