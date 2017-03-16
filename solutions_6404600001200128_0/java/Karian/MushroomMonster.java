import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;


public class MushroomMonster {

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
	
	public static String solve(BufferedReader buffer) throws NumberFormatException, IOException
	{
		//read input
		int N = Integer.parseInt(buffer.readLine().trim());
		long[] m = new long[N];
		String[] split = buffer.readLine().trim().split("\\s+");
		long eat1 = 0;
		long eat2 = 0;
		long biggestDifference = 0;
		m[0] = Long.parseLong(split[0]);
		for(int i = 1; i < N; i++)
		{
			m[i] = Long.parseLong(split[i]);
			long difference = m[i-1] - m[i];
			if(difference > 0)
			{
				eat1 += difference;
			}
			if(difference > biggestDifference)
			{
				biggestDifference = difference;
			}
		}
		for(int i = 0; i < N - 1; i++)
		{
			eat2 += Math.min(biggestDifference, m[i]);
		}
		return new String(eat1 + " " + eat2);
	}
}
