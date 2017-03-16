import java.io.*;
import java.util.*;
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
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
	static class Barber implements Comparable<Barber>{
		long time;
		int index;
		public Barber(long time, int index){
			this.time = time;
			this.index = index;
		}
		public int compareTo(Barber o) {
			if (time != o.time) return Long.compare(time, o.time);
			return Integer.compare(index, o.index);
		}
	}

	static class Testcase implements Callable<Testcase>{
		int testNumber;
        int barbernumber;
		int Bbarbers;
		int Nplaceinline;
		int[] M;
		Testcase(int testNumber) {
			this.testNumber = testNumber;
		}

		public void readInput(InputReader in){
			Bbarbers = in.ri();
			Nplaceinline = in.ri();
			M = IOUtils.readIntArray(in, Bbarbers);
		}

		public Testcase call(){
			long lcm = M[0];
			for(int i = 1; i < M.length; i++) lcm = IntegerUtils.lcm(lcm, M[i]);
			long cutintime = 0;
			for(int i = 0; i < M.length; i++) cutintime += lcm / M[i];
			Nplaceinline--;
			(Nplaceinline) %= cutintime;
			Nplaceinline++;
			TreeSet<Barber> ts = new TreeSet<>();
			for(int i = 1; i <= Bbarbers; i++) ts.add(new Barber(0, i));
			for(int i = 0; i < Nplaceinline - 1; i++) {
				Barber min = ts.pollFirst();
				Barber updated = new Barber(min.time + M[min.index - 1], min.index);
				ts.add(updated);
			}
			Barber result = ts.pollFirst();
			barbernumber = result.index;
			System.err.println("Done test " + testNumber+" "+cutintime+" "+Nplaceinline);
			//			sillysolve();
			return this;
		}
//		void sillysolve(){
//			TreeSet<Barber> ts = new TreeSet<>();
//			for(int i = 1; i <= Bbarbers; i++) ts.add(new Barber(0, i));
//			for(int i = 0; i < Nplaceinline - 1; i++) {
//				Barber min = ts.pollFirst();
//				Barber updated = new Barber(min.time + M[min.index - 1], min.index);
//				ts.add(updated);
//			}
//			Barber result = ts.pollFirst();
//			long sillyresult = result.index;
//			if (sillyresult != barbernumber) throw new RuntimeException();
//		}

		public void writeOutput(OutputWriter out){
			out.printLine("Case #" + testNumber + ": " + barbernumber);
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

class IntegerUtils {
	public static long gcd(long a, long b) {
        a = Math.abs(a);
        b = Math.abs(b);
		while (b != 0) {
			long temp = a % b;
			a = b;
			b = temp;
		}
		return a;
	}
	public static long lcm(long a, long b) {
		return a / gcd(a, b) * b;
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

