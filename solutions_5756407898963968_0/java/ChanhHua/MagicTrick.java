package Qualification;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class MagicTrick {

	private static String WORKING_DIR = "D:\\Working\\CodeJam\\Qualification\\";

	public static void main(String[] args) {

		try {
			Scanner sc = new Scanner(new File(WORKING_DIR + "input.txt"));
			PrintWriter pw = new PrintWriter(new File(WORKING_DIR + "output.txt"));
			int numCase = sc.nextInt();
			for (int i = 0 ; i<numCase ; i++) {
				int[] firstRow = new int[4];
				int[] secondRow = new int[4];
				int first = sc.nextInt();
				for (int row=1; row<=4; row++) {
					for (int col=0; col<4; col++) {
						if (row == first) {
							firstRow[col] = sc.nextInt();
						} else {
							sc.nextInt();
						}
					}
				}
				int second = sc.nextInt();
				for (int row=1; row<=4; row++) {
					for (int col=0; col<4; col++) {
						if (row == second) {
							secondRow[col] = sc.nextInt();
						} else {
							sc.nextInt();
						}
					}
				}
				
				int resCount = 0;
				int res = 0;
				for (int row1=0; row1<4; row1++) {
					for (int row2=0; row2<4; row2++) {
						if (firstRow[row1] == secondRow[row2]) {
							resCount++;
							res = firstRow[row1];
						}
					}
				}
					
				if (resCount == 0) {
					pw.write("Case #" + (i+1) + ": Volunteer cheated!" + "\n");
				} else if (resCount == 1) {
					pw.write("Case #" + (i+1) + ": " + res + "\n");
				} else {
					pw.write("Case #" + (i+1) + ": Bad magician!" + "\n");
				}
				
			}
			pw.flush();
			pw.close();
			sc.close();
			System.out.println("Done!");
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}
	
}
