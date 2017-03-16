import java.io.*;
import java.util.*;
import java.math.*;

public class Repeater implements Runnable {
	public static void main(String[] args) {
		new Thread(new Repeater()).start();
	}

	String unique(String s) {
		String ret = "";
		for (int index = 0; index < s.length(); ++index) {
			if (index == 0 || s.charAt(index) != s.charAt(index - 1)) {
				ret += s.charAt(index);
			}
		}
		return ret;
	}

	int[] count(String s, int m) {
		int[] ret = new int[m];
		int it = -1;
		for (int index = 0; index < s.length(); ++index) {
			if (index == 0 || s.charAt(index) != s.charAt(index - 1)) {
				++it;
			}
			++ret[it];
		}
		return ret;
	}

	public void run() {
		InputReader in = new InputReader(System.in);
		PrintWriter out = new PrintWriter(System.out);

		int task = in.nextInt();
		for (int taskIndex = 1; taskIndex <= task; ++taskIndex) {
			out.print("Case #" + taskIndex + ": ");
			int n = in.nextInt();
			String[] s = new String[n];
			for (int index = 0; index < n; ++index) {
				s[index] = in.next();
			}
			String pattern = unique(s[0]);
			boolean valid = true;
			for (int index = 0; index < n; ++index) {
				if (!unique(s[index]).equals(pattern)) {
					valid = false;
					break;
				}
			}
			if (!valid) {
				out.println("Fegla Won");
				continue;
			}
			int m = pattern.length();
			int[][] mat = new int[n][];
			for (int index = 0; index < n; ++index) {
				mat[index] = count(s[index], m);
			}

			int ret = 0;
			for (int it = 0; it < m; ++it) {
				int[] times = new int[n];
				for (int index = 0; index < n; ++index) {
					times[index] = mat[index][it];
				}
				Arrays.sort(times);
				int mid = times[n / 2];
				for (int index = 0; index < n; ++index) {
					ret += Math.abs(mid - times[index]);
				}
			}
			out.println(ret);
		}

		out.close();
	}
}

class InputReader {
	BufferedReader buff;
	StringTokenizer tokenizer;

	InputReader(InputStream stream) {
		buff = new BufferedReader(new InputStreamReader(stream));
		tokenizer = null;
	}
	boolean hasNext() {
		while (tokenizer == null || !tokenizer.hasMoreTokens())
			try {
				tokenizer = new StringTokenizer(buff.readLine());
			}
			catch (Exception e) {
				return false;
			}
		return true;
	}
	String next() {
		if (!hasNext())
			throw new RuntimeException();
		return tokenizer.nextToken();
	}
	int nextInt() { return Integer.parseInt(next()); }
	long nextLong() { return Long.parseLong(next()); }
}

