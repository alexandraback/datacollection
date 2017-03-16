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

	static long oldsolution(long k) {
		long counter = 0;

		while (k != 0) {
			long rev = reverse(k);
			if (rev < k) {
				long j = k;
				while (reverse(j - 1) < rev) {
					--j;
					rev = reverse(j);
				}
				counter += k - j + 1;
				k = reverse(j);

			} else {
				--k;
				++counter;
			}

		}
		return counter;
	}
	
	static long solution(int n, int r, int c) {
		if (n <= 1)
			return 0;
		long min = Integer.MAX_VALUE;
		long nn = (1 << (r * c));
		for (int i = 1; i < nn; ++i) {
			int count = 0;
			for (int j = 1; j < nn; j *= 2) {
				if ((i & j) != 0)
					++count;
			}
			
			if (count != n)
				continue;
			
			boolean x[][] = new boolean[r][c];
			
			for (int j = 1, cc = 0; j < nn; j *= 2, cc++) {
				if ((i & j) != 0) {
					x[cc / c][cc % c] = true;
				}
			}
			
			long cur = 0;
			for (int j = 0; j < r; ++j) {
				for (int k = 0; k < c; ++k) {
					if (x[j][k] && j + 1 < r && x[j+1][k])
						++cur;
					if (x[j][k] && k + 1 < c && x[j][k+1])
						++cur;
				}
			}
			
			min = Math.min(cur, min);
		}
		
		return min;
	}

	static long reverse(long k) {
		StringBuilder s = new StringBuilder(k + "");
		if (s.charAt(s.length() - 1) == '0')
			return Long.MAX_VALUE;
		return Long.parseLong(s.reverse().toString());
	}

	static void banana() throws IOException {
		int testCase = nextInt();

		for (int i = 1; i <= testCase; ++i) {
			int n, r, c;
			
			r = nextInt();
			c = nextInt();
			n = nextInt();
			
			writer.println("Case #" + i + ": " + solution(n,r,c));
		}
	}
}