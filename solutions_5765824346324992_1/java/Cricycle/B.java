import java.util.*;

public class B
{
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		for (int test = 1; test <= t; ++test)
		{
			int b = in.nextInt();
			int n = in.nextInt();
			int[] barbers = new int[b];
			for (int i = 0; i < barbers.length; ++i)
				barbers[i] = in.nextInt();
			
			// want the largest time such that # of people who have already been cut < n
			// time is such that TIME+1 will have # of people who have already been cut >= n
			long low = 0;
			long high = Long.MAX_VALUE/3;
			while (low < high-1)
			{
				long guessCutTime = (high + low)/2;
				long howManyCut = getCut(guessCutTime, barbers);
				//System.out.printf("guessCutTime = %d, howManyCut = %d\n", guessCutTime, howManyCut);
				if (howManyCut >= n)
				{
					high = guessCutTime;
				}
				else
				{
					low = guessCutTime;
				}
				//System.out.printf("  low = %d, high = %d\n", low, high);
			}
			
			// at this point, low = the time that I am selected to get a hair cut.
			int answer = -1;
			// WAS BUG: was not considering the others who need to get cut before me, that happens at the same time as me
			long currentCut = getCut(low, barbers);
			for (int i = 0; i < barbers.length; ++i)
			{
				if (low % barbers[i] == 0)
				{
					++currentCut;
					if (currentCut == n)
					{
						answer = i;
						break;
					}
				}
			}
			
			System.out.printf("Case #%d: %d\n", test, answer+1);
		}
	}
	
	public static long getCut(long guessTime, int[] barbers)
	{
		long totalCut = 0;
		for (int i = 0; i < barbers.length; ++i)
		{
			totalCut += (guessTime + barbers[i] - 1) / barbers[i];
		}
		
		return totalCut;
	}
}