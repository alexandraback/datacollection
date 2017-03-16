
import java.io.*;
import java.util.*;

public class NoisyNeighbors {
	public static Scanner in = new Scanner(System.in);
	public static PrintWriter PW = new PrintWriter(System.out);

	public static void main(String[] args) throws IOException {
		int cases = in.nextInt();

		for (int c = 1; c <= cases; c++) {
			int R = in.nextInt();
			int C = in.nextInt();
			int N = in.nextInt();

			int mzo = (R * C + 1) / 2; // max zero occupancy
			int mzb = (R * C) / 2;

			int conflicts = 0;

			if (N > mzo) {
				conflicts = R * (C - 1) + C * (R - 1);// total number of
														// walls

				N = R * C - N;
				// N is number of white cells

				mzo = ((R - 2) * (C - 2) + 1) / 2;
				if (mzo < 0)
					mzo = 0;

				if (N <= mzo)
					conflicts -= 4 * N;
				else {
					
					if(N-mzo>((R-2)/2 + (C-2)/2)*2){
						mzo = ((R - 2) * (C - 2)) / 2;
					}
					
					if (mzo < 0)
						mzo = 0;
					conflicts -= 4 * mzo;

					if (R > 1 && C > 1)
						conflicts -= 3 * (N - mzo);
					else
						conflicts -= 2 * (N - mzo);
				}
			}

			PW.println("Case #" + c + ": " + conflicts);
		}

		PW.close();
	}
}