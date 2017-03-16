import java.io.File;
import java.io.PrintStream;
import java.util.Locale;
import java.util.Scanner;

public class A {
	private static int getMin(int[] k) {
		int maxLen = 0;
		for (int i = 0; i < k.length; i++) {
			if (k[i] > maxLen)
				maxLen = k[i];

		}
		int min = maxLen * k.length;

		for (int len = 1; len <= maxLen; len++) {
			int r = 0;
			for (int i = 0; i < k.length; i++)
				r += Math.abs(k[i] - len);
			if (r < min) {
				min = r;
			}

		}
		return min;

	}

	public static void main(String[] args) throws Exception {
		Locale.setDefault(Locale.US);

		Scanner in = new Scanner(new File("problem.in"));
		PrintStream out = new PrintStream(new File("problem.out"));

		int T = in.nextInt();
		for (int test = 1; test <= T; test++) {
			int n = in.nextInt();
			String[] s = new String[n];
			int[] index = new int[n], k = new int[n];

			for (int i = 0; i < n; i++) {
				s[i] = in.next();
			}

			boolean f = true;
			int res = 0;

			while (index[0] < s[0].length()) {
				char c = s[0].charAt(index[0]);

				f = true;

				for (int i = 0; i < n; i++) {
					k[i] = 0;
					while (index[i] < s[i].length()
							&& s[i].charAt(index[i]) == c) {
						k[i]++;
						index[i]++;
					}
					if (k[i] == 0) {
						f = false;
						break;
					}

				}
				if (!f) {
					break;
				}
				res += getMin(k);

			}
			if (f) {
				for (int i = 0; i < n; i++) {
					if (index[i] < s[i].length()) {
						f = false;
						break;
					}
				}
			}

			out.print("Case #" + test + ": ");
			if (f) {
				out.println(res);
			} else {
				out.println("Fegla Won");
			}
		}
	}
}
