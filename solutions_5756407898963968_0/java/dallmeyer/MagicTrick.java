import java.util.HashSet;
import java.util.Scanner;


public class MagicTrick {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		int T = in.nextInt();
		for (int t = 1; t <= T; t++)
		{
			runMe(in, t);
		}
	}

	private static void runMe(Scanner in, int t)
	{
		int[][] grid = new int[4][4];
		HashSet<Integer> poss = new HashSet<Integer>();
		
		int ans1 = in.nextInt()-1;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				grid[i][j] = in.nextInt();
			}
		}
		
		for (int j = 0; j < 4; j++)
		{
			poss.add(grid[ans1][j]);
		}
		
		int ans2 = in.nextInt()-1;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				grid[i][j] = in.nextInt();
			}
		}
		
		int ans = -1;
		int count = 0;
		for (int j = 0; j < 4; j++)
		{
			if (poss.contains(grid[ans2][j]))
			{
				count++;
				ans = grid[ans2][j];
			}
		}
		
		System.out.print("Case #" + t + ": ");
		if (count == 1)
		{
			System.out.println(ans);
		}
		else if (count == 0)
		{
			System.out.println("Volunteer cheated!");
		}
		else
		{
			System.out.println("Bad magician!");
		}
	}
}
