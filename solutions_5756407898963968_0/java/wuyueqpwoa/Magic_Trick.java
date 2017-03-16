import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintStream;
import java.util.HashSet;
import java.util.Scanner;

public class Magic_Trick {

	private Scanner sc = new Scanner(System.in);
	private PrintStream ps = new PrintStream(System.out);

	public void setIO(InputStream is, OutputStream os) {
		sc = new Scanner(is);
		ps = new PrintStream(os);
	}

	public void solve() throws FileNotFoundException {
		int cases = sc.nextInt();

		for (int tCases = 1; tCases <= cases; ++tCases) {
			HashSet<Integer> data = new HashSet<>();

			// input1
			int answer1 = sc.nextInt();

			for (int i = 1; i <= 4; ++i) {
				for (int j = 1; j <= 4; ++j) {
					int temp = sc.nextInt();

					if (i == answer1) {
						data.add(temp);
					}
				}
			}

			// input2
			int answer2 = sc.nextInt();
			int count = 0, realAnswer = 0;

			for (int i = 1; i <= 4; ++i) {
				for (int j = 1; j <= 4; ++j) {
					int temp = sc.nextInt();

					if (i == answer2) {
						if (!data.add(temp)) {
							++count;
							realAnswer = temp;
						}
					}
				}
			}

			if (count == 1) {
				ps.println("Case #" + tCases + ": " + realAnswer);
			} else if (count > 1) {
				ps.println("Case #" + tCases + ": Bad magician!");
			} else if (count == 0) {
				ps.println("Case #" + tCases + ": Volunteer cheated!");
			}
		}

		sc.close();
	}

	public static void main(String[] args) throws FileNotFoundException {
		InputStream is = new FileInputStream(
				"Problems\\Magic_Trick\\A-small-attempt2.in");
		OutputStream os = new FileOutputStream(
				"Problems\\Magic_Trick\\A-small-attempt2.out");

		Magic_Trick solver = new Magic_Trick();
		solver.setIO(is, os);
		solver.solve();
	}
}
