

import java.util.Scanner;

import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Double.parseDouble;
import static java.lang.Float.parseFloat;

public class Mushroom {
	public static Scanner s = new Scanner(System.in);
	
	public static void main(String[] args) {
		int n = parseInt(s.nextLine());
		
		for (int i=1 ; i<=n ; i++) {
			System.out.print("Case #" + i + ": ");
			System.err.println(i+"/"+n);
			
			run();
		}
	}
	
	public static void run() {
		int N = s.nextInt();
		
		long kfirst = 0;
		long ksecond = 0;
		
		int m[] = new int[N];
		for (int i=0 ; i<N ; i++) {
			m[i] = s.nextInt();
		}
		
		int rate = 0;
		
		for (int i=1 ; i<N ; i++) {
			int dif = m[i] - m[i-1];
			
			if (dif < 0) {
				kfirst += -dif;
			}
			
			if (-dif > rate) {
				rate = -dif;
			}
		}
		
		for (int i=1 ; i<N ; i++) {
			ksecond += Math.min(rate, m[i-1]);
		}
		
		System.out.println(kfirst + " " + ksecond);
	}
	
}
