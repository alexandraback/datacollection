package com.google.jam2014.QR;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Scanner;

public class MagicTrick {

	/**
	 * @param args
	 * @throws FileNotFoundException 
	 */
	public static void main(String[] args) throws FileNotFoundException {
		FileInputStream fis = new FileInputStream(args[0]);
		PrintWriter pw = new PrintWriter(new File(args[1]));
		Scanner scanner = new Scanner(fis);
		int T = scanner.nextInt();
		for (int t = 0; t < T; t++) {
			HashSet<Integer> candidates = new HashSet<Integer>();
			int answer = -1;
			int a1 = scanner.nextInt();
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					int cc = scanner.nextInt();
					if (i + 1 == a1) {
						candidates.add(cc);
					}
				}
			}
			
			int a2 = scanner.nextInt();
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					int cc = scanner.nextInt();
					if (a2 == i + 1) {
						if (candidates.contains(cc)) {
							if (answer == -1) {
								answer = cc;
							} else {
								answer = -2;
							}
						}
					}
				}
			}
			if (answer == -1) {
				pw.println("Case #" + (t+1) + ": Volunteer cheated!");
			} else if (answer == -2) {
				pw.println("Case #" + (t+1) + ": Bad magician!");
			} else 
				pw.println("Case #" + (t+1) + ": " + answer);
		}
		pw.close();
	}

}
