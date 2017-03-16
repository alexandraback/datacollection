import java.io.*;
import java.util.ArrayList;
import java.util.InputMismatchException;
import java.util.List;
import java.util.Locale;
import java.util.concurrent.*;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Alex
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
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {
	static class Testcase implements Callable<Testcase>{
		int testNumber;
        int yres = 0;
		int zres = 0;
		int N;
		int[] m;
		Testcase(int testNumber) {
			this.testNumber = testNumber;
		}

		public void readInput(InputReader in){
			N = in.ri();
			m = IOUtils.readIntArray(in, N);
		}

		public Testcase call() {
			for(int i = 0; i < m.length - 1; i++)  if (m[i+1] < m[i]) yres += m[i] - m[i+1];
			int maxrate = 0;
			for(int i = 0; i < m.length - 1; i++)  if (m[i+1] < m[i]) maxrate = Math.max(maxrate, m[i] - m[i + 1]);
			for(int i = 0; i < m.length - 1; i++)  zres += Math.min(maxrate, m[i]);
			System.err.println("Done test " + testNumber + " " + maxrate);
			return this;
		}

		public void writeOutput(OutputWriter out) {
			out.printLine("Case #" + testNumber + ": " + yres+" "+zres);
		}
	}


    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int nt = in.readInt();
        List<Future<Testcase>> tests = new ArrayList<Future<Testcase>>();
        ExecutorService pool = Executors.newFixedThreadPool(8);
        for (int it = 0; it < nt; ++it) {
            Testcase t = new Testcase(it + 1);
            t.readInput(in);
            tests.add(pool.submit(t));
        }
        for (Future<Testcase> test : tests) {
            try {
                Testcase t = test.get();
                t.writeOutput(out);
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            } catch (ExecutionException e) {
                throw new RuntimeException(e);
            }
        }
        pool.shutdown();
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
	public int ri(){
		return readInt();
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
	public boolean isSpaceChar(int c) {
		if (filter != null)
			return filter.isSpaceChar(c);
		return isWhitespace(c);
	}

	public static boolean isWhitespace(int c) {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}
	public interface SpaceCharFilter {
		public boolean isSpaceChar(int ch);
	}
}

class IOUtils {
	public static int[] readIntArray(InputReader in, int size) {
		int[] array = new int[size];
		for (int i = 0; i < size; i++)
			array[i] = in.readInt();
		return array;
	}
}

class OutputWriter {
	private final PrintWriter writer;

	public OutputWriter(OutputStream outputStream) {
		writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
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
}

