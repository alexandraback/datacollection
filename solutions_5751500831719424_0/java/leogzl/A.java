import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class A {
	public final static String IN_FILE = "A.in";
	public final static String OUT_FILE = "A.out";

	private static Scanner IN;

	public static void main(String[] args) throws Exception {
		InputStream in = new FileInputStream(IN_FILE);
		PrintWriter out = new PrintWriter(new FileWriter(OUT_FILE));
		IN = new Scanner(in);

		int T = IN.nextInt();
		IN.nextLine();
		for (int t = 1; t <= T; t++) {
			int N;
			N = IN.nextInt();
			String[] S = new String[N];

			IN.nextLine();
			for (int i = 0; i < N; i++) {
				S[i] = IN.nextLine();
			}

			char[] C = new char[100];
			int[][] G = new int[N][100];

			Arrays.fill(C, (char) 0);
			for (int i = 0; i < N; i++) {
				Arrays.fill(G[i], 0);
			}

			C[0] = S[0].charAt(0);
			G[0][0] = 1;

			int m = 1;
			for (int j = 1; j < S[0].length(); j++) {
				if (S[0].charAt(j) != S[0].charAt(j - 1)) {
					C[m++] = S[0].charAt(j);
				}
				G[0][m - 1]++;
			}

			boolean fail = false;

			for (int i = 1; i < N && !fail; i++) {
				if (C[0] != S[i].charAt(0)) {
					fail = true;
					break;
				}

				int mm = 0;
				for (int j = 0; j < S[i].length(); j++) {
					if (C[mm] != S[i].charAt(j)) {
						mm++;
					}
					if (C[mm] != S[i].charAt(j)) {
						fail = true;
						break;
					}
					G[i][mm]++;
				}

				if (m != mm + 1) {
					fail = true;
					break;
				}

			}

			if (fail) {
				out.println("Case #" + t + ": Fegla Won");
			} else {
				int tt = 0;
				for (int k = 0; k < m; k++) {
					int min = 1000000;

					for (int i = 0; i < N; i++) {
						int mm = 0;
						for (int j = 0; j < N; j++) {
							mm += Math.abs(G[i][k] - G[j][k]);
						}

						min = Math.min(mm, min);
					}

					tt += min;
				}

				out.println("Case #" + t + ": " + tt);
			}
		}

		out.flush();
		out.close();
		in.close();
	}

}
