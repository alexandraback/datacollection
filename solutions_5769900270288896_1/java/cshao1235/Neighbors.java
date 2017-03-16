import java.io.BufferedReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class Neighbors {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		try
		{
			BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
			int t = Integer.parseInt(f.readLine());
			FileWriter fout = new FileWriter("neighbors.out");
			for(int i = 1; i <= t; i++)
			{
				StringTokenizer st = new StringTokenizer(f.readLine());
				int r = Integer.parseInt(st.nextToken());
				int c = Integer.parseInt(st.nextToken());
				int n = Integer.parseInt(st.nextToken());
				if(n <= (r*c + 1)/2)
				{
					System.out.println("Case #" + i + ": " + 0);
					fout.write("Case #" + i + ": " + 0 + "\n");
				}
				else
				{
					boolean[][] isPerson = new boolean[r][c];
					int numBadWalls = r*(c-1) + c*(r-1);
					int[][] badWalls = new int[r][c];
					for(int row = 0; row < r; row++)
					{
						for(int col = 0; col < c; col++)
						{
							badWalls[row][col] = 4;
							if(row == 0)
								badWalls[row][col]--;
							if(row == r - 1)
								badWalls[row][col]--;
							if(col == 0)
								badWalls[row][col]--;
							if(col == c - 1)
								badWalls[row][col]--;
						}
					}
					for(int j = 0; j < r*c - n; j++)
					{
						int max = -1;
						int maxR = 0;
						int maxC = 0;
						for(int row = 0; row < r; row++)
						{
							for(int col = 0; col < c; col++)
							{
								if(!isPerson[row][col] && badWalls[row][col] > max)
								{
									max = badWalls[row][col];
									maxR = row;
									maxC = col;
								}
							}
						}
						isPerson[maxR][maxC] = true;
						if(maxR > 0)
							badWalls[maxR - 1][maxC]--;
						if(maxR < r - 1)
							badWalls[maxR + 1][maxC]--;
						if(maxC > 0)
							badWalls[maxR][maxC - 1]--;
						if(maxC < c - 1)
							badWalls[maxR][maxC + 1]--;
						numBadWalls -= max;
					}
					if(r > 1 && r%2 == 1 && c > 1 && c%2 == 1 && (r*c + 1)/2 == n-1)
						numBadWalls--;
					System.out.println("Case #" + i + ": " + r + " " + c + " " + n + " " + numBadWalls);
					fout.write("Case #" + i + ": " + numBadWalls + "\n");
				}
				//System.out.println("Case #" + i + ": " + minTime);
				//fout.write("Case #" + i + ": " + minTime + "\n");
			}
			f.close();
			fout.close();
		}
		catch(IOException e)
		{
			System.out.println(e);
		}

	}

}
