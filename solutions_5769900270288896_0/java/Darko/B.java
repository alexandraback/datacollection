import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;

public class B {

	private void work() throws Exception {
		Scanner sc = new Scanner(new BufferedReader(new FileReader("B-small-attempt0.in")));
		PrintWriter pw = new PrintWriter(new FileWriter("B-small-attempt0.out"));

		int nc = sc.nextInt();
		for (int tc = 1; tc <= nc; tc++) {
			int r = sc.nextInt();
			int c = sc.nextInt();
			int n = sc.nextInt();
			int best = Integer.MAX_VALUE;
			boolean[][] g = new boolean[r][c];
			int m = r * c;
			for (int i = 0; i < 1 << m; i++) {
				if (Integer.bitCount(i) != n)
					continue;
				for (int j = 0; j < m; j++) {
					g[j / c][j % c] = ((1 << j) & i) != 0;
				}
				int count = 0;
				for (int j = 0; j < r; j++) {
					for (int k = 0; k < c; k++) {
						if (g[j][k]) {
							if (j < r - 1 && g[j + 1][k])
								count++;
							if (k < c - 1 && g[j][k + 1])
								count++;
						}
					}
				}
				if (count < best)
					best = count;
			}
			pw.printf("Case #%d: %d\n", tc, best);
		}
		sc.close();
		pw.close();
	}

	public static void main(String[] args) throws Exception {
		new B().work();
	}

}
