import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class A
{
	static String FILE_IN = "A-small-attempt0.in";
	static String FILE_OUT = "A.out";

	static String solve(BufferedReader in) throws IOException
	{
		int N = Integer.parseInt(in.readLine());
		PriorityQueue<Letter> pq = new PriorityQueue<Letter>();

		StringTokenizer st = new StringTokenizer(in.readLine());

		char maxChar = (char) ('A' + N);
		Double total = 0.0;

		for (char c = 'A'; c < maxChar; c++)
		{
			int n = Integer.parseInt(st.nextToken());
			total += n;
			pq.add(new Letter(n, c));
		}

		StringBuilder res = new StringBuilder();
		Letter max;
		while (!pq.isEmpty())
		{
			max = pq.remove();
			res.append(max.letter);
			max.freq--;
			total--;

			if (max.freq > 0)
				pq.add(max);

			if (!pq.isEmpty())
			{
				max = pq.remove();
				if (max.freq / total > 0.5)
				{
					res.append(max.letter);
					max.freq--;
					total--;
					
					if (max.freq > 0)
						pq.add(max);
				}
				else
					pq.add(max);
			}
			res.append(" ");
		}
		
		return res.deleteCharAt(res.length() - 1).toString();
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
			String result = solve(in);
			System.out.printf("Case #%d: %s%n", t, result);
			out.printf("Case #%d: %s%n", t, result);
		}

		System.out.println("Complete");
		in.close();
		out.close();
	}
}

class Letter implements Comparable<Letter>
{
	int freq;
	char letter;

	public Letter(int f, char l)
	{
		freq = f;
		letter = l;
	}

	public int compareTo(Letter o)
	{
		return o.freq - this.freq;
	}

	public String toString()
	{
		return String.format("%c: %d", letter, freq);
	}
}
