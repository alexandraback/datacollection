import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;

public class B1 {

	public static void main(String[] args) throws Exception {

		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

		int T = Integer.parseInt(in.readLine());
		for (int t = 1; t <= T; t++) {
			String[] data = in.readLine().split(" ");
			int R = Integer.parseInt(data[0]);
			int C = Integer.parseInt(data[1]);
			int N = Integer.parseInt(data[2]);
			
			int min = Integer.MAX_VALUE;
			boolean[][] grid = new boolean[R][C];
			for (int b = 0; b < (1 << R * C); b++) {
				if (Integer.bitCount(b) == N) {
					String bs = Integer.toString(b, 2);
					for (int i = 0; i < bs.length(); i++) {
						int r = i / C;
						int c = i % C;
						grid[r][c] = (bs.charAt(i) == '1');
					}
					int unhappiness = 0; 
					for (int r = 0; r < R; r++) {
						for (int c = 0; c < C; c++) {
							if (grid[r][c]) {
								if (r < R - 1 && grid[r + 1][c])
									unhappiness++;
								if (c < C - 1 && grid[r][c + 1])
									unhappiness++;
							}
						}
					}
					if (unhappiness < min)
						min = unhappiness;
				}
			}
			
			out.println("Case #" + t + ": " + min);
		}
		out.close();
	}

}
