package com.google.codejam.ka;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.LinkedHashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class Repeater {

	public static void main(String args[]) throws FileNotFoundException {
		parseInput(args[0]);
	}

	private static void parseInput(String arg) throws FileNotFoundException {
		Scanner scanner = new Scanner(new File(arg));
		int testCases = scanner.nextInt();
		for (int i = 0; i < testCases; i++) {
			int wordCnt = scanner.nextInt();
			int charCounts[][] = new int[wordCnt][];
			String line = scanner.next();
			char[] ref = uniqueChars(line);
			int[] count = count(line, ref);
			boolean noSol = count == null;
			charCounts[0] = count;
			for (int j = 1; j < wordCnt; j++) {
				line = scanner.next();
				if (!noSol) {
					count = count(line, ref);
					if (count == null) {
						noSol = true;
					} else {
						charCounts[j] = count;
					}
				}
			}
			if (noSol) {
				printOutput(i + 1, "Fegla Won");
			} else {
				printOutput(i + 1, "" + findMin(charCounts));
			}
		}
	}

	private static int findMin(int[][] charCounts) {
		int sumChanges = 0;
		for (int i = 0; i < charCounts[0].length; i++) {
			int minForChar = Integer.MAX_VALUE;
			for (int j = 0; j < charCounts.length; j++) {
				int cnt  = 0;
				for (int k = 0; k < charCounts.length; k++) {
					cnt += Math.abs(charCounts[j][i] - charCounts[k][i]);
				}
				if (cnt < minForChar) {
					minForChar = cnt;
				}
			}
			sumChanges += minForChar;
		}
		return sumChanges;
	}

	private static int[] count(String word, char[] ref) {
		int[] charCnt = new int[ref.length];
		int idx = 0;
		int cnt = 0;
		for (char c : word.toCharArray()) {
			if (c == ref[idx]) {
				++cnt;
			} else if (idx + 1 >= ref.length || c != ref[idx+1] || cnt == 0) {
				return null;
			} else {
				charCnt[idx] = cnt;
				++idx;
				cnt = 1;
			}
		}
		if (idx < ref.length - 1) {
			return null;
		} else {
			charCnt[idx] = cnt;
			return charCnt;
		}
	}

	private static char[] uniqueChars(String string) {

		char[] chars = string.toCharArray();
		StringBuilder charSet = new StringBuilder();
		for (int i = 0; i < chars.length; i++) {
			if (i + 1 == chars.length || chars[i] != chars[i+1]) {
				charSet.append(chars[i]);
			}
		}

		return charSet.toString().toCharArray();
	}

	private static void printOutput(int i, String s) {
		System.out.println(String.format("Case #%d: %s", i, s));
	}
}
