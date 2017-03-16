import java.io.*;
import java.util.*;
public class Repeater
{
	public static void main (String args[]) throws IOException
	{
		BufferedReader br = new BufferedReader (new FileReader ("A-small.txt"));
		PrintWriter out = new PrintWriter (new FileWriter ("Aoutput.txt"));
		
		
		int trials = Integer.parseInt (br.readLine ());
					
		int [][] charCount = new int[101][101];
		char []chars = new char[101];	//Word, charachter
		int [] maxes = new int [101];
		int [] mins = new int [101];
		
		for (int t=1;t<=trials;t++)
		{
			//System.out.println ("Starting Trial " + t);
			int n = Integer.parseInt (br.readLine ());
			//System.out.println ("N = " + n);
			int numDifChars = 0;
			boolean impossible = false;

			//First word:
				String word = br.readLine ();
				chars[0] = word.charAt(0);
				charCount[0][0] = 1;
				
				for (int i=1;i<word.length();i++)
				{
					if (word.charAt(i)==word.charAt(i-1))
					{
						charCount[0][numDifChars]++;
					}
					else
					{
						/*maxes[numDifChars] = charCount[0][numDifChars];
						mins[numDifChars] = charCount[0][numDifChars];*/
						numDifChars++;
						chars[numDifChars] = word.charAt(i);
						charCount[0][numDifChars]=1;
					}
				}
				
				numDifChars++;
				
			//Rest of the words:
			for (int i=1;i<n;i++)
			{
			
				word=br.readLine();
				if (impossible)
					continue;
				
				int curChar = 0;
				charCount[i][0] = 0;
				for (int j=0;j<word.length();j++)
				{
					if (word.charAt(j)==chars[curChar])
					{
						charCount[i][curChar]++;
					}
					else if (charCount[i][curChar]==0)	//Skipped a letter
					{
						impossible = true;
					}
					else
					{/*
						if (charCount[i][curChar]<mins[curChar])
							mins[curChar] = charCount[i][curChar];
						if (charCount[i][curChar]>maxes[curChar])
							maxes[curChar] = charCount[i][curChar];
						*/	
						curChar++;
						if (word.charAt(j)==chars[curChar])
						{
							charCount[i][curChar] = 1;
						}
						else
						{
							impossible = true;
						}
					}
				}
				if (curChar!=numDifChars -1)
				{
					impossible = true;
				}			
				
			}
			
			
			if (impossible)
			{
				out.println ("Case #" + t+ ": Fegla Won");
			}
			else
			{
			/*
				for (int i=0;i<n;i++)
				{
					System.out.print (i + ": ");
					for (int j=0;j<numDifChars;j++)
					{
						System.out.print (charCount[i][j] + " ");
					}
					System.out.println ();
				}
				*/
				
				//For each char, find the optimal number of repititions.
				int total = 0;
				for (int curChar=0;curChar<numDifChars;curChar++)
				{
					int thisChar = 200000000;
					for (int repititions = 1;repititions<=101;repititions++)
					{
						int cur = 0;
						for (int i=0;i<n;i++)
						{
							if (charCount[i][curChar] < repititions)
								cur+=repititions-charCount[i][curChar];
							else
								cur+= charCount[i][curChar]-repititions;
						}
						
						if (cur<thisChar)
							thisChar = cur;
					}
					total += thisChar;
				}
				
				out.println ("Case #" + t + ": " + total);
			}
			
			
		}
		
		out.close();
	}
}