import java.io.*;
import java.util.*;

public class Main
{
	public static void main(String args[])
	{
		try
		{
			BufferedReader br = new BufferedReader(new FileReader("B-small-attempt1.in"));
			
			int cases = Integer.parseInt(br.readLine());
			
			for(int i = 0; i < cases; i++)
			{
				System.out.print("Case #" + (i+1) + ": ");
				
				String input = br.readLine();
				StringTokenizer st = new StringTokenizer(input);
				
				int numBarbers = Integer.parseInt(st.nextToken());
				int placeInLine = Integer.parseInt(st.nextToken());
				Barber[] barbers = new Barber[numBarbers];
				
				String barbersString = br.readLine();
				StringTokenizer st2 = new StringTokenizer(barbersString);
				
				for(int j = 0; j < numBarbers; j++)
				{
					barbers[j] = new Barber(Integer.parseInt(st2.nextToken()));
				}
				
				process(barbers, placeInLine);
				//System.out.println();
			}
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
	}
	
	public static void process(Barber[] barbers, int myPlace)
	{
		// ----------------------------
		// Quick increment based on lcm
		int lcm = (int)lcm(barbers);
		//System.out.println("lcm (jump in time) " + lcm);
		
		int quickIncrementNumber = 0;
		for(int i = 0; i < barbers.length; i++)
		{
			quickIncrementNumber += lcm / barbers[i].time;
		}
		//System.out.println("qin (jump in position)  " + quickIncrementNumber);
		
		
		int timesToJump = (myPlace / quickIncrementNumber)-1;
		//System.out.println("timesToJump " + timesToJump);
		
		int newTime = lcm * timesToJump;
		for(int i = 0; i < barbers.length; i++)
		{
			barbers[i].next = newTime;
		}
		
		// Print status
		for(int i = 0; i < barbers.length; i++)
		{
			//System.out.println("Barber " + i + "... Time: " + barbers[i].time + "... Next: " + barbers[i].next );
		}
		
		int newPosition = timesToJump * quickIncrementNumber;
		//System.out.println("Position now: " + newPosition );
		
		
		// NORMAL INCREMENT NOW		
		int time = newTime;
		for(int i = newPosition; i < myPlace; i++)
		{
			for(int j = 0; j < barbers.length; j++)
			{
				if(barbers[j].next <= time)
				{
					barbers[j].next = barbers[j].next + barbers[j].time;
					
					if(i == myPlace-1)
					{
						System.out.println("" + (j+1));
						// Print status
						for(int z = 0; z < barbers.length; z++)
						{
							//System.out.println("Barber " + z + "... Time: " + barbers[z].time + "... Next: " + barbers[z].next );
						}
					}
					break;
				}
			}
			
			time = getMinimumNextTime(barbers);
		}
	}
	
	public static int getMinimumNextTime(Barber[] barbers)
	{
		int min = Integer.MAX_VALUE;
		for(int i = 0; i < barbers.length; i++)
		{
			if(barbers[i].next < min)
			{
				min = barbers[i].next;
			}
		}
		return min;
	}
	
	
	// LCM and GCD
	private static long lcm(Barber[] input)
	{
	    long result = input[0].time;
	    for(int i = 1; i < input.length; i++)
	    	result = lcm(result, input[i].time);
	    return result;
	}
	
	private static long lcm(long a, long b)
	{
	    return a * (b / gcd(a, b));
	}
	
	private static long gcd(long a, long b)
	{
	    while (b > 0)
	    {
	        long temp = b;
	        b = a % b; // % is remainder
	        a = temp;
	    }
	    return a;
	}
}

class Barber
{
	public Barber(int time)
	{
		this.time = time;
	}
	
	public int time;
	public int next;
}
