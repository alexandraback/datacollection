package R1B_2014;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;

public class Asmall {

	public static void main(String[] args) throws FileNotFoundException {
		Scanner reader = new Scanner(new FileReader("in"));
		int nt = reader.nextInt();
		for (int t = 1; t <= nt; t++) {
			System.out.print("Case #" + t + ": ");
			int n = reader.nextInt();
			ArrayList<P>[] dec = new ArrayList[n];
			for(int j = 0; j < n; j++) {
				String x = reader.next();
				dec[j] = new ArrayList<P>();
				for(int i = 0; i < x.length(); i++) {
					if(i == 0) {
						dec[j].add(new P(x.charAt(i), 1));
					} else {
						if(x.charAt(i) == x.charAt(i - 1)) {
							dec[j].get(dec[j].size() - 1).cnt++;
						} else {
							dec[j].add(new P(x.charAt(i), 1));
						}
					}
				}
			}
			int s = dec[0].size();
			HashSet<Character> S = new HashSet<Character>();
			boolean ok = true;
			// check sizes
			for(int j = 1; ok && j < n; j++) {
				if(dec[j].size() != s) {
					ok = false;
				}	
			}
			// check letters
			StringBuilder sb = new StringBuilder();
			for(P p : dec[0]) {
				sb.append(p.c);
			}
			for(int j = 1; ok && j < n; j++) {
				for(int i = 0; ok && i < dec[j].size(); i++) {
					if(dec[j].get(i).c != sb.charAt(i)) {
						ok = false;
					}
				}
			}
		
			if(!ok) {
				System.out.println("Fegla Won");
			} else {
				int count = 0;
				for(int i = 0; i < dec[0].size(); i++) {
					P[] p = new P[n];
					for(int j = 0; j < n; j++) {
						p[j] = dec[j].get(i);
					}
					Arrays.sort(p);
					int change = p[n / 2].cnt;
					for(int j = 0; j < n; j++) {
						count += Math.abs(change - p[j].cnt);
					}
				}
				System.out.println(count);
 			}
		}
	}
	
	static class P implements Comparable<P> {
		char c;
		int cnt;
		public P(char c, int cnt) {
			this.c = c;
			this.cnt = cnt;
		}
		public String toString() {
			return "[" + c + ", " + cnt + "]";
		}
		@Override
		public int compareTo(P other) {
			return cnt - other.cnt;
		}
	}
	
	
}
