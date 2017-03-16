/*
ID: jprakha1
LANG: JAVA
TASK: R1_2
 */

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

/*
public class R1_2 {

}

 */

public class R1_2 {
	private static PrintWriter printWriter;

	public void solve() throws FileNotFoundException {
		InputStream inputStream = getClass().getResourceAsStream("R1_2.in");

		InputHelper inputHelper = new InputHelper(inputStream);

		printWriter = new PrintWriter(new File("R1_2.out"));

		//actual solution
		int t = inputHelper.readInteger();
		
		for(int ct = 1; ct <= t; ct++)
		{
			int r = inputHelper.readInteger();
			int c = inputHelper.readInteger();
			int n = inputHelper.readInteger();
			
			int p = 0;
			int ans = 100000;
			while(p < (1 << (r * c)))
			{
				int nop = 0;
				for(int i = 0; i < r; i++)
				{
					for(int j = 0; j < c; j++)
					{
						if(((1 << (i * c + j)) & p) == (1 << (i * c + j)))
							nop++;
					}
				}
				
				if(nop != n)
				{
					p++;
					continue;
				}
				
				int ns = 0;
				for(int i = 0; i < r; i++)
				{
					for(int j = 0; j < c; j++)
					{
						int ci = i * c + j;
						
						int oi = (i - 1) * c + j;
						if(i > 0 && isS(p, ci) && isS(p, oi))
						{
							ns++;
						}
						
						oi = i * c + j - 1;
						if(j > 0 && isS(p, ci) && isS(p, oi))
						{
							ns++;
						}
					}
				}
				
				ans = Math.min(ans, ns);
				
				p++;
			}
			
			printWriter.println("Case #" + ct + ": " + ans);
		}

		//end here

		printWriter.close();
	}

	private boolean isS(int p, int ci) {
		if((p & (1 << ci)) == (1 << ci))
		{
			return true;
		}
		return false;
	}

	public static void main(String[] args) throws FileNotFoundException {
		(new R1_2()).solve();
	}

	class InputHelper {
		StringTokenizer tokenizer = null;
		private BufferedReader bufferedReader;

		public InputHelper(InputStream inputStream) {
			InputStreamReader inputStreamReader = new InputStreamReader(
					inputStream);
			bufferedReader = new BufferedReader(inputStreamReader, 16384);
		}

		public String read() {
			while (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					String line = bufferedReader.readLine();
					if (line == null) {
						return null;
					}
					tokenizer = new StringTokenizer(line);
				} catch (IOException e) {
					e.printStackTrace();
				}
			}

			return tokenizer.nextToken();
		}

		public Integer readInteger() {
			return Integer.parseInt(read());
		}

		public Long readLong() {
			return Long.parseLong(read());
		}
	}
}
