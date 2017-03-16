import java.util.*;

class A_Repeater
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		int Cases = T;
		outer:while(T-->0)
		{
			int N = sc.nextInt();
			String[] str = new String[N];
			
			for(int i = 0; i < N; ++i)
				str[i] = sc.next();
			
			String testStr = Reduce(str[0]);
			
			for(int i = 1; i < N; ++i)
			{
				String cur = Reduce(str[i]);
				if(!testStr.equals(cur))
				{
					System.out.println("Case #"+(Cases-T)+": Fegla Won");
					continue outer;
				}
			}
			
			int[][][] charCost = new int[N][testStr.length()][101];
			
			for(int i = 0; i < N; ++i)
			{
				charCost[i] = countBySection(str[i],testStr.length());
			}
			
			int count = 0;
			
			for(int i = 0; i < testStr.length(); ++i)
			{
				int best = Integer.MAX_VALUE;
				for(int j = 0; j < 101; ++j)
				{
					int curSum = 0;
					for(int k = 0; k < N;++k)
					{
						curSum+=charCost[k][i][j];
					}
					best = Math.min(best,curSum);
				}
				count += best;
			}
			
			System.out.println("Case #"+(Cases-T)+": "+count);
		}
	}
	public static String Reduce(String str)
	{
		StringBuilder sb = new StringBuilder();
		for(int i = 0; i < str.length(); ++i)
		{
			while(i + 1 < str.length() && str.charAt(i) == str.charAt(i+1))
				++i;
			sb.append(str.charAt(i));
		}
		return sb.toString();
	}
	
	public static int[][] countBySection(String str, int N)
	{
		int[][] count = new int[N][101];
		int ptr = 0;
		for(int i = 0; i < str.length(); ++i)
		{
			int cc = 1;
			while(i + 1 < str.length() && str.charAt(i) == str.charAt(i+1))
			{
				++cc;
				++i;
			}
			count[ptr][0] = 1000; //large value
			for(int j = 1; j < 101; ++j)
			{
				count[ptr][j] = Math.abs(cc-j);
			}
			ptr++;
		}
		return count;
	}
}