package therepeater;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Arrays;
import java.util.HashSet;

public class TheRepeater
{
	public static void main(String[] args) throws IOException
	{
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedReader br = Files.newBufferedReader(Paths.get("large.in", args), Charset.defaultCharset());
		System.setOut(new PrintStream(Files.newOutputStream(Paths.get("output.out"))));

		final int CASES = Integer.parseInt(br.readLine());
		String line;

		outer:
			for (int cs = 0; cs < CASES; cs++)
			{
//			line = br.readLine();

				final int N = Integer.parseInt(br.readLine());

				line = br.readLine();
				char[] chars = line.toCharArray();
				int[] prum = new int[chars.length];
				char[] projected = new char[chars.length];
				int length = 0;
				char lastChar = chars[0];
				for (char ch : chars)
				{
					if (ch == lastChar)
					{
						prum[length]++;
						continue;
					}

					length++;
					projected[length] = ch;
					prum[length] = 1;
					lastChar = ch;
				}
				length++;
				projected[0] = chars[0];
				
//				System.err.println(new String(projected));

				int[][] prums = new int[length][N];
				for (int i = 0; i < length; i++)
					prums[i][0] = prum[i];

				boolean exit = false;

				for (int i = 1; i < N; i++)
				{
					line = br.readLine();
					if (!exit)
					{
						int off = 0;
						for (char ch : line.toCharArray())
						{
							if (ch == projected[off])
								prums[off][i]++;
							else if (ch != projected[off] && prums[off][i] != 0)
							{
								off++;
								if(off >= length)
									exit = true;
								else if (ch != projected[off])
									exit = true;
								else
									prums[off][i]++;
							}
							else // != a == 0
								exit = true;
						}
						
						if(off != length - 1)
							exit = true;
					}
				}

				if (exit)
					printMessage(cs + 1, "Fegla Won");
				else
				{
					int count = 0;
					for(int i = 0; i < length; i++)
					{
						int median = selectKth(prums[i], N / 2);
//						System.err.println(Integer.toString(median));
//						System.err.println(Arrays.toString(prums[i]));
						for(int j = 0; j < N; j++)
							count += Math.abs(prums[i][j] - median);
					}
					printMessage(cs + 1, Integer.toString(count));
				}

			//final int space = line.indexOf(' ');
				//final int A = Integer.parseInt(line.substring(0, space));
				//final int B = Integer.parseInt(line.substring(space + 1));
				//printStatus(cs + 1);
				//br.readLine();
			}
	}

	private static void printStatus(int dataCase)
	{
		String msg = null;
		printMessage(dataCase, msg);
	}

	public static void printMessage(int dataCase, String message)
	{
		System.out.println("Case #" + dataCase + ": " + message);
	}

	public static int parseIntArray(char[] line, int[] target)
	{
		int j = 0;
		int accumulator = -1;
		for (char ch : line)
			if (ch == ' ')
			{
				if (accumulator != -1)
				{
					target[j] = accumulator;
					accumulator = -1;
					j++;
				} // we found a new digit
			}
			else
				accumulator = accumulator == -1
					? (ch - '0')
					: accumulator * 10 + (ch - '0');
		if (accumulator != -1)
			target[j++] = accumulator;
		return j;
	}

	public static int selectKth(int[] arr, int k)
	{
		if (arr == null || arr.length <= k)
			throw new Error("arr "+Arrays.toString(arr) +k);

		int from = 0, to = arr.length - 1;

		while (from < to)
		{
			int r = from, w = to;
			int mid = arr[(r + w) / 2];

			while (r < w)
			{

				if (arr[r] >= mid)
				{ 
					int tmp = arr[w];
					arr[w] = arr[r];
					arr[r] = tmp;
					w--;
				}
				else
				{ 
					r++;
				}
			}

			if (arr[r] > mid)
				r--;

			if (k <= r)
			{
				to = r;
			}
			else
			{
				from = r + 1;
			}
		}

		return arr[k];
	}
}
