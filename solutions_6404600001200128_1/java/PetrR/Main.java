
import java.io.BufferedReader;
import java.io.IOException;
import java.io.PrintStream;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.nio.file.Paths;

public class Main
{
	public static void main(String[] args) throws IOException
	{
		BufferedReader br = Files.newBufferedReader(Paths.get("A-large.in", args), Charset.defaultCharset());
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		System.setOut(new PrintStream(Files.newOutputStream(Paths.get("output.out"))));

		final int CASES = Integer.parseInt(br.readLine());
		String line;

		for (int cs = 0; cs < CASES; cs++)
		{
			line = br.readLine();
			//final int A = Integer.parseInt(line.substring(0, space));
			//final int B = Integer.parseInt(line.substring(space + 1));

			final int N = Integer.parseInt(line);
			int[] arr = new int[N];
			parseIntArray(br.readLine().toCharArray(), arr);
			
			

			printStatus(cs + 1, arr);
			//br.readLine();
		}
	}

	private static void printStatus(int dataCase, int[] arr)
	{
//		System.err.println(Arrays.toString(arr));
		int case1 = 0;
		int max = 0;
		for(int i = 1; i < arr.length; i++) {
			int diff = arr[i - 1] - arr[i];
			if(diff > 0)
				case1 += diff;
			if(diff > max)
				max = diff;
		}
//		System.err.println("max "+max);
		
		int case2 = 0;
		for(int i = 0; i < arr.length - 1; i++)
			if(arr[i] < max)
				case2 += arr[i];
		else
				case2 += max;
		
		String msg = Integer.toString(case1) + ' ' + Integer.toString(case2);
		printMessage(dataCase, msg);
	}

	public static void printMessage(int dataCase, String message)
	{
		System.out.println("Case #" + dataCase + ": " + message);
	}

	public static int parseIntArray(char[] line, int[] target)
	{
		// ignore the first character!!

		int j = 0;
		int accumulator = -1;
		boolean sign = true; // can be surely done without this
		for (char ch : line)
			if (ch == '-')
			{
				accumulator = 0;
				sign = false;
			}
			else if (ch < '0' || ch > '9')
			{
				if (accumulator != -1)
				{
					target[j] = sign ? accumulator : -accumulator;
					accumulator = -1;
					sign = true;
					j++;
				} // we found a new digit
			}
			else
				accumulator = accumulator == -1
					? (ch - '0')
					: accumulator * 10 + (ch - '0');
		if (accumulator != -1)
			target[j++] = sign ? accumulator : -accumulator;
		return j;
	}
}
