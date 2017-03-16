/*
 * This code is meant to run under the Java Runtime Environment, version 1.7 or
 * later.
 */

package qualification.a;

import java.io.BufferedReader;
import java.io.FileReader;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main0 {
	
	// This is used to work around the inability of Eclipse to use a file as
	// System.in when running a program.
	private static final String IN_FILE_NAME = "input.txt";

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(new BufferedReader(new FileReader(IN_FILE_NAME)));
		
		int numCases = in.nextInt();
		
		for (int i = 1; i <= numCases; i++) {
			int answer0 = in.nextInt();
			int[][] cards0 = new int[4][4];
			for (int j = 0; j < 4; j++) {
				for (int k = 0; k < 4; k++) {
					cards0[j][k] = in.nextInt();
				}
			}
			int answer1 = in.nextInt();
			int[][] cards1 = new int[4][4];
			for (int j = 0; j < 4; j++) {
				for (int k = 0; k < 4; k++) {
					cards1[j][k] = in.nextInt();
				}
			}
			
			int[] possibilities = solve(cards0, answer0, cards1, answer1);
			String result;
			if (possibilities.length > 1) {
				result = "Bad magician!";
			}
			else if (possibilities.length < 1) {
				result = "Volunteer cheated!";
			}
			else {
				assert(possibilities.length == 1);
				result = ""+possibilities[0];
			}
			System.out.println(String.format("Case #%s: %s", i, result));
		}
		
		in.close();
	}
	
	// cards0 and cards1 must be in row-major order.
	private static int[] solve(int[][] cards0, int answer0, int[][] cards1,
		int answer1)
	{
		// Figure out which cards are possible based on each query/answer.
		Set<Integer> possibilities0 = new HashSet<Integer>(4);
		for (int p : cards0[answer0-1]) {
			possibilities0.add(p);
		}
		Set<Integer> possibilities1 = new HashSet<Integer>(4);
		for (int p : cards1[answer1-1]) {
			possibilities1.add(p);
		}
		
		// Find all possibilities that are in both sets.
		possibilities0.retainAll(possibilities1);
		int[] result = new int[possibilities0.size()];
		int i = 0;
		for (Integer p : possibilities0) {
			result[i] = p;
			i++;
		}
		
		return result;
	}
}
