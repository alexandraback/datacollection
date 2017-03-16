import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class CodeJam1A_2 {
	
	public static void main(String[] args) {
		// Template starts here
		BufferedReader br = null;
		try {
			br = new BufferedReader(new FileReader("input.txt"));
			int numTestCase = Integer.valueOf(br.readLine());
			for(int testCase=1; testCase<=numTestCase; testCase++)
			{
				System.out.print("Case #" + testCase + ": ");
				
				// Read each test case
				
				// Array
				String[] qArray = br.readLine().split(" ");
				int numBarber = Integer.valueOf(qArray[0]);
				long myPlace = Long.valueOf(qArray[1]);
				
				// Array
				String[] qArray2 = br.readLine().split(" ");
				long[] minutes = new long[numBarber];
				long[] minutesLeft = new long[numBarber];
				for(int i=0; i<numBarber; i++)
				{
					minutes[i] = Integer.valueOf(qArray2[i]);
					minutesLeft[i] = 0;
				}
				
				
				int ans = 0;
				
				//long minGlobalMinute = min(minutes);
				long maxTimeToTrial = myPlace*max(minutes);
				long minTimeToTrial = 0;
				//long timeToTrial = (myPlace/numBarber)*minGlobalMinute;
				long timeToTrial = maxTimeToTrial/2;
				//long previousTimeToTrial = 0;
				long currentQueueInBarber = 0;
				while(true)
				{
					currentQueueInBarber = 0;
					
					for(int i=0; i<numBarber; i++)
					{
						long headCut = timeToTrial/minutes[i];
						currentQueueInBarber += headCut;
						long timeUsed = headCut*minutes[i];
						long diff = timeToTrial - timeUsed;
							
						minutesLeft[i] = minutes[i] - diff;
						currentQueueInBarber++;
						
					}
					if(currentQueueInBarber > myPlace)
					{
						maxTimeToTrial = timeToTrial;
						timeToTrial = (minTimeToTrial + maxTimeToTrial)/2;
					}
					else if(currentQueueInBarber < myPlace)
					{
						minTimeToTrial = timeToTrial;
						timeToTrial = (minTimeToTrial + maxTimeToTrial)/2;
						if(maxTimeToTrial - minTimeToTrial < 5)
						{
							break;
						}
					}
					else
					{
						break;
					}
						
				}
				
				if(currentQueueInBarber == myPlace)
				{
					long[] timeJustUsed = new long[numBarber];
					for(int i=0; i<numBarber; i++)
					{
						timeJustUsed[i] = minutes[i] - minutesLeft[i];
					}
					ans = find(timeJustUsed, min(timeJustUsed)) +1;
				}
				
				while(currentQueueInBarber != myPlace)
				{
					long minMinute = min(minutesLeft);
					if(minMinute == 0)
					{
						int freeBarber = findZero(minutesLeft);
						minutesLeft[freeBarber] = minutes[freeBarber];
						currentQueueInBarber++;
						ans = freeBarber+1;
					}
					else
					{
						for(int i=0; i<numBarber; i++)
						{
							minutesLeft[i] -= minMinute;
						}
					}
				}
				
				// Print output
				System.out.println(ans);
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
		// Template ends here
	}
	
	public static long min(long[] array)
	{
		long min = Long.MAX_VALUE;
		for(int i=0; i<array.length; i++)
		{
			if(array[i] == 0 )
			{
				return 0;
			}
			if(array[i] < min)
			{
				min = array[i];
			}
		}
		return min;
	}
	
	public static long max(long[] array)
	{
		long max = Long.MIN_VALUE;
		for(int i=0; i<array.length; i++)
		{
			if(array[i] > max)
			{
				max = array[i];
			}
		}
		return max;
	}
	
	public static int findZero(long[] array)
	{
		for(int i=0; i<array.length; i++)
		{
			if(array[i] == 0 )
			{
				return i;
			}			
		}
		return -1;
	}
	
	public static int find(long[] array, long value)
	{
		for(int i=array.length-1; i>=0; i--)
		{
			if(array[i] == value)
			{
				return i;
			}			
		}
		return -1;
	}
	
}
