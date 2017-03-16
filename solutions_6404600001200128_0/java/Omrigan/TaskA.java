import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Collection;
import java.util.StringTokenizer;

public class TaskA {
	public static void main(String[] argc) throws IOException {
		Main.main(TaskA.class.getCanonicalName().toLowerCase(), argc);
	}
}

class Task {
	InputReader in;
	OutputWriter out;

	void run() {
		int T = in.nextInt();
		for(int t = 0; t<T;t++){
			int N = in.nextInt();
			int[] arr = new int[N];
			for(int i = 0;i<N;i++)
				arr[i] = in.nextInt();
			int f = 0;
			int last = 0, maxs = 0;
			for(int i = 1;i<N;i++)
			{
				f += arr[i-1] - Math.min(arr[i-1], arr[i]);
				maxs = Math.max(maxs, arr[i-1] - arr[i]);
				//last = Math.min(last, arr[i]);
			}
			int s = 0, rate = maxs;
			for(int i = 1;i<N;i++)
			{
				s+=Math.min(rate, arr[i-1]);
			}
			out.println("Case #" + (t+1) + ": " + f + " " + s);
			
		}
	}
}

class Main {
	public static void main(String classname, String[] argc) throws IOException {
		boolean test = (argc.length > 0 && argc[0].equals("test"));
		InputReader in = new InputReader(new FileInputStream(classname + ".in"));
		OutputWriter out = new OutputWriter(new FileOutputStream(classname
				+ ".out"));
		test = false;
		if (!test) {
			Task t = new Task();
			t.in = in;
			t.out = out;
			t.run();
		} else
		{
			do {
				Task t = new Task();
				t.in = in;
				t.out = out;
				long time = System.currentTimeMillis();
				t.run();
				out.print("====TIME: " + (System.currentTimeMillis() - time)
						+ "=====");
				out.flush();
			} while (in.hasNext());
		}
		out.close();
	}
}

class InputReader {
	BufferedReader reader;
	StringTokenizer token;
	String nextLine;

	public InputReader(InputStream in) throws IOException {
		reader = new BufferedReader(new InputStreamReader(in));
		token = new StringTokenizer(reader.readLine());
		nextLine = reader.readLine();
	}

	boolean hasNext() {
		return token.hasMoreTokens() || !nextLine.equals("");
	}

	String next() {
		if (!token.hasMoreElements()) {
			token = new StringTokenizer(nextLine);
			try {
				nextLine = reader.readLine();
			} catch (Exception e) {
				e.printStackTrace();
			}
			if (nextLine == null)
				nextLine = "";

		}
		return token.nextToken();
	}

	int nextInt() {
		return Integer.parseInt(next());
	}

	long nextLong() {
		return Long.parseLong(next());
	}

	double nextDouble() {
		return Double.parseDouble(next());
	}

	BigInteger nextBigInteger() {
		return new BigInteger(next());
	}

	BigDecimal nextBigDouble() {
		return new BigDecimal(next());
	}
}

class OutputWriter extends PrintWriter {

	public OutputWriter(OutputStream out) {
		super(out);
	}

	public void print(Object... o) {
		for (Object x : o)
			this.print(x);
	}

	public void println(Object... o) {
		this.print(o);
		println();
	}

	public void printlnCollection(Collection<Object> col) {
		for (Object obj : col)
			this.println(obj);

	}

}
