import java.io.*;
import java.util.*;
import java.math.*;

/**
 * Iron Maiden - Number of the Beast.
 * 
 * @author Gorokhov Nikita (wackloner@gmail.com)
 */

public class A implements Runnable {
	
	void solve() {
		int t = nextInt();
		for (int testNumber = 1; testNumber <= t; testNumber++) {
			int n = nextInt();
			char[][] s = new char[n][];
			for (int i = 0; i < n; i++)
				s[i] = nextString().toCharArray();
			char[][] sample = new char[n][100];
			int[] len = new int[n];
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < s[i].length; j++)
					if (j == 0 || s[i][j] != s[i][j - 1])
						sample[i][len[i]++] = s[i][j];
			}
			boolean ok = true;
			for (int i = 1; i < n; i++) {
				if (len[i] != len[0]) {
					ok = false;
					break;
				}
				for (int j = 0; j < len[i]; j++)
					if (sample[i][j] != sample[0][j]) {
						ok = false;
						break;
					}
			}
			print("Case #");
			print(testNumber);
			print(": ");
			if (!ok) {
				println("Fegla Won");
				continue;
			}
			int[][] cnt = new int[n][len[0]];
			for (int i = 0; i < n; i++) {
				int cur = 0, num = 0;
				for (int j = 0; j < s[i].length; j++) {
					num++;
					if (j == s[i].length - 1 || s[i][j] != s[i][j + 1]) {
						cnt[i][cur++] = num;
						num = 0;
					}
				}
			}
			int ans = 0;
			for (int i = 0; i < len[0]; i++) {
				int best = Integer.MAX_VALUE;
				for (int j = 1; j <= 100; j++) {
					int cur = 0;
					for (int k = 0; k < n; k++)
						cur += Math.abs(j - cnt[k][i]);
					if (cur < best)
						best = cur;
					if (best < cur)
						break;
				}
				ans += best;
			}
			println(ans);
		}
	}
	
	public static void main(String[] args) throws IOException {
		new A("input.txt", "output.txt").run();
	}
	
	A() {
		this.stream = System.in;
		this.writer = new PrintWriter(System.out);
	}
	
	A(String input, String output) throws IOException {
		File inputFile = new File(input);
		inputFile.createNewFile();
		stream = new FileInputStream(inputFile);
		File outputFile = new File(output);
		outputFile.createNewFile();
		writer = new PrintWriter(outputFile);
	}
	
	public void run() {
		solve();
		writer.close();
	}
	
	void halt() {
		writer.close();
		System.exit(0);
	}
	
	PrintWriter writer;;
	
	void print(Object... objects) {
		for (int i = 0; i < objects.length; i++) {
			if (i != 0)
				writer.print(' ');
			writer.print(objects[i]);
		}
	}
	
	void println(Object... objects) {
		print(objects);
		writer.println();
	}
	
	void printArray(int[] array) {
		for (int i = 0; i < array.length; i++) {
			if (i != 0) writer.print(' ');
			writer.print(array[i]);
		}
		writer.println();
	}
	
	void printArray(long[] array) {
		for (int i = 0; i < array.length; i++) {
			if (i != 0) writer.print(' ');
			writer.print(array[i]);
		}
		writer.println();
	}
	
	void printMatrix(int[][] matrix) {
		for (int i = 0; i < matrix.length; i++)
			printArray(matrix[i]);
	}
	
	void printMatrix(long[][] matrix) {
		for (int i = 0; i < matrix.length; i++)
			printArray(matrix[i]);
	}
	
	/**
	 * Pure Egor's code is straight ahead.
	 */
	
	InputStream stream;
	byte[] buf = new byte[1024];
	int curChar, numChars;
	
	int nextInt() {
		int c = next();
		while (isWhitespace(c))
			c = next();
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = next();
		}
		int res = 0;
		do {
			if (c < '0' || c > '9')
				throw new InputMismatchException();
			res *= 10;
			res += c - '0';
			c = next();
		} while (!isWhitespace(c));
		return res * sgn;
	}
	
	long nextLong() {
		int c = next();
		while (isWhitespace(c))
			c = next();
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = next();
		}
		long res = 0;
		do {
			if (c < '0' || c > '9')
				throw new InputMismatchException();
			res *= 10;
			res += c - '0';
			c = next();
		} while (!isWhitespace(c));
		return res * sgn;
	}
	
	double nextDouble() {
		int c = next();
		while (isWhitespace(c))
			c = next();
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = next();
		}
		double res = 0;
		while (!isWhitespace(c) && c != '.') {
			if (c == 'e' || c == 'E')
				return res * Math.pow(10, nextInt());
			if (c < '0' || c > '9')
				throw new InputMismatchException();
			res *= 10;
			res += c - '0';
			c = next();
		}
		if (c == '.') {
			c = next();
			double m = 1;
			while (!isWhitespace(c)) {
				if (c == 'e' || c == 'E')
					return res * Math.pow(10, nextInt());
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				m /= 10;
				res += (c - '0') * m;
				c = next();
			}
		}
		return res * sgn;
	}
	
	BigInteger nextBigInteger() {
		try {
			return new BigInteger(nextString());
		} catch (NumberFormatException e) {
			throw new InputMismatchException();
		}
	}
	
	int next() {
		if (numChars == -1)
			throw new InputMismatchException();
		if (curChar >= numChars) {
			curChar = 0;
			try {
				numChars = stream.read(buf);
			} catch (IOException e) {
				throw new InputMismatchException();
			}
			if (numChars <= 0)
				return -1;
		}
		return buf[curChar++];
	}
	
	String nextString() {
		int c = next();
		while (isWhitespace(c))
			c = next();
		StringBuilder res = new StringBuilder();
		do {
			if (Character.isValidCodePoint(c))
				res.appendCodePoint(c);
			c = next();
		} while (!isWhitespace(c));
		return res.toString();
	}
	
	String nextLine() {
		StringBuilder buf = new StringBuilder();
		int c = next();
		while (c != '\n' && c != -1) {
			if (c != '\r')
				buf.appendCodePoint(c);
			c = next();
		}
		return buf.toString();
	}
	
	boolean EOF() {
		int value;
		while (isWhitespace(value = peek()) && value != -1)
			next();
		return value == -1;
	}
	
	int peek() {
		if (numChars == -1)
			return -1;
		if (curChar >= numChars) {
			curChar = 0;
			try {
				numChars = stream.read(buf);
			} catch (IOException e) {
				return -1;
			}
			if (numChars <= 0)
				return -1;
		}
		return buf[curChar];
	}
	
	boolean isWhitespace(int c) {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}
}