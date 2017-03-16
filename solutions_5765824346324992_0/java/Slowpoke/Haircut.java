import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;


public class Haircut {
	Scanner in;	public static void main(String[] args){
		Haircut  myClass = new Haircut();
		myClass.solve();
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

	private static long gcd(long[] input)
	{
	    long result = input[0];
	    for(int i = 1; i < input.length; i++) result = gcd(result, input[i]);
	    return result;
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
	
	
	
	FileWriter writer; 
		private void solve() {
		try {			in =  new Scanner(new BufferedReader(new FileReader("B-small-attempt2.in")));
		writer = new FileWriter("the-file-name.txt");
		int T = in.nextInt();
			for(int i = 1; i <= T; i++){
				
			ArrayList<Long> mults = new ArrayList<Long>();	
			int B = in.nextInt();
			long N = in.nextLong();
			N  = N -1;
			
			
			long[] allBs = new long[B];
			long allMult = 1;
			long[] allTimes = new long[B];
			
			long modCustomers = 0;
			BigInteger bigN = new BigInteger(N + "");
		
			
			long ans = 0;
			
			for(int j = 0; j < B; j++){
				allBs[j] = in.nextLong();
				//allTimes[j] = allBs[j];
				//allMult = allMult * allBs[j]; 
			}
		
			
			allMult = lcm(allBs);
			
			for(int j = 0; j < B; j++){
				modCustomers += allMult / allBs[j];
			}
			
			long limit = bigN.mod(new BigInteger(""+modCustomers)).longValue();
			
			long coun = 0;
			int minIndex = -1;
			
			System.out.println(limit);
			
			while(coun <= limit){
				
				long min = Long.MAX_VALUE;
				
				for(int j = 0; j < B; j++){
					if(allTimes[j] < min){
						minIndex = j;
						min = allTimes[j];
					}
				}
				
				allTimes[minIndex] += allBs[minIndex];
				coun++;
				
			}
			
			
			
			
			
			ans = minIndex + 1;
			
			StringBuilder s = new StringBuilder();
			s.append("Case #");
			s.append(i);
			s.append(": ");
s.append(ans);
			
			s.append("\n");
			
	writer.write(s.toString());
			
					}
		writer.close();			
		}
			catch (IOException e) {
			}
			
			
		}
}
