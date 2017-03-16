/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package GCJ;

import java.io.IOException;

/**
 *
 * @author t7639192
 */
public class ProblemB {

	/**
	 * @param args the command line arguments
	 */
	public static void main(String[] args) {
		try {
			new GCJSolver("B-small-attempt0.in", "B-small-attempt0.out") {
				private int total = 0;
				private int unhapiness = 0;
				private int minUnhapinness, R, C, N;
				private short[][] grid;

				@Override
				public void solve() throws IOException {
					R = in.nextInt();
					C = in.nextInt();
					N = in.nextInt();

					if (N >= R * C) {
						out.println(2 * R * C - C - R);
						return;
					}
					if(N == 0){
						out.println(0);
						return;
					}

					minUnhapinness = 4 * R * C;
					grid = new short[R][C];
					helpSolve(0, 0);
					out.println(minUnhapinness);
				}

				private void helpSolve(int x, int y) {
					grid[x][y] = 1;
					total++;
					int change = 0;
					if (x > 0) {
						change += grid[x - 1][y];
					}
					if (y > 0) {
						change += grid[x][y - 1];
					}
					if (x < R - 1) {
						change += grid[x + 1][y];
					}
					if (y < C - 1) {
						change += grid[x][y + 1];
					}
					unhapiness += change;
					if (total >= N) {
						minUnhapinness = Math.min(minUnhapinness, unhapiness);
						grid[x][y] = 0;
						total--;
						unhapiness -= change;
					}
					if (y < C - 1) {
						helpSolve(x, y + 1);
					} else if (x < R - 1) {
						helpSolve(x + 1, 0);
					}
					if (grid[x][y] > 0) {
						grid[x][y] = 0;
						total--;
						unhapiness -= change;
						if (y < C - 1) {
							helpSolve(x, y + 1);
						} else if (x < R - 1) {
							helpSolve(x + 1, 0);
						}
					}
				}
			}.solveAll().close();
		} catch (Exception ex) {
			ex.fillInStackTrace();
		}
	}
}
