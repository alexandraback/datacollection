import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Scanner;

public class ProblemA {
	private static Scanner in;
	private static PrintWriter out;

	private void solve() {
		int row1, row2;
		HashSet<Integer> grid1, grid2;
		
		row1 = in.nextInt();
		grid1 = new HashSet<>();
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (i == row1 - 1) {
					grid1.add(in.nextInt());
				} else {
					in.nextInt();
				}
			}
		}
		row2 = in.nextInt();
		grid2 = new HashSet<>();
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (i == row2 - 1) {
					grid2.add(in.nextInt());
				} else {
					in.nextInt();
				}
			}
		}
		grid1.retainAll(grid2);
		switch (grid1.size()) {
		case 0:
			out.print("Volunteer cheated!");
			break;
		case 1:
			out.print(grid1.iterator().next());
			break;
		default:
			out.print("Bad magician!");
			break;
		}
	}

	public static void main(String[] args) {
		try {
			in = new Scanner(new FileReader(args[0]));
			out = new PrintWriter(new FileWriter(args[1]));
			int tests = in.nextInt();
			for (int test = 1; test <= tests; test++) {
				System.out.println("Processing case #" + test);
				out.print("Case #" + test + ": ");
				new ProblemA().solve();
				out.println();
			}
			in.close();
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
