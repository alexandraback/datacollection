import java.util.*;
import java.io.*;
public class Round1AProbB {
	
	public static void main(String[] args) throws Exception
	{
		String file = "Round1A/B-small-attempt0.in";

		BufferedReader br = new BufferedReader(new FileReader(file));
		PrintWriter writer = new PrintWriter("Round1A/outBsmall.txt", "UTF-8");
		String line;

		int T = Integer.parseInt(br.readLine());
		for(int test=0;test<T;test++)
		{
			String[] parts = br.readLine().split(" ");
			int B = Integer.parseInt(parts[0]);
			long N = Integer.parseInt(parts[1]);
			
			String[] parts2 = br.readLine().split(" ");
			int[] M = new int[B];
			int minB = -1;
			for(int i=0;i<parts2.length;i++)
			{
				M[i] = Integer.parseInt(parts2[i]);
				if(M[i]<minB || minB==-1)
					minB = M[i];
			}
			
			int res = barberNumber(B,N,M,minB)+1;

			writer.println("Case #"+(test+1)+": " + res);
		}
		writer.close();
	}
	
	public static int barberNumber(int B, long N, int[] M, int minM)
	{
		long time = timeUntilServed(B,N,M,minM);
		long remaining = N - customersServed(time, B, N, M) - 1L;
		for(int i=0;i<B;i++)
		{
			if((time % M[i]) == 0)
			{
				if(remaining == 0)
				{
					return i;
				}
				else
				{
					remaining--;
				}
			}
		}
		return -1;
	}
	
	public static long timeUntilServed(int B, long N, int[] M, int minM)
	{
		if(N==1) return 0;
		
		long goal = N-1;
		long min = 0;
		long max = goal * minM + 1;//exclusive
		while(min < max)
		{
			long guessTime = (min + max) / 2;
			long currentServed = customersServed(guessTime, B, N, M);
			long nextServed = customersServed(guessTime+1, B, N, M);
			//if(currentServed <= goal && goal < nextServed)
			//	return guessTime;
			if(goal >= nextServed)
			{
				min = guessTime + 1;
				
			}
			else if(goal < currentServed)
			{
				max = guessTime;
			}
			else
			{
				return guessTime;
			}
		}
		throw new RuntimeException("Ouch");
	}
	
	public static long customersServed(long time, int B, long N, int[] M)
	{
		long num = 0;
		for(int i=0;i<B;i++)
		{
			num += (int)Math.ceil((double)time / M[i]);			
		}
		return num;
	}

}