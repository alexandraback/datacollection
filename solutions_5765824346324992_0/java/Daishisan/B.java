import java.io.PrintStream;
import java.util.Scanner;


public class B {

	private static PrintStream out = System.out;
	
	private static int b;
	private static long n;
	private static int[] ts;
	
	private static long computeNumStarted(long m) {
		long ret = 0;
		if (m > 0)
			for (int i = 0; i < b; ++i)
				ret += (m - 1)/ts[i] + 1;
		return ret;
	}
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int numTests = in.nextInt();
		for (int test = 1; test <= numTests; ++test) {
			// read input
			b = in.nextInt();
			n = in.nextLong();
			ts = new int[b];
			for (int i = 0; i < b; ++i)
				ts[i] = in.nextInt();
			// find the minute I'm served
			long l = 0;
			long h = 100000L*n;
			while (l + 1 < h) {
				long m = (l + h)/2;
				long numStarted = computeNumStarted(m);
				if (numStarted >= n)
					h = m;
				else
					l = m;
				
			}
			// in that minute, find which barber serves me
			long ans = -1;
			long x = n - computeNumStarted(l);
			int idx = 0;
			for (int i = 0; i < b; ++i) {
				if (l%ts[i] == 0)
					++idx;
				if (idx == x) {
					ans = i + 1;
					break;
				}
			}
			// output answer
			out.println("Case #" + test + ": " + ans);
		}
	}

}
