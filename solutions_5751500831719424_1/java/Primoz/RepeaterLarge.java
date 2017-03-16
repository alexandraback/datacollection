package Round1b2014;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class RepeaterLarge 
{
	public static void main(String[] args) throws FileNotFoundException 
	{
		Scanner sc = new Scanner (new File ("A-large.in"));
		PrintWriter pw = new PrintWriter(new File("rep.out"));
		
		int t = sc.nextInt();
		
		for (int i = 0; i < t; i++)
		{
			int n = sc.nextInt();
			String [] inputs = new String [n];
			int [] lens = new int [n];
			
			int insertions = 0;
			
			for (int j = 0 ; j < n; j++)
				inputs[j] = sc.next();
			
			while (true)
			{
				
				int ends = 0;
				for (int k = 0; k < n; k++)
				{
					if (inputs[k].length() <= lens[k])
						ends ++;
				}
				
				//System.out.println("end" + ends);
				if (ends == n)
				{
					pw.printf("Case #%d: %d\n", i+1, insertions);
					break;
				}
				else if (ends > 0 )
				{
					
					pw.printf("Case #%d: %s\n", i+1, "Fegla Won");
					break;
				}		
				
								
				int [] sublen = new int [n];
				char c = inputs[0].charAt(lens[0]);
				
				//System.out.println(c);
				
				for (int k = 0; k < n; k++ )
				{
					for (lens[k] = lens[k] ; lens[k] < inputs[k].length(); lens[k]++)
					{
						if (inputs[k].charAt(lens[k]) == c)
						{
							sublen[k] ++;
							
						}
						else
						{							
							break;
						}
							
					}
				}				
				
				ends = 0;
				for (int k = 0; k < n; k++)
				{
					if (sublen[k] == 0)
						ends ++;
				}
				if (ends > 0)
				{
					pw.printf("Case #%d: %s\n", i+1, "Fegla Won");
					break;
				}
				
				int minchanges = Integer.MAX_VALUE;
				
				for (int k = 1 ; k <= 100; k++)
				{
					int changes = 0;
					for (int p = 0; p < n; p++)
					{
						
						changes += Math.abs(sublen[p] - k);
					}
					if (changes < minchanges )
						minchanges  = changes;
				}
				insertions += minchanges;
				
			}
			
		}
		
		pw.close();
		System.out.println("done");
	}
}
