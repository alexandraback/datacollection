package cz.phx.gcj2016.round1C;

import java.io.*;
import java.util.Arrays;
import java.util.Scanner;
import java.util.stream.Stream;

import static java.util.Arrays.stream;

/**
 * Created by PHX on 08.05.2016.
 */
public class Task1CA {

	private static int YEAR = 2016;
	private static String ROUND = "round1C";

	private final int t;

	public static void main(String[] args) throws IOException {
//		new Task1CA("A-test");
		new Task1CA("A-small-attempt0");
//		new Task1CA("A-large");
	}

	public Task1CA(String inFile) throws IOException {

		String folder = "resources/" + YEAR + "/" + ROUND + "/";

		Scanner scanner = new Scanner(new File(folder + inFile + ".in"));

		FileWriter fw = new FileWriter(folder + inFile + ".out");
		BufferedWriter writer = new BufferedWriter(fw);

		t = scanner.nextInt();

		for (int i = 0; i < t; i++) {
			processOne(i, scanner, writer);
		}

		scanner.close();
		writer.close();
	}

	private void processOne(int t, Scanner scanner, BufferedWriter writer) throws IOException {
		int n = scanner.nextInt();
		int[] inRoom = new int[n];
		for (int i = 0; i < n; i++) {
			inRoom[i] = scanner.nextInt();
		}

		StringBuilder go = new StringBuilder();
		do {
			int max = Arrays.stream(inRoom).max().getAsInt();

			if (max == 0) break;

			int maxCount = 0;
			int noZero = 0;
			for (int i = 0; i < n; i++) {
				if (inRoom[i] == max) maxCount++;
				if (inRoom[i] > 0) noZero++;
			}

			int toGo = 1;
			if (noZero == 2 && maxCount == 2) toGo = 2;

			for (int i = 0; i < n; i++) {
				if (inRoom[i] == max) {
					inRoom[i]--;
					toGo--;
					go.append(convertToLetter(i));
				}
				if (toGo == 0) break;
			}
			go.append(" ");

		} while (hasAny(inRoom));

		String result = go.toString();

		String row = "Case #" + (t + 1) + ": " + result;
		writer.write(row + "\n");
		System.out.println(row);
	}

	private boolean hasAny(int[] inRoom) {
		for (int i = 0; i < inRoom.length; i++) {
			if (inRoom[i] > 0) return true;
		}
		return false;
	}

	private String convertToLetter(int i) {
		return  "ABCDEFGHIJKLMNOPQRSTUVWXYZ".substring(i, i+1);
	}
}
