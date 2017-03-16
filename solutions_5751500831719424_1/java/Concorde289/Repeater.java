package round1B_2014;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;

public class Repeater {

	public static void main (String [] args) throws IOException{

		//Timing
		//long s = System.currentTimeMillis ();

		//Set up the reader and printer
		BufferedReader in = new BufferedReader (new FileReader ("IN.txt"));
		PrintWriter out = new PrintWriter (new BufferedWriter (new FileWriter ("OUT.txt")));
		int noCases = Integer.parseInt(in.readLine());

		//Solve the cases
		for (int caseNo = 1; caseNo <= noCases; caseNo++){
			int noStrings = Integer.parseInt(in.readLine());
			String [] initStrings = new String [noStrings];
			for (int i = 0; i < noStrings; i++)
				initStrings[i] = in.readLine();

			Letter [] [] strings = new Letter [noStrings] [];
			for (int i = 0; i < noStrings; i++)
				strings [i] = toLetterArray(initStrings[i]);		

			int n = getMinMoves(strings);
			String answer = String.valueOf(n);
			if (n == -1)
				answer = "Fegla Won";
			out.println(String.format("Case #%d: %s", caseNo, answer));
			out.flush();//So I can see how my program is doing
		}

		//Close the files
		in.close();
		out.close();

		//Timing
		//long e = System.currentTimeMillis();
		//System.out.println((e - s) / 1000.0);

		//Terminate the program
		System.exit(0);

	} //Main method

	static Letter [] toLetterArray(String str)
	{
		ArrayList<Letter> arr = new ArrayList<Letter>();
		arr.add(new Letter(str.charAt(0)));
		int pos = 0;
		for (int i = 1; i < str.length(); i++)
		{
			if (str.charAt(i) == arr.get(pos).c)
				arr.get(pos).n++;
			else
			{
				arr.add(new Letter(str.charAt(i)));
				pos++;
			}
		}
		Letter [] a = new Letter [arr.size()];
		arr.toArray(a);
		return a;
	}

	static int getMinMoves(Letter [] [] grid)
	{

		//Ensure that are all same length
		for (int i = 0; i < grid.length; i++)
		{
			if (grid[i].length != grid[0].length)
				return -1;
		}

		//Ensure that all have same letters
		for (int letterNo = 0; letterNo < grid[0].length; letterNo++)
			for (int stringNo = 1; stringNo < grid.length; stringNo++)
			{
				if (grid[stringNo][letterNo].c != grid[0][letterNo].c)
					return -1;
			}

		//Find the minimum number of moves for each letter
		int minMoves = 0;
		for (int letterNo = 0; letterNo < grid[0].length; letterNo++)
		{
			int min = Integer.MAX_VALUE;
			for (int n = 1; n <= 100; n++)
			{
				int number = 0;
				for (int stringNo = 0; stringNo < grid.length; stringNo++)
					number += Math.abs(n - grid[stringNo][letterNo].n);
				min = Math.min(number, min);
			}
			minMoves += min;
		}
		return minMoves;
	}

	static int getNoMoves(Letter [] s, Letter [] target)
	{
		int count = 0;
		if (s.length != target.length)
			return -1;
		for (int i = 0; i < s.length; i++)
		{
			if (s[i].c != target[i].c)
				return -1;
			count += Math.abs(s[i].n-target[i].n);
		}
		return count;
	}

	static class Letter
	{
		char c;
		int n;
		public Letter (char ch)
		{
			c = ch;
			n = 1;
		}

		public String toString()
		{
			return "" + String.valueOf(n) + c;
		}
	}
}
