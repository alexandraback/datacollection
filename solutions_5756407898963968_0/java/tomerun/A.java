import java.util.Scanner;

public class A {

	static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		int T = sc.nextInt();
		for (int i = 1; i <= T; ++i) {
			System.out.printf("Case #%d: %s\n", i, solve());
		}
	}

	static String solve() {
		int cand = row() & row();
		int pop = Integer.bitCount(cand);
		if (pop == 1) {
			return "" + Integer.numberOfTrailingZeros(cand);
		} else if (pop == 0) {
			return "Volunteer cheated!";
		} else {
			return "Bad magician!";
		}
	}

	static int row() {
		int r = sc.nextInt() - 1;
		int[][] matrix = new int[4][4];
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				matrix[i][j] = sc.nextInt();
			}
		}
		int ret = 0;
		for (int i = 0; i < 4; ++i) {
			ret |= 1 << matrix[r][i];
		}
		return ret;
	}

}