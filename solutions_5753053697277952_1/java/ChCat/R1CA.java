import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;

public class R1CA {

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

			solve();
		}

		pw.close();
	}

	private static class Party implements Comparable<Party> {
		char id;
		int count;

		public Party(char id, int count) {
			super();
			this.id = id;
			this.count = count;
		}

		public int compareTo(Party other) {
			return -Integer.compare(this.count, other.count);
		}

	}

	private static void solve() throws IOException {

		int N = readInt();
		Queue<Party> queue = new PriorityQueue<Party>(N);

		int total = 0;

		for (int i = 0; i < N; i++) {
			int pi = readInt();
			total += pi;
			queue.add(new Party((char) ('A' + i), pi));
		}

		while (!queue.isEmpty()) {

			Party p1 = queue.poll();
			pw.print(p1.id);

			total--;
			Party p2 = queue.peek();
			if (p2.count > total / 2) {
				p2 = queue.poll();
				total--;
				pw.print(p2.id);

				if (p2.count > 1)
					queue.offer(new Party(p2.id, p2.count - 1));
			}
			if (p1.count > 1)
				queue.offer(new Party(p1.id, p1.count - 1));
			pw.print(' ');

		}

		pw.println();

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
