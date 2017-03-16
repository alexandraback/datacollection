import java.util.*;
import java.io.*;

public class TheRepeater
{
	public static void main(String args[])throws IOException
	{
		Scanner sc = new Scanner(new File("TR_s.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("TR_s.out"));
		int T=sc.nextInt();
		int i,j,k,l,count;
		int count1[],count2[];
		String a,b,output,s1,s2;
		for(i=1;i<=T;i++)
		{
			sc.nextInt();
			a=sc.next();
			b=sc.next();
			s1="";
			s2="";
			for(j=0,k=0;j<a.length();)
			{
				while(a.charAt(j)==a.charAt(k))
				{
					k++;
					if(k>a.length()-1)
						break;
				}
				s1+=a.charAt(j);
				j=k;
			}
			for(j=0,k=0;j<b.length();)
			{
				while(b.charAt(j)==b.charAt(k))
				{
					k++;
					if(k>b.length()-1)
						break;
				}
				s2+=b.charAt(j);
				j=k;
			}
			count=0;
			if(s1.equals(s2))
			{
			count1=new int[s1.length()];
			count2=new int[s1.length()];
			for(j=0,k=0,l=0;j<count1.length;j++)
			{
				while(s1.charAt(j)==a.charAt(k))
				{
				k++;
				if(k>a.length()-1)
					break;
				count1[j]++;
				}
				while(s1.charAt(j)==b.charAt(l))
				{
				l++;
					if(l>b.length()-1)
						break;
				count2[j]++;
				}
				count+=(int)(Math.abs(count1[j]-count2[j]));
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