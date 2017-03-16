package com.spawn.codejam;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.concurrent.atomic.AtomicInteger;
// https://github.com/google/guava/
//import com.google.common.collect.*;

class Case {

	public int caseNumber;
	public String result;

	public Case(int i, Scanner s) {
		caseNumber = i;
		parse(s);
	}

	public String getResult() {
		return "Case #" + caseNumber + ": " + result + "\n";
	}

	int n;
	int[] m;
	int maxDiff = Integer.MIN_VALUE;
	int sum = 0;

	public void parse(Scanner s) {
		n = s.nextInt();
		m = new int[n];
		m[0] = s.nextInt();
		int last = m[0];
		for (int i = 1; i < n; i++) {
			m[i] = s.nextInt();
			int diff = last - m[i];
			if (diff > maxDiff)
				maxDiff = diff;
			last = m[i];
			if (diff > 0)
				sum += diff;
		}
	}

	public void solve() {
		int c2 = 0;
		int last = m[0];
		for (int i = 1; i < n; i++) {
			c2 += Math.min(maxDiff, m[i - 1]);
		}
		result = sum + " " + c2;

		System.out.println("#" + caseNumber + " done; "
				+ Main.casesRemaining.decrementAndGet() + " remaining");
	}
}

public class Main {

	public static AtomicInteger casesRemaining = new AtomicInteger();

	public static void main(String[] args) {
		try {
			String name = readLine();
			Scanner s = new Scanner(new File("../" + name + ".in"));

			int t = s.nextInt();
			casesRemaining.set(t);
			ArrayList<Case> cases = new ArrayList<Case>(t);
			File f = new File("../" + name + ".out");
			FileWriter output = new FileWriter(f);
			for (int i = 0; i < t; i++) {
				cases.add(i, new Case(i + 1, s));
			}
			if (name.equals("test"))
				cases.stream().forEach(Case::solve);
			else
				cases.parallelStream().forEach(Case::solve);

			for (int i = 0; i < t; i++) {
				output.write(cases.get(i).getResult());
			}
			output.close();
			s.close();

		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	private static String readLine() throws IOException {
		if (System.console() != null) {
			return System.console().readLine();
		}
		BufferedReader reader = new BufferedReader(new InputStreamReader(
				System.in));
		return reader.readLine();
	}

}
