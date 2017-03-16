import java.util.Scanner;


public class Barber 
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		long t = sc.nextLong();
		for (long i=0;i<t;++i)
		{
			long b = sc.nextLong();
			long n = sc.nextLong();
			long[] m =new long[(int) b];
			for (long j=0;j<b;++j)
			{
				m[(int) j] = sc.nextLong();
			}
			long lcm = m[0];
			for (int j=1;j<b;++j)
			{
				lcm = lcm(lcm, m[j]);
			}
			long done = 0;
			for (int j=0;j<b;++j)
			{
				done += lcm/m[j];
			}
			long remainder = n%done;
			if (remainder==0)
				remainder = done;
			long ans = findAns(remainder, m);
			System.out.println("Case #"+(i+1)+": "+ans);
		}
	}
	
	public static long findAns(long r, long[] m)
	{
		long ans = -1;
		
		long time = 1;
		long c = 0 + m.length;
		
		if (r<=m.length)
			return r;
		
		while (true)
		{
			for (int i=0;i<m.length;++i)
			{
				if (time%m[i] == 0)
				{
					++c;
					if (c==r)
					{
						ans = i;
						break;
					}
				}
			}
			++time;
			if (ans >=0)
				break;
		}
		++ans;
		return ans;
	}
	
	private static long gcd(long a, long b)
	{
	    while (b > 0)
	    {
	        long temp = b;
	        b = a % b; // % is remainder
	        a = temp;
	    }
	    return a;
	}
	
	private static long lcm(long a, long b)
	{
	    return a * (b / gcd(a, b));
	}
}
