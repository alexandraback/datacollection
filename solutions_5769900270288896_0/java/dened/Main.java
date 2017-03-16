import java.io.Reader;
import java.io.FileInputStream;
import java.util.AbstractList;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.util.List;
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
 * @author Denis Nedelyaev
 */
public class Main {
	public static void main(String[] args) throws Exception {
		Locale.setDefault(Locale.US);
		InputStream inputStream;
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
		OutputStream outputStream = new FileOutputStream("b.out");
		FastScanner in = new FastScanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskB solver = new TaskB(in, out);
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i);
		out.close();
	}
}

class TaskB {
    private final FastScanner in;
    private final PrintWriter out;

    public TaskB(FastScanner in, PrintWriter out) {
        this.in = in;
        this.out = out;
    }

    public void solve(int testNumber) throws IOException {
        int rows = in.nextInt();
        int cols = in.nextInt();
        int n = in.nextInt();
        int ans = Integer.MAX_VALUE;

        for (int set = 0; set < (1 << (rows * cols)); set++) {
            int count = Integer.bitCount(set);
            if (count == n) {
                int value = 0;
                for (int row = 0; row < rows; row++) {
                    for (int col = 0; col < cols; col++) {
                        boolean a = BitUtils.isSet(set, row * cols + col);
                        if (row + 1 < rows) {
                            boolean b = BitUtils.isSet(set, (row + 1) * cols + col);
                            if (a && b) {
                                value++;
                            }
                        }
                        if (col + 1 < cols) {
                            boolean b = BitUtils.isSet(set, row * cols + col + 1);
                            if (a && b) {
                                value++;
                            }
                        }
                    }
                }
                ans = Math.min(ans, value);
            }
        }
        out.println("Case #" + testNumber + ": " + ans);
    }
}

class FastScanner {
    private BufferedReader br;
    private String line = "";
    private int pos;

    public FastScanner(InputStream is) {
        this(new BufferedReader(new InputStreamReader(is)));
    }

    public FastScanner(Reader reader) {
        br = new BufferedReader(reader);
    }

    public String next() throws IOException {
        if (!goToNextToken()) {
            return null;
        }
        return readString();
    }

    public int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    private boolean goToNextToken() throws IOException {
        if (br == null) {
            return false;
        }

        while (pos == line.length()) {
            line = br.readLine();

            if (line == null) {
                br = null;
                return true;
            }

            pos = 0;

            skipWhitespace();
        }

        return true;
    }

    private String readString() {
        int start = pos;

        while (pos < line.length()) {
            char c = line.charAt(pos);

            if (c == ' ' || c == '\t') {
                break;
            }

            pos++;
        }

        String result = line.substring(start, pos);

        skipWhitespace();

        return result;
    }

    private void skipWhitespace() {
        while (pos < line.length()) {
            char c = line.charAt(pos);

            if (c != ' ' && c != '\t') {
                break;
            }

            pos++;
        }
    }
}

class BitUtils {
    public static boolean isSet(long number, int index) {
        if (index < 0 || index > 62) {
            throw new IndexOutOfBoundsException();
        }
        return (number & (1L << index)) != 0;
    }

}

