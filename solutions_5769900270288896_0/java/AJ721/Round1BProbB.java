import java.util.*;
import java.io.*;
public class Round1BProbB 
{
	public static HashMap<Long,Long> cache = new HashMap<Long,Long>();
	public static void main(String[] args) throws Exception
	{
		String file = "Round1B/B-small-attempt0.in";

		BufferedReader br = new BufferedReader(new FileReader(file));
		PrintWriter writer = new PrintWriter("Round1B/outBsm.txt", "UTF-8");
		String line;

		int T = Integer.parseInt(br.readLine());
		for(int test=0;test<T;test++)
		{
			String[] parts = br.readLine().split(" ");
			int R = Integer.parseInt(parts[0]);
			int C = Integer.parseInt(parts[1]);
			int N = Integer.parseInt(parts[2]);
			
			writer.println("Case #" + (test+1) + ": "+unhappiness(R,C,N));
			System.out.println(test);
		}
		writer.close();
	}
	public static int unhappiness(int R, int C, int N)
	{
		if(R*C==N)
		{
			return (R-1)*C + (C-1)*R;
		}
		boolean[][] apts = new boolean[R][C];
		int bestUnhappiness = -1;
		int choices = 1<<(R*C);
		for(int choice=0;choice<choices;choice++)
		{
			int temp = choice;
			int count = 0;
			for(int spot=0;spot<R*C;spot++)
			{
				int nextR = spot/C;
				int nextC = spot%C;
				apts[nextR][nextC]=(temp%2==1);
				if(temp%2==1)
					count++;
				temp /= 2;
			}
			if(count == N)
			{
				int current = totalUnhappiness(apts,R,C);
				if(bestUnhappiness < 0 || current<bestUnhappiness)
				{
					bestUnhappiness = current;
				}
				if(bestUnhappiness==0)
				{
					return 0;
				}
			}
		}
		return bestUnhappiness;
	}
	/*
	public static int placeTenants(int spot, int R, int C, int remaining)
	{
		int nextR = spot/C;
		int nextC = spot%C;
		if(
	}*/
	public static int totalUnhappiness(boolean[][] apts, int R, int C)
	{
		int res =0;
		for(int r=0;r<R;r++)
		{
			for(int c=0;c<C;c++)
			{
				if(apts[r][c])
				{
					if(r>0 && apts[r-1][c]) res++;
					if(c>0 && apts[r][c-1]) res++;
					if(r<R-1 && apts[r+1][c]) res++;
					if(c<C-1 && apts[r][c+1]) res++;
				}
			}
		}
		return res/2;
	}
}