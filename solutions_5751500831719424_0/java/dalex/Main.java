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
    static class LetterSequence {
        char letter;
        int count;

        LetterSequence(char letter, int count) {
            this.letter = letter;
            this.count = count;
        }

        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            LetterSequence that = (LetterSequence) o;

            if (count != that.count) return false;
            if (letter != that.letter) return false;

            return true;
        }

        public int hashCode() {
            int result = (int) letter;
            result = 31 * result + count;
            return result;
        }
    }

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        out.print("Case #" + testNumber + ": ");
        int n = in.readInt();
        String[] a = new String[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.readString();
        }
        List<LetterSequence>[] letters = new List[n];
        for (int i = 0; i < n; i++) {
            letters[i] = process(a[i]);
        }
        for (int i = 0; i < n; i++) {
            if (letters[i].size() != letters[0].size()) {
                out.printLine("Fegla Won");
                return;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < letters[0].size(); j++) {
                if (letters[i].get(j).letter != letters[0].get(j).letter) {
                    out.printLine("Fegla Won");
                    return;
                }
            }
        }
        int result = 0;
        for (int p = 0; p < letters[0].size(); p++) {
            int best = Integer.MAX_VALUE;
            for (int need = 1; need <= 100; need++) {
                int curRes = 0;
                for (int i = 0; i < n; i++) {
                    int have = letters[i].get(p).count;
                    curRes += Math.abs(have - need);
                }
                best = Math.min(best, curRes);
            }
            result += best;
        }
        out.printLine(result);
    }

    private List<LetterSequence> process(String s) {
        List<LetterSequence> result = new ArrayList<LetterSequence>();
        for (int i = 0; i < s.length(); ) {
            char letter = s.charAt(i);
            int j = i;
            while (j < s.length() && s.charAt(j) == letter) {
                j++;
            }
            result.add(new LetterSequence(letter, j - i));
            i = j;
        }
        return result;
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

    public void print(Object...objects) {
		for (int i = 0; i < objects.length; i++) {
			if (i != 0)
				writer.print(' ');
			writer.print(objects[i]);
		}
	}

    public void printLine(Object...objects) {
		print(objects);
		writer.println();
	}

    public void close() {
		writer.close();
	}

    public void printLine(int i) {
		writer.println(i);
	}
}

