package round1b;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class A {

	private static class P {
		char c;
		int cnt;
		public P(char c, int cnt) {
			this.c = c;
			this.cnt = cnt;
		}
	}
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int numTests = in.nextInt();
		for (int test = 1; test <= numTests; ++test) {
			int n = in.nextInt();
			in.nextLine();
			// create breakdowns
			ArrayList<ArrayList<P>> breakdown = new ArrayList<ArrayList<P>>();
			for (int i = 0; i < n; ++i) {
				char[] s = in.nextLine().toCharArray();
				char prev = '?';
				int cnt = 1;
				breakdown.add(new ArrayList<P>());
				for (int j = 0; j < s.length; ++j) {
					if (prev == s[j]) {
						++cnt;
					} else {
						cnt = 1;
						prev = s[j];
					}
					if (j + 1 == s.length || s[j + 1] != s[j]) {
						breakdown.get(i).add(new P(prev, cnt));
					}
				}
			}
			// check breakdown lengths are the same
			boolean works = true;
			for (int i = 1; i < n; ++i)
				works = works && breakdown.get(i).size() == breakdown.get(0).size();
			// now do median
			int ans = 0;
			if (works) {
				for (int i = 0; i < breakdown.get(0).size() && works; ++i) {
					int[] a = new int[n];
					for (int j = 0; j < n && works; ++j) {
						if (breakdown.get(j).get(i).c != breakdown.get(0).get(i).c) {
							works = false;
							break;
						}
						a[j] = breakdown.get(j).get(i).cnt;
					}
					Arrays.sort(a);
					if (n%2 == 1) {
						for (int j = 0; j < n; ++j)
							ans += Math.abs(a[j] - a[n/2]);
					} else {
						int cand1 = 0;
						int cand2 = 0;
						for (int j = 0; j < n; ++j) {
							cand1 += Math.abs(a[j] - a[n/2]);
							cand2 += Math.abs(a[j] - a[n/2 - 1]);
						}
						ans += Math.min(cand1, cand2);
					}
						
				}
			}
			// print out answer
			System.out.println("Case #" + test + ": " + (works ? ans : "Fegla Won"));
		}
	}

}
