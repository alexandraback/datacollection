package gcj2014;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;

public class TheRepeater {
	static String PATH = "data/gcj2014/1b/", PROBLEM = "A", SIZE = "small",
			ATTEMPT = "2";

	static int minActions(String s0, String s1) {
		int l0 = s0.length(), l1 = s1.length();
		int[][] costs = new int[l0][];
		for (int i = 0; i < l0; i++) {
			costs[i] = new int[l1];
		}
		costs[0][0] = (s0.charAt(0) == s1.charAt(0) ? 0 : -1);
		for (int j = 1; j < l1; j++) {
			if (s1.charAt(j - 1) == s1.charAt(j) && costs[0][j - 1] != -1)
				costs[0][j] = costs[0][j - 1] + 1;
			else
				costs[0][j] = -1;
		}
		for (int i = 1; i < l0; i++) {
			if (s0.charAt(i - 1) == s0.charAt(i) && costs[i - 1][0] != -1)
				costs[i][0] = costs[i - 1][0] + 1;
			else
				costs[i][0] = -1;
			int min = -1;
			for (int j = 1; j < l1; j++) {
				if (s0.charAt(i) == s1.charAt(j))
					if (min == -1 || costs[i - 1][j - 1] < min)
						min = costs[i - 1][j - 1];
				if (s0.charAt(i - 1) == s0.charAt(i) && costs[i - 1][j] != -1)
					if (min == -1 || costs[i - 1][j] + 1 < min)
						min = costs[i - 1][j] + 1;
				if (s1.charAt(j - 1) == s1.charAt(j) && costs[i][j - 1] != -1)
					if (min == -1 || costs[i][j - 1] + 1 < min)
						min = costs[i][j - 1] + 1;
				costs[i][j] = min;
			}
		}
		return costs[l0 - 1][l1 - 1];
	}

	static int minActions1(String[] strs) {
		int l = strs.length;
		int[] cursors = new int[l];
		int cost = 0;
		while (true) {
			// First check if the cursors are pointing to a same char
			for (int i = 1; i < l; i++)
				if (strs[i].charAt(cursors[i]) != strs[0].charAt(cursors[0]))
					return -1;
			// Now all the chars are the same. Try to move to the end of this
			// same-char-sequence
			int[] steps = new int[l];
			for (int i = 0; i < l; i++) {
				int c = cursors[i] + 1;
				while (c < strs[i].length()
						&& strs[i].charAt(c) == strs[i].charAt(cursors[i])) {
					c++;
				}
				steps[i] = c - cursors[i];
				cursors[i] = c;
			}
			// Find the median same-char-sequence as the destination
			Arrays.sort(steps);
			int med = steps[l / 2];
			// Then find the necessary actions
			int sum = 0;
			for (int i = 0; i < l; i++) {
				sum += Math.abs(steps[i] - med);
			}
			// The necessary actions for this character is:
			cost += sum;
			// Now all the cursors have moved to the char after this
			// same-char-sequence, check if some are beyond the length
			int atEnd = 0;
			for (int i = 0; i < l; i++)
				if (cursors[i] >= strs[i].length())
					atEnd++;
			if (atEnd == 0)
				// not finished yet
				continue;
			if (atEnd == l)
				// all finished
				return cost;
			// Not all strings finish at the same time
			return -1;
		}

	}

	public static void main(String[] args) throws IOException {
		String filename = PATH + PROBLEM + "-" + SIZE;
		if (SIZE.equals("small"))
			filename += "-attempt" + ATTEMPT;
		Scanner sc = new Scanner(new File(filename + ".in"));
		BufferedWriter bw = new BufferedWriter(
				new FileWriter(filename + ".out"));
		int T = sc.nextInt();
		for (int t = 0; t < T; t++) {
			System.out.println("Case " + t);

			int N = sc.nextInt();
			String[] strs = new String[N];
			for (int i = 0; i < N; i++) {
				strs[i] = sc.next();
			}

			int act = minActions1(strs);
			// System.out.println(strs[0] + ", " + strs[1] + ": " + act);

			bw.write("Case #" + (t + 1) + ": "
					+ (act == -1 ? "Fegla Won" : act));
			bw.newLine();
		}
		sc.close();
		bw.close();
	}
}
