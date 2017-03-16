import java.util.*;
import java.io.*;
import java.math.*;

import static java.lang.Math.*;

public class Solution implements Runnable {
	
	
	public void solve() throws Exception {
		int tests = sc.nextInt();
		for (int test = 0; test < tests; test++) {
			out.print(String.format("Case #%d: ", test + 1));
			int row[] = new int [2];
			int grid[][][] = new int[2][4][4];
			int numbers[] = new int [17];
			for (int k = 0; k < 2; k++) {
				row[k] = sc.nextInt() - 1;
				for (int i = 0; i < 4; i++)
					for (int j = 0; j < 4; j++)
						grid[k][i][j] = sc.nextInt();
				for (int i = 0; i < 4; i++) {
					numbers[grid[k][row[k]][i]]++;
				}
			}
			int answer = -1;
			int answerCount = 0;
			for (int i = 1; i <= 16; i++)
				if (numbers[i] == 2) {
					answer = i;
					answerCount++;
				}
			if (answerCount == 0) {
				out.println("Volunteer cheated!");
			} else if (answerCount > 1) {
				out.println("Bad magician!");
			} else {
				out.println(answer);
			}
		}
	}


	static Throwable t;

	BufferedReader in;
	FastScanner sc;
	PrintWriter out;

	@Override
	public void run() {
		try {
			in = new BufferedReader(new FileReader("input.txt"));
			out = new PrintWriter(new FileWriter("output.txt"));
			//in = new BufferedReader(new InputStreamReader(System.in));
			//out = new PrintWriter(System.out);
			sc = new FastScanner(in);
			solve();
		} catch (Throwable t) {
			Solution.t = t;
		} finally {
			out.close();
		}
	}

	public static void main(String[] args) throws Throwable {
		Thread thread = new Thread(null, new Solution(), "", 1 << 26);
		thread.start();
		thread.join();
		if (Solution.t != null)
			throw t;
	}

}

class FastScanner {

	BufferedReader in;
	StringTokenizer st;

	public FastScanner(BufferedReader in) {
		this.in = in;
	}

	public String nextToken() throws Exception {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(in.readLine());
		return st.nextToken();
	}

	public int nextInt() throws Exception {
		return Integer.parseInt(nextToken());
	}

	public long nextLong() throws Exception {
		return Long.parseLong(nextToken());
	}

	public double nextDouble() throws Exception {
		return Double.parseDouble(nextToken());
	}

}