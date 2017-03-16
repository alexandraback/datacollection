/* 
 * Google Code Jam - 2015 - Round 1B - Problem B "Noisy Neighbors"
 * Solution for small input by Qiyu Zhu
 */

import java.util.Scanner;


public class ProblemBSmall {
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int cases = in.nextInt();
		for (int i = 0; i < cases; i++)
			System.out.printf("Case #%d: %d%n", i + 1, handleCase(in));
	}
	
	
	private static int handleCase(Scanner in) {
		int r = in.nextInt();
		int c = in.nextInt();
		int n = in.nextInt();
		
		int min = Integer.MAX_VALUE;
		boolean[][] grid = new boolean[r][c];
		for (int i = 0, end = 1 << (r * c); i < end; i++) {
			if (Integer.bitCount(i) != n)
				continue;
			for (int y = 0; y < r; y++) {
				for (int x = 0; x < c; x++)
					grid[y][x] = ((i >>> (y * c + x)) & 1) != 0;
			}
			
			int count = 0;
			for (int y = 0; y < r - 1; y++) {
				for (int x = 0; x < c; x++) {
					if (grid[y][x] && grid[y + 1][x])
						count++;
				}
			}
			for (int y = 0; y < r; y++) {
				for (int x = 0; x < c - 1; x++) {
					if (grid[y][x] && grid[y][x + 1])
						count++;
				}
			}
			min = Math.min(count, min);
		}
		return min;
	}
	
}
