import java.io.*;
import java.util.*;

public class Main implements Runnable {

	public void _main() throws IOException {
		int numTests = nextInt();
		for (int test = 1; test <= numTests; test++) {
			int r1 = nextInt() - 1;
			int[][] s1 = new int[4][4];
			for (int r = 0; r < 4; r++) {
				for (int c = 0; c < 4; c++) {
					s1[r][c] = nextInt();
				}
			}
			int r2 = nextInt() - 1;
			int[][] s2 = new int[4][4];
			for (int r = 0; r < 4; r++) {
				for (int c = 0; c < 4; c++) {
					s2[r][c] = nextInt();
				}
			}
			int numPossibilities = 0;
			int ans = -1;
			for (int cand = 1; cand <= 16; cand++) {
				boolean ok1 = false;
				boolean ok2 = false;
				for (int c = 0; c < 4; c++) {
					if (s1[r1][c] == cand) {
						ok1 = true;
					}
					if (s2[r2][c] == cand) {
						ok2 = true;
					}
				}
				if (ok1 && ok2) {
					ans = cand;
					++numPossibilities;
				}
			}
			out.print("Case #" + test + ": ");
			if (numPossibilities == 0) {
				out.println("Volunteer cheated!");
			} else if (numPossibilities > 1) {
				out.println("Bad magician!");
			} else {
				out.println(ans);
			}
		}
	}


	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;

	private String next() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			String rl = in.readLine();
			if (rl == null)
				return null;
			st = new StringTokenizer(rl);
		}
		return st.nextToken();
	}

	private int nextInt() throws IOException {
		return Integer.parseInt(next());
	}

	private long nextLong() throws IOException {
		return Long.parseLong(next());
	}

	private double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}

	public static void main(String[] args) {
		Locale.setDefault(Locale.UK);
		new Thread(new Main()).start();
	}

	public void run() {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			in = new BufferedReader(new FileReader("A-small-attempt0.in"));
			out = new PrintWriter(new FileWriter("A-small-attempt0.out"));

			_main();

			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(202);
		}
	}

}
