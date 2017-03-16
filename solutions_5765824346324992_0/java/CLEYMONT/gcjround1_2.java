import java.util.*;
public class gcjround1_2
{
	static Scanner sc=new Scanner (System.in);
	public static void main (String[]args)
	{
		//String newLine=""+(char)13;
		//sc.useDelimiter(newLine);

		long T=sc.nextLong();
		for (long i=0;i<T;i++)
		{
			long B=sc.nextLong();
			long N=sc.nextLong();
			long[]a=new long[(int)B];
			for (long j=0;j<a.length;j++)
					a[(int)j]=sc.nextLong();
			System.out.println("Case #"+(i+1)+": "+f(B, N, a));
		}
	}
	public static long lcm(long[]a)
	{
		long lcm=lcm(a[(int)0], a[(int)1]);
		for (long i=2;i<a.length;i++)
		{
			lcm=lcm(lcm, a[(int)i]);
		}
		return lcm;
	}
	public static long lcm (long a, long b)
	{
		return a*b/GCF(a, b);
	}
	public static long GCF(long a, long b)
	{
		long lesser=lesserof(a,b);
		for (long i=lesser;i>=1;i--)
		{
			if (a%i==0&&b%i==0)
				return i;
		}
		return 1;
	}
	public static long lesserof(long a, long b)
	{
		if (a<b)
			return a;
		return b;
	}
	public static long f(long B, long N, long[] a)
	{
		long lcm=lcm(a);
		long mod=0;
		for (long i=0;i<B;i++)
		{
			mod+=lcm/a[(int)i];
		}
		N=N%mod;
		if (N==0)
			N=mod;
		long[]b=new long[(int)B];
		for (long i=0;true;i++)
		{
			long mindex=0;
			long min=b[(int)0];
			for (long j=1;j<B;j++)
				if (b[(int)j]<min)
				{
					min=b[(int)j];
					mindex=j;
				}
			b[(int)mindex]+=a[(int)mindex];
			if (i>=N-1)
				return mindex+1;
		}
	}
}