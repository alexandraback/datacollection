package com.figuraj.codejam.round1b;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.List;
import java.util.Locale;
import java.util.Scanner;

public class A {

	private static boolean DEBUG = false;
	private static String FILE_IN = "D:/CodeJam/A-small-attempt0.in";
	private static String FILE_OUT = "D:/CodeJam/out/A.txt";

	private static int solve(List<String> input) {
		List<String> normalizedStrings = new ArrayList<String>();
		List<List<Integer>> counts = new ArrayList<List<Integer>>();

		for (String s : input) {
			char prev = s.charAt(0);
			List<Integer> myCounts = new ArrayList<Integer>();
			int counter = 1;
			String normalized = "";
			for (int i = 1; i < s.length(); i++) {
				if (s.charAt(i) == prev) {
					counter++;
				} else {
					normalized += prev;
					prev = s.charAt(i);
					myCounts.add(counter);
					counter = 1;
				}
			}
			normalized += prev;
			myCounts.add(counter);
			normalizedStrings.add(normalized);
			counts.add(myCounts);
		}
		if (!stringsEqual(normalizedStrings)) {
			return -1;
		}

		int length = normalizedStrings.get(0).length();
		int n = normalizedStrings.size();
		int totalActions = 0;
		for (int pos = 0; pos < length; pos++) {
			int min = Integer.MAX_VALUE;
			for (int i = 0; i < n; i++) {
				int desired = counts.get(i).get(pos);
				int actions = 0;
				for (int j = 0; j < n; j++) {
					int c1 = counts.get(j).get(pos);
					actions += Math.abs(c1 - desired);
				}
				if (actions < min) {
					min = actions;
				}
			}
			totalActions += min;
		}

		return totalActions;
	}

	private static boolean stringsEqual(List<String> strings) {
		String s = strings.get(0);
		for (String s1 : strings) {
			if (!s1.equals(s)) {
				return false;
			}
		}
		return true;
	}

	private static void output(int result, int testCase) {
		String s = "Case #" + testCase + ": ";
		switch (result) {
		case -1:
			s += "Fegla Won";
			break;
		default:
			s += result;
		}
		System.out.println(s);
	}

	public static void main(String[] args) throws FileNotFoundException {
		if (DEBUG) {
			System.setIn(new FileInputStream(FILE_IN));
			System.setOut(new PrintStream(FILE_OUT));
		}

		Scanner sc = new Scanner(System.in);
		sc.useLocale(Locale.US);
		int T = sc.nextInt();
		for (int i = 1; i <= T; i++) {
			int n = sc.nextInt();
			List<String> input = new ArrayList<String>();
			for (int j = 0; j < n; j++) {
				input.add(sc.next());
			}
			output(solve(input), i);
		}
	}
}
