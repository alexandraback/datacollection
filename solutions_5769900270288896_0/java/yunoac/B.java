package R1B;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class B {

	static Scanner reader;
	static PrintWriter writer;
	
	public static void main(String[] args) throws IOException {
		reader = new Scanner(new FileReader("input"));
		writer = new PrintWriter(new FileWriter("output"));
		int nt = reader.nextInt();
		for(int tc = 1; tc <= nt; tc++) {
			solve(tc);
		}
		writer.close();
		reader.close();
	}

	static void solve(int tc) {
		best = Integer.MAX_VALUE;
		r = reader.nextInt();
		c = reader.nextInt();
		n = reader.nextInt();
		brute(0, 0, new int[r][c], 0);
		writer.printf("Case #%d: %d\n", tc, best);
	}
	
	static int r, c, n;
	
	static int[][] dir = new int[][] {
		new int[] {-1, 0},
		new int[] {1, 0},
		new int[] {0, -1},
		new int[] {0, 1}
	};
	
	static int best = Integer.MAX_VALUE;
	
	static void brute(int i, int j, int[][] g, int cnt) {
		
		if(i == r) {
			if(cnt == n) {
				int score = 0;
				for(int ii = 0; ii < r; ii++) {
					for(int jj = 0; jj < c; jj++) {
						for(int[] d : dir) {
							int iii = ii + d[0];
							int jjj = jj + d[1];
							if(0 <= iii && iii < r && 0 <= jjj && jjj < c) {
								if(g[ii][jj] == 1 && g[iii][jjj] == 1) {
									score++;
								}
							}
						}
					}
				}
				score /= 2;
				best = Math.min(best, score);
			}
		} else {
			
		
		if(j + 1 == c) {
			g[i][j] = 0;
			brute(i + 1, 0, g, cnt);
			g[i][j] = 1;
			brute(i + 1, 0, g, cnt + 1);
		} else {
			g[i][j] = 0;
			brute(i, j + 1, g, cnt);
			g[i][j] = 1;
			brute(i, j + 1, g, cnt + 1);
			
		}
		
		}
		
	}
	
}
