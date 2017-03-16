import java.util.Scanner;

public class b {
	public static int solve(boolean[][] grid, int r, int c, int n, int sr, int sc)
	{
		if (n == 0) {
			int u = 0;
			for (int i = 0; i < r; i++) {
				for (int j = 1; j < c; j++) {
					if (grid[i][j - 1] && grid[i][j]) {
						u++;
					}
				}
			}
			for (int j = 0; j < c; j++) {
				for (int i = 1; i < r; i++) {
					if (grid[i - 1][j] && grid[i][j]) {
						u++;
					}
				}
			}
			return u;
		}
		else {
			int nr, nc;
			if (sc + 1 == c) {
				nr = sr + 1;
				nc = 0;
			}
			else {
				nr = sr;
				nc = sc + 1;
			}
			grid[sr][sc] = true;
			int x = solve(grid, r, c, n - 1, nr, nc);
			grid[sr][sc] = false;
			int rem = c * (r - sr - 1) + c - sc;
			int y;
			if (rem > n) {
				y = solve(grid, r, c, n, nr, nc);
			}
			else {
				y = x;
			}
			return Math.min(x,  y);
		}
	}
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int caseNum = 1; caseNum <= t; caseNum++) {
			int r = sc.nextInt();
			int c = sc.nextInt();
			int n = sc.nextInt();
			boolean[][] grid = new boolean[r][c];
			System.out.println("Case #" + caseNum + ": " + solve(grid, r, c, n, 0, 0));
		}
	}
}
