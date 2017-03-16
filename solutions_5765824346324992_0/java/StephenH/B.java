import java.util.*;

public class B
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int test = 1, cases = Integer.parseInt(sc.nextLine());

		int[] barberRem;
		int[] barberTime;

		long position, cycle, cycleCut;
		int numBarbs;
		int next;
		int nextDone, newNextDone;
		int cutBarber;

		boolean noCycle;

		int i;

		while(test <= cases)
		{
			numBarbs = sc.nextInt();
			position = sc.nextInt();

			barberRem = new int[numBarbs];
			barberTime = new int[numBarbs];

			for(i = 0; i < numBarbs; i++)
			{
				barberTime[i] = sc.nextInt();
			}

			cutBarber = -1;
			cycle = 1;

			noCycle = false;

			for(i = 0; i < numBarbs; i++)
			{
				barberRem[i] = 0;

				if(!noCycle)
					cycle = (cycle / gcd(cycle, barberTime[i])) * barberTime[i];

				if(cycle >= position * 100000)
					noCycle = true;
			}

			if(!noCycle)
			{
				cycleCut = 0;

				for(i = 0; i < numBarbs; i++)
				{
					cycleCut += cycle / barberTime[i];
				}

				position %= cycleCut;

				if(position == 0)
					position = cycleCut;
			}

			next = 1;
			nextDone = 0;

			while(next <= position)
			{
				newNextDone = Integer.MAX_VALUE;

				for(i = 0; i < numBarbs; i++)
				{
					barberRem[i] -= nextDone;

					if(barberRem[i] == 0)
					{
						barberRem[i] = barberTime[i];

						if(next == position)
							cutBarber = i + 1;

						next++;
					}

					newNextDone = Math.min(newNextDone, barberRem[i]);
				}

				nextDone = newNextDone;
			}

			System.out.println("Case #" + test + ": " + cutBarber);

			test++;
		}
	}

	public static long gcd(long a, long b)
	{
		if(a == 0)
			return b;

		if(b == 0)
			return a;

		if(a > b)
			return gcd(a % b, b);
		else return gcd(a, b % a);
	}
}