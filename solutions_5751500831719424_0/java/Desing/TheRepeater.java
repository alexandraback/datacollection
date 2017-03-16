package com.desing.codejam.y2014.round1b;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Scanner;

public class TheRepeater {

	public static void main(String[] args) throws FileNotFoundException {

		String inputPathName = "inputs3/TheRepeater-small-practice.in";
		// String inputPathName = "inputs3/TheRepeater-large-practice.in";
		String outputPathName = "C:/Users/desingurajan_s/Desktop/out.txt";

		try (Scanner sc = new Scanner(new BufferedReader(new FileReader(
				new File(inputPathName))));
				PrintWriter pw = new PrintWriter(new File(outputPathName))) {
			int T = sc.nextInt();
			for (int t = 1; t <= T; t++) {

				int N = sc.nextInt();

				String s1 = sc.next();
				String s2 = sc.next();

				if (s1.equals(s2)) {
					// System.out.format("Case #%d: %d%n", t, 0);
					pw.format("Case #%d: %d%n", t, 0);
				} else {

					int s1Changes = 0;
					StringBuilder sb = new StringBuilder();
					int i = 1;
					for (; i < s1.length(); i++) {
						if (s1.charAt(i) == s1.charAt(i - 1)) {
							s1Changes++;
						} else {
							sb.append(s1.charAt(i - 1));
						}
					}
					sb.append(s1.charAt(i - 1));
					s1 = sb.toString();

					int s2Changes = 0;
					sb = new StringBuilder();
					i = 1;
					for (; i < s2.length(); i++) {
						if (s2.charAt(i) == s2.charAt(i - 1)) {
							s2Changes++;
						} else {
							sb.append(s2.charAt(i - 1));
						}
					}
					sb.append(s2.charAt(i - 1));
					s2 = sb.toString();

					int tChanges = Math.abs(s1Changes - s2Changes);
					if (tChanges > 0 && s1.equals(s2)) {
						// System.out.format("Case #%d: %d%n", t, tChanges);
						pw.format("Case #%d: %d%n", t, tChanges);
					} else {
						// System.out.format("Case #%d: %s%n", t, "Fegla Won");
						pw.format("Case #%d: %s%n", t, "Fegla Won");
					}
				}
			}
		}
	}
}
