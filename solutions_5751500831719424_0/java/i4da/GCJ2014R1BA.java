package gcj;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class GCJ2014R1BA {

	//n==2
	String solveSmall(int n, String[] strs) {
		int i = 0, j = 0;
		int s0 = 0, s1 = 0;

		int ans = 0;
		boolean isNG = false;
		while (i < strs[0].length() && j < strs[1].length()) {
			char c0 = strs[0].charAt(i);
			while (i < strs[0].length() && strs[0].charAt(i) == c0) {
				i++;
			}
			int cnt0 = i - s0;
			s0 = i;

			char c1 = strs[1].charAt(j);
			if (c0 != c1) {
				isNG = true;
				break;
			}
			while (j < strs[1].length() && strs[1].charAt(j) == c0) {
				j++;
			}
			int cnt1 = j - s1;
			s1 = j;

			ans += Math.abs(cnt0 - cnt1);
		}
		if (i != strs[0].length() || j != strs[1].length()) {
			isNG = true;
		}

		return isNG ? "Fegla Won" : ans + "";
	}

	String solve(int n, String[] strs) {
		return solveSmall(n, strs);
	}

	String solve(Scanner sc) {
		StringBuilder sb = new StringBuilder();
		int testCaseSize = sc.nextInt();
		for (int tc = 1; tc <= testCaseSize; tc++) {
			int n = sc.nextInt();
			String[] strings = new String[n];
			for (int i = 0; i < n; i++) {
				strings[i] = sc.next();
			}

			sb.append("Case #").append(tc).append(": ")
					.append(solve(n, strings)).append('\n');
		}
		return sb.toString();
	}

	String solve(String inputFilePath) throws FileNotFoundException {
		Scanner sc = new Scanner(new FileReader(inputFilePath));
		String ans = solve(sc);
		sc.close();
		return ans;
	}

	final static String WORK_DIR = "dat/gcj2014r1b/";

	public static void main(String[] args) throws IOException {
//		String fileName = "A-sample";
				String fileName = "A-small-attempt1";
		//		String fileName = "A-large";
		String inputFileName = fileName + ".in";
		String outputFileName = fileName + ".out";
		PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR
				+ outputFileName));
		pw.print(new GCJ2014R1BA().solve(WORK_DIR + inputFileName));
		pw.flush();
		pw.close();
	}

}
