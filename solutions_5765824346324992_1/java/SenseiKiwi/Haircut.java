package round1A;

import java.util.Scanner;

public class Haircut {

	public static void main(String[] args) {
		
		Scanner input = new Scanner(System.in);
		
		int c;
		int k;
		int b;
		int n;
		int cases;
		int[] times;
		
		cases = input.nextInt();
		for (c = 1; c <= cases; c++)
		{
			b = input.nextInt();
			n = input.nextInt();
			times = new int[b];
			for (k = 0; k < b; k++)
				times[k] = input.nextInt();
			
			System.out.printf("Case #%d: %d\n", c, solve(n, times));
		}
	}
	
	static long solve(long turn, int[] times)
	{
		// At a certain time T, barber K has seen FLOOR(T / M[K]) + 1 customers.
		// That includes seeing the first customer at time T = 0.
		// Apply binary search to find the lowest time such that the total number
		// of customers attended A is less than or equal to N (turn in line).
		
		// Worst case time is one incredibly slow barber and an insanely long line:
		// 10^9 * 10^5 = 10^14
		// Also need to make sure that A doesn't cause an overflow for the fastest
		// barbershop possible: 10^3 barbers seeing 1 customer each minute given 10^14 minutes to work.
		// That's... 10^17 customers attended, which is (barely) safe.
		
		int k;
		int w;
		long mid;
		long lower = 0;
		long upper = 100000000001000L;
		while (lower < upper)
		{
			mid = (upper - lower) / 2 + lower;
			if (countAttended(mid, times) < turn)
				lower = mid + 1;
			else
				upper = mid;
		}
		// Calculate W: the position in the order of people attended when the target turn comes up
		w = (int) (turn - countAttended(lower - 1, times));
		
		// Find the Wth available barber
		for (k = 0; k < times.length; k++)
		{
			if (lower % times[k] == 0)
			{
				w--;
				if (w == 0)
					return k + 1;
			}
		}
		return -1;
	}
	
	static long countAttended(long minute, int[] times)
	{
		long attended = 0;
		for (int k = 0; k < times.length; k++)
			attended += minute / times[k] + 1;
		return attended;
	}

}
