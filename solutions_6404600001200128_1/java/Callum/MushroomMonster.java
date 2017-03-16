import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class MushroomMonster
{

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new FileReader("A-large.in"));
		PrintWriter pw = new PrintWriter("A-large.out");
		
		int t = Integer.parseInt(br.readLine());
		
		for (int test = 0; test < t; test++)
		{
			int n = Integer.parseInt(br.readLine());
			int[] mushrooms = new int[n];
			
			StringTokenizer st = new StringTokenizer(br.readLine());
			for (int i = 0; i < n; i++)
			{
				mushrooms[i] = Integer.parseInt(st.nextToken());
			}
			
			int m1 = method1(mushrooms);
			int m2 = method2(mushrooms);
			
			pw.printf("Case #%d: %d %d%n", test + 1, m1, m2);
		}
		br.close();
		pw.close();
	}
	
	public static int method1(int[] mush)
	{
		int cur = 0;
		for (int i = 1; i < mush.length; i++)
		{
			cur += Math.max(0, mush[i - 1] - mush[i]);
		}
		return cur;
	}
	
	private static int method2(int[] mush)
	{
		int maxDiff = 0;
		for (int i = 1; i < mush.length; i++)
		{
			maxDiff = Math.max(maxDiff, mush[i - 1] - mush[i]);
		}
		int r = 0;
		for (int i = 0; i < mush.length - 1; i++)
		{
			r += Math.min(maxDiff, mush[i]);
		}
		return r;
	}
}