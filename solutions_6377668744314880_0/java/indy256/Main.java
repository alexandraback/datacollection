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
			final String regex = "C-(small|large).*[.]in";
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
			outputStream = new FileOutputStream("c.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskC solver = new TaskC();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskC {
	public void solve(int testNumber, InputReader in, PrintWriter out) {
		int n = in.nextInt();
		int[] x = new int[n];
		int[] y = new int[n];
		for (int i = 0; i < n; i++) {
			x[i] = in.nextInt();
			y[i] = in.nextInt();
		}

		out.printf("Case #%d:\n", testNumber);

		for (int i = 0; i < n; i++) {
			int cnt = 0;
			for (int j = 0; j < n; j++) {
				if (i == j) continue;
				int x1 = x[j] - x[i];
				int y1 = y[j] - y[i];
				int cnt1 = 0;
				int cnt2 = 0;
				for (int k = 0; k < n; k++) {
					int x2 = x[k] - x[i];
					int y2 = y[k] - y[i];
					long cross = (long) x1 * y2 - (long) x2 * y1;
					if (cross <= 0) ++cnt1;
					if (cross >= 0) ++cnt2;
				}
				cnt = Math.max(cnt, Math.max(cnt1, cnt2));
			}

			out.printf("%d\n", n == 1 ? 0 : n - cnt);
		}
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

