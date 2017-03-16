package Round1b2014;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;


public class Repeater 
{
	public static void main(String[] args) throws FileNotFoundException 
	{
		Scanner sc = new Scanner(new File ("A-small-attempt0.in"));
		PrintWriter w = new PrintWriter(new File ("bla"));
		int t = sc.nextInt();
		
		for (int n = 0; n < t; n++)
		{
			int d = sc.nextInt();
			String first = sc.next();
			String second = sc.next();
			
			int insertion = 0;
			int firsti = 0;
			int secondi = 0;
			
			while (true)
			{
				
				
				if (firsti >= first.length() && secondi >= second.length())
				{
					w.printf("Case #%d: %d\n", n+1, insertion);
					break;
				}
				else if (firsti >= first.length())
				{
					if (first.charAt(firsti - 1) == second.charAt(secondi))
					{
						secondi ++;
						insertion ++;
					}	
					else
					{
						w.printf("Case #%d: %s\n", n+1, "Fegla Won");
						break;
					}
				}
				else if (secondi >= second.length())
				{
					if (second.charAt(secondi - 1) == first.charAt(firsti))
					{
						firsti ++;
						insertion ++;
					}
					else
					{
						w.printf("Case #%d: %s\n", n+1, "Fegla Won");
						break;
					}
				}
				else if(first.charAt(firsti) == second.charAt(secondi))
				{
					firsti ++;
					secondi ++;
					
					continue;
				}
					
				else
				{
					if (secondi > 0 && second.charAt(secondi - 1) == first.charAt(firsti))
					{
						firsti ++;
						insertion ++;
					}
					else if (firsti > 0 && first.charAt(firsti - 1) == second.charAt(secondi))
					{
						secondi ++;
						insertion ++;
					}
					else
					{
						w.printf("Case #%d: %s\n", n+1, "Fegla Won");
						break;						
					}
						
				}
				
			}
			
		}
		w.close();
		System.out.println("done");
		
	}
}
