package A;

import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.Vector;

public class Solve 
{
	private static Scanner s;
	
	public static void main(String[] args) throws Exception
	{
		s=new Scanner(new File("input.in"));
		PrintWriter w = new PrintWriter( new FileWriter( new File("output.out")));
		
		int n_case = s.nextInt();
		
		for(int i=0;i<n_case;i++)
		{
			int n = s.nextInt();
			s.nextLine();
			String[] v = new String[n];
			Vector<Vector<Pair>> contRip = new Vector<Vector<Pair>>(n);
			boolean poss = true;
			for(int j =0 ;j<n;j++)
			{
				v[j]=s.nextLine();
			}
			
			String minEquals="";
			for(int k =0;k<n;k++)
			{
				String no_rip = ""+v[k].charAt(0);
				char aus = v[k].charAt(0);
				contRip.add( new Vector<Pair>());
				contRip.get(k).add(new Pair(aus, 0));
				for(int j =0; j<v[k].length();j++)
				{
					if(aus!=v[k].charAt(j))
					{
						aus=v[k].charAt(j);
						no_rip+=aus;
						contRip.get(k).add(new Pair(aus, 1));
					}
					else
					{
						contRip.get(k).lastElement().rip++;
					}
				}
				if(minEquals.isEmpty())
				{
					minEquals = no_rip;
				}
				else
				{
					if(minEquals.compareTo(no_rip)!=0)
					{
						poss = false;
						break;
					}
					else
					{
						minEquals = no_rip;
					}
				}
			}
			if(poss)
			{
				int result =0;
				for(int j =0;j<minEquals.length();j++)
				{
					int min_ris = Integer.MAX_VALUE;
					for(int k =0;k<n;k++)
					{
						int ris=0;
						for(int h=0;h<n;h++)
						{
							ris+=Math.abs(contRip.get(k).get(j).rip - contRip.get(h).get(j).rip);
						}
						if(ris<min_ris)
						{
							min_ris=ris;
						}
					}
					result+=min_ris;
				}
				w.println("Case #"+(i+1)+": "+result);
			}
			else
			{
				w.println("Case #"+(i+1)+": Fegla Won");
			}
		}
		w.close();
	}
	
}

class Pair
{
	public char lettera;
	public int rip;
	
	public Pair(char c, int n)
	{
		lettera = c;
		rip= n;
	}
}
