import java.io.*;    //PrintWriter
import java.math.*;  //BigInteger, BigDecimal
import java.util.*;  //StringTokenizer, ArrayList

public class GCJ_2015_R1A_B
{	
	FastReader in;
	PrintWriter out;
//	final String PROBLEM_NAME = "B-ex";
	final String PROBLEM_NAME = "B-small-attempt0";
//	final String PROBLEM_NAME = "B-small-attempt1";
//	final String PROBLEM_NAME = "B-large";
	
	public static void main(String[] args) throws IOException  {
		new GCJ_2015_R1A_B().runWithFiles();
	}
	
	void run()
	{		
		in = new FastReader(System.in);
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}
	
	void runWithFiles() throws IOException  {
		in = new FastReader(new File("src/" + PROBLEM_NAME + ".in")); //"_in.txt"));
		out = new PrintWriter(new File("src/" + PROBLEM_NAME + ".out")); //"_out.txt"));

		solve();
		out.close();
	}
	
	void solve()
	{
		int T = in.nextInt();  

		for (int tc = 1; tc <= T; tc++)
		{
			int b = in.nextInt();
			int n = in.nextInt();
			
			int[] m = new int[b];
			long lcm = 0;
			for (int i = 0; i < b; i++) 
			{
				m[i] = in.nextInt();
				if (i == 0) 
					lcm = m[i];
				else
					lcm = LCM(lcm, m[i]);
			}
			
			int totInCycle = 0;
			for (int i = 0; i < b; i++)
				totInCycle += lcm / m[i];
			
			String ans = "";
			int cnt = 0;
			for (int min = 0; min < lcm && ans.equals(""); min++)
				for (int i = 0; i < b && ans.equals(""); i++)
				{
					if (min % m[i] == 0)
					{
						cnt++;
						if (n % totInCycle == cnt || (n % totInCycle == 0 && cnt == totInCycle))					
							ans = (i+1) + "";
					}
				}		

			
			System.out.println("Case #" + tc + ": " + ans);
			out.println("Case #" + tc + ": " + ans);
		}
	}
	
    long GCD(long a, long b)
    {
        if (b == 0) return a;
        return GCD(b, a % b);
    }
    long LCM(long a, long b)
    {
        return a * b / GCD(a, b);
    }


	//-----------------------------------------------------

	
	class FastReader
	{
	    BufferedReader br;
	    StringTokenizer tokenizer;
	    
	    public FastReader(InputStream stream)
	    {
	        br = new BufferedReader(new InputStreamReader(stream));
	        tokenizer = null;
	    }
		public FastReader(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
				tokenizer = null;
			}
			catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}
	    
	    private String next() {
	        while (tokenizer == null || !tokenizer.hasMoreTokens())
	            try {
	            	tokenizer = new StringTokenizer(br.readLine());
	            }
	            catch (IOException e) {
	                throw new RuntimeException(e);
	            }
	        return tokenizer.nextToken();
	    }
		public String nextLine() {
			try	{
				return br.readLine();
			}
			catch(Exception e) {
				throw(new RuntimeException());
			}
		}

	    int nextInt() {
	        return Integer.parseInt(next());
	    }
	    long nextLong() {
	        return Long.parseLong(next());
	    }
	    double nextDouble() {
	        return Double.parseDouble(next());
	    }	    
	    BigInteger nextBigInteger() {
	        return new BigInteger(next());
	    }
	    BigDecimal nextBigDecimal() {
	        return new BigDecimal(next());
	    }
	}
}
