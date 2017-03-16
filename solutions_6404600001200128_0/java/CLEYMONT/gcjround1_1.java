import java.util.*;
public class gcjround1_1
{
	static Scanner sc=new Scanner (System.in);
	public static void main (String[]args)
	{
		//String newLine=""+(char)13;
		//sc.useDelimiter(newLine);

		int T=sc.nextInt();
		for (int i=0;i<T;i++)
		{
			int N=sc.nextInt();
			//number of recorded times
			f(N, i);
			//System.out.println("Case #"+(i+1)+": "+f(N));
		}
	}
	public static int f(int N, int j)
	{
		int curr=0;
		int next=sc.nextInt();
		int[]a=new int[N];
			a[0]=next;
		int max=0;
		int meth1max=0;
		for (int i=1;i<N;i++)
		{
			 curr=next;
			 next=sc.nextInt();
			 a[i]=next;
			if (curr-next>max)
				max=curr-next;
			if (curr-next>0)
				meth1max+=curr-next;
		}
		int sum=0;
		for (int i=0;i<N-1;i++)
		{
			if (a[i]>max)
				sum+=max;
			else
				sum+=a[i];
		}
			System.out.println("Case #"+(j+1)+": "+meth1max+" "+sum);
		return sum;
	}
}