import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;

public class MagicTrick {
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new FileReader("src/in.txt"));
		PrintWriter out = new PrintWriter("out.txt");

		int t = Integer.parseInt(in.readLine());

		for (int tc = 1; tc <= t; tc++) {
			int[] used = new int[17];

			readInput(in, used);
			readInput(in, used);

			int count = 0;
			int candidate = -1;
			for (int i = 1; i <= 16; i++) {
				if (used[i] == 2) {
					count++;
					candidate = i;
				}
			}

			StringBuilder sb = new StringBuilder();
			sb.append("Case #" + tc + ": ");

			switch (count) {
			case 0:
				sb.append("Volunteer cheated!");
				break;
			case 1:
				sb.append(candidate);
				break;
			default:
				sb.append("Bad magician!");
				break;
			}

			out.println(sb);
		}

		in.close();
		out.close();
	}

	private static void readInput(BufferedReader in, int[] used)
			throws IOException {
		int r = Integer.parseInt(in.readLine());
		for (int i = 1; i <= 4; i++) {
			String[] split = in.readLine().split(" ");
			if (i == r) {
				for (int j = 1; j <= 4; j++) {
					int no = Integer.parseInt(split[j - 1]);
					used[no]++;
				}
			}
		}
	}
}
