package cz.phx.gcj2014.round1B;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import java.util.regex.Pattern;

public class TaskA {

	private final int t;

	public TaskA(String inFile, String outFile) throws IOException {
		Scanner scanner = new Scanner(new File(inFile));

		FileWriter fw = new FileWriter(outFile);
		BufferedWriter writer = new BufferedWriter(fw);

		t = scanner.nextInt();

		for (int i = 0; i < t; i++) {
			processOne(i + 1, scanner, writer);
		}

		scanner.close();
		writer.close();
	}

	private void processOne(int T, Scanner scanner, BufferedWriter writer) throws IOException {
		int N = scanner.nextInt();

		String text[] = new String[N];
		for (int i = 0; i < N; i++) {
			text[i] = scanner.next();
		}

		if (testIfItIsPossible(text)) {
			int result = 0;

			int index[] = new int[N];
			int count[] = new int[N];

			do {
				int min = Integer.MAX_VALUE;
				int max = Integer.MIN_VALUE;
				for (int i = 0; i < N; i++) {
					int same = sameCharacters(text[i], index[i]);
					count[i] = same;
					if (same > max) max = same;
					if (same < min) min = same;

					index[i] += same;
				}

				int best = Integer.MAX_VALUE;
				for (int i = min; i <= max; i++) {
					int diff = 0;
					for (int j = 0; j < N; j++) {
						diff += Math.abs(i - count[j]);
					}
					if (diff < best) best = diff;
				}
				result += best;
			}
			while (index[0] < text[0].length());


			writer.write("Case #" + T + ": " + result + "\n");
		}
		else {
			writer.write("Case #" + T + ": Fegla Won\n");
		}

	}

	private boolean testIfItIsPossible(String[] text) {
		String first = text[0];
		for (int i = 1; i < text.length; i++) {
			if (getNumberOfActions(first, text[i]) == -1) {
				return false;
			}
		}

		return true;
	}

	private int getNumberOfActions(String s1, String s2) {
		int diff = 0;

		int i1 = 0;
		int i2 = 0;

		do {
			char c1 = s1.charAt(i1);
			char c2 = s2.charAt(i2);

			if (c1 != c2) return -1;

			int count1 = sameCharacters(s1, i1);
			int count2 = sameCharacters(s2, i2);

			diff += Math.abs(count1 - count2);

			i1 += count1;
			i2 += count2;
		} while (i1 < s1.length() && i2 < s2.length());

		if (i1 != s1.length() || i2 != s2.length()) return -1;

		return diff;
	}

	private int sameCharacters(String s1, int pos) {
		char ch = s1.charAt(pos);

		int count = 0;

		for (int i = pos; i < s1.length(); i++) {
			if (ch == s1.charAt(i)) {
				count++;
			}
			else {
				break;
			}
		}
		return count;
	}

	public static void main(String[] args) throws IOException{
//		String fileName = "A-test.in";
//		String fileName = "A-small-attempt0.in";
		String fileName = "A-large.in";
		new TaskA(fileName, fileName + ".out");
	}

}
