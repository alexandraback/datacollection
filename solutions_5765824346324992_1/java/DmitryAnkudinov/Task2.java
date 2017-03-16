package Round1A;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Scanner;

public class Task2 {
	private static long gcd(long a, long b)
	{
	    while (b > 0)
	    {
	    	long temp = b;
	        b = a % b;
	        a = temp;
	    }
	    return a;
	}

	private static long gcd(int[] input)
	{
		long result = input[0];
	    for(int i = 1; i < input.length; i++) result = gcd(result, input[i]);
	    return result;
	}
	
	private static long lcm(long a, long b)
	{
	    return a * (b / gcd(a, b));
	}

	private static long lcm(int[] input)
	{
		long result = input[0];
	    for(int i = 1; i < input.length; i++) result = lcm(result, input[i]);
	    return result;
	}
	
	public static void main(String[] args) throws FileNotFoundException {
		File file = new File("D:/Development/Competitions/GoogleCodeJam/GoogleCodeJam2015/data/B-large.in");
		
		Scanner sc = new Scanner(file);
		//Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		int[] result = new int[T];
		
		for (int i = 0; i < T; ++i)
		{
			int B = sc.nextInt();
			int[] M = new int[B];
			int N = sc.nextInt();
			for (int j = 0; j < B; ++j)
				M[j] = sc.nextInt();
			
			long cycleLength = lcm(M);
			long cycleStep = gcd(M);
			
			ArrayList<Integer> indices = new ArrayList<Integer>();
			for (int j = 0; j < B; ++j)
				indices.add(j + 1);
			
			System.out.printf("Have to process %d steps\n", cycleLength / cycleStep); 
			int count = 1;
			for (long step = cycleStep; step < cycleLength; step += cycleStep)
			{
				count++;
				if (count % 10000 == 0)
					System.out.printf("Processed %d\n", count);
				
				for (int j = 0; j < B; ++j)
				{
					if ((step % M[j]) == 0)
						indices.add(j + 1);
				}
			}
			
			result[i] = indices.get((N - 1) % indices.size());
		}
		sc.close();

		PrintStream out = new PrintStream(new FileOutputStream("D:/Development/Competitions/GoogleCodeJam/GoogleCodeJam2015/data/B-large.out"));
		System.setOut(out);
		for (int i = 0; i < T; ++i)
			System.out.println(String.format("Case #%d: %d", i + 1, result[i]));
	}
}


/*
Problem


*/