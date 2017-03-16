import java.util.Arrays;
import java.util.Scanner;


public class A {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		int T = in.nextInt();
		mainLoop: for (int caseNo = 1; caseNo <= T; caseNo++)
		{
			int N = in.nextInt();
			String[] strs = new String[N];
			strs[0] = in.next();
			String master = reduce(strs[0]);
			int masterLen = master.length();
			int[][] counts = new int[N][masterLen];
			counts[0] = count(strs[0], master);
			boolean fail = false;
			
			for (int i = 1; i < N; i++)
			{
				strs[i] = in.next();
				int[] temp = count(strs[i], master);
				if (temp == null)
				{
					fail = true;
				}
				else
				{
					counts[i] = temp;
				}
			}
			
			if (fail)
			{
				System.out.println("Case #" + caseNo + ": Fegla Won");
				continue mainLoop;
			}
			
			int numMoves = 0;
			for (int i = 0; i < masterLen; i++)
			{
				int[] vals = new int[N];
				for (int j = 0; j < N; j++)
				{
					vals[j] = counts[j][i];
				}
				Arrays.sort(vals);
				
				int median = vals[N/2];
				for (int j = 0; j < N; j++)
				{
					numMoves += Math.abs(vals[j] - median);
				}
			}
			
			System.out.println("Case #" + caseNo + ": " + numMoves);
		}
	}
	
	private static int[] count(String s, String m)
	{
		int[] counts = new int[m.length()];
		
		int mi = 0;
		char c = m.charAt(mi);
		for (int i = 0; i < s.length(); i++)
		{
			if (s.charAt(i) != c)	//move to next master char
			{
				if (counts[mi] == 0 || mi == m.length()-1)	//prev master char did not occur, error
				{
					return null;
				}
				
				mi++;
				c = m.charAt(mi);
			}
			
			if (s.charAt(i) == c)
			{
				counts[mi]++;
			}
			else
			{
				return null;	//next master char did not occur, error
			}
		}
		
		if (mi < m.length()-1)
		{
			return null;
		}
		
		return counts;
	}
	
	private static String reduce(String s)
	{
		char lastChar = s.charAt(0);
		String m = "" + lastChar; 
		
		for (int i = 1; i < s.length(); i++)
		{
			if (s.charAt(i) != lastChar)
			{
				lastChar = s.charAt(i);
				m += lastChar;
			}
		}
		
		return m;
	}

}
