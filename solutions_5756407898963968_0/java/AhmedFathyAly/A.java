package Qualification2014;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashSet;

/**
 * Open an input file called "input.txt", output file "output.txt" The file
 * begins with n,the number of lines, followed by n lines each line of the n
 * lines has two numbers writes all the number separated be a space in the
 * output file
 * 
 */
public class A
{

	public static void main(String[] args) throws IOException
	{
		// For the Input file
		BufferedReader in = new BufferedReader(new FileReader("input.txt"));

		// For the output file
		BufferedWriter out = new BufferedWriter(new FileWriter("output.txt"));

		// Read the number from the input file and write them to the output file
		int nCases = Integer.parseInt(in.readLine());
		for (int i = 0; i < nCases; i++)
		{
			System.out.println((i+1));
			// First round
			int answer1 = Integer.parseInt(in.readLine());
			int[][] arrangment1 = new int[4][4];
			for (int j = 0; j < 4; j++)
			{
				int[] row = new int[4];
				String[] strs = in.readLine().split(" ");
				for (int k = 0; k < strs.length; k++)
					row[k] = Integer.parseInt(strs[k]);
				arrangment1[j] = row;
			}
			
			// Second round
			int answer2 = Integer.parseInt(in.readLine());
			int[][] arrangment2 = new int[4][4];
			for (int j = 0; j < 4; j++)
			{
				int[] row = new int[4];
				String[] strs = in.readLine().split(" ");
				for (int k = 0; k < strs.length; k++)
					row[k] = Integer.parseInt(strs[k]);
				arrangment2[j] = row;
			}
			
			out.write("Case #" + (i+1) + ": ");
			out.write(solve(arrangment1, arrangment2, answer1-1, answer2-1));
			out.write("\n");
		}
		out.flush();

		// Close the streams
		in.close();
		out.close();
	}

	private static String solve(int[][] arrangment1, int[][] arrangment2, int answer1, int answer2)
	{
		// Get the numbers in the first arrangment
		HashSet<Integer> firstNums = new HashSet<>();
		for (int i = 0; i < 4; i++)
			firstNums.add(arrangment1[answer1][i]);
		
		// Get the numbers in the second arrangment
		HashSet<Integer> secondNums = new HashSet<>();
		for (int i = 0; i < 4; i++)
			secondNums.add(arrangment2[answer2][i]);
		
		// Count similarities
		int ans = -1;
		int count = 0;
		for (Integer num : firstNums)
		{
			if (secondNums.contains(num))
			{
				count ++;
				ans = num;
			}
		}
		
		if (count == 0)
			return "Volunteer cheated!";
		else if (count > 1)
			return "Bad magician!";
		else
			return ans + "";
	}

}
