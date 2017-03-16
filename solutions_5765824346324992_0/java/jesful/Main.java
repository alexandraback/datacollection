import java.util.Scanner;

public class Main
{
	Scanner scan=new Scanner(System.in);
	int B;
	int N;
	int[] M;
	void input()
	{
		B=scan.nextInt();
		N=scan.nextInt();
		M=new int[B];
		for (int i=0;i<B;i++)
		{
			M[i]=scan.nextInt();
		}
	}
	long[] getVec(long time)
	{
		long[] res=new long[B];
		for (int i=0;i<B;i++)
		{
			res[i]=time/M[i]+1;
		}
		return res;
	}
	long[] check(long time)
	{
		long[] res=getVec(time);
		long sum = 0;
		for (int i=0;i<B;i++)
		{
			sum += res[i];
		}
		if (sum>=N)
			return res;
		else
			return null;
	}
	int solve()
	{
		long low = 0;
		long high = 100000000000000l;
		long[] time = null;
		long ans = 0;
		while (low<=high)
		{
			long mid = (low+high)/2;
			long[] vec = check(mid);
			if (vec!=null)
			{
				time = vec;
				high = mid - 1;
				ans = mid;
			}
			else
			{
				low = mid + 1;
			}
		}
		if (ans == 0)
		{
			return N;
		}
		else
		{
			long[] vec = getVec(ans-1);
			long sum = 0;
			for (int i=0;i<B;i++)
			{
				sum+=vec[i];
			}
			int diff = (int)(N-sum);
			for (int i=0;i<B;i++)
			{
				if ((time[i]-1)*M[i] == ans)
				{
					diff--;
					if (diff == 0)
						return i+1;
				}
			}
		}
		return N;
	}
	
	void run()
	{
		int T=scan.nextInt();
		for (int t=0;t<T;t++)
		{
			input();
			System.out.printf("Case #%d: %d\n", t+1,
					solve());
		}
	}
	public static void main(String[] args)
	{
		new Main().run();
	}
}
