import java.io.*;    //PrintWriter
import java.math.*;  //BigInteger, BigDecimal
import java.util.*;  //StringTokenizer, ArrayList

public class GCJ_2015_R1A_A
{	
	FastReader in;
	PrintWriter out;
//	final String PROBLEM_NAME = "A-ex";
	final String PROBLEM_NAME = "A-small-attempt0";
//	final String PROBLEM_NAME = "A-small-attempt1";
//	final String PROBLEM_NAME = "A-small-practice";
//	final String PROBLEM_NAME = "A-large";
	
	public static void main(String[] args) throws IOException  {
		new GCJ_2015_R1A_A().runWithFiles();
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
			int n = in.nextInt();
			
			int[] m = new int[n];
			for (int i = 0; i < n; i++) 
				m[i] = in.nextInt();
			
			int max = 0, cnt = 0;
			for (int i = 0; i < n-1; i++)
			{
				max = Math.max(max, m[i] - m[i+1]);
				if (m[i] > m[i+1]) 
					cnt += (m[i] - m[i+1]);
			}
			
			int cnt2 = 0;
			for (int i = 0; i < n-1; i++)
			{
				if (m[i] <= max)
					cnt2 += m[i];
				else
				{
					cnt2 += max;
					m[i] -= 10;
				}
			}
			
			String ans = cnt + " " + cnt2;
			
			System.out.println("Case #" + tc + ": " + ans);
			out.println("Case #" + tc + ": " + ans);
		}
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
