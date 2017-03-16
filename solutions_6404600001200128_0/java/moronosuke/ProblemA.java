package codejam2015.round1A;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class ProblemA {

	public static void main(String[] args) {
		String fileName = "A-small-attempt0";
		File folder = new File(new File("files", "codejam2015"), "round1A");
		File inputFile = new File(folder, fileName + ".in");
		File outputFile = new File(folder, fileName + ".out");
		try (BufferedReader reader = new BufferedReader(new FileReader(inputFile))) {
			try (PrintWriter writer = new PrintWriter(new FileWriter(outputFile))) {
				int count = Integer.parseInt(reader.readLine());
				for (int i = 0; i < count; i++) {
					int n = Integer.parseInt(reader.readLine());
					writer.printf("Case #%d: %s\n", i+1,
							solveIt(n, readIntegers(reader)));
				}
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
		System.out.println("Done.");
	}

	private static String solveIt(long n, int[] m) {
		return solveMethod1(n, m) + " " + solveMethod2(n, m);
	}

	private static int solveMethod1(long n, int[] m) {
		int min = 0;
		for (int i = 1; i < n; i++) {
			if (m[i] < m[i - 1]) {
				min += m[i - 1] - m[i];
			}
		}
		return min;
	}

	private static int solveMethod2(long n, int[] m) {
		int maxDiff = 0;
		for (int i = 1; i < n; i++) {
			if (m[i] < m[i - 1]) {
				int diff = m[i - 1] - m[i];
				if (maxDiff < diff) {
					maxDiff = diff;
				}
			}
		}
		int min = 0;
		for (int i = 1; i < n; i++) {
			min += Math.min(maxDiff, m[i - 1]);
		}
		return min;
	}

	private static int[] readIntegers(BufferedReader reader) throws IOException {
		String[] strings = reader.readLine().split("\\s");
		int[] numbers = new int[strings.length];
		for (int i = 0; i < strings.length; i++) {
			numbers[i] = Integer.parseInt(strings[i]);
		}
		return numbers;
	}
}
