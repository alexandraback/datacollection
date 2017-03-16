import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Locale;
import java.util.Scanner;

public class CodeJam {

	Scanner in;
	PrintWriter out;
	
	int solveIt(int rows, int cols, int n) {
		if (rows == 1 || cols == 1) {
			int max = Math.max(rows, cols);
			int free = (max - 1) / 2 + 1;
			if (n <= free) {
				return 0;
			} else {
				int b1 = max % 2 == 0 ? 1 : 0;
				int diff = n - free;
				if (diff <= b1) {
					return b1;
				} else {
					return b1 * 1 + (diff - b1) * 2;
				}
			}
		}
		int firstRow = (cols - 1) / 2 + 1;
		int secondRow = cols - firstRow;
		int rowsUsedFirst = (rows - 1) / 2 + 1;
		int rowsUsedSecond = rows - rowsUsedFirst;
		
		int free = firstRow * rowsUsedFirst + secondRow * rowsUsedSecond;
		
		if (n <= free) {
			return 0;
		}
		int borders2 = 0;
		if (rows % 2 == 1 && cols % 2 == 1) {
			borders2 = 1;
		} else {
			borders2 = 2;
		}
		if (n <= free + borders2) {
			int diff = n - free;
			return diff * 2;
		}
		int bordersTotal = cols + rows - 2;
		int borders3 = bordersTotal - borders2;
		if (n <= free + bordersTotal) {
			int diff = n - free - borders2;
			return (diff * 3 + borders2 * 2);
		} else {
			int diff = n - free - bordersTotal;
			return (diff * 4 + borders3 * 3 + borders2 * 2);
		}
	}

	boolean [][]used;
	int best;
	
	void gen(int r, int c, int n) {
		if (n == 0) {
			// check
			int ans = 0;
			for (int row = 0; row < used.length; row ++) {
				for (int col = 0; col < used[0].length; col++) {
					
					int nextRow = (row + 1) % used.length;
					if (nextRow != 0) {
						if (used[row][col] && used[nextRow][col]) {
							ans++;
						}
					}
					if (col + 1 < used[0].length) {
						if (used[row][col] && used[row][col + 1]) {
							ans++;
						}
					}
				}
			}
			best = Math.min(best, ans);
			return;
		}
		if (r == used.length) {
			return;
		}
		int newC = c + 1;
		int newR = r;
		if (newC == used[0].length) {
			newC = 0;
			newR = r + 1;
		}
		used[r][c] = true;
		gen(newR, newC, n - 1);
		used[r][c] = false;
		gen(newR, newC, n);
	}
	
	void solveBrut() {
		best = Integer.MAX_VALUE / 2;
		int rows = in.nextInt();
		int cols = in.nextInt();
		int n = in.nextInt();
		used = new boolean[rows][cols];
		gen(0,0,n);
		out.println(best);
	}
	
	void solveFor() {
		int rows = in.nextInt();
		int cols = in.nextInt();
		int n = in.nextInt();
		int res1 = solveIt(rows, cols, n);
		int res2 = solveIt(cols, rows, n);
		if (res1 != res2) {
			throw new Error(rows + " " + cols);
		}
		out.println(Math.min(res1, res2));
	}

	void solve() {
		int n = in.nextInt();
		for (int test = 1; test <= n; test++) {
			out.print("Case #" + test + ": ");
			solveBrut();
			out.flush();
		}
	}
	
	static private final String path = "C:\\jam\\1B\\";
	static private final String problem = "B";
	static private final String tests = "B-small2";
	

	void run() {
		try {
			in = new Scanner(new FileReader(path + problem + "\\" + tests + ".in"));
			out = new PrintWriter(path + problem + "\\" + tests + ".out2");
		} catch (IOException e) {
		//	throw new Error(e);
			
			in = new Scanner(System.in);
			out = new PrintWriter(System.out);
			out.println(">");
			out.flush();
		}
		try {
			solve();
		} finally {
			out.close();
		}
	}

	public static void main(String[] args) {
		new CodeJam().run();
	}
}