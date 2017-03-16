import java.io.*;
import java.util.Arrays;
import java.util.Scanner;

public class A
{
	static boolean badCase;
	public static String letters(String first)
	{
		String letters = "";
		char prev = first.charAt(0);
		letters += prev;
		for (int i = 1; i < first.length(); i++)
			if (first.charAt(i)!= prev)
			{
				prev =  first.charAt(i);
				letters += prev;
			}
		return letters;
	}
	
	public static int [] getCounts (String letters, String next)
	{
		int [] counts = new int [letters.length()];
		int index = 0;
		for (int i = 0; i < letters.length(); i++)
		{
			while (index < next.length() && next.charAt(index)==letters.charAt(i))
			{
				counts[i]++;
				index++;
			}
			if (counts[i]== 0)
				badCase = true;
		}
			
		if (index < next.length())
			badCase = true;
		
		return counts;
	}
	
	/**
	 * @param args
	 * @throws IOException
	 */
	public static void main(String[] args) throws IOException
	{
		String fileName = "A-small0";
		Scanner in = new Scanner(new File(fileName + ".in"));
		PrintWriter out = new PrintWriter(new FileWriter(fileName + ".out"));

		int noOfCases = in.nextInt();
		for (int caseNo = 1; caseNo <= noOfCases; caseNo++)
		{
			int N = in.nextInt();
			String first = in.next();
			
			badCase = false;
			String letters = letters(first);
			int [] [] counts = new int [N][];
			counts[0] = getCounts (letters, first);
			for (int i = 1; i < N;i++)
			{
				counts[i] = getCounts(letters, in.next());
			}
			
//			for (int row = 0; row < counts.length; row++)
//			{
//				for (int col = 0; col < counts[row].length; col++)
//					System.out.printf("%3d", counts[row][col]);
//				System.out.println();
//					
//			}
				
			
			
			if (!badCase)
			{
				int noOfMoves = 0;
				
				for (int col = 0; col < counts[0].length; col++)
				{
					// Find range of values
					int low = 1000;
					int high = -1;
					for (int row = 0; row < counts.length; row++)
					{
						low = Math.min(low, counts[row][col]);
						high = Math.max(high, counts[row][col]);
				     }
					
					int bestMoves = 10000;
					for (int target = low; target<= high; target++)
					{
						int moves = 0;
						for (int row = 0; row < counts.length; row++)
						{
							moves += Math.abs(counts[row][col]-target);
					     }
						if (moves < bestMoves)
							bestMoves = moves;
					}
				//	System.out.println(col + " " +bestMoves);
					noOfMoves += bestMoves;
					
				
				}
				System.out.printf("Case #%d: %d%n", caseNo, noOfMoves);
				out.printf("Case #%d: %d%n", caseNo, noOfMoves);
			}
			else
			{
				System.out.printf("Case #%d: Fegla Won%n", caseNo);
				out.printf("Case #%d: Fegla Won%n", caseNo);
			}

		}
		in.close();
		out.close();

	}

}
