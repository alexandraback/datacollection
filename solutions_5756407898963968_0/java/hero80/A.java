package codejam.year2014.qual;

import java.util.*;
import java.io.*;
import java.math.*;

public class A {

	private static Scanner sc;

	public static void main(final String[] args) {
//		setStreams("C:\\temp\\testA");
		 setStreams("C:\\temp\\A-small");
		sc = new Scanner(System.in);
		final int numCases = sc.nextInt();
		handleCases(numCases);
	}

	private static void setStreams(final String baseFileName) {
		try {
			System.setIn(new FileInputStream(baseFileName + ".in"));
			 System.setOut(new PrintStream(baseFileName + ".out"));
		} catch (final FileNotFoundException e) {
			e.printStackTrace();
		}
	}

	private static void handleCases(final long numCases) {
		for (int i = 1; i <= numCases; i++) {
			handleCase(i);
		}
	}

	private static void handleCase(final int caseNumber) {
		int answer1 = sc.nextInt() - 1;
		long[][] table1 = readTable();
		
		Set<Long> potentials = new HashSet<>();
		potentials.add(table1[answer1][0]);
		potentials.add(table1[answer1][1]);
		potentials.add(table1[answer1][2]);
		potentials.add(table1[answer1][3]);
		
		
		int answer2 = sc.nextInt() - 1;
		long[][] table2 = readTable();
		
		int matches = 0; 
		long number = 0;
		if(potentials.contains(table2[answer2][0])) {
			matches++;
			number = table2[answer2][0];
		}
		if(potentials.contains(table2[answer2][1])) {
			matches++;
			number = table2[answer2][1];
		}
		if(potentials.contains(table2[answer2][2])) {
			matches++;
			number = table2[answer2][2];
		}
		if(potentials.contains(table2[answer2][3])) {
			matches++;
			number = table2[answer2][3];
		}
		
		if(matches == 1) {
			System.out.println("Case #" + caseNumber + ": " + number);
		}
		else if(matches == 0) {
			System.out.println("Case #" + caseNumber + ": Volunteer cheated!");
		}
		else {
			System.out.println("Case #" + caseNumber + ": Bad magician!");
		}
	}

	private static long[][] readTable() {
		long[][] table = new long[4][4];
		for(int i = 0 ; i < 4 ; i++) {
			for(int j = 0 ; j < 4 ; j++) {
				table[i][j] = sc.nextLong();
//				log("Read: " + table[i][j]);
			}
		}
		
		return table;
	}

	private static void log(final String message) {
		System.out.println(message);
	}
}
