import java.io.File;
import java.io.IOException;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;


public class Main 
{

	public static void main(String[] args) throws IOException 
	{
		new Main().doIt();
	}

	private void doIt() throws IOException 
	{
		Scanner sc = new Scanner(new File("in.txt"));
		PrintStream ps = new PrintStream(new File("out.txt"));
		
		int T = sc.nextInt();
		String[] ss,g;
		String s,sk;
		for(int c=1;c<=T;c++)
		{
			int n = sc.nextInt();
			ss = new String[n];
			g = new String[n];
			for(int i=0;i<n;i++)
			{
				ss[i] = sc.next();
				g[i] = getSketch(ss[i]);
				//System.out.println(g[i]);
			}
			boolean fw = false;
			sk = g[0];
			for(int i=1;i<n;i++)
			{
				if(!g[i].equals(sk))
				{
					fw = true;
					break;
				}
			}
			if(fw)
			{
				ps.printf("Case #%d: Fegla Won\n",c);
				continue;
			}
			int[] f = new int[n];
			int index,sum,best=Integer.MAX_VALUE;
			int total = 0;
			char cc;
			for(int i=0;i<sk.length();i++)
			{
				cc = sk.charAt(i);
				for(int j=0;j<n;j++)
				{
					s = ss[j];
					index = 0;
					while(index < s.length() && s.charAt(index)==cc)
					{
						index++;
					}
					ss[j] = s.substring(index);
					f[j] = index;
				}
				Arrays.sort(f);
				if(f[0]==f[n-1])
					continue;
				best=Integer.MAX_VALUE;
				for(int k=f[0];k<=f[n-1];k++)
				{
					sum = computeSum(f,k);
					best  = Math.min(sum,best);
				}
				total += best;
			}
			ps.printf("Case #%d: %d\n",c,total);
		}
		
		sc.close();
		ps.close();
		
	}
	
	private int computeSum(int[] f, int k) 
	{
		int s = 0;
		for(int i=0;i<f.length;i++)
			s += Math.abs(f[i]-k);
		return s;
	}

	private String getSketch(String s)
	{
		char c= s.charAt(0);
		String ans=c+"";
		for(int i=1;i<s.length();i++)
		{
			if(s.charAt(i)==c)
				continue;
			else
			{
				c= s.charAt(i);
				ans += (c+"");
			}
		}
		return ans;
	}
	
	
}
