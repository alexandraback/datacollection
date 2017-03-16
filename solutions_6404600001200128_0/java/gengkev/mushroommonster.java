// gengkev
// This is the brute-force solution.
// Useful for checking answers with other program, probably.

import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class mushroommonster {
	private static final boolean useStandardInput = false;
	private static final String filename = "round1A/A-small-attempt0";
	private static final boolean log = false;

	private static void run() throws IOException {
		final int T = readLineInt();

		for (int i = 1; i <= T; i++) {
			int N = readLineInt();
			int[] mushrooms = readLineIntArray();
			int result1 = method1(mushrooms);
			int result2 = method2(mushrooms);
			output(i, String.valueOf(result1) + " " + String.valueOf(result2));
		}
	}

	private static int method1(int[] mushrooms) {
		int N = mushrooms.length;
		int total = 0;
		for (int i = 1; i < N; i++) {
			// if mushrooms decrease
			if (mushrooms[i] < mushrooms[i-1]) {
				int diff = mushrooms[i-1] - mushrooms[i];
				total += diff;
			}
		}
		return total;
	}

	private static int method2(int[] mushrooms) {
		int N = mushrooms.length;
		int max = 0;
		for (int i = 1; i < N; i++) {
			// if mushrooms decrease
			if (mushrooms[i] < mushrooms[i-1]) {
				int diff = mushrooms[i-1] - mushrooms[i];
				if (diff > max) max = diff;
			}
		}

		log("max = " + max);

		int total = 0;
		for (int i = 1; i < N; i++) {
			int x = Math.min(mushrooms[i-1], max);
			total += x;
		}
		return total;
	}


	// ----------------------------------------------------------------------------------------------------------------
	// competition helper methods

	private static BufferedReader reader;
	private static BufferedWriter writer;

	public static void main(String[] args) throws IOException {
		if (useStandardInput) {
			reader = new BufferedReader(new InputStreamReader(System.in));
			writer = new BufferedWriter(new StringWriter());
		} else {
			reader = new BufferedReader(new FileReader(filename + ".in"));
			writer = new BufferedWriter(new FileWriter(filename + ".out"));
		}
		run();
		reader.close();
		writer.close();
		if (!useStandardInput)
			System.out.println("FINISHED for file " + filename);
		System.exit(0);
	}

	private static String readLine() throws IOException {
		return reader.readLine();
	}
	private static int readLineInt() throws IOException {
		return Integer.parseInt(readLine());
	}
	private static int[] readLineIntArray() throws IOException {
		String[] strings = readLine().split("\\s");
		int L = strings.length;
		int[] ints = new int[L];
		for (int i = 0; i < L; i++) {
			ints[i] = Integer.parseInt(strings[i]);
		}
		return ints;
	}

	private static void output(int caseNo, String str) throws IOException {
		String output = "Case #" + caseNo + ": " + str + "\n";
		System.out.print("OUT: " + output);
		if (!useStandardInput) {
			writer.write(output);
		}
	}

	private static void log(String s) {
		if (log) System.out.println(s);
	}
	private static void log(String s, boolean newline) {
		if (log) System.out.print(s + (newline ? "\n" : ""));
	}
}
