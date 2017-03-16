import java.io.*;
import java.util.*;

public class MagicTrick {
	static String problem = "A";

	public static void main(String[] args) throws Exception {
//		InputReader r = new InputReader(System.in);
//		PrintWriter out = new PrintWriter(System.out);
		InputReader r = new InputReader(new FileReader(problem + ".in"));
		PrintWriter out = new PrintWriter(new FileWriter(problem + "Solution.out"));
		int T = r.nextInt();
		int test = 1;
		while (T-- > 0) {
			int row1 = r.nextInt();
			int[][] arr = new int[4][4];
			for (int i = 0; i < arr.length; i++) {
				for (int j = 0; j < arr.length; j++) {
					arr[i][j] = r.nextInt();
				}
			}
			int row2 = r.nextInt();
			int[][] arr2 = new int[4][4];
			for (int i = 0; i < arr2.length; i++) {
				for (int j = 0; j < arr2.length; j++) {
					arr2[i][j] = r.nextInt();
				}
			}
			int candidates = 0;
			int res = -1;
			for (int i = 0; i < 4; i++) {
				int x = arr[row1 - 1][i];
				for (int j = 0; j < 4; j++) {
					if (arr2[row2 - 1][j] == x) {
						candidates++;
						res = x;
					}
				}
			}
			out.printf("Case #%d: ", test++);
			if (candidates == 1)
				out.println(res);
			else if (candidates == 0)
				out.println("Volunteer cheated!");
			else
				out.println("Bad magician!");
		}
		out.close();
	}

	static class InputReader {
		private BufferedReader reader;
		private StringTokenizer tokenizer;

		public InputReader(InputStream stream) {
			reader = new BufferedReader(new InputStreamReader(stream));
			tokenizer = null;
		}

		public InputReader(FileReader stream) {
			reader = new BufferedReader(stream);
			tokenizer = null;
		}

		public String nextLine() {
			try {
				return reader.readLine();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
				return null;
			}
		}

		public String next() {
			while (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					tokenizer = new StringTokenizer(reader.readLine());
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
			return tokenizer.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}

		public long nextLong() {
			return Long.parseLong(next());
		}
	}
}
