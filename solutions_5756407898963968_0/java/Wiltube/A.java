package qualifiers;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Scanner;

public class A {
	final static Boolean DEBUG_ENABLE = true;
	final static Boolean TIMER_ENABLE = true;

	final static String FILE_NAME = "A-small-attempt0";// <<<--------

	final static String BASE = "C:/CodeJam/" + FILE_NAME;
	final static String INPUT = BASE + ".in";
	final static String OUTPUT = BASE + ".out";
	static Scanner in;
	static PrintWriter out;

	public static void main(String[] args) {
		try {
			in = new Scanner(new FileReader(INPUT));
			out = new PrintWriter(OUTPUT);

			int number_of_cases = in.nextInt();
			in.nextLine();
			for (int c = 0; c < number_of_cases; c++) {
				out.print("Case #" + (c + 1) + ": ");

				if (DEBUG_ENABLE)
					System.out.println("Solving case " + (c + 1) + "...");
				if (TIMER_ENABLE) {
					long startTime = System.currentTimeMillis();
					caseSolver();
					long endTime = System.currentTimeMillis();
					System.out.println((endTime - startTime) + " ms");
				} else
					caseSolver();

				out.println();
			}
			out.println();
			out.flush();
			out.close();
			in.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}

	private static void caseSolver() {
		int[] first_row = new int[4];
		int[] second_row = new int[4];
		int first_choose;
		int second_choose;

		first_choose = in.nextInt() - 1;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (first_choose == i)
					first_row[j] = in.nextInt();
				else
					in.nextInt();
			}
		}
		second_choose = in.nextInt() - 1;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (second_choose == i)
					second_row[j] = in.nextInt();
				else
					in.nextInt();
			}
		}

		int count = 0;
		int card = -1;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (first_row[i] == second_row[j]) {
					card = first_row[i];
					count++;
				}
			}
		}

		if (count > 1)
			out.print("Bad magician!");
		else if (count == 0)
			out.print("Volunteer cheated!");
		else
			out.print(card);
	}
}
