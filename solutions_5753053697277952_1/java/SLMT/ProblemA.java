package round1c;

import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

public class ProblemA {
	
	public static void main(String[] args) {
		Scanner inputScanner = new Scanner(System.in);
		
		// Get the number of test cases
		int n;
		int[] people;
		int totalCases = inputScanner.nextInt();
		for (int caseId = 1; caseId <= totalCases; caseId++) {
			// Read numbers
			n = inputScanner.nextInt();
			people = new int[n];
			for (int i = 0; i < n; i++)
				people[i] = inputScanner.nextInt();
			
			String[] plans = getAPlan(people);
			
			// Print the result
			StringBuilder out = new StringBuilder();
			out.append("Case #" + caseId + ":");
			for (String plan : plans)
				out.append(" " + plan);
			System.out.println(out);
		}
		
		inputScanner.close();
	}
	
	private static String[] getAPlan(int[] people) {
		int party1 = -1, party2 = -1;
		int max;
		String persons = "";
		List<String> plan = new LinkedList<String>();
		
		while (!isAllGone(people)) {
			// Find the parties with the most number of members
			max = -1;
			party2 = -1;
			for (int i = 0; i < people.length; i++) {
				if (people[i] > max) {
					max = people[i];
					party1 = i;
				}
			}
			
			// Find if there is another party has the same number of members
			for (int i = 0; i < people.length; i++) {
				if (i != party1 && people[i] == max)
					party2 = i;
			}
			
			// Decrease the number
			people[party1]--;
			if (party2 != -1)
				people[party2]--;
			
			// If there is only one left
			if (isOnlyOneLeft(people)) {
				people[party2]++;
				party2 = -1;
			}
			
			// Append a plan
			persons = "" + (char) ('A' + party1);
			if (party2 != -1)
				persons += (char) ('A' + party2);
			plan.add(persons);
		}
		
		return plan.toArray(new String[0]);
	}
	
	private static boolean isAllGone(int[] people) {
		for (int i : people)
			if (i != 0)
				return false;
		return true;
	}
	
	private static boolean isOnlyOneLeft(int[] people) {
		boolean isOne = false;
		for (int i : people) {
			if (i > 1)
				return false;
			else if (i == 1 && !isOne)
				isOne = true;
			else if (i == 1 && isOne)
				return false;
		}
		
		return isOne;
	}
}
