package Round1B;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Locale;
import java.util.Scanner;

public class ProblemA {

	static BufferedWriter out;

	public static void solve(Scanner sc) throws IOException {
		int n = sc.nextInt();
		String[] s = new String[n];
		for (int i = 0; i < s.length; i++) {
			s[i] = sc.next();
		}
		// check possible
		int[] pos = new int[n];

		String reduce = removeDuplicates(s[0]);
		for (int i = 0; i < pos.length; i++) {
			if (!reduce.equals(removeDuplicates(s[i]))) {
				System.out.println("Fegla Won");
				out.write("Fegla Won\n");
				return;
			}
		}

		int changes = 0;
		int[] diff = new int[n];
		while (true) {
			if (pos[0] == s[0].length()) {
				break;
			}
			char currChar = s[0].charAt(pos[0]);
			for (int i = 0; i < s.length; i++) {
				diff[i] = 0;
				while (pos[i] < s[i].length()
						&& s[i].charAt(pos[i]) == currChar) {
					pos[i]++;
					diff[i]++;
				}
			}
			// find number of changes
			Arrays.sort(diff);
			for (int i = 0; i < diff.length; i++) {
				changes += Math.abs(diff[i] - diff[n / 2]);
			}
		}
		System.out.println(changes);
		out.write(changes + "\n");

	}

	public static String removeDuplicates(String s) {
		StringBuilder b = new StringBuilder();
		char last = ' ';
		for (int i = 0; i < s.length(); i++) {
			char c = s.charAt(i);
			if (last != c) {
				b.append(c);
				last = c;
			}
		}

		return b.toString();
	}

	public static void main(String[] args) throws IOException {
//		 String name = "A-practice";
//		String name = "A-small-attempt3";
		 String name = "A-large";
		Scanner sc = new Scanner(new File(name + ".in"));
		sc.useLocale(Locale.US);

		FileWriter fstream = new FileWriter(name + ".out");
		out = new BufferedWriter(fstream);

		int cases = sc.nextInt();

		for (int i = 1; i <= cases; i++) {
			System.out.format(Locale.US, "Case #%d: ", i);
			out.write("Case #" + i + ": ");
			solve(sc);
		}
		sc.close();
		out.close();
	}
}
