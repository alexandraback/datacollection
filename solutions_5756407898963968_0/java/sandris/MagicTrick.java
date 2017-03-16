package com.sandris.codejam2014;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class MagicTrick {
	
	private static class Arrangement {
		int[] first;
		int[] second;
	}
	
	private void run(File directory) throws IOException {
		File inputFile = new File(directory, "input.txt");
		File outputFile = new File(directory, "output.txt");
		BufferedReader reader = new BufferedReader(new FileReader(inputFile));
		PrintWriter writer = new PrintWriter(new FileWriter(outputFile));
		int testCaseCount = Integer.parseInt(readLine(reader));
		for (int testCaseIndex = 0; testCaseIndex < testCaseCount; testCaseIndex++) {
			printResult(testCaseIndex, solve(readNext(reader)), writer);
		}
		writer.close();
		reader.close();
	}
	
	private String solve(Arrangement arrangement) {
		int[] first = arrangement.first;
		int counter = 0;
		int solution = 0;
		for (int i = 0; i < 4; i++) {
			int current = first[i];
			for (int j = 0; j < 4; j++) if (arrangement.second[j] == current) {
				if (++counter > 1) {
					return "Bad magician!";
				}
				solution = current;
			}
		}
		if (counter == 0) {
			return "Volunteer cheated!";
		}
		return Integer.toString(solution);
	}

	public static void main(String[] args) throws IOException {
		new MagicTrick().run(new File(args[0]));
	}
	
	private String readLine(BufferedReader reader) {
		try {
			return reader.readLine();
		} catch (IOException exception) {
			throw new RuntimeException(exception);
		}
	}
	
	private void printResult(int testCaseIndex, String result, PrintWriter writer) {
		int number = testCaseIndex + 1;
		String output = "Case #" + number + ": " + result;
		writer.println(output);
		System.out.println(output);
	}
	
	private Arrangement readNext(BufferedReader reader) {
		Arrangement arrangement = new Arrangement();
		arrangement.first = getLine(reader);
		arrangement.second = getLine(reader);
		return arrangement;
	}
	
	private int[] getLine(BufferedReader reader) {
		int row = Integer.parseInt(readLine(reader));
		for (int i = 1; i < row; i++) readLine(reader);
		String[] numbers = readLine(reader).split(" ");
		for (int i = row; i < 4; i++) readLine(reader);
		int[] line = new int[4];
		for (int i = 0; i < 4; i++) line[i] = Integer.parseInt(numbers[i]);
		return line;
	}

}
