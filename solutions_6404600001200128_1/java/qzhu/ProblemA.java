/* 
 * Google Code Jam - 2015 - Round 1A - Problem B "Mushroom Monster"
 * Solution by Qiyu Zhu
 */

import java.util.Scanner;


public class ProblemA {
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int cases = in.nextInt();
		for (int i = 0; i < cases; i++)
			System.out.printf("Case #%d: %s%n", i + 1, handleCase(in));
	}
	
	
	private static String handleCase(Scanner in) {
		// Read input
		int[] numMushrooms = new int[in.nextInt()];
		for (int i = 0; i < numMushrooms.length; i++)
			numMushrooms[i] = in.nextInt();
		
		// First pass
		int method1Total = 0;
		int method2MaxRateSeen = 0;
		for (int i = 1; i < numMushrooms.length; i++) {
			int consumed = Math.max(numMushrooms[i - 1] - numMushrooms[i], 0);
			method1Total += consumed;
			method2MaxRateSeen = Math.max(consumed, method2MaxRateSeen);
		}
		
		// Second pass
		int method2Total = 0;
		for (int i = 0; i < numMushrooms.length - 1; i++)
			method2Total += Math.min(method2MaxRateSeen, numMushrooms[i]);
		return method1Total + " " + method2Total;
	}
	
}
