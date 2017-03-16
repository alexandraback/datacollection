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

	int[] x, y;
	int n;

	public String getResult() {
		return "Case #" + caseNumber + ": " + result + "\n";
	}

	public void parse(Scanner s) {
		n = s.nextInt();
		x = new int[n];
		y = new int[n];
		for (int i = 0; i < n; i++) {
			x[i] = s.nextInt();
			y[i] = s.nextInt();
		}
	}

	private int line(int ax, int ay, int bx, int by, int cx, int cy) {
		return ((bx - ax) * (cy - ay) - (by - ay) * (cx - ax));
	}

	StringBuilder sb = new StringBuilder();

	public void s() {
		int[] res = new int[n];
		for (int i = 0; i < n; i++) {
			res[i] = Integer.MAX_VALUE;
			for (int j = 0; j < n; j++) {
				if (i == j)
					continue;
				int countLeft = 0, countRight = 0;
				for (int k = 0; k < n; k++) {
					if (i == k || j == k)
						continue;
					int d = line(x[i], y[i], x[j], y[j], x[k], y[k]);
					if (d < 0)
						countLeft++;
					else if (d > 0)
						countRight++;
				}
				res[i] = Math.min(countLeft, Math.min(countRight, res[i]));
				if (countLeft == 0 || countRight == 0)
					break;
			}
			sb.append('\n').append(res[i]);
		}
	}

	public void solve() {
		s();
		result = sb.toString();

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
