import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Test {
	public static void main(String[] args) {
		try {
			InputStream inputStream = new FileInputStream(
					"D:\\codeforse\\CF\\input.txt");
			OutputStream outputStream = new FileOutputStream(
					"D:\\codeforse\\CF\\output.txt");
			// InputStream inputStream = System.in;
			// OutputStream outputStream = System.out;
			InputReader in = new InputReader(inputStream);
			PrintWriter out = new PrintWriter(outputStream);
			C solver = new C();
			int t = in.nextInt();
			for (int i = 0; i < t; i++) {
				solver.solve(i+1, in, out);
			}
			out.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}

class C {

	public void solve(int testNumber, InputReader in, PrintWriter out) {
		int v = in.nextInt() - 1;

		int[] a = new int[4];
		int t;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				t = in.nextInt();
				if (v == i) {
					a[j] = t;
				}
			}
		}
		v = in.nextInt() - 1;
		int count = 0;
		int value = 0;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				t = in.nextInt();
				if (v == i) {
					for (int ii = 0; ii < 4; ii++) {
						if (a[ii] == t) {
							value = t;
							count++;
						}
					}
				}
			}
		}
		out.print("Case #"+testNumber+": ");
		if (count == 1){
			out.println(value);
		}else if (count == 0){
			out.println("Volunteer cheated!");
		}else{
			out.println("Bad magician!");
		}
	}
}

class pair {

}

class InputReader {

	public BufferedReader reader;
	public StringTokenizer tokenizer;

	public InputReader(InputStream stream) {
		reader = new BufferedReader(new InputStreamReader(stream));
		tokenizer = null;
	}

	public String next() {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			try {
				tokenizer = new StringTokenizer(reader.readLine());
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		return tokenizer.nextToken();
	}

	public int nextInt() {
		return Integer.parseInt(next());
	}

	public long nextLong() {
		return Long.parseLong(next());
	}

}
