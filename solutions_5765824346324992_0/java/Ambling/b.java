import java.util.Scanner;
import java.util.TreeSet;

public class b {
	static class barber implements Comparable<barber> {
		public int bar;
		public int need;
		public long next;
		public barber(int b, int n) {
			bar = b;
			need = n;
			next = 0;
		}
		
		@Override
		public int compareTo(barber o) {
			if (next > o.next) return 1;
			else if (next == o.next && bar > o.bar) return 1;
			else return -1;
		}
	}
	
	static int gcd(int a, int b) {
		if (a > b) return gcd(b, a);
		else if (a == 0) return b;
		else return gcd(a, b-a);
	}
	
	static int mcm(int a, int b) {
		if(a > b) return mcm(b, a);
		else if(b % a == 0) return b;
		else return a * b / gcd(a, b);
	}
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

		int T = in.nextInt();
		for (int t = 1; t <= T; t++) {
			// TODO

			int nbar = in.nextInt();
			int num = in.nextInt();
			
			TreeSet<barber> barqueue = new TreeSet<>();
			int[] needs = new int[nbar];
			int maxcommon = 1;
			for (int i = 0; i < nbar; i++) {
				int need = in.nextInt();
				needs[i] = need;
				maxcommon = mcm(maxcommon, need);
				barqueue.add(new barber(i+1, need));
			}
			
//			System.out.println("" + nbar + " " + num);
			int re = 0;
			for (int i = 0; i < nbar; i++) {
				re += maxcommon / needs[i];
//				System.out.printf("%d ", needs[i]);
			}
			
			int take = 0;
			num %= re;
			if (num == 0) num += re;
			

//			System.out.println("-- mcm: "+maxcommon + " re: " + re + " num: " + num);
			while (num > 0) {
				barber bar = barqueue.pollFirst();
				take = bar.bar;
				
				//System.out.println("bar: " + bar.bar + " next: " + bar.next);
				
				bar.next += bar.need;
				barqueue.add(bar);
				num --;
			}
			
			System.out.printf("Case #%d: %d\n", t, take);
		}
	}
}
