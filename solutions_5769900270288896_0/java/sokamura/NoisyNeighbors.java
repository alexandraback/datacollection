import java.io.File;
import java.util.Scanner;


public class NoisyNeighbors {

	public static void main(String[] args) throws Exception {
		Scanner s = new Scanner(new File("B-small.in"));

		int caseNum = s.nextInt();
		for (int t = 1; t <= caseNum; ++t) {
			int r = s.nextInt();
			int c = s.nextInt();
			int n = s.nextInt();

			System.out.println("Case #" + t + ": " + NoisyNeighbors.solve(r, c, n));
		}

		for (int i=1; i<=4; ++i) {
			for (int j=1; i*j<=16; ++j) {
				System.out.print("["+i+","+j+"]");
				for (int n=0; n<=i*j; ++n) {
					System.out.print(solve(i,j,n) + ",");
				}
				System.out.println();
			}
		}
	}

	public static int solve(int r, int c, int n) {
		// swap
		if (r > c) {
			int tmp = c;
			c = r;
			r = tmp;
		}

		int ans[][][] = new int[5][6][];
		ans[3][3] = new int[]{0,0,0,0,0,0,3,6,8,12};
		ans[3][4] = new int[]{0,0,0,0,0,0,0,2,4,7,10,13,17};
		ans[3][5] = new int[]{0,0,0,0,0,0,0,0,0,3,6,8,11,14,18,22};
		ans[4][4] = new int[]{0,0,0,0,0,0,0,0,0,2,4,7,10,13,16,20,24};

		if (r == 1) {
			return Math.max(0,(c-1)-(c-n)*2);
		} else if (r == 2) {
			if (n <= c) {
				return 0;
			} else if(n <= c + 2) {
				return (n-c)*2;
			} else {
				return 4+(n-c-2)*3;
			}
		} else if (r == 3 || r == 4) {
			return ans[r][c][n];
		} else {
			return -1;
		}
	}
}
