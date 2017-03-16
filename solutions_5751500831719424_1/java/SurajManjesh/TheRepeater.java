import java.util.*;
import java.io.*;

public class TheRepeater
{
	public static void main(String args[])throws IOException
	{
		Scanner sc = new Scanner(new File("TR_l.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("TR_l.out"));
		int T=sc.nextInt();
		int N,i,j,k,l,count,low,temp;
		boolean flag;
		int c[][];
		String arr[],output,s[];
		for(i=1;i<=T;i++)
		{
			N=sc.nextInt();
			arr=new String[N];
			s=new String[N];
			for(j=0;j<N;j++)
			{
				arr[j]=sc.next();
				for(l=0,k=0;l<arr[j].length();)
				{
					while(arr[j].charAt(l)==arr[j].charAt(k))
					{
						k++;
						if(k>arr[j].length()-1)
							break;
					}
					s[j]+=arr[j].charAt(l);
					l=k;
				}
			}
			flag=true;
			for(j=0;j<N-1;j++)
			{
				if(!s[j].equals(s[j+1]))
				{
					flag=false;
					break;
				}
			}
			count=0;
			if(flag)
			{
				c=new int[N][s[0].length()];
				for(j=0;j<N;j++)
				{
					l=0;
					for(k=0;k<s[0].length();k++)
					{
						while(s[j].charAt(k)==arr[j].charAt(l))
						{
						l++;
						if(l>arr[j].length()-1)
							break;
						c[j][k]++;
						}
					}
				}
				count=0;
				for(k=0;k<s[0].length();k++)
				{
					low=Integer.MAX_VALUE;
					for(l=0;l<N;l++)
					{
						temp=0;
						for(j=0;j<N;j++)
						{
							temp+=(int)(Math.abs(c[j][k]-c[l][k]));
						}
						if(temp<low)
							low=temp;
					}
					count+=low;
				}
			output=Integer.toString(count);
			}
			else
			output="Fegla Won";
			pw.println("Case #"+i+": "+output);
		}
		sc.close();
		pw.close();
	}

}