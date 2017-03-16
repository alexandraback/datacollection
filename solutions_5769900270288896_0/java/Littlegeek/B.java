package round1B;
import java.util.*;
import java.lang.*;
import java.io.*;

public class B {

	public static void main(String[] args) throws Exception{
		Scanner in = new Scanner(new File("B.in"));
		FileWriter out = new FileWriter("bout.txt");
		
		int T = in.nextInt();
		
		for (int i = 1; i <= T; i++) {
			int R = in.nextInt();
			int C = in.nextInt();
			int N = in.nextInt();
			boolean rc[][] = new boolean[R][C];
			
			if (N > (int) (R*C / 2.0 + 0.5)) {
				for (boolean[] b : rc) {
					Arrays.fill(b, true);
				}
				for (int j = 0; j < R*C - N; j++) {
					int rr = -1, cc = -1, min = sad(rc);
					for (int r = 0; r < R; r++) {
						for (int c = 0; c < C; c++) {
							if (rc[r][c]) {
								rc[r][c] = false;
								int maybe = sad(rc);
								if (maybe < min) {
									min = maybe;
									rr = r;
									cc = c;
								}
								rc[r][c] = true;
							}
						}
					}
					rc[rr][cc] = false;
				}
			}
			String s = "Case #" + i + ": " + sad(rc) + "\n";
			System.out.print(s);
			out.write(s);
		}
		in.close();
		out.close();
	}
	
	public static int sad(boolean[][] rc) {
		int r = rc.length;
		int c = rc[0].length;
		int s = 0;
		for (int ir = 0; ir < r; ir++) {
			for (int ic = 0; ic < c; ic++) {
				if (rc[ir][ic]) {
					if (ir > 0 && rc[ir - 1][ic]) s++;
					if (ic > 0 && rc[ir][ic - 1]) s++;
				}
			}
		}
		return s;
	}

}
