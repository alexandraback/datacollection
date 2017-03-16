import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.util.HashSet;
import java.util.Set;

public class MagicTrick {

	public static void main(String[] args) throws Exception {
		MagicTrick object = new MagicTrick();
		object.work();
	}

	private void work() throws Exception {
		StreamTokenizer st = new StreamTokenizer(new BufferedReader(
				new FileReader(this.getClass().getSimpleName() + ".in")));
		PrintWriter pw = new PrintWriter(new FileWriter(this.getClass()
				.getSimpleName() + ".out"));

		st.nextToken();
		int tcases = (int) st.nval;

		for (int tc = 1; tc <= tcases; tc++) {
			st.nextToken();
			int row1 = (int) st.nval;

			int board1[][] = new int[4][4];

			for (int row = 0; row < 4; row++)
				for (int col = 0; col < 4; col++) {
					st.nextToken();
					board1[row][col] = (int) st.nval;
				}

			st.nextToken();
			int row2 = (int) st.nval;

			int board2[][] = new int[4][4];

			for (int row = 0; row < 4; row++)
				for (int col = 0; col < 4; col++) {
					st.nextToken();
					board2[row][col] = (int) st.nval;
				}

			pw.write("Case #" + tc + ": " + solve(row1, board1, row2, board2)
					+ "\r\n");
		}

		pw.close();
	}

	private String solve(int row1, int[][] board1, int row2, int[][] board2) {
		row1--;
		row2--;

		Set<Integer> possible = new HashSet<>();

		for (int col = 0; col < board1[row1].length; col++)
			possible.add(board1[row1][col]);

		int count = 0, solution = -1;

		for (int col = 0; col < board2[row2].length; col++) {
			if (possible.contains(board2[row2][col])) {
				count++;
				solution = board2[row2][col];
			}
		}

		if (count == 1)
			return String.valueOf(solution);

		if (count > 1)
			return "Bad magician!";

		return "Volunteer cheated!";

	}

}
