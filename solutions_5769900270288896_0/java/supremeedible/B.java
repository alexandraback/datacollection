import java.util.Scanner;

public class B {
	public static int search(boolean[][] arr, int R, int C, int tenantsLeft, int I, int J, int unhappy, int toBeat)
	{	
		for (int i = I; i < R; i++)
		{
			for (int j = i == I ? J : 0; j < C; j++)
			{
				int thisUnhappy = unhappy;
				
				arr[i][j] = true;
				
				if (i > 0 && arr[i - 1][j])
				{
					thisUnhappy++;
				}
				
				if (j > 0 && arr[i][j - 1])
				{
					thisUnhappy++;
				}
				
				// prune
				
				if (thisUnhappy < toBeat)
				{
					if (tenantsLeft > 1)
					{
						thisUnhappy = search(arr, R, C, tenantsLeft - 1, i, j + 1, thisUnhappy, toBeat);
					}
					
					if (thisUnhappy < toBeat)
					{
						toBeat = thisUnhappy;
					}
				}
				
				arr[i][j] = false;
			}
		}
		
		return toBeat;
	}
	
	public static void main(String[] args)
	{
		Scanner scan = new Scanner(System.in);
		
		int T = scan.nextInt();
		
		for (int Q = 1; Q <= T; Q++)
		{
			int R = scan.nextInt();
			int C = scan.nextInt();
			int N = scan.nextInt();
			
			int min = Integer.MAX_VALUE;
			
			if (N <= R * C / 2)
			{
				min = 0;
			}
			else
			{
				boolean[][] arr = new boolean[R][C];
				
				min = search(arr, R, C, N, 0, 0, 0, Integer.MAX_VALUE);
			}
			
			System.out.printf("Case #%d: %d\n", Q, min);
		}
		
		scan.close();
	}
}
