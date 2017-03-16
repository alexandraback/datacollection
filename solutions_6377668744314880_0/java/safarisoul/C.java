package R1A;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class C {
	public static void main(String[] args) throws IOException,
			FileNotFoundException {
		String file = "C-small-attempt0";

		Scanner scan = new Scanner(new BufferedReader(new FileReader(file
				+ ".in")));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter(file
				+ ".out")));

		double EPS = 1e-9;

		int T = Integer.parseInt(scan.nextLine());
		for (int t = 1; t <= T; t++) {
			pw.println("Case #" + t + ":");
			int N = Integer.parseInt(scan.nextLine());
			int[][] coord = new int[N][2];
			for (int i = 0; i < N; i++) {
				String[] info = scan.nextLine().split(" ");
				coord[i][0] = Integer.parseInt(info[0]);
				coord[i][1] = Integer.parseInt(info[1]);
			}

			for (int i = 0; i < N; i++) {
				int min = Integer.MAX_VALUE;
				for (int j = 0; j < N; j++)
					if (j != i) {
						// vertical line
						if (coord[i][0] == coord[j][0]) {
							int left = 0, right = 0;
							for (int k = 0; k < N; k++)
								if (k != i && k != j) {
									if (coord[k][0] < coord[i][0])
										left++;
									else if (coord[k][0] > coord[i][0])
										right++;
								}
							min = Math.min(min, Math.min(left, right));
						}
						// y = ax + b
						else {
							double a = coord[j][1] - coord[i][1];
							a /= coord[j][0] - coord[i][0];
							double b = coord[j][1] - a * coord[j][0];
							int up = 0, down = 0;
							for (int k = 0; k < N; k++)
								if (k != i && k != j) {
									if (coord[k][1] > a * coord[k][0] + b + EPS)
										up++;
									else if (coord[k][1] + EPS < a
											* coord[k][0] + b)
										down++;
								}
							min = Math.min(min, Math.min(up, down));
						}
					}
				if (min == Integer.MAX_VALUE)
					pw.println(0);
				else
					pw.println(min);
			}
		}

		scan.close();
		pw.close();
	}

}
