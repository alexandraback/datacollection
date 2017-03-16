package googleCodeJam_5_15_1B;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

public class B {
	static String probName = "B";
	static boolean small = true;
	static Scanner in ;
		
	public static void main(String[] args) throws FileNotFoundException {
		System.setIn(new FileInputStream(new File(probName + "-" + ((small)? "small" : "large") + ".in")));
		System.setOut(new PrintStream(new File(probName + "-" + ((small)? "small" : "large") + ".out")));
		in = new Scanner(System.in);
		int T = in.nextInt();
		
		for (int t = 1; t <= T; t++) {
			int R = in.nextInt();
			int C = in.nextInt();
			int N = in.nextInt();
			System.out.printf("Case #%d: %d", t, get(R,C,N));
			System.out.println();
		}
	}
	
	static int get(int R, int C, int N) {
		int min = Integer.MAX_VALUE;
		for (int mask = 0; mask < (1 << (R * C)); mask++) {
			boolean[][] map = getFor(R, C, mask);
			if (numTenants(R, C, map) == N) {
				min = Math.min(getUnhappy(R, C, map), min);
			}
		}
		return min;	
	}
	
	
	static boolean[][] getFor(int R, int C, int mask) {
		boolean[][] ret = new boolean[R][C];
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				int bit = i * C + j;
				if ((mask & (1 << bit)) != 0) {
					ret[i][j] = true;
				}			
			}
		}
		return ret;
	}
	
	static int numTenants(int R, int C, boolean[][] map) {
		int total = 0;
		for (int i = 0; i < R; i++ ) {
			for (int j = 0; j < C; j++) {
				if (map[i][j]) {
					total++;
				}
			}
		}
		return total;
	}
	
	static int getUnhappy(int R, int C, boolean[][] map) {
		int total = 0;
		for (int i = 0; i < R; i++ ) {
			for (int j = 0; j < C; j++) {
				if (j < C - 1) {
					if (map[i][j] && map[i][j+1]) {
						total++;
					}
				}
				if (i < R - 1) {
					if (map[i][j] && map[i+1][j]) {
						total++;
					}
				}
			}
		}
		return total;
	}
}
