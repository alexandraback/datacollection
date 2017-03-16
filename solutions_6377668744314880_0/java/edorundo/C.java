import java.util.*;
import java.io.*;
public class C
{
	public static void main(String[] args) throws Exception
	{
//		Scanner in = new Scanner(System.in);
//		PrintWriter out = new PrintWriter(System.out);
		
		Scanner in = new Scanner(new File("C-small-attempt1.in"));
		PrintWriter out = new PrintWriter(new FileWriter(new File("C-small.out")));
		
		int t = in.nextInt();
		for(int x = 0; x < t; x++)
		{
			int n = in.nextInt();
			
			Point[] trees = new Point[n];
			for(int y = 0; y < n; y++)
			{
				trees[y] = new Point(in.nextInt(), in.nextInt());
			}
			
			out.println("Case #" + (x + 1) + ":");
			for(int z = 0; z < trees.length; z++)
			{
				ArrayList<Double> angles = new ArrayList<Double>();
				for(int a = 0; a < trees.length; a++)
				{
					if(a != z)
					{
						double current = Math.atan2(trees[a].y - trees[z].y, trees[a].x - trees[z].x);
						angles.add(current);
						angles.add(current + 2.0 * Math.PI);
					}
				}
				
				Collections.sort(angles);
				int index = 0;
				int result = n;
				for(int b = 0; b < angles.size(); b++)
				{
					while(index < angles.size() && angles.get(index) < angles.get(b) + Math.PI + 1E-12)
					{
						index++;
					}
					
					result = Math.min(result, n - (index - b) - 1);
				}
				
				if(n == 1)
				{
					out.println(0);
				}
				else
				{
					out.println(result);
				}
			}
		}
		
		out.close();
	}
	
	static class Point
	{
		int x;
		int y;
		
		public Point(int x, int y)
		{
			this.x = x;
			this.y = y;
		}
	}
}
