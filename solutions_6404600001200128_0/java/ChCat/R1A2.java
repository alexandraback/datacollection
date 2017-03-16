import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class R1A2 {

	private static BufferedReader br;
	private static StringTokenizer st;
	private static PrintWriter pw;

	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(new DataInputStream(
				new FileInputStream("r:\\input.txt"))));
		pw = new PrintWriter(new BufferedWriter(
				new FileWriter("r:\\output.txt")));
		int MAX_NUM_CASE = readInt();

		for (int qq = 1; qq <= MAX_NUM_CASE; qq++) {
			pw.print("Case #" + qq + ": ");

			int N = readInt();

			int[] m = new int[N];

			int freestyle = 0;
			int maxRate = 0;

			for (int i = 0; i < N; i++) {
				m[i] = readInt();

				if (i > 0) {
					if (m[i] < m[i - 1]) {
						int delta = m[i - 1] - m[i];
						freestyle += delta;
						maxRate = maxRate > delta ? maxRate : delta;
					}
				}
			}

			pw.print(freestyle);
			pw.print(" ");

			int cr = 0;

			for (int i = 0; i < N - 1; i++) {
				int delta = m[i] > maxRate ? maxRate : m[i];
				cr += delta;
			}

			pw.println(cr);

		}

		pw.close();
	}

	private static void skip(int n) throws IOException {
		int i = 1;
		while (i <= n) {
			br.readLine();
			i++;
		}
	}

	private static long readLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	private static double readDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	private static int readInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	private static String nextToken() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			if (!br.ready()) {
				pw.close();
				System.exit(0);
			}
			st = new StringTokenizer(br.readLine().trim());
		}
		return st.nextToken();
	}

}
