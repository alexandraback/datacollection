package j2015.round1B;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.util.Scanner;

@SuppressWarnings("all")
public class B {

	private static final String FILE_NAME = "B-small-attempt0";	
	
	private static final String RELATIVE_PATH;
	static {
		String p = B.class.getPackage().getName();
		p = p.replace('.', '\\');
		RELATIVE_PATH = "src\\" + p + "\\" + FILE_NAME;
	}
	
	private Scanner in;
	private PrintStream out;
	
	public B () throws FileNotFoundException {
		in = new Scanner(new File(RELATIVE_PATH + ".in"));	
		out = new PrintStream(RELATIVE_PATH + ".out"); 
			
		int cases = nextInt();	
		for (int i = 1; i <= cases; i++) {
			print("Case #" + i + ": ");
			solve();
			println();
		}	

		out.close();
		System.out.println("\nDONE!");
	}
	
	private void solve() {
		int R = nextInt();
		int C = nextInt();
		int N = nextInt();
		
		int[][] grid = new int[R][C];
		print(place(grid, N, R, C, 0));
	}
	private int place(int[][] grid, int N, int R, int C, int i) {
		if (N == 0) {
			return countUnhappiness(grid, R,C);
		}
		if (i >= R *C) return Integer.MAX_VALUE;

		int[][] cp = copy(grid, R, C);
		cp[i / C][i % C] = 1; 
		return Math.min(place(grid, N, R, C, i+1), place(cp, N-1, R,C,i+1));
	}
	
	private int[][] copy(int[][] grid, int R, int C) {
		int[][] copy = new int[R][C];
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				copy[i][j] = grid[i][j];
			}
		}
		return copy;
	}
	
	private int countUnhappiness(int[][] grid, int R, int C) {
		int uh = 0;
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (grid[i][j] == 1) {
					if (j != C -1)
					if (grid[i][j+1] == 1) uh++;
					if (i != R -1)
					if (grid[i+1][j] == 1) uh++;
				}
			}
		}
		return uh;
	}
	
	/*
	 * Manage input
	 */
	private String next() {
		return in.next();
	}
	private int nextInt() {
		return in.nextInt();
	}
	private long nextLong() {
		return in.nextLong();
	}

	/*
	 * Manage output
	 */
	private void print(String s) { 
		System.out.print(s);
		out.print(s); 
	}	
	private void print(int i) { 
		System.out.print(i);
		out.print(i); 
	}	
	private void print(Object o) {
		System.out.print(o);
		print(o);
	}
	private void println() { 
		System.out.println();
		out.println(); 
	}
	
	public static void main(String[] args) {
		try {
			new B();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
