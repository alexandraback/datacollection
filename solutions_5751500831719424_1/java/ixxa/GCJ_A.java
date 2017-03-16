import java.io.*;
import java.math.*;
import java.util.*;

public class GCJ_A {

	public static void main(String[] args) throws Exception {
		new GCJ_A().solve();
		// new FileInputStream(new File("input.txt")),
		// new PrintStream(new FileOutputStream(new File("output.txt"))));
	}

	String iname = "A-large (1).in";
	String oname = "output.txt";
	// FastScanner sc;
	PrintStream out;
	void solve() throws IOException {
		// sc = new FastScanner(new FileInputStream(iname));
		out = new PrintStream(new FileOutputStream(new File(oname)));
		BufferedReader in = new BufferedReader(new FileReader(iname));

		// int T = sc.nextInt();
		int T = Integer.parseInt(in.readLine());

		for (int _t = 0; _t < T; _t++) {
			System.out.println(_t);

			int N = Integer.parseInt(in.readLine());
			int[][] count = new int[100][N];
			int K = 0;
			String s0 = null;
			boolean ok = true;
			for (int i = 0; i < N; i++) {
				String str = in.readLine();

				int kk = 0;
				String ss = "" + str.charAt(0);
				count[kk][i]++;
				for (int jj = 1; jj < str.length(); jj++) {
					if (str.charAt(jj - 1) != str.charAt(jj)) {
						kk++;
						ss += str.charAt(jj);
					}
					count[kk][i]++;
				}

				if (s0 == null || s0.compareTo(ss) == 0) {
					// ok
					s0 = ss;
				} else {
					// ng
					ok = false;
					// break;
				}
				K = kk + 1;
			}

			if (ok) {
				int ret = 0;
				for (int kk = 0; kk < K; kk++) {
					int mcost = Integer.MAX_VALUE;
					for (int c = 1; c <= 100; c++) {
						int cost = 0;
						for (int i = 0; i < N; i++) {
							cost += Math.abs(count[kk][i] - c);
						}
						mcost = Math.min(mcost, cost);
					}
					ret += mcost;
				}
				gout(_t, "" + ret);

			} else {
				gout(_t, "Fegla Won");
			}

		}
	}

	void gout(int t, String ans) {
		out.println("Case #" + (t + 1) + ": " + ans);
	}
}

class FastScanner {

	private InputStream _stream;
	private byte[] _buf = new byte[1024];
	private int _curChar;
	private int _numChars;
	private StringBuilder _sb = new StringBuilder();

	FastScanner(InputStream stream) {
		this._stream = stream;
	}

	public int read() {
		if (_numChars == -1) throw new InputMismatchException();
		if (_curChar >= _numChars) {
			_curChar = 0;
			try {
				_numChars = _stream.read(_buf);
			} catch (IOException e) {
				throw new InputMismatchException();
			}
			if (_numChars <= 0) return -1;
		}
		return _buf[_curChar++];
	}

	public String next() {
		int c = read();
		while (isWhitespace(c)) {
			c = read();
		}
		_sb.setLength(0);
		do {
			_sb.appendCodePoint(c);
			c = read();
		} while (!isWhitespace(c));
		return _sb.toString();
	}

	public int nextInt() {
		return (int) nextLong();
	}
	public long nextLong() {
		int c = read();
		while (isWhitespace(c)) {
			c = read();
		}
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = read();
		}
		long res = 0;
		do {
			if (c < '0' || c > '9') throw new InputMismatchException();
			res *= 10;
			res += c - '0';
			c = read();
		} while (!isWhitespace(c));
		return res * sgn;
	}

	public boolean isWhitespace(int c) {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}
}

//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
