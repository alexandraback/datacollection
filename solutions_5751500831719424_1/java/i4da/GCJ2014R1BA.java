package gcj;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
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

	// 2<=n<=100
	String solveLarge(int n, String[] strs) {
		int[] cur = new int[n];
		int[] st = new int[n];

		int ans = 0;
		boolean isNG = false;
		while (true) {
			boolean isFinished = false;
			for (int i = 0; i < n; i++) {
				if (cur[i] == strs[i].length()) {
					isFinished = true;
				} else {
					isNG = true;
				}
			}
			if (isFinished) {
				break;
			} else {
				isNG = false;
			}

			char[] c = new char[n];
			int[] cnt = new int[n];
			for (int i = 0; i < n; i++) {
				c[i] = strs[i].charAt(cur[i]);
				while (cur[i] < strs[i].length()
						&& strs[i].charAt(cur[i]) == c[i]) {
					cur[i]++;
				}
				cnt[i] = cur[i] - st[i];
				st[i] = cur[i];
			}

			if (!isSameElement(c)) {
				isNG = true;
				break;
			}

			ans += getMinActionNum(cnt);
		}
		return isNG ? "Fegla Won" : ans + "";
	}

	boolean isSameElement(char[] c) {
		if (c.length <= 1)
			return true;
		for (int i = 1; i < c.length; i++) {
			if (c[i] != c[i - 1])
				return false;
		}
		return true;
	}

	int getMinActionNum(int[] cnt) {
		int min = Integer.MAX_VALUE;
		for (int i = 0; i < cnt.length; i++) {
			int sum = 0;
			for (int j = 0; j < cnt.length; j++) {
				sum += Math.abs(cnt[i] - cnt[j]);
			}
			min = Math.min(min, sum);
		}
		return min;

	}

	String solve(int n, String[] strs) {
		return solveLarge(n, strs);
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
//		String fileName = "A-small-attempt1";
				String fileName = "A-large";
		String inputFileName = fileName + ".in";
		String outputFileName = fileName + ".out";
		PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR
				+ outputFileName));
		pw.print(new GCJ2014R1BA().solve(WORK_DIR + inputFileName));
		pw.flush();
		pw.close();
	}

}
