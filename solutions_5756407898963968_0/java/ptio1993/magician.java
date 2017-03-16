import java.util.*;
import java.io.*;

class Run
{
	public static void main(String[] args) throws Exception
	{
		String file = "A-small-attempt0.in";
		Scanner in = new Scanner(new File(file));
		//BufferedReader in = new BufferedReader(new FileReader(file));
		PrintWriter out = new PrintWriter(new FileWriter("output.txt"));
		int testcase = in.nextInt();
		for (int test = 1; test <= testcase; ++test)
		{
			int answer = in.nextInt();
			System.out.println(answer);
			int[] first_row = new int[4];
			for (int i = 0; i < 4; ++i)
			{
				if (i+1 == answer)
				{
					for (int j = 0; j < 4; ++j)
					{
						first_row[j] = in.nextInt();
					}
				}
				else
				{
					for (int j = 0; j < 4; ++j)
					{
						in.nextInt();
					}
				}
			}
			int nextAnswer = in.nextInt();
			int[] second_row = new int[4];
			for (int i = 0; i < 4; ++i)
			{
				if (i+1 == nextAnswer)
				{
					for (int j = 0; j < 4; ++j)
					{
						second_row[j] = in.nextInt();
					}
				}
				else
				{
					for (int j = 0; j < 4; ++j)
					{
						in.nextInt();
					}
				}
			}
			int[] result = check_array(first_row,second_row);
			if(result[0] == 0)
			{
				out.format("Case #%d: Volunteer cheated!\n", test);
			} else if(result[0] == 1)
			{
				out.format("Case #%d: %d\n", test, result[1]);
			} else
			{
				out.format("Case #%d: Bad Magician!\n", test);
			}
		}
		out.close();
		in.close();
	}

	public static int[] check_array(int[] array1, int[] array2)
	{
		int count = 0;
		int key = 0;
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				if (array1[i] == array2[j])
				{
					key = array1[i];
					++count;
				}
			}
		}
		int[] ans = {count,key};
		return ans;
	}
}