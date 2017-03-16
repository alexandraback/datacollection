import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

public class TheRepeater {

	public static void main(String[] args) {
		Scanner scanner = null;
		try {
			scanner = new Scanner(new File("input.txt"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		int T = scanner.nextInt();
		FileWriter writer = null;
		try {
			writer = new FileWriter(new File("output.txt"));
		} catch (IOException e1) {
			e1.printStackTrace();
		}
		for (int trial = 1; trial <= T; trial++) {
			try {
				writer.write("Case #" + trial + ": ");
			} catch (IOException e1) {
				e1.printStackTrace();
			}
			try {
				solveTrial(scanner, writer);
			} catch (IOException e) {
				e.printStackTrace();
			}
			try {
				writer.write("\n");
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
		try {
			writer.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
		scanner.close();
	}

	static void solveTrial(Scanner scanner, FileWriter writer)
			throws IOException {
		int N = -1;
		while (N == -1) {
			String next = scanner.next();
			try {
				N = Integer.parseInt(next);
			} catch (Exception e) {
			}
		}
		char[] condensedString;
		int[][] condensedStringCount;
		String firstString = scanner.next();
		condensedString = new char[firstString.length()];
		condensedString[0] = firstString.charAt(0);
		int b = 1;
		int count = 1;
		condensedStringCount = new int[condensedString.length][N];
		for (int i = 1; i < firstString.length(); i++) {
			if (firstString.charAt(i) != firstString.charAt(i - 1)) {
				condensedStringCount[b - 1][0] = count;
				count = 1;
				condensedString[b] = firstString.charAt(i);
				b++;
			} else {
				count++;
			}
		}
		condensedStringCount[b - 1][0] = count;
		int maxB = b;
		for (int stringNum = 1; stringNum < N; stringNum++) {
			String newString = scanner.next();
			b = 1;// condensed string counter
			if (newString.charAt(0) != condensedString[0]) { // first character
																// is wrong
				writer.write("Fegla Won");
				return;
			}
			count = 1;
			for (int i = 1; i < newString.length(); i++) {
				if (newString.charAt(i) != newString.charAt(i - 1)) {
					condensedStringCount[b - 1][stringNum] = count;
					count = 1;
					if (b >= condensedString.length
							|| condensedString[b] != newString.charAt(i)) {
						writer.write("Fegla Won");
						return;
					}
					b++;
					if (b > maxB) {
						writer.write("Fegla Won");
						return;
					}
				} else {
					count++;
				}
			}
			condensedStringCount[b - 1][stringNum] = count;
			if (b != maxB) { // doesnt have enough characters
				writer.write("Fegla Won");
				return;
			}
		}
		// now we know for sure that it is possible
		int moves = 0;
		for (b = 0; b < maxB; b++) {
			Arrays.sort(condensedStringCount[b]);
			int median;
			if (N % 2 == 0) {
				median = (condensedStringCount[b][N / 2] + condensedStringCount[b][(N / 2) - 1]) / 2;
			} else
				median = condensedStringCount[b][(N - 1) / 2];
			for (int i = 0; i < N; i++) {
				moves += Math.abs(condensedStringCount[b][i] - median);
			}
		}
		writer.write(moves + "");
		return;
	}
}
