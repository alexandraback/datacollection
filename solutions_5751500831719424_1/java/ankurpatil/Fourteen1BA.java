import java.util.*;

public class Fourteen1BA {
	public static final String failure ="Fegla Won"; 
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for(int t = 1; t<=T;t++)
		{
			int N = sc.nextInt();
			String[] s = new String[N];
			for(int i =0;i<N;i++)
				s[i] = sc.next();
			System.out.print("Case #"+t+": ");
			int[][] count = new int[100][N];
			String[] masterString = new String[N];
			for(int i =0;i<N;i++)
			{
				char c = s[i].charAt(0);
				int idx = 0;
				masterString[i] = ""+c;
				count[idx][i]++;
				for(int j = 1 ;j<s[i].length();j++)
				{
					if(s[i].charAt(j)==c)
					{
						count[idx][i]++;
					}
					else
					{
						c = s[i].charAt(j);
						masterString[i] = masterString[i]+c;
						idx++;
						count[idx][i]++;
					}
				}
			}
			if(!checkFailed(masterString)) continue;
			
			int c = 0;
			for(int i = 0; i<100;i++)
			{
				if(count[i][0]==0) break;
				c = c + solve(count[i]);
			}
			System.out.println(c);
		}
	}
	public static boolean checkFailed(String[] masterString)
	{
		String ms = masterString[0];
		for(int i =1; i< masterString.length;i++)
		{
			if(!ms.equals(masterString[i]))
			{
				System.out.println(failure);
				return false;
			}
		}
		return true;
	}
	
	public static int solve(int[] count)
	{
		if(count[0]==0) return 0;
		Arrays.sort(count);
		int min = Integer.MAX_VALUE;
		for(int i = 0;i<count.length;i++)
		{
			int c = count[i];
			int sum = 0;
			for(int j = 0;j<count.length;j++)
			{
				sum = sum + Math.abs(count[j] - c);
			}
			min = Math.min(min, sum);
		}
		return min;
	}
}
