import java.io.IOException;
import java.util.Locale;
import java.util.InputMismatchException;
import java.io.FileOutputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FilenameFilter;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Vaibhav Mittal
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
        int n = in.readInt();
        String[] s = new String[n];
        for (int i = 0; i < n; ++i)
            s[i] = in.readString();

        String[] t = new String[n];
        for (int i = 0; i < n; ++i)
            t[i] = compress(s[i]);

        out.print("Case #" + testNumber + ": ");
        if (allEqual(t)) {
            int res = 0;
            int[] index = new int[n];
            for (char c : t[0].toCharArray()) {
                int[] cnt = new int[n];
                for (int i = 0; i < n; ++i)
                    for (; index[i] < s[i].length() && s[i].charAt(index[i]) == c; ++cnt[i], ++index[i]);
                res += findMin(n, cnt);
            }
            out.println(res);
        }
        else {
            out.println("Fegla Won");
        }
    }

    private String compress(String s) {
        String t = "";
        for (int i = 0, j; i < s.length(); i = j) {
            t += s.charAt(i);
            for (j = i; j < s.length() && s.charAt(i) == s.charAt(j); ++j);
        }
        return t;
    }

    private boolean allEqual(String[] s) {
        for (int i = 0; i < s.length; ++i)
            if (s[0].compareTo(s[i]) != 0)
                return false;
        return true;
    }

    private int findMin(int n, int[] cnt) {
        int res = Integer.MAX_VALUE;
        for (int l = 1; l <= 100; ++l) {
            int cur = 0;
            for (int c : cnt)
                cur += Math.abs(c - l);
            if (cur < res)
                res = cur;
        }
        return res;
    }
}

class InputReader {
    private InputStream stream;
    private byte[] buffer = new byte[1024];
    private int curChar;
    private int numChars;

    public InputReader(InputStream stream) {
        this.stream = stream;
    }

    private int read() {
        if (numChars == -1)
            throw new InputMismatchException();
        if (curChar >= numChars) {
            curChar = 0;
            try {
                numChars = stream.read(buffer);
            } catch (IOException e) {
                throw new InputMismatchException();
            }
            if (numChars <= 0)
                return -1;
        }
        return buffer[curChar++];
    }

    public int readInt() {
        int c = read();
        while (isWhiteSpace(c))
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
            res *= 10;
            res += c - '0';
            c = read();
        } while (!isWhiteSpace(c));
        return res * sign;
    }

    public String readString() {
        int c = read();
        while (isWhiteSpace(c))
            c = read();
        StringBuilder res = new StringBuilder();
        do {
            res.appendCodePoint(c);
            c = read();
        } while (!isWhiteSpace(c));
        return res.toString();
    }

    public String next() {
        return readString();
    }

    private boolean isWhiteSpace(int c) {
        return c == ' ' || c == '\n' || c == '\t' || c == '\r' || c == -1;
    }
}

