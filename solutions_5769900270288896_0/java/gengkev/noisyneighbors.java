import java.io.*;

public class noisyneighbors {
	private static final boolean useStandardInput = false;
	private static final String filename = "round1B/B-small-attempt0";
	private static final boolean log = true;

	private static int R;
	private static int C;
	private static int N;

	private static boolean[][] darn;

	private static void run() throws IOException {
		final int T = readLineInt();

		for (int i = 1; i <= T; i++) {
			int[] line = readLineIntArray();
			R = line[0];
			C = line[1];
			N = line[2];
			darn = new boolean[R][C];

			int result = recurse(0, 0, 0);
			output(i, String.valueOf(result));
		}
	}

	private static int recurse(int pos, int n, int u) {
		if (n == N) {
			return u;
		} else if (pos == R * C) {
			return Integer.MAX_VALUE;
		}
		int r = pos / C, c = pos % C;

		// first, set this to be on
		darn[r][c] = true;
		int u_here = 0;
		if (r > 0 && darn[r-1][c]) u_here++;
		if (c > 0 && darn[r][c-1]) u_here++;

		int next_u1 = recurse(pos+1, n+1, u+u_here);

		// then set this to be off
		darn[r][c] = false;
		int next_u2 = recurse(pos+1, n, u);

		return Math.min(next_u1, next_u2);
	}

	// ----------------------------------------------------------------------------------------------------------------
	// competition helper methods

	private static BufferedReader reader;
	private static BufferedWriter writer;

	public static void main(String[] args) throws IOException {
		if (useStandardInput) {
			reader = new BufferedReader(new InputStreamReader(System.in));
			writer = new BufferedWriter(new StringWriter());
		} else {
			reader = new BufferedReader(new FileReader(filename + ".in"));
			writer = new BufferedWriter(new FileWriter(filename + ".out"));
		}
		run();
		reader.close();
		writer.close();
		if (!useStandardInput)
			System.out.println("FINISHED for file " + filename);
		System.exit(0);
	}

	private static String readLine() throws IOException {
		return reader.readLine();
	}
	private static int readLineInt() throws IOException {
		return Integer.parseInt(readLine());
	}
	private static long readLineLong() throws IOException {
		return Long.parseLong(readLine());
	}
	private static int[] readLineIntArray() throws IOException {
		String[] strings = readLine().split("\\s");
		int L = strings.length;
		int[] ints = new int[L];
		for (int i = 0; i < L; i++) {
			ints[i] = Integer.parseInt(strings[i]);
		}
		return ints;
	}

	private static void output(int caseNo, String str) throws IOException {
		String output = "Case #" + caseNo + ": " + str + "\n";
		System.out.print("OUT: " + output);
		if (!useStandardInput) {
			writer.write(output);
		}
	}

	private static void log(String s) {
		if (log) System.out.println(s);
	}
	private static void log(String s, boolean newline) {
		if (log) System.out.print(s + (newline ? "\n" : ""));
	}
}
