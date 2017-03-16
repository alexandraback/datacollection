package gcj2014_1b;

import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;


public class A {

	static String getCanon(String s) {
		if (s.length() <= 1)
			return s;
		if (s.charAt(0) == s.charAt(1))
			return getCanon(s.charAt(0) + getCanon(s.substring(2)));
		return s.charAt(0) + getCanon(s.substring(1));
	}

	static String solve(int N, String[] S) {
		String canon = getCanon(S[0]);
		for (int i=1; i<N; i++)
			if (!canon.equals(getCanon(S[i])))
				return "Fegla Won";
		int ans = 0;
		while (S[0].length() > 0) {
			char c = S[0].charAt(0);
			int[] ct = new int[N];
			for (int i=0; i<N; i++) {
				if (S[i].length() == 0 || S[i].charAt(0) != c) {
					throw new AssertionError("Expected " + c + "  Got " + S[i]);
				}
				for (int j=0; j<=S[i].length(); j++) {
					if (j<S[i].length() && S[i].charAt(j) == c)
						ct[i]++;
					else {
						S[i] = S[i].substring(ct[i]);
						break;
					}
				}
			}
			int best = 123456789;
			for (int m=0; m<128; m++) {
				int diff = 0;
				for (int i=0; i<N; i++)
					diff += Math.abs(m - ct[i]);
				best = Math.min(best, diff);
			}
			ans += best;
		}
		return String.valueOf(ans);
	}

	public static void main(String[] args) {
		try {
			File fin = new File("A-small-attempt0.in");
			Scanner sc = new Scanner(fin);
			File fout = new File("A-out.txt");
			PrintWriter pw = new PrintWriter(fout);
			//PrintWriter pw = new PrintWriter(System.out);
			int T = sc.nextInt();
			for (int cn=1; cn<=T; cn++) {
				int N = sc.nextInt();
				String[] S = new String[N];
				for (int i=0; i<N; i++) {
					S[i] = sc.next();
				}
				pw.write("Case #" + cn + ": " + solve(N, S) + "\n");
			}
			pw.flush();
			pw.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
