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
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class TaskB {
	public static void main(String[] argc) throws IOException {
		Main.main(TaskB.class.getCanonicalName().toLowerCase(), argc);
	}
}


class T implements Comparable<T> {

	int num;
	long time;
	@Override
	public int compareTo(T o) {
		return Long.compare(time, o.time);
	}
	
}

class Task {
	InputReader in;
	OutputWriter out;

	void run() {
		int T = in.nextInt();
		for (int t = 0; t < T; t++) {
			int B = in.nextInt(), N = in.nextInt();
			int[] arr = new int[B];
			boolean[] busy = new boolean[N];
			int mul = 1;
			int rep = 0;
			for (int i = 0; i < B; i++){
				arr[i] = in.nextInt();
				mul*=arr[i];
			}
			for (int i = 0; i < B; i++)
				rep+= mul/arr[i];
			N=(N-1)%rep;
			N++;
				
			PriorityQueue<T> q = new PriorityQueue<T>();
			int i = 0, ans = 0;
			long time = 0;
			while (i < N) {
				while(!q.isEmpty() && q.peek().time<=time)
				{
					busy[q.poll().num] = false;
				}
				for (int j = 0; j < B; j++)
					if (!busy[j]) {
						busy[j] = true;
						T tmp = new T();
						tmp.num = j;
						tmp.time = time + arr[j];
						q.add(tmp);
						i++;
						if (i == N)
							ans = j + 1;
					}
				time = q.peek().time;
				//System.out.println(time);
			}
			
			out.println("Case #" + (t + 1) + ": " +  ans);

		}
	}
}

class Main {
	public static void main(String classname, String[] argc) throws IOException {
		boolean test = (argc.length > 0 && argc[0].equals("test"));
		InputReader in = new InputReader(new FileInputStream(classname + ".in"));
		OutputWriter out = new OutputWriter(new FileOutputStream(classname
				+ ".out"));
		if (!test) {
			Task t = new Task();
			t.in = in;
			t.out = out;
			t.run();
		} else {
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
		if (!token.hasMoreTokens()) {
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
