import java.io.*;    //PrintWriter
import java.math.*;  //BigInteger, BigDecimal
import java.util.*;  //StringTokenizer, ArrayList

public class GCJ_2015_R1B_B
{	
	FastReader in;
	PrintWriter out;
//	final String PROBLEM_NAME = "B-ex";
	final String PROBLEM_NAME = "B-small-attempt0";
//	final String PROBLEM_NAME = "B-small-attempt1";
//	final String PROBLEM_NAME = "B-large";
	
	public static void main(String[] args) throws IOException  {
		new GCJ_2015_R1B_B().runWithFiles();
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
			int r = in.nextInt();
			int c = in.nextInt();
			int n = in.nextInt();
			
			int max = r*c, minCnt = Integer.MAX_VALUE;
			
	        for (int mask = 0; mask < 1 << max; mask++)
	        {
	        	boolean[][] a = new boolean[r][c];
		        if (Integer.bitCount(mask) == n)
		        {
			        for (int i = 0; i < max; i++)
		                if ((mask & 1 << i) > 0)
		                {
		                	int rr = i / c;
		                	int cc = i - rr * c;
		                	a[rr][cc] = true;
		                }

		        	int cnt = 0;
			        for (int i = 0; i < r; i++)
			        	for (int j= 0; j < c-1; j++)
			        		if (a[i][j] && a[i][j+1]) cnt++;
			        
			        for (int i = 0; i < r-1; i++)
			        	for (int j= 0; j < c; j++)
			        		if (a[i][j] && a[i+1][j]) cnt++;
			        
			        minCnt = Math.min(cnt,  minCnt);
		        }
	        }

			String ans = minCnt+"";
			
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
