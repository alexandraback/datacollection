import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main {
	static BufferedReader reader;
	static StringTokenizer tokenizer;
	static PrintWriter writer;

	static int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	static long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	static double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	static boolean eof = false;

	static String nextToken() throws IOException {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			tokenizer = new StringTokenizer(reader.readLine());
		}
		return tokenizer.nextToken();
	}

	public static void main(String[] args) throws IOException {
		tokenizer = null;
		reader = new BufferedReader(new FileReader("input.txt"));
		writer = new PrintWriter(new FileWriter("output.txt"));
		// reader = new BufferedReader(new InputStreamReader(System.in,
		// "ISO-8859-1"));
		// writer = new PrintWriter(System.out);
		banana();
		reader.close();
		writer.close();
	}

	static void banana() throws IOException {
		int tests = nextInt();
		for (int ttt = 0; ttt < tests; ++ttt) {
			int n = nextInt();
			int a[] = new int[n];

			for (int i = 0; i < n; ++i) {
				a[i] = nextInt();
			}

			long firstMin = 0;
			long secondMin = 0;
			for (int i = 0; i < n - 1; ++i) {
				if (a[i] > a[i + 1]) {
					firstMin += a[i] - a[i + 1];
					secondMin = Math.max(secondMin, a[i] - a[i + 1]);
				}
			}

			long s = secondMin;
			secondMin = 0;

			for (int i = 0; i < n - 1; ++i) {
				secondMin += Math.min(a[i], s);
			}

			writer.println("Case #" + (ttt+1) + ": " + firstMin + " " + secondMin);
		}
	}
}