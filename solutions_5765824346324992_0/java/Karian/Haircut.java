import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.LinkedList;


public class Haircut {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws NumberFormatException, IOException {
		// open file and create a buffered reader
		FileReader input = new FileReader(args[0]);
		BufferedReader buffer = new BufferedReader(input);
		
		//read the number of testcases
		int max = Integer.parseInt(buffer.readLine().trim());
		
		// read a line and call the solving procedure for a single test case.  We expect back the result as a string
		for (int i = 1; i <= max; i++) {
			System.out.println("Case #"+i+": " + solve(buffer));
		}
	}
	
	public static int solve(BufferedReader buffer) throws NumberFormatException, IOException
	{
		//read input
		String[] split = buffer.readLine().trim().split("\\s+");
		int B = Integer.parseInt(split[0]);
		int N = Integer.parseInt(split[1]);
		int[] M = new int[B];
		String[] split2 = buffer.readLine().trim().split("\\s+");
		if(B == 1)
		{
			return 1;
		}
		for(int i = 0; i < B; i++)
		{
			M[i] = Integer.parseInt(split2[i]);
		}
		int lcm = lcm(M);
		int loop = 0;
		for(int i = 0; i < B; i++)
		{
			loop += lcm/M[i];
		}
		N = N % loop;
		if(N == 0)
		{
			N = loop;
		}
		int[] waitingTime = new int[B];
		LinkedList<Integer> list = new LinkedList<Integer>();
		boolean running = true;
		int min = 0;
		while(min < lcm)
		{
			int i = 0;
			while(waitingTime[i] > min)
			{
				i++;
			}
			list.add(i+1);
			waitingTime[i] += M[i];
			min = min(waitingTime);
		}
		return list.get(N-1);
	}
	
	private static int min(int[] input)
	{
	    int result = input[0];
	    for(int i = 1; i < input.length; i++) result = Math.min(result, input[i]);
	    return result;
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

	private static int lcm(int a, int b)
	{
	    return a * (b / gcd(a, b));
	}

	private static int lcm(int[] input)
	{
	    int result = input[0];
	    for(int i = 1; i < input.length; i++) result = lcm(result, input[i]);
	    return result;
	}
	
}
