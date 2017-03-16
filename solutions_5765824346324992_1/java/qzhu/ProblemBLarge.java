/* 
 * Google Code Jam - 2015 - Round 1A - Problem B "Haircut"
 * Solution for large input by Qiyu Zhu
 */

import java.util.Scanner;


public class ProblemBLarge {
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int cases = in.nextInt();
		for (int i = 0; i < cases; i++)
			System.out.printf("Case #%d: %d%n", i + 1, handleCase(in));
	}
	
	
	private static int handleCase(Scanner in) {
		// Read input
		int numBarbers = in.nextInt();
		int position = in.nextInt() - 1;  // 0-based indexing
		int[] barberTimes = new int[numBarbers];
		for (int i = 0; i < barberTimes.length; i++)
			barberTimes[i] = in.nextInt();
		
		// Find largest skipTime >= 0 such that numCustTaken(skipTime) <= position
		long skipTime = 0;
		if (numberOfCustomersTaken(barberTimes, 1) <= position) {
			skipTime = 1;
			while (numberOfCustomersTaken(barberTimes, skipTime * 2) <= position)
				skipTime *= 2;
			for (long i = skipTime / 2; i > 0; i /= 2) {
				long temp = skipTime | i;
				if (numberOfCustomersTaken(barberTimes, temp) <= position)
					skipTime = temp;
			}
		}
		
		position -= numberOfCustomersTaken(barberTimes, skipTime);
		long[] waits = new long[numBarbers];
		for (int i = 0; i < waits.length; i++) {
			long t = barberTimes[i];
			waits[i] = (skipTime + t - 1) / t * t;
		}
		while (true) {
			long minWait = waits[0];
			int minIndex = 0;
			for (int i = 0; i < waits.length; i++) {
				if (waits[i] < minWait) {
					minWait = waits[i];
					minIndex = i;
				}
			}
			if (position == 0)
				return minIndex + 1;  // 1-based indexing
			waits[minIndex] += barberTimes[minIndex];
			position--;
		}
	}
	
	
	private static long numberOfCustomersTaken(int[] barberTimes, long time) {
		long result = 0;
		for (int t : barberTimes)
			result += (time + t - 1) / t;
		return result;
	}
	
}
