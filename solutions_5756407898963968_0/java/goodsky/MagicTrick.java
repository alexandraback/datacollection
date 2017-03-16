import java.util.*;
import java.io.*;

public class MagicTrick {
	public static void main(String[] args) throws Exception
	{
		String inputfile = "D:\\in1.txt";
		String outputfile = "D:\\out1.txt";
		
		Scanner in = new Scanner(new File(inputfile));
		
		FileWriter fstream = new FileWriter(outputfile);
		BufferedWriter out = new BufferedWriter(fstream);
		
		int N = in.nextInt();
		for (int n = 1; n <= N; ++n)
		{
			System.out.printf("iteration %d\n", n);
			
			// first round
			int r1 = in.nextInt();
			int[] possibleCards1 = new int[4];
			
			for (int i = 1; i <= 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					int c = in.nextInt();
					if (r1 == i) possibleCards1[j] = c;
				}
			}

			// second round
			int r2 = in.nextInt();
			int[] possibleCards2 = new int[4];
			
			for (int i = 1; i <= 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					int c = in.nextInt();
					if (r2 == i) possibleCards2[j] = c;
				}
			}

			// check for matches
			int numMatches = 0;
			int lastMatch = -1;
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					if (possibleCards1[i] == possibleCards2[j])
					{
						++numMatches;
						lastMatch = possibleCards1[i];
					}
				}
			}
			
			out.write(String.format("Case #%d: ", n));
			
			// results time!
			if (numMatches == 0)
			{
				out.write("Volunteer cheated!");
			}
			else if (numMatches == 1)
			{
				out.write("" + lastMatch);
			}
			else
			{
				out.write("Bad magician!");
			}
			
			out.newLine();
		}
		
		System.out.println("Done...");
		out.close();
	}
}
