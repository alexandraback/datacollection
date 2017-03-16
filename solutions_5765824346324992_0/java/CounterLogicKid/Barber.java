package round_1A_2015;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Barber {
	public static void main(String[] args) throws IOException {
		BufferedReader f = new BufferedReader(new FileReader("barber.in"));
		PrintWriter out = new PrintWriter(new FileWriter("C:/Users/David/Desktop/barber.txt"));
		StringTokenizer t = new StringTokenizer(f.readLine());
		int testCases = Integer.parseInt(t.nextToken());
		for (int i = 1; i <= testCases; i++)
		{
			t = new StringTokenizer(f.readLine());
			int B = Integer.parseInt(t.nextToken());
			int N = Integer.parseInt(t.nextToken());
			
			int[] barb = new int[B];
			t = new StringTokenizer(f.readLine());
			for (int j = 0; j < B; j++)
				barb[j] = Integer.parseInt(t.nextToken());
			
			int num = 0;
			if (N <= B) num = N;
			else
			{
				double temporary = 0;
				for (int m: barb) temporary += 1.0/m;
				long time = (long) Math.floor(N/temporary);
				
				long doneByTime = 0;
				for (int m: barb) doneByTime += time/m;			

				while (doneByTime + 1 < N)
				{
					long minTimeToAdd = Integer.MAX_VALUE;
					for (int j = 0; j < B; j++)
					{
						long temp = barb[j] - time%barb[j];
						if (temp < minTimeToAdd)
							minTimeToAdd = temp;
					}
					
					time += minTimeToAdd;
					doneByTime = 0;
					for (int m: barb) doneByTime += time/m;
				}
				
				
				
				if (doneByTime == N)
				{
					long min = Integer.MAX_VALUE;
					for (int j = 0; j < B; j++)
						if (time%barb[j] < min) min = time%barb[j];
					time -= min;
					
					
					for (int j = B - 1; j >= 0; j--)
						if (time%barb[j] == 0)
						{
							num = j + 1;
							break;
						}
				}			
				else if (doneByTime + 1 == N)
				{
					long min = Integer.MAX_VALUE;
					for (int j = 0; j < B; j++)
						if (time%barb[j] < min) min = time%barb[j];
					time -= min;
					
					
					for (int j = 0; j < B; j++)
						if (time%barb[j] == 0)
						{
							num = j + 1;
							break;
						}
				}
				else //if (doneByTime > N)
				{
					long min = Integer.MAX_VALUE;
					for (int j = 0; j < B; j++)
						if (time%barb[j] < min) min = time%barb[j];
					time -= min;
					
					int count = (int) (doneByTime - N);
					for (int j = 0; j < B; j++)
						if (time%barb[j] == 0)
						{
							if (count == 0)
							{
								num = j + 1;
								break;
							}
							count--;
						}
				}
				
				System.out.println("T:" + time);
				System.out.println("Done: " + doneByTime);
				
				/*
				double lowest = Double.MAX_VALUE;
				for (int m: barb)
				{
					double temp = time - Math.ceil(time/m)*m;
					if (temp < lowest) temp = lowest;
				}
				*/
			}
			
			String ans = "Case #" + i + ": " + num;
			out.println(ans);
		}

		out.close(); f.close(); System.exit(0);
	}

}
