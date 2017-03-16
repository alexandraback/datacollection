import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Scanner;

public class Noisy {

	public static void main(String[] args) throws Exception {
		Noisy object = new Noisy();
		String className = object.getClass().getSimpleName();

		FileReader fileReader = new FileReader(new File(className.toLowerCase() + ".in"));
		Scanner scanner = new Scanner(new BufferedReader(fileReader));

		FileWriter wr = new FileWriter(className.toLowerCase() + ".out");

		int testCases = scanner.nextInt();

		for (int tc = 1; tc <= testCases; tc++) {

			int R = scanner.nextInt();
			int C = scanner.nextInt();
			int N = scanner.nextInt();

			int result = object.solve(R, C, N);

			wr.write("Case #" + tc + ": " + result + "\r\n");
		}

		scanner.close();
		wr.close();
	}

	private int solve(int R, int C, int N) throws Exception {

		int result = 1000000000;

		for (int i = 0; i < (1 << (R*C)); i++)
			if (Integer.bitCount(i) == N) {
				int map[][] = setAll(i, R, C);

				int current = 0;

				for (int r1 = 0; r1 < R; r1++)
					for (int c1 = 0; c1 < C; c1++)
						if (occupied(map, r1, c1)) {

						int r2 = r1;
						int c2 = c1 + 1;
						if (occupied(map, r2, c2)) {
							current++;
						}

						r2 = r1 + 1;
						c2 = c1;
						if (occupied(map, r2, c2)) {
							current++;
						}
					}

				result = Math.min(result, current);
			}

		return result;

	}

	private int[][] setAll(int setBits, int r, int c) {
		int[][] result = new int[r][c];

		for (int i = 0; i < r * c; i++) {

			int row = i / c;
			int col = i % c;

			if (((1 << i) & setBits) > 0)
				result[row][col] = 1;
		}

		return result;
	}

	private boolean occupied(int[][] map, int r, int c) {
		if (r < 0 || r >= map.length || c < 0 || c >= map[0].length)
			return false;

		return map[r][c] == 1;
	}

}
