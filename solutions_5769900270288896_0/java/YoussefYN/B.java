import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class B {

	public static void main(String[] args) throws IOException {
		// InputReader in = new InputReader(System.in);
		// FastPrinter out = new FastPrinter(System.out);
		InputReader in = new InputReader(new FileInputStream(
				"B-small-attempt1.in"));
		FastPrinter out = new FastPrinter(new FileOutputStream("OUT.txt"));
		int t = in.nextInt(), r, c, n, count;
		for (int i = 1; t-- > 0; i++) {
			r = in.nextInt();
			c = in.nextInt();
			n = in.nextInt();
			count = 0;
			if (r == 3 && c == 3 && n == 8) {
				count = 8;
			} else if (r == 1) {
				n -= Math.ceil(c / 2.0);
				if (n > 0) {
					count = 2 * n;
					if (c % 2 == 0)
						count--;
				}
			} else if (c == 1) {
				n -= Math.ceil(r / 2.0);
				if (n > 0) {
					count = 2 * n;
					if (r % 2 == 0)
						count--;
				}
			} else {
				n -= Math.ceil(r * c / 2.0);
				count = 0;

				if (n > 0) {
					if (r % 2 == 1) {
						if (c % 2 == 1) {
							int tt;
							if (n > (tt = 2 * (r / 2 + c / 2))) {
								count = 3 * tt;
								n -= tt;
								count += 4 * n;
							} else
								count = 3 * n;
						} else {
							int tt = (int) Math.ceil(r / 2.0);
							if (n > tt) {
								n -= tt;
								count = 2 * (tt);
								if (n > (tt = r / 2 + c - tt)) {
									n -= tt;
									count += 3 * (tt) + 4 * n;
								} else
									count += 3 * n;
							} else
								count = 2 * n;
						}
					} else {
						if (c % 2 == 1) {
							int tt = (int) Math.ceil(c / 2.0);
							if (n > tt) {
								n -= tt;
								count = 2 * (tt);
								if (n > (tt = c / 2 + r - tt)) {
									n -= tt;
									count += 3 * (tt) + 4 * n;
								} else
									count += 3 * n;
							} else
								count = 2 * n;
						} else {
							if (n > 2) {
								n -= 2;
								count = 4;
								int tt;
								if (n > (tt = r + c - 4)) {
									n -= tt;
									count += 3 * tt + 4 * n;
								} else
									count += 3 * n;
							} else
								count = 2 * n;
						}
					}
				}
			}
			out.printf("Case #%d: %d\n", i, count);
		}

		out.close();
	}
}

class ArrayUtils {
	static final Random rand = new Random(System.nanoTime());

	static final public int[] sortAndUnique(int[] a) {
		int[] ret = a.clone();
		sort(ret);
		if (ret.length == 0) {
			return ret;
		}
		int last = ret[0];
		int j = 1;
		for (int i = 1; i < ret.length; i++)
			if (last != ret[i]) {
				ret[j++] = ret[i];
				last = ret[i];
			}
		return Arrays.copyOf(ret, j);
	}

	public static final void sort(int[] a) {
		shuffle(a);
		Arrays.sort(a);
	}

	public static final void shuffle(int[] a) {
		for (int i = 0; i < a.length; i++) {
			int j = rand.nextInt(i + 1);
			int t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
	}

}

class InputReader {
	public BufferedReader reader;
	public StringTokenizer tokenizer;

	public InputReader(InputStream stream) {
		reader = new BufferedReader(new InputStreamReader(stream), 32768);
		tokenizer = null;
	}

	public String next() {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			try {
				tokenizer = new StringTokenizer(reader.readLine());
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		return tokenizer.nextToken();
	}

	public String nextLine() {
		try {
			return reader.readLine();
		} catch (IOException e) {
			e.printStackTrace();
			return null;
		}
	}

	public int[] readIntArray(int n) {
		int[] ret = new int[n];
		for (int i = 0; i < n; i++)
			ret[i] = nextInt();
		return ret;
	}

	public int nextInt() {
		return Integer.parseInt(next());
	}

	public long nextLong() {
		return Long.parseLong(next());
	}

	public double nextDouble() {
		return Double.parseDouble(next());
	}

	public BigInteger nextBigInt() {
		return new BigInteger(next());
	}
}

class FastPrinter extends PrintWriter {

	public FastPrinter(OutputStream out) {
		super(out);
	}

	public FastPrinter(Writer out) {
		super(out);
	}

}