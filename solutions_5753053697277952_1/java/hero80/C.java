package round1C;

import java.util.*;
import java.io.*;
import java.math.*;

public class C {

	private static Scanner sc;
	

	public static void main(final String[] args) {
//		setStreams("/Users/yariv/Downloads/C-small-attempt0");
//		setStreams("/Users/yariv/Downloads/C-large");
		setStreams("/Users/yariv/Downloads/test");
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

		System.out.println("Case #" + caseNumber + ": ");
	}
	
	private static void log(final String message) {
//		System.out.println(message);
	}
}
