import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Scanner;

public class ProblemA
{
	Scanner in = null;
	Writer out = null;
	
	private void solve() throws IOException
	{
		int testCount = in.nextInt();
		in.nextLine();
		for (int test = 0; test < testCount; ++test)
		{
			int firstRow = in.nextInt();
			in.nextLine();
			int[] firstNums = new int[4];
			for (int i = 0; i < 4; ++i)
			{
				if (i + 1 == firstRow)
				{
					for (int j = 0; j < 4; ++j)
					{
						firstNums[j] = in.nextInt();
					}
				}
				in.nextLine();
			}
			
			int secondRow = in.nextInt();
			in.nextLine();
			int[] secondNums = new int[4];
			for (int i = 0; i < 4; ++i)
			{
				if (i + 1 == secondRow)
				{
					for (int j = 0; j < 4; ++j)
					{
						secondNums[j] = in.nextInt();
					}
				}
				in.nextLine();
			}
			
			ArrayList<Integer> sol = new ArrayList<Integer>();
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					if (firstNums[i] == secondNums[j])
					{
						sol.add(firstNums[i]);
					}
				}
			}
			
			out.write("Case #" + (test + 1) + ": ");
			if (sol.size() == 0)
			{
				out.writeln("Volunteer cheated!");
			}
			else if (sol.size() == 1)
			{
				out.writeln(sol.get(0));
			}
			else
			{
				out.writeln("Bad magician!");
			}
		}
	}
	
	public static void main(String[] args) throws IOException
	{
		new ProblemA();
	}

	private ProblemA() throws IOException
	{
		in = new Scanner(new FileInputStream("ProblemAIn.txt"));
		out = new Writer(new OutputStreamWriter(new FileOutputStream("ProblemAOut.txt"), "utf-8"));
		solve();
		if (in != null)
			in.close();
		if (out != null)
			out.close();
	}
	
	private class Writer extends BufferedWriter
	{
		public Writer(java.io.Writer out)
		{
			super(out);
		}
		
		public void writeln(String str) throws IOException
		{
			write(str);
			newLine();
		}
		
		public void writeln(Object str) throws IOException
		{
			writeln(str.toString());
		}
	}
}
