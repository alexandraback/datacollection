import java.io.*;
import java.util.*;


public class Bslow {
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer st;
	
	static String nextToken() throws IOException {
		while (st==null || !st.hasMoreTokens())
			st = new StringTokenizer(in.readLine());
		return st.nextToken();
	}
	
	static int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}
	
	static long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}
	
	public static void main(String[] args) throws IOException {
		in = new BufferedReader(new FileReader("B.in"));
		out = new PrintWriter(new FileWriter("Bslow.out"));
		
		int qqq = nextInt();
		for (int qq=1; qq<=qqq; qq++) {
			out.printf("Case #%d: ", qq);

			int row = nextInt(), col = nextInt(), num = nextInt();
			int unhappy = row*col*5;
			
			for (int i=0; i<(1<<(row*col)); i++) {
				if (Integer.bitCount(i) != num) continue;
				boolean[][] grid = makeGrid(i, row, col);
				int poss = countWalls(grid);
				if (poss < unhappy) unhappy = poss;
			}
			out.println(unhappy);
		}
		out.close();
	}

	private static int countWalls(boolean[][] grid) {
		int[] dis = {-1, 1, 0, 0};
		int[] djs = {0, 0, -1, 1};
		int unhappy = 0;
		for (int i=0; i<grid.length; i++) {
			for (int j=0; j<grid[i].length; j++) {
				if (!grid[i][j]) continue;
				for (int ds = 0; ds<=3; ds++) {
					int di = dis[ds], dj = djs[ds]; 
					if (di==0 && dj == 0) continue;
					if (i+di<0 || i+di >= grid.length) continue;
					if (j+dj<0 || j+dj >= grid[i+di].length) continue;
					if (grid[i+di][j+dj]) unhappy++;
				}
			}
		}
		return unhappy/2;
	}

	private static boolean[][] makeGrid(int num, int row, int col) {
		boolean[][] ret = new boolean[row][col];
		for (int i=0; i<row; i++)
			for (int j=0; j<col; j++) {
				ret[i][j] = (num & (1<<(i*col+j))) != 0;
			}
		return ret;
	}
}
