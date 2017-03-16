import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;
import java.io.*;


public class ProblemB {
	public static void main(String[] args) throws IOException
	{
		Scanner in = new Scanner(new File("B-large.in"));
		PrintWriter out = new PrintWriter(new File("outputBlarge.txt"));
		int  t = in.nextInt();
		//System.out.println(t);
		for (int tnumber = 1; tnumber <= t; tnumber++)
		{
			int B = in.nextInt();
			int n = in.nextInt();
			int [] a = new int[B];
			int [] C = new int[100001];
			for (int i = 0; i < B; i++) 
			{
				a[i] = in.nextInt();
				//if  (a[i] == 0) System.out.println("WTFF" + tnumber);
				C[a[i]]++;
			}
			long l = 0; 
			long r = ((long) n) * 100000 + 1;
			long T = -1;
			while (l <= r)
			{
				long m = (l + r) / 2;
				long cnt = 0;
				for (int i = 0; i < B; i++)
				{
					cnt += m / (long) a[i] + 1;
					
 				}
				if (cnt >= (long) n) 
				{ 
					if (T == -1 || m < T) T = m; 
					r = m - 1; 
				}
				else l = m + 1;
			}
			System.out.println((long) T);
			int ans = -1;
			
			for (int i = 0; i < B; i++)
				if (T % a[i] == 0)
				{
					long S = T;
					long cnt = 0;
					if (S < 0) continue;
					for (int j = 0; j < B; j++)
						if (S % a[j] != 0) cnt += 1 + (S / a[j]);
						else cnt += S / a[j]; 
					for (int j = 0; j < i; j++) 
						if (S % a[j] == 0) cnt++;
					if (cnt == n - 1) { ans = i + 1; break; }
				}
			out.println("Case #" + tnumber + ": " + ans);

		}
		in.close();
		out.close();			
	}
		
		
		
	
	
	
}
