import java.util.*;
import java.io.*;

public class B {

	void solve() {
		int R = in.nextInt();
		int C = in.nextInt();
		int N = in.nextInt();
	
		int[][] m = new int[R][];
		for (int i = 0; i < R; i++)
			m[i] = new int[C];
		
		int n = 1 << R * C;
		int min = Integer.MAX_VALUE;
		for (int i = 0; i < n; i++) {
			if (NumberOfSetBits(i)==N)
			{
				int j = i;
				for (int r = 0; r < R; r++)
					for (int c = 0; c < C; c++) {
						m[r][c] = j & 1;
						j = (j >> 1);
					}
				int cnt = 0;
				for (int r = 0; r < R - 1; r++)
					for (int c = 0; c < C; c++) {
						if (m[r][c] == 1 && m[r+1][c] == 1)
							cnt +=1;
					}
				for (int r = 0; r < R; r++)
					for (int c = 0; c < C-1; c++) {
						if (m[r][c] == 1 && m[r][c+1] == 1)
							cnt +=1;
					}
				if (cnt < min)
					min = cnt;
			}
		}
		out.println(min);
	}
	
	int NumberOfSetBits(int i)
	{
	     i = i - ((i >> 1) & 0x55555555);
	     i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
	     return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
	}
	
	
	
	/*************************************************************************/

	public static void main(String[] args) throws Exception {
		main1();
	}

	public static void main0() {
		String s = "4 2 3 6 4 1 2 3 3 8 5 2 0";
		solveProblem0(s);
	}

	public static void main1() throws Exception {
		String load = "src/b-small-attempt0.in";
		String save = "src/b-small-attempt0.out";
		solveProblem1(load, save);
	}

	/*************************************************************************/

	public static void solveProblem0(String s) {
		in = new Scanner(s);
		out = new PrintWriter(System.out);
		solveAllCases();
		out.flush();
	}

	public static void solveProblem1(String load, String save)
			throws FileNotFoundException {
		in = new Scanner(new File(load));
		out = new PrintWriter(new File(save));
		solveAllCases();
		out.close();
	}
	
	/*************************************************************************/

	static void solveAllCases() {
		int T = in.nextInt();
		for (int t = 1; t <= T; t++) {
			out.print("Case #" + t + ": ");
			System.out.println("Case #" + t + ": ............");
			new B().solve();
		}
	}
	
	static Scanner in;
	static PrintWriter out;
}
