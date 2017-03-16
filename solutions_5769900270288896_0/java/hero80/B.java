package round1B;

import java.util.*;
import java.io.*;
import java.math.*;

public class B {

	private static Scanner sc;
	private static int R,C,N;
	private static boolean[][] board;
	

	public static void main(final String[] args) {
		setStreams("/Users/yariv/Downloads/B-small-attempt0");
//		setStreams("/Users/yariv/Downloads/test");
		sc = new Scanner(System.in);
		final int numCases = sc.nextInt();
		handleCases(numCases);
	}

	private static void setStreams(final String baseFileName) {
		try {
			System.setIn(new FileInputStream(baseFileName + ".in"));
			System.setOut(new PrintStream(baseFileName + ".out"));
		} catch (final FileNotFoundException e) {
			e.printStackTrace();
		}
	}

	private static void handleCases(final long numCases) {
		for (int i = 1; i <= numCases; i++) {
			handleCase(i);
		}
	}

	private static void handleCase(final int caseNumber) {
		R = sc.nextInt();
		C = sc.nextInt();
		N = sc.nextInt();
		
		
		board = new boolean[R][C];
		int res = fillBoard(0, N);
		System.out.println("Case #" + caseNumber + ": " + res);
	}

	private static int fillBoard(int pos, int left) {
		if(left == 0) {
			return noise();
		}
		if(pos >= R * C) {
			return Integer.MAX_VALUE;
		}
		board[pos / C][pos % C] = true;
		int res = fillBoard(pos + 1, left - 1);
		board[pos / C][pos % C] = false;
		int res2 = fillBoard(pos +1, left);
		return Math.min(res, res2);
	}
	
	private static int noise() {
		int count = 0;
		 
		for(int i = 0 ; i < R * C ; i++) {
			int row = i / C;
			int col = i % C;
			
			if(!board[row][col]) {
				continue;
			}
			if(col + 1 < C && board[row][col + 1]) {
				count++;
			}
			if(row + 1 < R && board[row + 1][col]) {
				count++;
			}
		}
		return count;
	}
	
	private static void log(final String message) {
		System.out.println(message);
	}
}
