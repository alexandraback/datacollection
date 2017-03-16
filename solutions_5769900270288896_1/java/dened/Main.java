import java.io.Reader;
import java.io.FileInputStream;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
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
        int used = in.nextInt();
        int total = rows * cols;
        int free = total - used;
        int ans;

        if (used <= (total + 1) / 2) {
            ans = 0;
        } else if (rows == 1 || cols == 1) {
            ans = total - 1 - 2 * free;
        } else {
            ans = (rows - 1) * cols + (cols - 1) * rows;

            int interiorRows = rows - 2;
            int interiorCols = cols - 2;

            int interior = interiorRows * interiorCols;
            if (interior == 0) {
                interior = total - 4;
                int interiorAlt = Math.min(free, (interior + 1) / 2);
                ans -= 3 * interiorAlt;
                free -= interiorAlt;
                ans -= 2 * free;
            } else if (interiorRows == 1 || interiorCols == 1) {
                ans -= Math.max(getDiff(free, interior, 0), getDiff(free, interior, 1));
            } else {
                int interiorAlt = Math.min(free, (interior + 1) / 2);
                ans -= 4 * interiorAlt;
                free -= interiorAlt;

                int interiorPerimeter = 2 * interiorRows + 2 * (interiorCols - 2);
                int interiorPerimeterAlt = Math.min(free, interiorPerimeter / 2);
                ans -= 3 * interiorPerimeterAlt;
                free -= interiorPerimeterAlt;
                
                if (interiorRows % 2 == 0 || interiorRows % 2 == 0) {
                    int nearCorner = Math.min(free, 2);
                    ans -= 3 * nearCorner;
                    free -= nearCorner;
                }

                ans -= 2 * free;
            }
        }

        out.println("Case #" + testNumber + ": " + ans);
    }

    private int getDiff(int free, int interior, int round) {
        int diff = 0;

        int interiorAlt = Math.min(free, (interior + round) / 2);
        diff += 4 * interiorAlt;
        free -= interiorAlt;

        int interiorBorder = Math.min(free, interior - 2 * interiorAlt + 1);
        diff += 3 * interiorBorder;
        free -= interiorBorder;

        interiorAlt = Math.min(free, 2 * (interior - interiorAlt));
        diff += 3 * interiorAlt;
        free -= interiorAlt;

        diff += 2 * free;

        return diff;
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

