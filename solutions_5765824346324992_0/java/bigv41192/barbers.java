import java.util.*;
import java.io.*;
import java.math.*;

public class barbers
{
	public static int simulate(long min, long max, Pair [] minutes, long lineLocation)
	{
		if(lineLocation <= minutes.length)
		{
			return (int)lineLocation;
		}
		lineLocation = lineLocation - (long) minutes.length;
		long numBarbers =(long) minutes.length;
		long firstMin = 100001;
		if(lineLocation > numBarbers)
		{
			long increment = lineLocation * min /(numBarbers+1);
		
			//increment minutes passed already
			for(int i = 0; i < minutes.length; i++)
			{
				lineLocation = lineLocation - increment / minutes[i].timeToCut;
				if(lineLocation == 0)
					return i+1;
					if(increment > minutes[i].timeToCut)
						minutes[i].timeRemaining = minutes[i].timeToCut - (increment % minutes[i].timeToCut);
					else
						minutes[i].timeRemaining = minutes[i].timeToCut - increment;
				if(minutes[i].timeRemaining == 0)
					minutes[i].timeRemaining = minutes[i].timeToCut;
				if(minutes[i].timeRemaining < firstMin)
					firstMin = minutes[i].timeRemaining;
			}
		}
		else
			firstMin = min;
		long nextMin = 100000;
		while(true)
		{
			for(int i = 0; i < minutes.length; i ++)
			{
				if(minutes[i].timeRemaining <= firstMin)
				{
					long diff = firstMin - minutes[i].timeRemaining;
					lineLocation = lineLocation - 1;
					minutes[i].timeRemaining = minutes[i].timeToCut-diff;
					if(minutes[i].timeRemaining < nextMin)
						nextMin = minutes[i].timeRemaining;
					if(lineLocation == 0)
						return i+1;
				}
				else
				{
					minutes[i].timeRemaining = minutes[i].timeRemaining - firstMin;
					if(minutes[i].timeRemaining < nextMin)
						nextMin = minutes[i].timeRemaining;
					
				}
			}
			firstMin = nextMin;
			nextMin = 100000;
		}
	}
	public static void main(String [] args) throws Exception
	{
		Scanner inScan = new Scanner(System.in);
		System.out.println("Enter the filename");
		String filename = inScan.nextLine();
		BufferedReader b = new BufferedReader(new FileReader(filename));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("out2.txt")));

		int numExamples = Integer.parseInt(b.readLine());
		for(int i = 0; i < numExamples; i++)
		{
			String [] stuff = b.readLine().split(" ");
			int numBarbers = Integer.parseInt(stuff[0]);
			long lineLocation = Long.parseLong(stuff[1]);
			stuff = b.readLine().split(" ");
			Pair [] minutes = new Pair[numBarbers];
			int maxIndex = -1;
			int minIndex = -1;
			long max = 0;
			long min = 100000;
			for(int j = 0; j < numBarbers; j++)
			{
				long curr = Long.parseLong(stuff[j]);
				minutes[j] = new Pair(curr,curr);
				if(curr > max)
				{
					max = curr;
					maxIndex = j;
				}
				if(curr < min)
				{
					min = curr;
					minIndex = j;
				}
			}
				
			int value = simulate(min,max,minutes,lineLocation);
			
			
			//Code goes here********
			out.print("Case #" + (i+1) + ": " + value);
			if(i != numExamples-1)
				out.println();
			out.flush();
		}
		
		out.close();
	}
	
	
}