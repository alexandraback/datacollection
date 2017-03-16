import java.io.*;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Locale;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Sanchit M. Bhatnagar (sanchit.m.bhatnagar@gmail.com)
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
    out.print("Case #" + testNumber + ": ");
    int N = in.readInt();
    String[] input = new String[N];
    int min = Integer.MAX_VALUE;
    int max = Integer.MIN_VALUE;
    int minIdx = -1;
    int maxIdx = -1;
    for (int i = 0; i < N; i++) {
      input[i] = in.readString();
      if (input[i].length() < min) {
        min = input[i].length();
        minIdx = i;
      }
      if (input[i].length() > max) {
        max = input[i].length();
        maxIdx = i;
      }
    }
    StringBuilder regex = new StringBuilder();
    char last = input[0].charAt(0);
    regex.append(last + "+");
    for (int i = 1; i < input[0].length(); i++) {
      if (input[0].charAt(i) == last)
        continue;
      else {
        last = input[0].charAt(i);
        regex.append(last + "+");
      }
    }
    Pattern p = Pattern.compile(regex.toString());
    boolean bad = false;
    for (int i = 0; !bad && i < N; i++) {
      Matcher matcher = p.matcher(input[i]);
      if (!matcher.matches()) {
        bad = true;
      }
    }
    if (bad) {
      out.println("Fegla Won");
    } else {
      String[] newInput = new String[N];
      for (int i = 0; i < N; i++) {
        StringBuilder sb = new StringBuilder();
        char[] tmpInput = input[i].toCharArray();
        char lastC = tmpInput[0];
        int count = 0;
        for (int j = 0; j < tmpInput.length; j++) {
          if (lastC == tmpInput[j])
            count++;
          else {
            sb.append(lastC + "" + count);
            count = 1;
            lastC = tmpInput[j];
          }
        }
        sb.append(lastC + "" + count);
        newInput[i] = sb.toString();
      }
      int ans = 0;
      int[] list = new int[N];
      String[][] newnew = new String[N][];
      for (int i = 0; i < newnew.length; i++) {
        newnew[i] = newInput[i].split("[a-zA-Z]");
        System.err.println(Arrays.toString(newnew[i]));
      }
      for (int j = 1; j < newnew[0].length; j++) {
        for (int i = 0; i < N; i++) {
          list[i] = Integer.parseInt(newnew[i][j]);
        }
        min = Integer.MAX_VALUE;
        for (int i = 0; i < list.length; i++) {
          int tmin = 0;
          for (int k = 0; k < list.length; k++) {
            tmin += Math.abs(list[i] - list[k]);
          }
          min = Math.min(min, tmin);
        }
        ans += min;
      }
      out.println(ans);
    }
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

  public void println(Object...objects) {
		print(objects);
		writer.println();
	}

  public void close() {
		writer.close();
	}

  public void println(int i) {
		writer.println(i);
	}
}

