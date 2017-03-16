import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;

public class Solution {

	private static BufferedReader in;
	private static FileWriter out;

	public static void main(String[] args) throws Exception {
		in = new BufferedReader(new FileReader("A-small-attempt0.in"));
		out = new FileWriter("out");

		doWork();

		in.close();
		out.close();
	}

	private static void doWork() throws Exception {
		int testCases = Integer.parseInt(in.readLine());

		for (int i = 0; i < testCases; i++) {
			int resp1 = Integer.parseInt(in.readLine());
			int[][] req1 = new int[4][4];
			for (int j = 0; j < req1.length; j++) {
				String[] split = in.readLine().split(" ");
				for (int k = 0; k < split.length; k++) {
					req1[j][k] = Integer.parseInt(split[k]);
				}
			}
			int resp2 = Integer.parseInt(in.readLine());
			int[][] req2 = new int[4][4];
			for (int j = 0; j < req2.length; j++) {
				String[] split = in.readLine().split(" ");
				for (int k = 0; k < split.length; k++) {
					req2[j][k] = Integer.parseInt(split[k]);
				}
			}

			println("Case #" + (i + 1) + ": " + solve(req1, resp1, req2, resp2));
		}
	}

	private static String solve(int[][] req1, int resp1, int[][] req2, int resp2) {
		int[] possibleAfterResp1 = req1[resp1 - 1];
		int[] possibleAfterResp2 = req2[resp2 - 1];

		int[] intersection = new int[4];
		int intersected = 0;
		for (int i : possibleAfterResp1) {
			for (int j : possibleAfterResp2) {
				if (i == j) {
					intersection[intersected++] = i;
					if (intersected > 1) {
						return "Bad magician!";
					}
				}
			}
		}

		if (intersected == 0) {
			return "Volunteer cheated!";
		}

		return String.valueOf(intersection[0]);
	}

	static void println(String line) throws Exception {
		out.write(line + '\n');
		System.out.println(line);
	}
}
