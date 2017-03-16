import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class R1C2 {

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
			pw.println("Case #" + qq + ": ");

			int N = readInt();

			long[] x = new long[N];
			long[] y = new long[N];

			int[] left = new int[N * N];

			for (int i = 0; i < N; i++) {
				x[i] = readLong();
				y[i] = readLong();
			}

			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (j == i)
						continue;
					for (int k = 0; k < N; k++) {
						if (k == i || k == j)
							continue;

						long s = (x[j] - x[i]) * (y[k] - y[i]) - (y[j] - y[i])
								* (x[k] - x[i]);
						if (s > 0) {
							left[i + j * N]++;
						}
					}
				}
			}

			for (int i = 0; i < N; i++) {
				int min = N - 1;
				for (int j = 0; j < N; j++) {
					if (j == i)
						continue;
					min = min < left[i + j * N] ? min : left[i + j * N];
				}
				pw.println(min);
			}

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
