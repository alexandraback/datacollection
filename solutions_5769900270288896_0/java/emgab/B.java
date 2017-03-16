import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class B {

	static int r, c, n;

	static int solve(int mask) {
		boolean[][] v = new boolean[r][c];
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if ((mask & (1 << (i * c + j))) != 0)
					v[i][j] = true;
			}
		}
		int cnt = 0;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (!v[i][j])
					continue;
				if (j + 1 < c && v[i][j + 1])
					cnt++;
				if (i + 1 < r && v[i + 1][j])
					cnt++;
			}
		}
		return cnt;
	}

	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new FileReader("B.in"));
		out = new PrintWriter("B.out");
		sc = new StringTokenizer("");
		int tc = nxtInt();
		for (int t = 1; t <= tc; t++) {
			r = nxtInt();
			c = nxtInt();
			n = nxtInt();
			int tot = r * c;
			int min = Integer.MAX_VALUE;
			for (int mask = 0; mask < 1 << tot; mask++) {
				if (Integer.bitCount(mask) == n) {
					min = Math.min(min, solve(mask));
				}
			}
			System.out.println("Case #" + t + ": " + min);
			out.println("Case #" + t + ": " + min);
		}
		br.close();
		out.close();
	}

	static BufferedReader br;
	static StringTokenizer sc;
	static PrintWriter out;

	static String nxtTok() throws IOException {
		while (!sc.hasMoreTokens()) {
			String s = br.readLine();
			if (s == null)
				return null;
			sc = new StringTokenizer(s.trim());
		}
		return sc.nextToken();
	}

	static int nxtInt() throws IOException {
		return Integer.parseInt(nxtTok());
	}

	static long nxtLng() throws IOException {
		return Long.parseLong(nxtTok());
	}

	static double nxtDbl() throws IOException {
		return Double.parseDouble(nxtTok());
	}

	static int[] nxtIntArr(int n) throws IOException {
		int[] a = new int[n];
		for (int i = 0; i < n; i++)
			a[i] = nxtInt();
		return a;
	}

	static long[] nxtLngArr(int n) throws IOException {
		long[] a = new long[n];
		for (int i = 0; i < n; i++)
			a[i] = nxtLng();
		return a;
	}

	static char[] nxtCharArr() throws IOException {
		return nxtTok().toCharArray();
	}
}