import java.io.*;
import java.util.*;
import java.math.*;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author coderbd
 */
public class Main {
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		InputStream inputStream;
		try {
			final String regex = "B-(small|large).*[.]in";
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
			outputStream = new FileOutputStream("b.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		TaskB solver = new TaskB();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskB {
    
    private int r;
    private int c;
    private int n;
    private boolean[][] map;
    
    private int getID(int row, int col) {
        return row * c + col;
    }

    private int getUnhappiness(int mask) {
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                map[i][j] = (mask >> getID(i, j) & 1) == 1;
        int unhappiness = 0;
        for (int i = 1; i < r; i++)
            for (int j = 0; j < c; j++)
                if (map[i-1][j] && map[i][j])
                    unhappiness++;
        for (int i = 0; i < r; i++)
            for (int j = 1; j < c; j++)
                if (map[i][j-1] && map[i][j])
                    unhappiness++;
        return unhappiness;
    }
    
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        r = in.readInt();
        c = in.readInt();
        n = in.readInt();
        map = new boolean[r][c];
        int rc = r * c;
        int bitmask = 1 << rc;
        int ans = Integer.MAX_VALUE;
        for (int mask = 0; mask < bitmask; mask++)
            if (Integer.bitCount(mask) == n)
                ans = Math.min(ans, getUnhappiness(mask));
        out.printLine("Case #" + testNumber + ": " + ans);
    }
    
}

class InputReader {

    private InputStream stream;
    private byte[] buf = new byte[1024];
    private int curChar;
    private int numChars;

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
            }
            catch (IOException e) {
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
        StringBuffer res = new StringBuffer();
        do {
            res.appendCodePoint(c);
            c = read();
        } while (!isSpaceChar(c));
        return res.toString();
    }

    public static boolean isSpaceChar(int c) {
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }

    public String next() {
        return readString();
    }

}

class OutputWriter {

    private final PrintWriter writer;

    public OutputWriter(OutputStream outputStream) {
        writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
    }

    public void print(Object... objects) {
        for (int i = 0; i < objects.length; i++) {
            if (i != 0)
                writer.print(' ');
            writer.print(objects[i]);
        }
    }

    public void printLine(Object... objects) {
        print(objects);
        writer.println();
    }

    public void close() {
        writer.close();
    }

}
