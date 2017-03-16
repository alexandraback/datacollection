import java.util.*;
import java.io.*;

public class GoogleRepeater
{
	public static void main(String[] args) throws Exception
	{
		Scanner infile = new Scanner(new File("rpt.in"));
		PrintWriter w = new PrintWriter(new BufferedWriter(new FileWriter("rpt.out")));
		int iterations = infile.nextInt();
		for(int loop = 1; loop <= iterations; loop++)
		{
			int num = infile.nextInt();
			StringI[] words = new StringI[num];
			for(int a = 0; a < num; a++)
				words[a] = new StringI(infile.next());
			char[] testc = words[0].getChars();
			boolean doneyet = false;
			for(int a = 1; a < num; a++)
			{
				if(!Arrays.equals(testc, words[a].getChars()))
				{
					w.println("Case #" + loop + ": Fegla Won");
					doneyet = true;
					break;
				}
			}
			if(!doneyet)
				w.println("Case #" + loop + ": " + check(words));
		}
		w.close();
	}
	private static int check(StringI[] words)
	{
		int returned = 0;
		for(int a = 0; a < words[0].getLen(); a++)
			returned += optimize(words, a);
		return returned;
	}
	private static int optimize(StringI[] words, int a)
	{
		int min = findMin(words, a);
		int max = findMax(words, a);
		int returned = 0;
		for(int q = 0; q < words.length; q++)
			returned += Math.abs(min - words[q].getCount(a));
		for(int i = min+1; i < max; i++)
		{
			int t = 0;
			for(int q = 0; q < words.length; q++)
				t += Math.abs(i - words[q].getCount(a));
			if(t < returned)
				returned = t;
		}
		return returned;
	}
	private static int findMin(StringI[] words, int a)
	{
		int min = words[0].getCount(a);
		for(int i = 1; i < words.length; i++)
		{
			if(words[i].getCount(a) < min)
				min = words[i].getCount(a);
		}
		return min;
	}
	private static int findMax(StringI[] words, int a)
	{
		int max = words[0].getCount(a);
		for(int i = 1; i < words.length; i++)
		{
			if(words[i].getCount(a) > max)
				max = words[i].getCount(a);
		}
		return max;
	}
}
class StringI
{
	private char[] chars;
	private int[] counts;
	public StringI(String a)
	{
		int size = countSt(a);
		chars = new char[size];
		counts = new int[size];
		fill(a);
	}
	private static int countSt(String a)
	{
		int temp = 1;
		char tempc = a.charAt(0);
		for(int i = 1; i < a.length(); i++)
		{
			if(a.charAt(i)!=(tempc))
			{
				temp++;
				tempc = a.charAt(i);
			}
		}
		return temp;
	}
	private void fill(String a)
	{
		char tempc = a.charAt(0);
		int count = 1;
		int ind = 0;
		for(int i = 1; i < a.length(); i++)
		{
			if(a.charAt(i) == tempc)
				count++;
			else
			{
				chars[ind] = tempc;
				counts[ind] = count;
				tempc = a.charAt(i);
				count = 1;
				ind++;
			}
		}
		chars[chars.length - 1] = tempc;
		counts[counts.length - 1] = count;
	}
	public char[] getChars()
	{
		return chars;
	}
	public char getChar(int a)
	{
		return chars[a];
	}
	public int getCount(int a)
	{
		return counts[a];
	}
	public int getLen()
	{
		return chars.length;
	}
}