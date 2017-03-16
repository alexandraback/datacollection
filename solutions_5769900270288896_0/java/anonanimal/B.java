import java.util.Scanner;

public class B {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for (int i = 0; i < T; i++) {
			int ans = solve(in);
			System.out.printf("Case #%d: %d\n", i + 1, ans);
		}

	}

	static int R, C, N;

	public static int solve(Scanner in) {
		R = in.nextInt();
		C = in.nextInt();
		N = in.nextInt();

		boolean[][] state = new boolean[R][C];

		int ans = backtrack(state, 0, 0, N);
		return ans;
	}

	public static int backtrack(boolean[][] state, int curR, int curC, int n) {

		if (n == 0) {
			return score(state);
		}

		if (curR == R) {
			return 1000000000;
		}

		int nextR, nextC;

		if (curC == C - 1) {
			nextR = curR + 1;
			nextC = 0;

		} else {
			nextR = curR;
			nextC = curC + 1;
		}

		// Don't place one here
		int candidate1 = backtrack(state, nextR, nextC, n);

		state[curR][curC] = true;
		int candidate2 = backtrack(state, nextR, nextC, n - 1);
		state[curR][curC] = false;

		return Math.min(candidate1, candidate2);
	}

	public static int score(boolean[][] state) {

		int ans = 0;
		for (int i = 0; i < state.length; i++) {
			for (int j = 0; j < state[0].length; j++) {
				if (state[i][j] == false) {
					continue;
				}

				if (j != 0) {
					if (state[i][j - 1]) {
						ans++;
					}
				}
				if (i != 0) {
					if (state[i - 1][j]) {
						ans++;
					}

				}
				if (i < state.length - 1) {
					if (state[i + 1][j]) {
						ans++;
					}

				}
				if (j < state[0].length - 1) {
					if (state[i][j + 1]) {
						ans++;
					}
				}

			}
		}

		return ans / 2;
	}

}
