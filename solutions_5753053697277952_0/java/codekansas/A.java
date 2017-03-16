package qualC2016;

import java.util.PriorityQueue;
import java.util.Scanner;

public class A {
	public static void main(String... args) {
		Scanner s = new Scanner(System.in);
		
		final int T = s.nextInt();
		
		for (int t = 1; t <= T; t++) {
			N = s.nextInt();
			P = new int[N];
			for (int i = 0; i < N; i++) P[i] = s.nextInt();
			
			System.out.printf("Case #%d:%s\n", t, solve());
		}
		
		s.close();
	}
	
	static class ICPair implements Comparable<ICPair> {
		public int i;
		public char c;
		
		public ICPair(int ii, char cc) {
			this.i = ii;
			this.c = cc;
		}
		
		@Override
		public int compareTo(ICPair arg0) {
			return arg0.i - this.i;
		}
		
	}
	
	static String solve() {
		PriorityQueue<ICPair> pq = new PriorityQueue<>();
		for (int i = 0; i < N; i++) {
			pq.add(new ICPair(P[i], (char) ('A' + i)));
		}
		
		StringBuilder sb = new StringBuilder();
		
		while (!pq.isEmpty()) {
			int sum = 0;
			for (ICPair p : pq) sum += p.i;
			for (ICPair p : pq) {
				if (2 * p.i > sum) {
					return "ERROR";
				}
			}
			
			ICPair top = pq.remove(), sec = pq.remove();
			if (top.i == sec.i) {
				if (pq.size() == 0) {
					sb.append(" " + top.c + sec.c);
					top.i--;
					sec.i--;
				} else {
					sb.append(" " + top.c);
					top.i--;
				}
				
				if (top.i > 0) {
					pq.add(top);
				}
				
				if (sec.i > 0) {
					pq.add(sec);
				}
			} else {
				sb.append(" " + top.c);
				top.i--;
				pq.add(top);
				pq.add(sec);
			}
		}
		
		return sb.toString();
	}
	
	static int N;
	static int[] P;
}
