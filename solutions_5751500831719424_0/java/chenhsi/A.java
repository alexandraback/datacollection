import java.util.*;
import java.io.*;
import java.math.*;

public class A
{
	public static void main(String[] args) throws IOException
	{
		Scanner in = new Scanner(new BufferedReader(new FileReader("A-small-attempt0.in")));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("A-small.out")));
		
		int tt = in.nextInt();
		for (int I = 1; I <= tt; I++)
		{
			out.print("Case #" + I + ": ");
			int n = in.nextInt();
			List<String> list = new ArrayList<String> ();
			for (int i = 0; i < n; i++)
				list.add(in.next());
			boolean safe = true;
			int total = 0;
			outer: while (list.get(0).length() > 0)
			{
				char c = list.get(0).charAt(0);
				int count = 0;
				List<Integer> list2 = new ArrayList<Integer> ();
				int max = 0;
				for (int i = 0; i < n; i++)
				{
					String str = list.get(i);
					if (str.length() == 0 || str.charAt(0) != c)
					{
						safe = false;
						break outer;
					}
					int j = 1;
					while (str.length() > j && str.charAt(j) == c)
						j++;
					list.set(i, str.substring(j));
					list2.add(j);
					max = Math.max(j, max);
				}
				total += solve(list2, max);
			}
			for (int i = 1; i < n; i++)
				if (list.get(i).length() > 0)
				{
					safe = false;
					break;
				}
			if (!safe)
				out.println("Fegla Won");
			else
				out.println(total);
		}
		out.flush();
		out.close();
	}
	
	private static int solve(List<Integer> list, int max)
	{
		int best = Integer.MAX_VALUE;
		for (int i = 1; i <= max; i++)
		{
			int total = 0;
			for (int n : list)
				total += Math.abs(n - i);
			best = Math.min(best, total);
		}
		return best;
	}
}
