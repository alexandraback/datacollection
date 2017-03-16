import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class B {

	public static void main(String[] args) throws IOException {
		BufferedReader in = new  BufferedReader(new InputStreamReader(System.in));
		
		int t = Integer.parseInt(in.readLine());
		
		for (int i = 1; i <= t; i++) {
			long res = 0;

			String[] next = in.readLine().split(" ");
			int b = Integer.parseInt(next[0]);
			long n = Long.parseLong(next[1]);
			next = in.readLine().split(" ");
			int[] mi = new int[b];
			
			for (int j = 0; j < b; j++) {
				mi[j] = Integer.parseInt(next[j]);
			}
			
			if (n < b) res = (long) n;
			else {
				long largest = 0;
				for (int j = 0; j < b; j++) {
					largest = Math.max(largest, mi[j]);
				}
				
				
				n -= b;
				
				long time = 0;
				
				long sum = 0;
				while (sum < n) {
					time += 10000;
					sum = 0;
					for (int k = 0; k < b; k++) {
						sum += time / mi[k];
					}
				}
				
				time -= 10000;
				int lastsum = 0;
				for (int k = 0; k < b; k++) {
					lastsum += time / mi[k];
				}
				n -= lastsum;
				
				while (n > 0) {
					time++;
					for (int k = 1; k <= b; k++) {
						if (mi[k-1] == 1) n--;
						else if (time % mi[k-1] == 0) n--;
						//System.out.println("time " + time + "mi k "+ mi[k-1] + " n " + n);
						if (n == 0) {
							//System.out.println("k is " + k);
							res = k;
							break;
						}
					}
				}
				
			}
			
			System.out.format("Case #%d: %d\n", i, res);
		}
	}

}
