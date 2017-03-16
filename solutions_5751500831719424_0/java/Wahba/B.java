import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.*;

public class B implements Runnable {

	private void solve() throws IOException {
		int t = nextInt();
		end: while (t-- > 0) {
			int n = nextInt();
			String[] strings = new String[n];
			for (int i = 0; i < n; i++)
				strings[i] = nextToken();
			String small = "";
			for (int i = 0; i < strings[0].length(); i++) {
				if (i > 0 && strings[0].charAt(i - 1) == strings[0].charAt(i)) continue;
				small += strings[0].charAt(i);
			}
			HashSet<Integer> idxs = new HashSet<>();
			int[][] counts = new int[n][small.length()];
			pf();
			for (int i = 0; i < n; i++) {
				int idx = 0;
				for (int j = 0; j < strings[i].length(); ) {
					if (idx >= small.length() || strings[i].charAt(j) != small.charAt(idx)) {
						pl("Fegla Won");
						continue end;
					}
					while (j < strings[i].length() && strings[i].charAt(j) == small.charAt(idx)) {
						counts[i][idx]++;
						++j;
					}
					++idx;
				}
				idxs.add(idx);
			}
			if (idxs.size() > 1) {
				pl("Fegla Won");
				continue;
			}
			int res = 0;
			for (int j = 0; j < counts[0].length; j++) {
				int best = Integer.MAX_VALUE;
				int avg = 0;
				for (int i = 0; i < counts.length; i++) {
					avg += counts[i][j];
				}
				avg /= n;
				for (int a = Math.max(1, avg - 100); a <= avg + 100; a++) {
					int ans = 0;
					for (int i = 0; i < counts.length; i++) {
						ans += Math.abs(counts[i][j] - a);
					}
					best = Math.min(best, ans);
				}
				res += best;
			}
			pl(res);
		}
	}

	public static void main(String[] args) {
		new B().run();
	}

	BufferedReader reader;
	StringTokenizer tokenizer;
	PrintWriter writer;

	public void run() {
		try {
//			reader = new BufferedReader(new BufferedReader(new InputStreamReader(System.in)));
//			writer = new PrintWriter(System.out);
			reader = new BufferedReader(new BufferedReader(new FileReader("A-small-attempt2.in")));
			writer = new PrintWriter("A.out");
			tokenizer = null;
			solve();
			reader.close();
			writer.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	BigInteger nextBigInteger() throws IOException {
		return new BigInteger(nextToken());
	}

	String nextToken() throws IOException {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			tokenizer = new StringTokenizer(reader.readLine());
		}
		return tokenizer.nextToken();
	}

	void p(Object... objects) {
		for (int i = 0; i < objects.length; i++) {
			if (i != 0)
				writer.print(' ');
			writer.print(objects[i]);
		}
	}

	void pl(Object... objects) {
		p(objects);
		writer.println();
	}

	int cc;

	void pf() {
		writer.printf("Case #%d: ", ++cc);
	}

}