import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
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

	static long count(int a[], long x) {
		long res = 0;

		for (int i = 0; i < a.length; ++i)
			res += x / a[i] + (x % a[i] == 0 ? 0 : 1);

		return res;
	}

	static void banana() throws IOException {
		int tests = nextInt();
		for (int ttt = 0; ttt < tests; ++ttt) {
			long b = nextInt();
			long n = nextInt();
			if (n == 1) {
				writer.println("Case #" + (ttt + 1) + ": 1");
				continue;
			}

			int a[] = new int[(int) b];

			for (int i = 0; i < b; ++i)
				a[i] = nextInt();

			long l = 0;
			long r = 100000000000000000l;

			while (r - l > 1) {
				long m = (r + l) / 2;

				long count = count(a, m);

				if (count < n) {
					l = m;
				} else {
					r = m;
				}
			}

			long countL = count(a, l);
			long countR = count(a, r);

			List<Integer> finished = new ArrayList<Integer>();

			for (int i = 0; i < b; ++i) {
				if (l % a[i] == 0) {
					finished.add(i + 1);
				}
			}
			Collections.sort(finished);

			writer.println("Case #" + (ttt + 1) + ": "
					+ finished.get((int) (n - 1 - countL)));
		}
	}
}