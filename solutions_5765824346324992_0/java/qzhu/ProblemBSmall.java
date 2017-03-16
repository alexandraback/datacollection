/* 
 * Google Code Jam - 2015 - Round 1A - Problem B "Haircut"
 * Solution by Qiyu Zhu
 */

import java.math.BigInteger;
import java.util.Scanner;


public class ProblemBSmall {
	
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
		
		// Modular reduction
		BigInteger timeLcm = BigInteger.ONE;
		for (int time : barberTimes)
			timeLcm = lcm(BigInteger.valueOf(time), timeLcm);
		BigInteger servedPerLcm = BigInteger.ZERO;
		for (int time : barberTimes)
			servedPerLcm = servedPerLcm.add(timeLcm.divide(BigInteger.valueOf(time)));
		position = BigInteger.valueOf(position).mod(servedPerLcm).intValue();
		
		// Brute-force the rest
		int[] waits = new int[barberTimes.length];
		while (true) {
			int minWait = waits[0];
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
			for (int i = 0; i < waits.length; i++)
				waits[i] -= minWait;
			position--;
		}
	}
	
	
	private static BigInteger lcm(BigInteger x, BigInteger y) {
		return x.divide(x.gcd(y)).multiply(y);
	}
	
}
