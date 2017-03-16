import java.io.FileInputStream;
import java.util.InputMismatchException;
import java.io.InputStream;
import java.io.FilenameFilter;
import java.util.Locale;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.FileOutputStream;
import java.io.File;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		InputStream inputStream;
		try {
			final String regex = "A-(small|large).*[.]in";
			File directory = new File(".");
			File[] candidates = directory.listFiles(new FilenameFilter() {
				public boolean accept(File dir, String name) {
					return name.matches(regex);
				}
			});
			File toRun = null;
			for (File candidate : candidates) {
				if (toRun == null || candidate.lastModified() > toRun.lastModified())
					toRun = candidate;
			}
			inputStream = new FileInputStream(toRun);
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("a.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskA solver = new TaskA();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskA {
	public void solve(int testNumber, InputReader in, PrintWriter out) {
		int n = in.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
		}

		int res1 = 0;
		int rate = 0;

		for (int i = 0; i + 1 < n; i++) {
			res1 += Math.max(0, a[i] - a[i + 1]);
			rate = Math.max(rate, Math.max(0, a[i] - a[i + 1]));
		}

		int res2 = 0;
		for (int i = 0; i + 1 < n; i++) {
			res2 += Math.min(rate, a[i]);
		}

		out.printf("Case #%d: %d %d\n", testNumber, res1, res2);
	}
}

class InputReader {
	final InputStream is;
	final byte[] buf = new byte[1024];
	int pos;
	int size;

	public InputReader(InputStream is) {
		this.is = is;
	}

	public int nextInt() {
		int c = read();
		while (isWhitespace(c))
			c = read();
		int sign = 1;
		if (c == '-') {
			sign = -1;
			c = read();
		}
		int res = 0;
		do {
			if (c < '0' || c > '9')
				throw new InputMismatchException();
			res = res * 10 + c - '0';
			c = read();
		} while (!isWhitespace(c));
		return res * sign;
	}

	public String next() {
		int c = read();
		while (isWhitespace(c))
			c = read();
		StringBuilder sb = new StringBuilder();
		do {
			sb.append((char) c);
			c = read();
		} while (!isWhitespace(c));
		return sb.toString();
	}

	int read() {
		if (size == -1)
			throw new InputMismatchException();
		if (pos >= size) {
			pos = 0;
			try {
				size = is.read(buf);
			} catch (IOException e) {
				throw new InputMismatchException();
			}
			if (size <= 0)
				return -1;
		}
		return buf[pos++] & 255;
	}

	static boolean isWhitespace(int c) {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}

}

