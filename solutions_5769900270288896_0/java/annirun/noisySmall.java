import java.util.Arrays;
import java.util.Scanner;

public class noisySmall {
	static int[][][] memo;
	static final int inf = 1_000_000;

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int cases = in.nextInt();
		int cn = 0;

		while (cn++ < cases) {
			int rows = in.nextInt();
			int cols = in.nextInt();

			if (cols > rows) {
				int tmp = rows;
				rows = cols;
				cols = tmp;
			}

			int people = in.nextInt();

			memo = new int[rows][1 << cols][people + 1];
			for (int[][] iss : memo) {
				for (int[] is : iss) {
					Arrays.fill(is, inf);
				}
			}

			System.out.printf("Case #%d: %d\n", cn, dp(0, 0, people));
		}
	}

	private static int dp(int r, int lastC, int peopleLeft) {
		if (r == memo.length)
			return peopleLeft == 0 ? 0 : inf;
		if (memo[r][lastC][peopleLeft] != inf)
			return memo[r][lastC][peopleLeft];
		
		int best = inf;
		for (int hereC = 0; hereC < memo[0].length; hereC++) {
			if (Integer.bitCount(hereC) > peopleLeft)
				continue;
			
			int cost = Integer.bitCount(hereC & lastC);
			for (int bit = 1; bit < memo[0].length; bit<<=1) {
				if ((hereC & bit) != 0 && (hereC & (bit<<1)) != 0)
					cost++;
			}
			
			best = Math.min(best, cost + dp(r+1, hereC, peopleLeft - Integer.bitCount(hereC)));
		}
		
		return memo[r][lastC][peopleLeft] = best;
	}
}
