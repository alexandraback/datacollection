import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.Locale;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.File;
import java.io.Writer;
import java.io.FilenameFilter;
import java.util.List;
import java.io.IOException;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.io.FileOutputStream;
import java.io.FileInputStream;
import java.util.NoSuchElementException;
import java.math.BigInteger;
import java.io.InputStream;

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
		OutputWriter out = new OutputWriter(outputStream);
		TaskA solver = new TaskA();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskA {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.readInt();
        String[] a = new String[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.next();
        }
        List<List<Pair<Character, Integer>>> l = new ArrayList<List<Pair<Character, Integer>>>();
        for (int i = 0; i < n; i++) {
            l.add(ctr(a[i]));
        }

//        for (List<Pair<Character, Integer>> pairs : l) {
//            out.printLine(pairs);
//        }

        int m = l.get(0).size();
        int[] mi = new int[m];
        int[] ma = new int[m];

        for (int i = 0; i < n; i++) {
            if (l.get(i).size() != l.get(0).size()) {
                out.printFormat("Case #%d: Fegla Won\n", testNumber);
                return;
            }
            for (int j = 0; j < m; j++) {
                if (l.get(i).get(j).first != l.get(0).get(j).first) {
                    out.printFormat("Case #%d: Fegla Won\n", testNumber);
                    return;
                }

                mi[j] = Math.min(l.get(i).get(j).second, i == 0 ? Integer.MAX_VALUE : mi[j]);
                ma[j] = Math.max(l.get(i).get(j).second, i == 0 ? 0 : ma[j]);
            }

        }

        int[] ans = new int[m];

        for (int j = 0; j < m; j++) {
            for (int k = mi[j]; k <= ma[j]; k++) {
                int cur = 0;
                for (List<Pair<Character, Integer>> pairs : l) {
                    cur += Math.abs(pairs.get(j).second - k);
                }
                if (k == mi[j])
                    ans[j] = cur;
                else ans[j] = Math.min(ans[j], cur);

            }
        }
//        out.printLine(ans);

        int res = 0;
        for (int an : ans) {
            res += an;
        }
        out.printFormat("Case #%d: %d\n", testNumber, res);
    }

    List<Pair<Character, Integer>> ctr(String s) {
        List<Pair<Character, Integer>> ans = new ArrayList<Pair<Character, Integer>>();
        int cur = 1;
        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i) == s.charAt(i - 1)) ++cur;
            else {
                ans.add(Pair.makePair(s.charAt(i - 1), cur));
                cur = 1;
            }
        }

        ans.add(Pair.makePair(s.charAt(s.length() - 1), cur));

        return ans;
    }
}

class InputReader {

    private InputStream stream;
	private byte[] buf = new byte[1024];
	private int curChar;
	private int numChars;
	private SpaceCharFilter filter;

	public InputReader(InputStream stream) {
		this.stream = stream;
	}

	public int read() {
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

    public int readInt() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = read();
		}
		int res = 0;
		do {
			if (c < '0' || c > '9')
				throw new InputMismatchException();
			res *= 10;
			res += c - '0';
			c = read();
		} while (!isSpaceChar(c));
		return res * sgn;
	}

    public String readString() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		StringBuilder res = new StringBuilder();
		do {
			if (Character.isValidCodePoint(c))
				res.appendCodePoint(c);
			c = read();
		} while (!isSpaceChar(c));
		return res.toString();
	}

	public boolean isSpaceChar(int c) {
		if (filter != null)
			return filter.isSpaceChar(c);
		return isWhitespace(c);
	}

	public static boolean isWhitespace(int c) {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}

    public String next() {
		return readString();
	}

    public interface SpaceCharFilter {
		public boolean isSpaceChar(int ch);
	}
}

class OutputWriter {
	private final PrintWriter writer;

	public OutputWriter(OutputStream outputStream) {
		writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
	}

	public OutputWriter(Writer writer) {
		this.writer = new PrintWriter(writer);
	}

    public void printFormat(String format, Object...objects) {
		writer.printf(format, objects);
	}

	public void close() {
		writer.close();
	}

}

class Pair<U, V> implements Comparable<Pair<U, V>> {
	public final U first;
	public final V second;

	public static<U, V> Pair<U, V> makePair(U first, V second) {
		return new Pair<U, V>(first, second);
	}

	private Pair(U first, V second) {
		this.first = first;
		this.second = second;
	}

	public boolean equals(Object o) {
		if (this == o) return true;
		if (o == null || getClass() != o.getClass()) return false;

		Pair pair = (Pair) o;

		return !(first != null ? !first.equals(pair.first) : pair.first != null) && !(second != null ? !second.equals(pair.second) : pair.second != null);

	}

	public int hashCode() {
		int result = first != null ? first.hashCode() : 0;
		result = 31 * result + (second != null ? second.hashCode() : 0);
		return result;
	}

    public String toString() {
		return "(" + first + "," + second + ")";
	}

	public int compareTo(Pair<U, V> o) {
		int value = ((Comparable<U>)first).compareTo(o.first);
		if (value != 0)
			return value;
		return ((Comparable<V>)second).compareTo(o.second);
	}
}

