import java.util.Scanner;
import java.io.*;

public class CodeJam {
	
	int[] child;
	
	public static void main(String[] args) throws IOException
	{
		Scanner in = new Scanner(new File("in.txt"));
		PrintStream out = new PrintStream(new File("out.txt"));
		int t=in.nextInt();
		for(int q=1;q<=t;q++)
		{
			out.print("Case #"+q+": ");
			int n=in.nextInt();
			int[][] count = new int[n][105];
			char[] letter = new char[105];
			int index=0;
			String x = in.next().trim();
			letter[0]=x.charAt(0);
			count[0][0]=1;
			for(int i=1;i<x.length();i++)
			{
				if(letter[index]==x.charAt(i))
					count[0][index]++;
				else
				{
					index++;
					letter[index]=x.charAt(i);
					count[0][index]=1;
				}
			}
			letter[index+1]='#';
			System.out.println(letter);
			int check=0;
			for(int i=1;i<n;i++)
			{
				String y = in.next().trim();
				int indexx=0;
				if(letter[0]!=y.charAt(0))
				{
					check=1;
					break;
				}
				for(int j=0;j<y.length();j++)
				{
					if(letter[indexx]==y.charAt(j))
						count[i][indexx]++;
					else
					{
						if(letter[indexx+1]==y.charAt(j))
						{
							indexx++;
							count[i][indexx]++;
						}
						else
						{
							check=1;
							break;
						}
					}
				}
				if(index!=indexx)
					check=1;
				if(check==1)
					break;
			}
			if(check==1)
			{
				out.println("Fegla Won");
				continue;
			}
			int ans=0;
			for(int i=0;i<=index;i++)
			{
				int min=999999999;
				for(int h=1;h<=100;h++)
				{
					int sum=0;
					for(int j=0;j<n;j++)
						sum+=abb(h-count[j][i]);
					if(min>sum)
						min=sum;
				}
				ans+=min;
			}
			out.println(ans);
		}
		in.close();
		out.close();
	}
	
	public static int abb(int x)
	{
		if(x<0)
			return -x;
		return x;
	}
}
