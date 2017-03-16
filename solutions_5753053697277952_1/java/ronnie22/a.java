import java.io.*;
import java.util.*;


public class a 
{

	public static void main(String[] args) throws FileNotFoundException 
	{
		Scanner sc = new Scanner(new File("input.txt"));
		PrintWriter out = new PrintWriter("output.txt");
		
		int n_case = sc.nextInt();
		for(int i=1;i<=n_case;i++)
		{
			int n = sc.nextInt();
			int sen[] = new int[n];
			int tot  = 0;
			for(int j=0;j<n;j++)
			{
				sen[j] = sc.nextInt();
				tot+=sen[j];
			}
			String ris = solve(n,sen,tot);
			out.println("Case #"+i+": "+ris);
		}
		
		sc.close();
		out.close();
	}
	
	public static String solve(int n, int sen[],int tot)
	{
		String ris = new String();

		int max1 = -1;
		int pos1 = -1;
		int max2 = -1;
		int pos2 = -1;
		
		while(tot > 3)
		{
			max1 = -1;
			pos1 = -1;
			max2 = -1;
			pos2 = -1;
			for(int i=0;i<n;i++)
			{
				if(sen[i]>max1)
				{
					max2=max1;
					pos2=pos1;
					max1=sen[i];
					pos1=i;
				}
				else
				{
					if(sen[i]>max2)
					{
						max2=sen[i];
						pos2=i;
					}
				}
			}
			
			if(pos1!=-1)
			{
				ris+= Character.toChars(('A'+pos1))[0];
				sen[pos1]--;
				tot--;
			}
			
			if(pos2!=-1)
			{
				ris+=Character.toChars(('A'+pos2))[0];
				sen[pos2]--;
				tot--;
			}
			
			ris+=" ";
		}
		
		String last = "";
		for(int i=0;i<n;i++)
		{
			if(sen[i]!=0 && last.length()<2)
			{
				last+=Character.toChars(('A'+i))[0];
			}
			else
			{	if(last.length()==2)
				{
					ris+=Character.toChars(('A'+i))[0]+" ";
				}
			}
		}
		
		return ris + last;
	}

}
