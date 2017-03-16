import java.util.Scanner;
import java.io.OutputStream;
import java.io.IOException;
import java.io.FileOutputStream;
import java.util.Arrays;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream;
		try {
			inputStream = new FileInputStream("tc/A-small-attempt1.in");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("tc/output.txt");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		Scanner in = new Scanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		A solver = new A();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class A {
	public void solve(int testNumber, Scanner in, PrintWriter out) {
		int n = in.nextInt();
		String[] s = new String[n];
		for (int i = 0; i < n; ++i) s[i] = in.next();
		String[] m = new String[n];
		for (int i = 0; i < n; ++i) {
			char c = s[i].charAt(0);
			String cur = "" + c;
			for (int j = 0; j < s[i].length(); ++j) {
				if (s[i].charAt(j) != c) {
					cur += s[i].charAt(j);
					c = s[i].charAt(j);
				}
			}
			m[i] = cur;
		}
		for (int i = 1; i < n; ++i) {
			if (m[0].equals(m[i]) == false) {
				out.print(String.format("Case #%d: Fegla Won\n", testNumber));
				return;
			}
		}
		int[] min = new int[m[0].length()];
		Arrays.fill(min, Integer.MAX_VALUE);
		int[] max = new int[m[0].length()];
		Arrays.fill(max, Integer.MIN_VALUE);
		int[][] cnt = new int[n][];
		for (int i = 0; i < n; ++i) {
			cnt[i] = getCnt(m[0], s[i]);
			for (int j = 0; j < cnt[i].length; ++j) {
				min[j] = Math.min(min[j], cnt[i][j]);
				max[j] = Math.max(max[j], cnt[i][j]);
			}
		}
		long res = 0;
		for (int i = 0; i < min.length; ++i) {
			int minCnt = Integer.MAX_VALUE;
			for (int j = min[i]; j <= max[i]; ++j) {
				int cur = 0;
				for (int k = 0; k < n; ++k) {
					cur += Math.abs(cnt[k][i] - j);
				}
				minCnt = Math.min(minCnt, cur);
			}
			res += minCnt;
		}
		out.print(String.format("Case #%d: %d\n", testNumber, res));
	}

	private int[] getCnt(String m0, String s) {
		int[] ret = new int[m0.length()];
		int ptr = 0;
		int count = 0;
		for (int j = 0; j < m0.length(); ++j) {
			while (ptr < s.length() && s.charAt(ptr++) == m0.charAt(j)) {
				count++;
			}
			ret[j] = count;
			count = 1;
		}
		return ret;
	}
}

