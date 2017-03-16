package round1b;

import java.util.Scanner;

public class NoisyNeighbours {

	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();

		for(int zz = 1; zz <= T;zz++){

			int R = in.nextInt();
			int C = in.nextInt();
			int N = in.nextInt();

			int count = unhappiness(R, C, N);

			System.out.format("Case #%d: %d\n", zz, count);
		}		
	}

	static int unhappiness(int r, int c, int n) {

		int empty = r*c - n;

		if (empty == 0) {
			if (r == 1)
				return c-1;
			if (c == 1)
				return r-1;
			return (r-1)*c + r*(c-1);
		}

		if (empty >= (r*c)/2) {
			return 0;
		}

		if (r==1 || c == 1) {
			return (r-1)*c + r*(c-1) - (empty*2);
		}

		if (r == 2 || c ==2) {
			return (r-1)*c + r*(c-1) - (empty)*3;
		}

		if (r== 3 || c ==3 ) {
			return (r-1)*c + r*(c-1) - 4 - (empty-1)*3;
		}
		
		if (r== 4 || c == 4 ) {
			return (r-1)*c + r*(c-1) - 4 - (empty-1)*3;
		}
		
		return n;
	}
}
