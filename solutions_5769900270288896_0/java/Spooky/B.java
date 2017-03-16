package r1b2015;

import java.io.File;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.Scanner;

public class B
{

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in).useLocale(Locale.US);
		//PrintWriter out = new PrintWriter(System.out);
		PrintWriter out = new PrintWriter(new File("B.out"));

		for (int t = in.nextInt(), cs = 1; t > 0; t--, cs++) {
			out.print("Case #" + cs + ": ");
			
			int r = in.nextInt();
			int c = in.nextInt();
			int n = in.nextInt();
			
			int d = r*c;
			int k = 1 << d;
			int min = Integer.MAX_VALUE;
			for (int mask = 0; mask < k; mask++) {
				if (Integer.bitCount(mask) == n) {
					int cur = count(mask, r, c);
					if (cur < min) {
						min = cur;
					}
				}
			}
			
			out.println(min);
		}
		
		out.flush();
	}

	static int count(int mask, int r, int c) {
		boolean[][] b = new boolean[r][c];
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				if (((mask >> (i*c + j))&1) != 0)
					b[i][j] = true;
		int res = 0;
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				if (b[i][j]) {
					if (i > 0 && b[i-1][j]) res++;
					if (i+1 < r && b[i+1][j]) res++;
					if (j > 0 && b[i][j-1]) res++;
					if (j+1 < c && b[i][j+1]) res++;
				}
		
		return res/2;
	}
}
