package round1A;

import java.util.Scanner;

public class MushroomMonster {

	public static void main(String[] args) {
		
		Scanner input = new Scanner(System.in);
		
		int c;
		int k;
		int n;
		int cases;
		int[] shrooms;
		
		cases = input.nextInt();
		for (c = 1; c <= cases; c++)
		{
			n = input.nextInt();
			shrooms = new int[n];
			for (k = 0; k < n; k++)
				shrooms[k] = input.nextInt();
			
			System.out.printf("Case #%d: %d %d\n", c, methodA(shrooms), methodB(shrooms));
		}
	}
	
	static long methodA(int[] shrooms)
	{
		int k;
		long total = 0;
		for (k = 1; k < shrooms.length; k++)
			if (shrooms[k] < shrooms[k - 1])
				total += shrooms[k - 1] - shrooms[k];
		
		return total;
	}
	
	static long methodB(int[] shrooms)
	{
		// Find the maximum drop between rounds.
		// Then assume that she always eats that many mushrooms between rounds.
		// If that would result in fewer mushrooms than there are recorded,
		// assume that she ate as many as were available and that Bartholomew
		// added more instantly before the next measurement.
		
		int k;
		long max = 0;
		for (k = 1; k < shrooms.length; k++)
			max = Math.max(max, shrooms[k - 1] - shrooms[k]);

		long total = 0;
		for (k = 1; k < shrooms.length; k++)
			total += Math.min(max, shrooms[k - 1]);
		
		return total;
	}

}
