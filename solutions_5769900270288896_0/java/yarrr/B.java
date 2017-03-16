import java.io.*;
import java.util.*;
import java.math.*;

public class B implements Runnable {
	private static BufferedReader in;
	private static PrintWriter out;
	private static StringTokenizer st;
	private static Random rnd;

	private void solve() throws IOException {
		int tests = nextInt();
		for (int test = 1; test <= tests; test++) {
			out.print("Case #" + test + ": ");
			solveOne();
		}
	}

	private void solveOne() throws IOException {
		int height = nextInt(), width = nextInt(), targetBits = nextInt();
		boolean[][] cells = new boolean[height][width];
		int total = height * width;
		int result = Integer.MAX_VALUE;
		for (int mask = 0; mask < (1 << total); mask++) {
			if (Integer.bitCount(mask) != targetBits)
				continue;
			//out.println(mask);
			int currentResut = 0;
			for (int i = 0; i < height; i++) {
				for (int j = 0; j < width; j++) {
					int id = i * width + j;
					cells[i][j] = checkBit(mask, id);
				}
			}
			for (int i = 0; i < height; i++) {
				for (int j = 0; j < width; j++) {
					if (i + 1 < height && cells[i][j] && cells[i + 1][j])
						++currentResut;
					if (j + 1 < width && cells[i][j] & cells[i][j + 1])
						++currentResut;
				}
			}
			result = Math.min(result, currentResut);
		}
		out.println(result);
	}

	private boolean checkBit(int mask, int id) {
		return ((mask >> id) & 1) != 0;
	}

	public static void main(String[] args) {
		new B().run();
	}

	public void run() {
		try {
			final String className = this.getClass().getName().toLowerCase();

			try {
				in = new BufferedReader(new FileReader(className + ".in"));
				out = new PrintWriter(new FileWriter(className + ".out"));
				// in = new BufferedReader(new FileReader("input.txt"));
				// out = new PrintWriter(new FileWriter("output.txt"));
			} catch (FileNotFoundException e) {
				in = new BufferedReader(new InputStreamReader(System.in));
				out = new PrintWriter(System.out);
			}

			rnd = new Random();

			solve();

			out.close();
		} catch (IOException e) {
			e.printStackTrace();
			System.exit(42);
		}
	}

	private String nextToken() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			String line = in.readLine();

			if (line == null)
				return null;

			st = new StringTokenizer(line);
		}

		return st.nextToken();
	}

	private int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	private long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	private double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
}