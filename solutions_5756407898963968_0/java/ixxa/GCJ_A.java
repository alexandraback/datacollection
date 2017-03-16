import java.io.*;
import java.math.*;
import java.util.*;

public class GCJ_A {

	public static void main(String[] args) throws Exception {
		new GCJ_A().solve();
		// new FileInputStream(new File("input.txt")),
		// new PrintStream(new FileOutputStream(new File("output.txt"))));
	}

	void solve() throws IOException {
		PrintStream out = new PrintStream(new FileOutputStream(new File("output.txt")));
		FastScanner sc = new FastScanner(new FileInputStream("A-small-attempt0.in"));

		int T = sc.nextInt();

		for (int test = 0; test < T; test++) {
			int mask1 = 0;
			int r1 = sc.nextInt() - 1;
			for (int i = 0; i < 4; i++) {
				for (int jj = 0; jj < 4; jj++) {
					int a = sc.nextInt();
					if (i == r1) {
						mask1 |= 1 << a;
					}
				}
			}
			int mask2 = 0;
			int r2 = sc.nextInt() - 1;
			for (int i = 0; i < 4; i++) {
				for (int jj = 0; jj < 4; jj++) {
					int a = sc.nextInt();
					if (i == r2) {
						mask2 |= 1 << a;
					}
				}
			}

			int mask = mask1 & mask2;

			out.print("Case #" + (test + 1) + ": ");
			if (mask == 0) {
				out.println("Volunteer cheated!");
			} else if (Integer.bitCount(mask) == 1) {
				for (int bi = 1;; bi++) {
					if ((mask >> bi & 1) == 1) {
						out.println(bi);
						break;
					}
				}


			} else {
				out.println("Bad magician!");
			}
		}
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
