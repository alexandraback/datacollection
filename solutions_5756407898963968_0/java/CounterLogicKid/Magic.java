package qualifying_round_2014;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Magic {

	public static void main(String[] args) throws IOException {
		BufferedReader f = new BufferedReader(new FileReader("Magic.in"));
		PrintWriter out = new PrintWriter(new FileWriter("C:/Users/David/Desktop/Magic.txt"));
		StringTokenizer t = new StringTokenizer(f.readLine());
		int testCases = Integer.parseInt(t.nextToken());
		String[] ans = new String[testCases];
		for (int i = 0; i < testCases; i++)
		{
			ArrayList<Integer> pos = new ArrayList<Integer>();
			t = new StringTokenizer(f.readLine());
			int r1 = Integer.parseInt(t.nextToken());
			for (int j = 0; j < 4; j++)
			{
				t = new StringTokenizer(f.readLine());
				if (j + 1 == r1)
				{
					for (int k = 0; k < 4; k++)
						pos.add(Integer.parseInt(t.nextToken()));
				}			
			}
			t = new StringTokenizer(f.readLine());
			int r2 = Integer.parseInt(t.nextToken());
			for (int j = 0; j < 4; j++)
			{
				t = new StringTokenizer(f.readLine());
				if (j + 1 == r2)
				{
					for (int k = 0; k < 4; k++)
						pos.add(Integer.parseInt(t.nextToken()));
				}			
			}
			for (Integer c: pos)
				System.out.println(c);
			int a = solve(pos);
			System.out.println();
			if (a > 0) ans[i] = "Case #" + (i+1) + ": " +  a;
			else if ( a == -1) ans[i] = "Case #" + (i+1) + ": " + "Bad magician!";
			else ans[i] = "Case #" + (i+1) + ": " + "Volunteer cheated!";
		}

		for (int i = 0; i < testCases; i++)
		{
			System.out.println(ans[i]);
			out.println(ans[i]);
		}
		
		out.close(); f.close(); System.exit(0);
	}

	/**
	 * 1-16 if works
	 * -1 if bad magician
	 * -2 if cheat
	 */
	public static int solve(ArrayList<Integer> num)
	{
		ArrayList<Integer> pos = new ArrayList<Integer>();
		for (int i = 0; i < 4; i++)
		{
			int k = num.get(i);
			for (int j = 4; j < 8; j++)
				if (k == num.get(j))
				{
					pos.add(k);
					break;
				}
		}
		if (pos.size() == 0)
			return -2;
		if (pos.size() == 1)
			return pos.get(0);
		return -1;
	}
}
