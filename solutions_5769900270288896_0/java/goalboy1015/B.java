import java.io.File;
import java.io.PrintStream;
import java.util.Scanner;

public class B {
	static final Boolean SAMPLE = false;
	static final String PROBLEM = "B";
	static final String INPUT = "small";
	static final String ID = "0";
	static final String PATH = "/Users/wangkai/Documents/codejam-commandline-1.2-beta1/source/";

	static int minUnhappy;

	public static void main(String[] args) throws Throwable {
		Scanner in = SAMPLE ? new Scanner(System.in) : new Scanner(new File(
				PATH + PROBLEM + "-" + INPUT + "-" + ID + ".in"));
		PrintStream out = SAMPLE ? System.out : new PrintStream(PATH + PROBLEM
				+ "-" + INPUT + "-" + ID + ".out");

		int test = in.nextInt();
		for (int t = 1; t <= test; t++) {
			out.print("Case #" + t + ": ");

			int R = in.nextInt();
			int C = in.nextInt();
			int N = in.nextInt();

			minUnhappy = Integer.MAX_VALUE;
			search(new boolean[R][C], 0, 0, R * C, N);
			minUnhappy /= 2;

			out.println(minUnhappy);
		}

		out.close();
		in.close();

		System.out.println("finish!");
	}

	static void search(boolean[][] board, int r, int c, int remain,
			int tenantNum) {
		if (remain == 0) {
			minUnhappy = Math.min(minUnhappy, countUnhappy(board));
			return;
		}

		if (c == board[0].length) {
			search(board, r + 1, 0, remain, tenantNum);
			return;
		}

		if (remain > tenantNum) {
			search(board, r, c + 1, remain - 1, tenantNum);
		}
		if (tenantNum > 0) {
			board[r][c] = true;
			search(board, r, c + 1, remain - 1, tenantNum - 1);
			board[r][c] = false;
		}
	}

	static int countUnhappy(boolean[][] board) {
		final int[] OFFSET_R = { -1, 0, 1, 0 };
		final int[] OFFSET_C = { 0, 1, 0, -1 };
		int row = board.length;
		int col = board[0].length;
		int unhappy = 0;
		for (int r = 0; r < row; r++) {
			for (int c = 0; c < col; c++) {
				if (!board[r][c]) {
					continue;
				}
				for (int k = 0; k < OFFSET_R.length; k++) {
					int adjR = r + OFFSET_R[k];
					int adjC = c + OFFSET_C[k];
					if (adjR >= 0 && adjR < row && adjC >= 0 && adjC < col
							&& board[adjR][adjC]) {
						unhappy++;
					}
				}
			}
		}
		return unhappy;
	}
}
