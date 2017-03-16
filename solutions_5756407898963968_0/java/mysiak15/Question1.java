package round_1;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class Question1 
{
	public static void main(String args[])
	{
		readFile();
	}

	private static void readFile()
	{
		try 
		{
			BufferedReader br = new BufferedReader(new FileReader("C:\\Users\\Marek\\Desktop\\A-small-attempt0.in"));
			int count = Integer.parseInt(br.readLine());
			String [] as = new String[count];
			
			for (int i = 0; i < count; i++) 
			{
				int a1 = Integer.parseInt(br.readLine());
				int [] r1 = new int [4];
				for (int j = 0; j < 4; j++)
					if (a1 == j+1)
						r1 = split(br.readLine());
					else
						br.readLine();
				
				int a2 = Integer.parseInt(br.readLine());
				int [] r2 = new int [4];
				for (int j = 0; j < 4; j++)
					if (a2 == j+1)
						r2 = split(br.readLine());
					else
						br.readLine();
				
				as[i] = doMagic(r1, r2);
			}
			printToFile(as);
			
	    	br.close();
		}catch(IOException ioe){System.out.println("File not found!");}
	}
	
	private static String doMagic(int[] r1, int[] r2)
	{
		int count = 0;
		int n = -1;
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				if (r1[i] == r2[j])
				{
					count++;
					n = r1[i];
				}
		
		switch (count)
		{
			case 0: return "Volunteer cheated!";
			case 1: return ""+n;
			default: return "Bad magician!";
		}
	}
	
	private static int[] split(String s)
	{
		String [] a = s.split(" ");
		int[] r = new int [4];
		for (int i = 0; i < 4; i++)
			r[i] = Integer.parseInt(a[i]);
		return r;
	}
	
	private static void printToFile(String[] s)
	{
		try 
		{
			PrintWriter br = new PrintWriter(new FileWriter("C:\\Users\\Marek\\Desktop\\A-small-attempt0.out"));

			for (int i = 1; i <= s.length; i++)
				br.println("Case #"+i+": "+s[i-1]);
			
	    	br.close();
		}catch(IOException ioe){System.out.println("File not found!");}
	}
}

