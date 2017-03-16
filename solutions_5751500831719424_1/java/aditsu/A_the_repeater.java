import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class A_the_repeater {
	public static void main(final String... args) throws IOException {
		final String fname = "A-large";
		final Scanner sc = new Scanner(new File(fname + ".in"));
		final PrintWriter pw = new PrintWriter(fname + ".out");
		final int t = sc.nextInt();
		
		for (int i = 1; i <= t; ++i) {
			System.out.println(i);
			final int n = sc.nextInt();
			sc.nextLine();
			final String[] w = new String[n];
			for (int j = 0; j < n; ++j) {
				w[j] = sc.nextLine() + '\n';
			}
			StringBuilder sb = new StringBuilder();
			List<List<Integer>> ll = new ArrayList<List<Integer>>();
			List<Integer> l = new ArrayList<Integer>();
			int m = 0;
			String s = w[0];
			for (int j = 0; j < s.length(); ++j) {
				if (j > 0 && s.charAt(j) == s.charAt(j - 1)) {
					m++;
				}
				else {
					if (m > 0) {
						sb.append(s.charAt(j - 1));
						l.add(m);
					}
					m = 1;
				}
			}
			final String str = sb.toString();
			ll.add(l);
			boolean ok = true;
			for (int k = 1; k < n; ++k) {
				l = new ArrayList<Integer>();
				m = 0;
				s = w[k];
				sb.setLength(0);
				for (int j = 0; j < s.length(); ++j) {
					if (j > 0 && s.charAt(j) == s.charAt(j - 1)) {
						m++;
					}
					else {
						if (m > 0) {
							sb.append(s.charAt(j - 1));
							l.add(m);
						}
						m = 1;
					}
				}
				if (!str.equals(sb.toString())) {
					ok = false;
					break;
				}
				ll.add(l);
			}
			if (ok) {
				int r = 0;
				for (int j = 0; j < str.length(); ++j) {
					int best = Integer.MAX_VALUE;
					l = new ArrayList<Integer>();
					for (int k = 0; k < n; ++k) {
						l.add(ll.get(k).get(j));
					}
					Collections.sort(l);
					for (int k = l.get(0); k <= l.get(n - 1); ++k) {
						int tt = 0;
						for (int q = 0; q < n; ++q) {
							tt += Math.abs(l.get(q) - k);
						}
						if (tt < best) {
							best = tt;
						}
					}
					r += best;
				}
				pw.println("Case #" + i + ": " + r);
			}
			else {
				pw.println("Case #" + i + ": Fegla Won");
			}
		}
		pw.close();
	}
}
