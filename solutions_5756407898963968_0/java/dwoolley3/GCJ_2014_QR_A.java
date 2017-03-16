import java.io.*;    //PrintWriter
import java.math.*;  //BigInteger, BigDecimal
import java.util.*;  //StringTokenizer, ArrayList


public class GCJ_2014_QR_A
{	
	FastReader in;
	PrintWriter out;
	
	public static void main(String[] args)  {
		new GCJ_2014_QR_A().runWithFiles();
	}
	
	void run()
	{		
		in = new FastReader(System.in);
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}
	
	void runWithFiles() {
		//in = new FastReader(new File("src/A-ex.in"));
		in = new FastReader(new File("src/A-small-attempt0.in"));
		//in = new FastReader(new File("src/A-large.in"));
		try {
			//out = new PrintWriter(new File("src/A-ex.out"));
			out = new PrintWriter(new File("src/A-small-attempt0.out"));
			//out = new PrintWriter(new File("src/A-large.out"));
		} 
		catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		solve();
		out.close();
	}
	
	void solve()
	{
		int T = in.nextInt();  
		//in.nextLine(); //use after a nextInt() and prior to reading another in.nextLine()

		for (int tc = 1; tc <= T; tc++)
		{
			int r1 = in.nextInt() - 1;
			
			int[][] a = new int[4][4];
			for (int i = 0; i < 4; i++) 
				for (int j = 0; j < 4; j++) 
					a[i][j] = in.nextInt();
			
			int r2 = in.nextInt() - 1;
			int[][] b = new int[4][4];
			for (int i = 0; i < 4; i++) 
				for (int j = 0; j < 4; j++) 
					b[i][j] = in.nextInt();
			
			int cnt = 0, g = 0;
			for (int i = 0; i < 4; i++)
				for (int j = 0; j < 4; j++)
					if (a[r1][i] == b[r2][j])
					{
						g = a[r1][i];											
						cnt++;
					}		

			String ans = "";
			if (cnt == 1) ans = g+"";
			else if (cnt == 0) ans = "Volunteer cheated!";
			else ans = "Bad magician!";
			
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
