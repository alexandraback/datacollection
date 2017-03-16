import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.ArrayList;
import java.util.Scanner;

public class R1B {

	private final static String CLASS_NAME = R1B.class.getSimpleName();
	
	public static void main(String[] args) throws FileNotFoundException, UnsupportedEncodingException {
		PrintWriter writer = new PrintWriter(CLASS_NAME + ".out", "UTF-8");
		Scanner scan = new Scanner(System.in);
		int T = scan.nextInt();
		for(int t=0; t<T; t++)
		{
			int B = scan.nextInt();
			long N = scan.nextLong();
			long[] M = new long[B];
			for(int b=0; b<B; b++)
			{
				M[b] = scan.nextLong();
			}
			String ans = "Case #"+(t+1)+": " + getAns(M, N);
			System.out.println(ans);
			writer.println(ans);
		}
		scan.close();
		writer.close();
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
	
	private static long lcm(long a, long b)
	{
	    return a * (b / gcd(a, b));
	}
	
	private static long lcm(long[] input)
	{
	    long result = input[0];
	    for(int i = 1; i < input.length; i++) result = lcm(result, input[i]);
	    return result;
	}
	
	private static String getAns(long[] M, long N)
	{
		long LCD = lcm(M);
		int numCustSatisfied = 0;
		for(int i=0; i<M.length; i++)
		{
			numCustSatisfied += LCD / M[i];
		}
	
		
		ArrayList<Integer> nextIndex = new ArrayList<>();
		
		
		long[] next = new long[M.length];
		
		for(int i=0; i<numCustSatisfied; i++)
		{
			int nextBarber = getMinIndex(next);
			nextIndex.add(nextBarber);
			next[nextBarber] += M[nextBarber];
		}
		
		int indexToLookup = -1;
		if(N%numCustSatisfied == 0)
		{
			indexToLookup = nextIndex.size() - 1;
		}
		else
		{
			indexToLookup = (int)((N%numCustSatisfied) -1);
		}
		int barberIndex = nextIndex.get(indexToLookup);
		
		return (barberIndex+1) + "";
	}
	
	private static int getMinIndex(long[] next)
	{
		long lowest = Long.MAX_VALUE;
		int lowestIndex = -1;
		for(int i = 0; i < next.length; i++){
	        if(lowest > next[i])
	        {
	        	lowest = next[i];
	        	lowestIndex = i;
	        }
	    }
		return lowestIndex;
	}

}
