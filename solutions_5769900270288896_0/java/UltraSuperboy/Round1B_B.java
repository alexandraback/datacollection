package CodeJam2015;

import java.util.Scanner;

public class Round1B_B {
	
	static boolean map[][] = new boolean[17][17];
	static int R, C;
	static int best;
	
	static int dir[][] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
	
	static void recur(int left, int unhappiness, int last) {
		if (left == 0) {
			if (unhappiness < best)
				best = unhappiness;
			return;
		}
		for (int x = last+1; x < R*C; x++) {
			int i = x / C;
			int j = x % C;
			if (!map[i][j]) {
				map[i][j] = true;
				int newunhappy = unhappiness;
				for (int d = 0; d < 4; d++) {
					int di = i + dir[d][0];
					int dj = j + dir[d][1];
					if (di >= 0 && di < R && dj >= 0 && dj < C && map[di][dj])
						newunhappy++;
				}
				recur(left-1, newunhappy, x);
				map[i][j] = false;
			}
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int cases = 1; cases <= T; cases++) {
			R = sc.nextInt();
			C = sc.nextInt();
			int N = sc.nextInt();
			
			for (int i = 0; i < R; i++)
				for (int j = 0; j < C; j++)
					map[i][j] = false;
			best = 99999999;
			recur(N, 0, -1);
			System.out.println("Case #" + cases + ": " + best);
		}
		sc.close();
	}

}
/*
4
2 3 6
4 1 2
3 3 8
5 2 0
*/