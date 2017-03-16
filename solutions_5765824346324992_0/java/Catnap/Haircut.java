import java.util.*;
import java.io.*;

public class Haircut
{
	public static int n;
	
	public static void main(String[] args) throws IOException
	{
		Scanner sc = new Scanner(new File("Haircut.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("Haircut.out")));
		
		n = sc.nextInt();
		for (int i = 0; i < n; i++)
		{
			int numBarber = sc.nextInt();
			int place = sc.nextInt();
			ArrayList<Integer> times = new ArrayList<Integer>();
			for (int j = 0; j < numBarber; j++)
			{
				times.add(sc.nextInt());
			}
			int ans = runTest(place, times);
			out.println("Case #" + (i+1) + ": " + ans);
		}
		
		out.close();
		System.exit(0);
	}
	
	public static int runTest(int place, ArrayList<Integer> times)
	{
		//find the LCM and then find how many people they can serve in that timeframe
		//mod your place value by this 
		
		
		int lcm = lcm(times);
		int numPeople = 0;
		for (int i = 0; i < times.size(); i++)
		{
			numPeople += lcm / times.get(i);
			if (lcm % times.get(i) != 0) System.out.println("uh oh");
		}
		place %= numPeople;
		
		//System.out.println(numPeople);
		//System.out.println(place);
		
		if (place == 0) place += numPeople;
		int[] process = new int[times.size()];
		for (int i = 0; i < process.length; i++) process[i] = 1;
		while (true)
		{
			//run through the list of barbers, checking if their done (0)
			//if they are done, take a new customer (place--) and add back the time (+times.get())
			//else take one off their time
			//when place hits 0, return the barber you're currently one
			
			for (int i = 0; i < process.length; i++)
			{
				process[i]--;
				if (process[i] == 0) //if they can take a new customer
				{
					place--;
					if (place == 0) return i+1;
					process[i] += times.get(i);
				}
			}
		}
	}
	
	private static int lcm(ArrayList<Integer> input)
	{
		int result = input.get(0);
		for (int i = 1; i < input.size(); i++) result = lcm(result, input.get(i));
		return result;
	}
	
	private static int lcm(int a, int b)
	{
		return a * (b / gcd(a, b));
	}
	
	private static int gcd(int a, int b)
	{
		while (b > 0)
		{
			int temp = b;
			b = a % b; // % is remainder
			a = temp;
		}
		return a;
	}

	private static int gcd(int[] input)
	{
		int result = input[0];
		for(int i = 1; i < input.length; i++) result = gcd(result, input[i]);
		return result;
	}
}