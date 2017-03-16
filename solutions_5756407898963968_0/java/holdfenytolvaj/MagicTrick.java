package gcjpractice.qualification2014;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class MagicTrick {
	private static final String VOLUNTER_MISTAKE = "Volunteer cheated!";
	private static final String MAGICIAN_MISTAKE = "Bad magician!";

	private static Integer[][] getIntMatrix(Scanner sc, int rows, int colums) {
		Integer[][] m = new Integer[rows][colums];
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < colums; j++) {
				m[i][j] = sc.nextInt();
			}
			sc.nextLine();
		}
		return m;
	}

	public static void main(String[] args) {
		String base = "/home/radicsge/gcj2014/qualification/";
		String input = base + "a2.in";
		String output = base + "a2.out";

		try {
			Scanner sc = new Scanner(new FileReader(input));
			PrintWriter pw = new PrintWriter(output);

			int n = sc.nextInt();
			sc.nextLine();
			for (int c = 0; c < n; c++) {
				System.out.println("Test case " + (c + 1) + "...");
				pw.print("Case #" + (c + 1) + ": ");

				int firstAnswer = sc.nextInt();
				sc.nextLine();
				Integer[][] first = getIntMatrix(sc, 4, 4);
				int secondAnswer = sc.nextInt();
				sc.nextLine();
				Integer[][] second = getIntMatrix(sc, 4, 4);

				pw.println(solve(first, second, firstAnswer, secondAnswer));

			}
			pw.println();
			pw.flush();
			pw.close();
			sc.close();
		} catch (FileNotFoundException ex) {
			ex.printStackTrace();
		}
	}

	private static String solve(Integer[][] first, Integer[][] second, Integer firstAnswer, Integer secondAnswer) {
		List<Integer> possibleAnswers = new ArrayList<>(Arrays.asList(first[firstAnswer - 1]));
		possibleAnswers.retainAll(Arrays.asList(second[secondAnswer - 1]));

		if (possibleAnswers.size() == 1) {
			return possibleAnswers.get(0).toString();
		} else if (possibleAnswers.size() == 0) {
			return VOLUNTER_MISTAKE;
		} else {
			return MAGICIAN_MISTAKE;
		}
	}
}
