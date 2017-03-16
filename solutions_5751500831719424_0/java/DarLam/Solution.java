import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Locale;
import java.util.StringTokenizer;

public class Solution implements Runnable {
	
	private static final String IMPOSSIBLE = "Fegla Won";
	
	private BufferedReader in;
	private StringTokenizer st;
	private PrintWriter out;
	
	private String solve(int n, String[] s) {
		int len = 0;
		for (int i = 0; i < s[0].length(); i++) {
			if (i == 0 || s[0].charAt(i - 1) != s[0].charAt(i)) {
				len++;
			}
		}
		char[] c = new char[len];
		len = 0;
		for (int i = 0; i < s[0].length(); i++) {
			if (i == 0 || s[0].charAt(i - 1) != s[0].charAt(i)) {
				c[len] = s[0].charAt(i);
				len++;
			}
		}
		int[][] a = new int[n][len];
		for (int i = 0; i < n; i++) {
			int k = 0;
			for (int j = 0; j < len; j++) {
				while (k < s[i].length() && s[i].charAt(k) == c[j]) {
					a[i][j]++;
					k++;
				}
				if (a[i][j] == 0) {
					return IMPOSSIBLE;
				}
			}
			if (k != s[i].length()) {
				return IMPOSSIBLE;
			}
		}
		int result = 0;
		int[] b = new int[n];
		for (int i = 0; i < len; i++) {
			for (int j = 0; j < n; j++) {
				b[j] = a[j][i];
			}
			Arrays.sort(b);
			int mid = b[b.length / 2];
			for (int j = 0; j < n; j++) {
				result += Math.abs(mid - b[j]);
			}
		}
		return "" + result;
	}
	
	private void solve() throws IOException {
		int t = nextInt();
		for (int test = 1; test <= t; test++) {
			int n = nextInt();
			String[] s = new String[n];
			for (int i = 0; i < n; i++) {
				s[i] = next();
			}
			String answer = solve(n, s);
			out.println("Case #" + test + ": " + answer);
		}
	}
	
	@Override
	public void run() {
		try {
			solve();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(1);
		} finally {
			out.close();
		}
	}
	
	private int nextInt() throws IOException {
		return Integer.parseInt(next());
	}
	
	private String next() throws IOException {
		while (!st.hasMoreTokens()) {
			String line = in.readLine();
			if (line == null) {
				return null;
			}
			st = new StringTokenizer(line);
		}
		return st.nextToken();
	}
	
	public Solution(String filename) {
		try {
			in = new BufferedReader(new FileReader(filename + ".in"));
			st = new StringTokenizer("");
			out = new PrintWriter(new FileWriter(filename + ".out"));
		} catch (IOException e) {
			e.printStackTrace();
			System.exit(1);
		}
	}
	
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		new Solution("data").run();
	}
}
