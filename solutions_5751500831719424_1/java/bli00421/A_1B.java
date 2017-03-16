import java.util.*;
import java.io.*;

public class A_1B {
	static boolean eq(StringBuilder s1, StringBuilder s2) {
		int len;
		if ((len = s1.length()) != s2.length()) return false;
		
		for (int i = 0; i < len; i++) {
			if (s1.charAt(i) != s2.charAt(i)) return false;
		} return true;
	}
		
	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(new File("A-large.in"));
		PrintWriter out = new PrintWriter(new FileWriter("A-out.txt"));
		
		int T = in.nextInt();
		for (int t = 1; t <= T; t++) {
			int n = in.nextInt();
			String[] s = new String[n];
			int[] len = new int[n];

			for (int i = 0; i < n; i++) {
				s[i] = in.next();
				len[i] = s[i].length();
			}
			
			StringBuilder seq[] = new StringBuilder[n];
			for (int i = 0; i < n; i++) {
				seq[i] = new StringBuilder();
				char last = '-';
				for (int j = 0; j < len[i]; j++) {
					char c = s[i].charAt(j);
					if (c != last) seq[i].append(c);
					last = c;
				}
				//System.out.println(seq[i]);
			}

			boolean ok = true;
			for (int i = 1; i < n; i++) {
				if (!eq(seq[0], seq[1])) {
					out.println("Case #" + t + ": Fegla Won");
					ok = false;
					break;
				}
			}	if (!ok) continue;

			int ccount = seq[0].length();
			int[][] index = new int[n][ccount + 3];

			for (int i = 0; i < n; i++) {
				int p = 0, cur = 1;
				for (int j = 1; j < len[i]; j++) {
					if (s[i].charAt(j) == s[i].charAt(j - 1)) cur++;
					else {
						index[i][p++] = cur;
						cur = 1;
					}
				} index[i][p++] = cur;
			}
			
			int diff = 0;
			for (int i = 0; i < ccount; i++) {
				int minDiff = 1 << 30;
				for (int j = 0; j < n; j++) {
					int count = 0;
					for (int k = 0; k < n; k++)
						count += Math.abs(index[j][i] - index[k][i]);
					minDiff = Math.min(minDiff, count);
				}
				diff += minDiff;
			}

			out.println("Case #" + t + ": " + diff);
		}		

		out.close();
	}
}
