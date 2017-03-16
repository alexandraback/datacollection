package codejam2014.round1B;

import java.io.BufferedReader;
import java.io.Closeable;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;

public class ProblemA {

	public static void main(String[] args) {
		String fileName = "A-small-attempt0";
		File folder = new File(new File("files", "codejam2014"), "round1B");
		File inputFile = new File(folder, fileName + ".in");
		File outputFile = new File(folder, fileName + ".out");
		try (BufferedReader reader = new BufferedReader(new FileReader(inputFile))) {
			try (PrintWriter writer = new PrintWriter(new FileWriter(outputFile))) {
				int count = Integer.parseInt(reader.readLine());
				for (int i = 0; i < count; i++) {
					int n = Integer.parseInt(reader.readLine());
					String[] strings = new String[n];
					for (int j = 0; j < n; j++) {
						strings[j] = reader.readLine();
					}
					writer.printf("Case #%d: %s\n", i + 1, solveIt(strings));
				}
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
		System.out.println("Done.");
	}

	private static String solveIt(String[] strings) {
		String base = null;
		int moves = 0;
		for (int i = 0; i < strings.length; i++) {
			String simple = removeDuplicates(strings[i]);
			if (base == null) {
				base = simple;
			} else {
				if (!base.equals(simple)) {
					return "Fegla Won";
				}
			}
		}
		int[][] amounts = countDuplicates(strings, base);
		for (int i = 0; i < base.length(); i++) {
			int mean = mean(amounts, i, strings.length);
			for (int j = 0; j < strings.length; j++) {
				moves += Math.abs(amounts[j][i] - mean);
			}
		}
		return String.valueOf(moves);
	}

	private static int mean(int[][] amounts, int n, int items) {
		int[] amount = new int[items];
		for (int i = 0; i < items; i++) {
			amount[i] = amounts[i][n];
		}
		Arrays.sort(amount);
		return amount[items/2];
	}

	private static String removeDuplicates(String string) {
		StringBuilder buffer = new StringBuilder();
		char previousChar = ' ';
		for (int i = 0; i < string.length(); i++) {
			char ch = string.charAt(i);
			if (ch != previousChar) {
				buffer.append(ch);
				previousChar = ch;
			}
		}
		return buffer.toString();
	}

	private static int[][] countDuplicates(String[] strings, String base) {
		int[][] amounts = new int[strings.length][base.length()];
		for (int i = 0; i < strings.length; i++) {
			char previousChar = ' ';
			int n = -1;
			for (int j = 0; j < strings[i].length(); j++) {
				char ch = strings[i].charAt(j);
				if (ch != previousChar) {
					n++;
					previousChar = ch;
				}
				amounts[i][n]++;
			}
		}
		return amounts;
	}

	private static void close(Closeable file) {
		if (file != null) {
			try {
				file.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
	}
}
