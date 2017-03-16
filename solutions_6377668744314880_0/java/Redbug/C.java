import static java.lang.Integer.*;
import static java.lang.Math.*;

import java.util.*;

public class C {

	public Object solve() {
		int N = sc.nextInt();
		Point [] P = new Point[N];
		for (int i : rep(N))
			P[i] = new Point(sc.nextLong(), sc.nextLong());

		//System.err.println(Arrays.toString(P));
		int [] res = new int [N];

		int Z = 1 << N;
		@SuppressWarnings("unchecked")
		Set<Point> W [] = new Set[Z];
		for (int m : rep(Z)) {
			int K = bitCount(m);
			Point [] Q = new Point[K]; int k = 0;
			for (int j : rep(N))
				if (has(m, j))
					Q[k++] = P[j];

			Jarvis J = new Jarvis();
			//System.err.println(Arrays.toString(Q));
			W[m] = J.convexHull(Q);
		}

		//System.err.println("OK");
		for (int i : rep(N)) {
			res[i] = N;
			for (int m : rep(1 << N)) {
				int K = bitCount(m);
				if (W[m].contains(P[i]))
					res[i] = min(res[i], N-K);
			}
		}

		return println(res);
	}

	/** Class point **/
	class Point implements Comparable<Point>
	{
		final long x, y;
		Point(long x, long y) {
			this.x = x;
			this.y = y;
		}
		public String toString() {
			return Arrays.toString(new long [] { x, y });
		}
		@Override
		public int compareTo(Point o) {
			if (x != o.x)
				return Long.signum(x - o.x);
			else
				return Long.signum(y - o.y);

		}
	}

	/** Class Jarvis **/
	class Jarvis
	{
		private boolean CCW(Point p, Point q, Point r)
		{
			long val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

			if (val >= 0)
				return false;
			return true;
		}
		public Set<Point> convexHull(Point[] points)
		{
			Arrays.sort(points);
			int n = points.length;
			/** if less than 3 points return **/
			if (n < 3) {
				Set<Point> res = new HashSet<>();
				for (int i : rep(n))
					res.add(points[i]);
				return res;
			}
			int[] next = new int[n];
			Arrays.fill(next, -1);

			/** find the leftmost point **/
			int leftMost = 0;
			for (int i = 1; i < n; i++)
				if (points[i].x < points[leftMost].x)
					leftMost = i;
			int p = leftMost, q;
			/** iterate till p becomes leftMost **/
			do
			{
				/** wrapping **/
				q = (p + 1) % n;
				for (int i = 0; i < n; i++)
					if (CCW(points[p], points[i], points[q]))
						q = i;

				next[p] = q;
				p = q;
			} while (p != leftMost);

			/** Display result **/
			//display(points, next);
			List<Integer> H = new ArrayList<>();
			for (int i = 0; i < n; ++i)
				if (next[i] != -1)
					H.add(i);

			List<Integer> J = new ArrayList<>();
			for (int i : H) {
				int j = next[i];
				for (int k = 0; k < n; ++k)
					if (next[k] == -1) {
						Point p0 = points[i], p1 = points[j], z = points[k];
						long D = (z.y - p0.y)*(z.x - p1.x) - (z.y - p1.y)*(z.x - p0.x);
						if (D == 0)
							J.add(k);
					}
			}

			for (int j : J)
				H.add(j);

			Set<Point> res = new HashSet<>();
			for (int h : H)
				res.add(points[h]);
			return res;
		}
	}

	private static long and (long x, int i) { return (x & bit(i)); }
	private static long bit (int i) { return (1L << i); }
	private static boolean has(long x, int i) { return and(x, i) != 0; }
	private static int [] rep(int N) { return rep(0, N); }
	private static int [] rep(int S, int T) { if (T <= S) return new int [0]; int [] res = new int [T-S]; for (int i = S; i < T; ++i) res[i-S] = i; return res; }
	////////////////////////////////////////////////////////////////////////////////////
	private static IOUtils.MyScanner sc = new IOUtils.MyScanner();
	private static Object println(Object o) { return IOUtils.println(o); }
	private static class IOUtils {
		public static class MyScanner {
			public int nextInt() { return sc.nextInt(); }
			public long nextLong() { return sc.nextLong(); }
			private final java.util.Scanner sc;
			private MyScanner() {
				sc = new java.util.Scanner(System.in);
				sc.hasNext();
				start();
			}
		}
		private static class MyWriter extends java.io.PrintWriter {
			public MyWriter lnprint(Object o, Object ...a) { println(); print(IOUtils.build(o, a)); return this; }
			public String toString() { return out.toString(); }
			public MyWriter() { super(new java.io.StringWriter()); }
		}
		private static String build(Object o, Object... a) { return buildDelim(" ", o, a); }
		private static String buildDelim(String delim, Object o, Object... a) {
			StringBuilder b = new StringBuilder();
			append(b, o, delim);
			for (Object p : a)
				append(b, p, delim);
			return b.substring(delim.length());
		}
		private static MyWriter println(Object o) {
			MyWriter res = new MyWriter();
			if (o.getClass().isArray()) {
				int len = java.lang.reflect.Array.getLength(o);
				for (int i = 0; i < len; ++i)
					res.lnprint(java.lang.reflect.Array.get(o, i));
			} else if (o instanceof Iterable<?>)
				for (Object p : (Iterable<?>) o)
					res.lnprint(p);
			else
				res.lnprint(o);
			return res;
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
				print("Case #" + n + ": " + build(new C().solve()));
			err("------------------");
			err(time());
		}
	}
	public static void main(String[] args) {
		int N = sc.nextInt();
		IOUtils.run(N);
	}
}
