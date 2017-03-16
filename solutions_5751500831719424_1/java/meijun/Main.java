import java.util.*;
import java.io.*;

import static java.util.Arrays.*;
import static java.lang.Math.*;

public class Main {
	static boolean LOCAL = System.getSecurityManager() == null;
	Scanner in = new Scanner(System.in);
	PrintWriter out = new PrintWriter(System.out);

	void run() {
		int t = in.nextInt();
		for (int i = 1; i <= t; i++) {
			out.printf("Case #%d: ", i);
			solve();
		}
	}
	void solve() {
		int n = in.nextInt();
		char[][] css = new char[n][];
		for (int i = 0; i < n; i++) css[i] = in.next().toCharArray();
		char[][] ci = new char[n][];
		int[][] cnt = new int[n][];
		for (int i = 0; i < n; i++) {
			ArrayList<Character> cl = new ArrayList<>();
			cl.add(css[i][0]);
			for (char c : css[i]) if (cl.get(cl.size() - 1) != c) cl.add(c);
			ci[i] = toc(cl.toArray(new Character[0]));
			int m = ci[i].length;
			cnt[i] = new int[m];
			for (int j = 0, k = 0; j < m; j++) {
				while (k < css[i].length && css[i][k] == ci[i][j]) {
					k++;
					cnt[i][j]++;
				}
			}
		}
		if (!fit(ci)) out.println("Fegla Won");
		else {
			int res = 0;
			for (int i = 0; i < cnt[0].length; i++) {
				int[] is = new int[n];
				for (int j = 0; j < n; j++) is[j] = cnt[j][i];
				sort(is);
				int k = is[n / 2];
				for (int t : is) res += abs(k - t);
			}
			out.println(res);
		}
	}

	private boolean fit(char[][] ci) {
		int n = ci[0].length;
		for (char[] cs : ci) if (cs.length != n) return false;
		for (int i = 0; i < n; i++) {
			for (char[] cs : ci) if (cs[i] != ci[0][i]) return false;
		}
		return true;
	}
	private char[] toc(Character[] Cs) {
		int n = Cs.length;
		char[] cs = new char[n];
		for (int i = 0; i < n; i++) cs[i] = Cs[i];
		return cs;
	}
	void debug(Object... os) {
		System.err.println(deepToString(os));
	}

	public static void main(String[] args) {
		long start = System.nanoTime();
		if (LOCAL) {
			try {
				System.setIn(new FileInputStream("./../in"));
				System.setOut(new PrintStream("./../out.txt"));
			} catch (IOException e) {
				LOCAL = false;
			}
		}
		Main main = new Main();
		main.run();
		main.out.close();
		if (LOCAL)
			System.err.printf("[Time %.6fs]%n",
					(System.nanoTime() - start) * 1e-9);
	}
}

class Scanner {
	BufferedReader br;
	StringTokenizer st;

	Scanner(InputStream in) {
		br = new BufferedReader(new InputStreamReader(in));
		eat("");
	}

	private void eat(String string) {
		st = new StringTokenizer(string);
	}

	String nextLine() {
		try {
			return br.readLine();
		} catch (IOException e) {
			return null;
		}
	}

	boolean hasNext() {
		while (!st.hasMoreTokens()) {
			String s = nextLine();
			if (s == null)
				return false;
			eat(s);
		}
		return true;
	}

	String next() {
		hasNext();
		return st.nextToken();
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
}