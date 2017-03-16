import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Problem2 {
	public static void main(String args[]) throws IOException
	{
		long t = System.currentTimeMillis();

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		for(int ii=1; ii<=T; ii++)
		{		
			StringTokenizer st = new StringTokenizer(br.readLine());
			int R = Integer.parseInt(st.nextToken());
			int C = Integer.parseInt(st.nextToken());
			int N = Integer.parseInt(st.nextToken());
			int M = R*C;
			int min = Integer.MAX_VALUE;
			for(int i=0; i<(int)(Math.pow(2,M)); i++)
			{
				String s = Integer.toBinaryString(i);
				int c = 0;
				for(int j=0; j<s.length(); j++)
					if(s.charAt(j)=='1') c++;
				if(c == N)
				{
					int[][] d = new int[R][C];
					int e = 0;
					a:for(int k=0; k<R; k++)
					{
						for(int l=0; l<C; l++)
						{
							if(e < s.length())
							{
								d[k][l] = s.charAt(e)-'0';
								e++;
							}
							else
								break a;
						}
					}
					int score = 0;
					for(int k=0; k<R; k++)
					{
						for(int l=0; l<C; l++)
						{
							if(d[k][l]==1)
							{
								if(l+1 < C && d[k][l+1]==1) score++;
								if(l > 0 && d[k][l-1]==1) score++;
								if(k > 0 && d[k-1][l]==1) score++;
								if(k+1 < R && d[k+1][l]==1) score++;
							}
						}
					}
					min = Math.min(min, score);
				}
			}
			
			System.out.println("Case #"+ii+": "+min/2);
		}
		System.out.println(System.currentTimeMillis()-t);
	}
}