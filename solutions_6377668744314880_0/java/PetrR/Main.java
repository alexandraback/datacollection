
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
		BufferedReader br = Files.newBufferedReader(Paths.get("C-small-attempt0.in", args), Charset.defaultCharset());
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		System.setOut(new PrintStream(Files.newOutputStream(Paths.get("output.out"))));

		final int CASES = Integer.parseInt(br.readLine());
		String line;

		for (int cs = 0; cs < CASES; cs++)
		{
			line = br.readLine();
			//final int space = line.indexOf(' ');
			//final int A = Integer.parseInt(line.substring(0, space));
			//final int B = Integer.parseInt(line.substring(space + 1));

			final int N = Integer.parseInt(line);

			int[][] point = new int[N][2];
			for (int i = 0; i < N; i++)
			{
				line = br.readLine();
				final int space = line.indexOf(' ');
				point[i][0] = Integer.parseInt(line.substring(0, space));
				point[i][1] = Integer.parseInt(line.substring(space + 1));
			}

			printStatus(cs + 1, point);
			//br.readLine();
		}
	}

	private static void printStatus(int dataCase, int[][] points)
	{
		printMessage(dataCase, "");
		if(points.length > 1)
			for (int i = 0; i < points.length; i++)
				System.out.println(Integer.toString(count(points, i)));
		else
			System.out.println("0");
	}
	private static final int X = 0;
	private static final int Y = 1;

	private static int count(int[][] points, int pivot)
	{
		int min = Integer.MAX_VALUE;

		for (int i = 0; i < points.length; i++)
		{
			if (i != pivot)
			{
				int less = 0;
				int more = 0;

				long deltaY = points[i][Y] - points[pivot][Y];
				long deltaX = points[i][X] - points[pivot][X];
				long deltaXY1 = deltaX * points[pivot][Y];
				long deltaYX1 = deltaY * points[pivot][X];
				long sum = deltaXY1 - deltaYX1;

				for (int j = 0; j < points.length; j++)
				{
					long val = sum + deltaY * points[j][X] - deltaX * points[j][Y];

					if (val < 0)
						less++;
					else if (val > 0)
						more++;
				}

//				System.err.println("less " + less + " more " + more);
				min = Math.min(Math.min(less, more), min);
			}
		}

		return min;
	}

	public static void printMessage(int dataCase, String message)
	{
		System.out.println("Case #" + dataCase + ":" + message);
	}
}
