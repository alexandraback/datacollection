import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Task1 {
	private static InputStream in;
	private static PrintStream out;
	private static Scanner sc;
	static {
		try {
			in = new FileInputStream("A-small-attempt1.in");// System.in;
			out = new PrintStream(new FileOutputStream("out.txt"));// System.out;
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	public static void main(String[] args) {
		sc = new Scanner(in);
		int numCases = sc.nextInt();
		for (int i = 0; i < numCases; i++) {
			out.println("Case #" + (i + 1) + ": " + solve());
		}
	}

	private static String solve() {

		int row1 = sc.nextInt() - 1;
		Integer[][] cards1 = new Integer[4][4];
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++) {
				cards1[i][j] = sc.nextInt();
			}

		List<Integer> afterFirst = Arrays.asList(cards1[row1]);

		int row2 = sc.nextInt() - 1;
		Integer[][] cards2 = new Integer[4][4];
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++) {
				cards2[i][j] = sc.nextInt();
			}

		int numMatches = 0;
		int match = -1;
		for (int i = 0; i < 4; i++) {
			if (afterFirst.contains(cards2[row2][i])) {
				numMatches++;
				match = cards2[row2][i];
			}
		}

		if (numMatches == 0)
			return "Volunteer cheated!";
		if (numMatches == 1)
			return "" + match;
		return "Bad magician!";

	}
}
