import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class B
{
	static String FILE_IN = "B-large.in";
	static String FILE_OUT = "B.out";

	static String solve(BufferedReader in, PrintWriter out) throws IOException
	{
		StringTokenizer st = new StringTokenizer(in.readLine());

		int rows = Integer.parseInt(st.nextToken());
		int cols = Integer.parseInt(st.nextToken());
		int n = Integer.parseInt(st.nextToken());

		int mathMin = Math.min(rows, cols);

		int area = rows * cols;
		int perim = 2 * rows + 2 * (cols - 2);
		if (mathMin == 1)
			perim = Math.max(rows, cols);

		int free, corners, edges, centres;

		if (area % 2 == 0)
		{
			free = area / 2;
			if (mathMin > 1)
			{
				corners = 2;
				edges = (perim - 4) / 2;
				centres = area - free - corners - edges;
			}
			else
			{
				corners = 1;
				edges = area - free - corners;
				centres = 0;
			}

			return String.format("%d",
					count(mathMin, n, free, corners, edges, centres));
		}

		free = area / 2;
		if (Math.min(rows, cols) > 1)
		{
			corners = 4;
			edges = perim - 2 * (rows / 2) - 2 * (cols / 2) - corners;
			centres = area - free - corners - edges;
		}
		else
		{
			corners = 2;
			edges = area - free - corners;
			centres = 0;
		}
		int method1 = count(mathMin, n, free, corners, edges, centres);

		free = area / 2 + 1;

		corners = 0;
		if (Math.min(rows, cols) > 1)
		{
			edges = perim - 4 - 2 * ((rows - 2) / 2) - 2 * ((cols - 2) / 2);
			centres = area - free - corners - edges;
		}
		else
		{
			edges = area - free;
			centres = 0;
		}
		int method2 = count(mathMin, n, free, corners, edges, centres);

		int min = Math.min(method1, method2);
		return String.format("%d", min);
	}

	static int count(int min, int n, int free, int corners, int edges,
			int centres)
	{
		int corner = 2;
		int edge = 3;
		int centre = 4;
		
		if(min == 1)
		{
			corner = 1;
			edge = 2;
		}
		
		int unhappy = 0;
		n -= free;

		while (n > 0 && corners > 0)
		{
			unhappy += corner;
			n--;
			corners--;
		}
		while (n > 0 && edges > 0)
		{
			unhappy += edge;
			n--;
			edges--;
		}
		while (n > 0 && centres > 0)
		{
			unhappy += centre;
			n--;
			centres--;
		}
		return unhappy;
	}

	public static void main(String[] args) throws IOException
	{
		BufferedReader in = new BufferedReader
				(new FileReader("files/" + FILE_IN));
		PrintWriter out = new PrintWriter(new BufferedWriter
				(new FileWriter("files/" + FILE_OUT)));

		int T = Integer.parseInt(in.readLine());
		for (int t = 1; t <= T; t++)
		{
			String result = solve(in, out);
			System.out.printf("Case #%d: %s%n", t, result);
			out.printf("Case #%d: %s%n", t, result);
		}

		System.out.println("Complete");
		in.close();
		out.close();
	}
}
