import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class R1B2 {

	private static BufferedReader br;
	private static StringTokenizer st;
	private static PrintWriter pw;

	private static class Barb implements Comparable<Barb> {
		public int time;
		public int period;
		public int number;

		public Barb(int time, int period, int number) {
			this.time = time;
			this.period = period;
			this.number = number;
		}

		@Override
		public int compareTo(Barb b) {
			if (time != b.time) {
				return time - b.time;
			}

			return number - b.number;

		}
	}

	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(new DataInputStream(
				new FileInputStream("r:\\input.txt"))));
		pw = new PrintWriter(new BufferedWriter(
				new FileWriter("r:\\output.txt")));
		int MAX_NUM_CASE = readInt();

		for (int qq = 1; qq <= MAX_NUM_CASE; qq++) {
			pw.print("Case #" + qq + ": ");

			int B = readInt();
			int N = readInt();

			PriorityQueue<Barb> queue = new PriorityQueue<Barb>();

			long common = 1;

			for (int i = 1; i <= B; i++) {
				int period = readInt();
				common *= period;
				queue.add(new Barb(period, period, i));
			}

			int ppk = 0;

			for (Barb b : queue) {
				ppk += common / b.period;
			}

			N = N % ppk;
			if (N == 0) {
				N = ppk;
			}

			if (N <= B) {
				pw.println(N);
				continue;
			} else {
				N = (N - B);

				Barb b = null;
				while (N > 0) {
					b = queue.poll();
					queue.add(new Barb(b.time + b.period, b.period, b.number));
					N--;
				}

				pw.println(b.number);
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
