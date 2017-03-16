import java.util.Scanner;


public class B {
	
	private static int b;
	private static long n;
	private static int[] barbers;

	public static void main(String[] args) {
		
		Scanner s = new Scanner(System.in);
		
		int numCases = s.nextInt();
		
		for(int numC = 0; numC < numCases; ++numC)
		{
			b = s.nextInt();
			n = s.nextInt();
			
			barbers = new int[b];
			
			int max = 0;
			for(int i = 0; i < b; ++i)
			{
				barbers[i] = s.nextInt();
				if(barbers[i] > max)
				{
					max = barbers[i];
				}
			}
			
			long number = binarySearch(0, (max+1) * (n+1));
			
			int res = 0;
			
			long numBefore = getNum(number-1);
			long numAfter = getNum(number);
			// detect which barbers are free...
			for(int i = 0; i < b; ++i)
			{
				if(number % barbers[i] == 0)
				{
					numBefore++;
					if(numBefore == n)
					{
						res = i+1;
						break;
					}
				}
			}
			
			System.out.print("Case #");
			System.out.print(numC+1);
			System.out.print(": ");
			System.out.println(res);
		}

	}
	
	// inclusive
	static long binarySearch(long start, long end)
	{
		if(start >= end)
		{
			return start;
		}
		
		long mid = (end+start) / 2;
		
		if(bigger(mid))
		{
			return binarySearch(mid+1, end);
		}else
		{
			return binarySearch(start, mid);
		}
		
	}
	
	static long getNum(long c)
	{
		long num = 0;
		for(int i = 0; i < b; ++i)
		{
			num += c / barbers[i] + 1;
		}
		return num;
	}
	
	static boolean bigger(long c)
	{
		long num = 0;
		for(int i = 0; i < b; ++i)
		{
			num += c / barbers[i] + 1;
			if(num > n)
			{
				return false;
			}
		}
		if(num >= n)
		{
			return false;
		}else
		{
			return true;
		}
	}

}
