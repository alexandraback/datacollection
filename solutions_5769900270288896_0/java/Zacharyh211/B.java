import java.io.IOException;
import java.util.Scanner;


public class B {
	public static void main(String [] args) throws IOException {
		Scanner in = new Scanner(System.in);
		int ct = in.nextInt();
		for(int cs = 1; cs <= ct; cs++) {
			int row = in.nextInt();
			int col = in.nextInt();
			int num = in.nextInt();
			
			boolean[][] loc = new boolean[row][col];
			int[][] neigh = new int[row][col];
			
			int added = 0;
			for(int r = 0; r < row; r++)
				for(int c = 0; c < col; c++) {
					if(added < num) {
						loc[r][c] = true;
						added++;
						update(neigh, r, c, true);
					}
					else {
						int value = cost(loc,r,c);
						int max = -10;
						int rr = -1;
						int cc = -1;
						update(neigh, r, c, true);
						for(int r1 = 0; r1 <= r; r1++)
							for(int c1 = 0; c1 < col; c1++)
								if(loc[r1][c1] && max < neigh[r1][c1]) {
									max = neigh[r1][c1];
									rr = r1;
									cc = c1;
								}
						update(neigh, r, c, false);
						if(max >= value) {
							neigh[rr][cc] = 0;
							update(neigh, rr, cc, false);
							update(neigh, r, c, true);
							loc[rr][cc] = false;
							loc[r][c] = true;
						}
					}
				}
			int total = 0;
			for(int r = 0; r < row; r++) {
				for(int c = 0; c < col; c++)
					total += neigh[r][c];
			}
			System.out.printf("Case #%d: %d%n", cs, total/2);
		}
	}
	public static int cost(boolean[][] loc, int r, int c) {
		int cst = 0;
		if(r > 0 && loc[r-1][c])
			cst++;
		if(r < loc.length-1 && loc[r+1][c])
			cst++;
		if(c > 0 && loc[r][c-1])
			cst++;
		if(c < loc[0].length-1 && loc[r][c+1])
			cst++;
		return cst;
	}
	
	public static void update(int[][] loc, int r, int c, boolean add) {
		int delta = add ? 1 : -1;
		if(r > 0)
			loc[r-1][c] += delta;
		if(r < loc.length-1)
			loc[r+1][c] += delta;
		if(c > 0)
			loc[r][c-1] += delta;
		if(c < loc[0].length-1)
			loc[r][c+1] += delta;
	}
}
