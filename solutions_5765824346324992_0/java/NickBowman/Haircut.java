import java.util.*;
import java.io.*;
import java.math.BigInteger;

public class Haircut{

	
	public static void main(String[] args) throws IOException
	{
		Haircut solution = new Haircut();

		solution.solve();

	}

	public void solve() throws IOException
	{
		Scanner input = new Scanner( new File( "B-small-attempt0.in"));
		//Scanner input = new Scanner( new File( "DijkstraInput.txt"));
		//Scanner input = new Scanner( new File( "MissedCases.txt"));
		PrintWriter writer = new PrintWriter( "HaircutOutput.txt");
		int numCases = Integer.parseInt( input.nextLine());
		for ( int x = 0; x < numCases; x++)
		{
			String tempLine = input.nextLine();
			StringTokenizer io = new StringTokenizer(tempLine);
			int b = Integer.parseInt(io.nextToken());
			int n = Integer.parseInt(io.nextToken());
			String tempLine2 = input.nextLine();
			StringTokenizer io2 = new StringTokenizer(tempLine2);
			ArrayList<Integer> minutes = new ArrayList<Integer>();
			int ans = 0;
			while (io2.hasMoreTokens())
			{
				minutes.add(Integer.parseInt(io2.nextToken()));
			}
			Barber[] barbers = new Barber[b];
			for ( int i = 0; i<b; i++)
			{
				barbers[i] = new Barber(i+1, minutes.get(i));
			}
			int lcm = 1;
			for (int a = 0; a< minutes.size(); a++)
			{
				lcm*= minutes.get(a);
			}
			int numCutted = 0;
			for ( int lol = 0; lol<minutes.size(); lol++)
			{
				numCutted += lcm/minutes.get(lol);
			}
			if (n<= b)
			{
				ans = n;
			}
			else
			{
				n = n%numCutted;
				if ( n == 0 )
				{
					n = numCutted;
				}
				int numAssigned = assign(barbers);
				System.out.println(numAssigned);
				if ( n <= b)
				{
					ans = n;
				}
				int customerBeingServed = 1 + numAssigned;
				while ( customerBeingServed < (n+1))
				{
					for ( int i = 0; i < barbers.length; i++)
					{
						if ( barbers[i].isFree())
						{
							barbers[i].assignCustomer();
							customerBeingServed++;
							if ( customerBeingServed == (n+1))
							{
								ans = barbers[i].getIdentifier();
							}
						}
					}
					for ( int l = 0; l < barbers.length; l++)
					{
						barbers[l].minutePassed();
					}
				}


			}
			writer.println("Case #" + (x+1) + ": " + ans );

		}
		writer.close();
		


	}

	public int assign(Barber[] barbs)
	{
		int numAssigned = 0;
		for ( int x =0; x<barbs.length; x++)
		{
			if ( barbs[x].isFree())
			{
				numAssigned++;
				barbs[x].assignCustomer();
			}
		}
		return numAssigned;
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



	public class Barber{

		int myIdentifier;
		int myDuration;
		int minutesLeft;
		public Barber(int identifier, int duration)
		{
			myIdentifier = identifier;
			myDuration = duration;
			minutesLeft = 0;
		}

		public boolean isFree()
		{
			return minutesLeft == 0;
		}

		public void assignCustomer()
		{
			minutesLeft = myDuration;
		}

		public int getIdentifier()
		{
			return myIdentifier;
		}

		public void minutePassed()
		{
			minutesLeft--;
		}
	}

	

	
	

	
}