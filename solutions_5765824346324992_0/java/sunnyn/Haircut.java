import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.StringTokenizer;


public class Haircut {
	static Haircut xx = new Haircut();
	public static void main(String args[]) throws IOException
	{
		long t = System.currentTimeMillis();

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		for(int ii=1; ii<=T; ii++)
		{		
			StringTokenizer st = new StringTokenizer(br.readLine());
			int B = Integer.parseInt(st.nextToken());
			int N = Integer.parseInt(st.nextToken());
			BB[] arr = new BB[B];
			StringTokenizer st1 = new StringTokenizer(br.readLine());
			long lcm = 1;
			for(int i=0; i<B; i++)
			{
				arr[i] = xx.new BB(i+1,Integer.parseInt(st1.nextToken()));
				lcm = lcm(arr[i].time, lcm);
			}
			PriorityQueue<BB> q = new PriorityQueue<BB>(B, new Comparator<BB>() {

				public int compare(BB o1, BB o2) {
					if(o1.rettime < o2.rettime) return -1;
					else if(o1.rettime > o2.rettime) return 1;
					else return Integer.compare(o1.label, o2.label);
				}
			});
			int r = 0;
			for(int i=0; i<B; i++)
			{
				q.add(arr[i]);
				r += lcm/arr[i].time;
			}
			N = N % (int)r;
			if(N ==0) N+= r;
			int res = 0;
			if(N <= B)
			{
				res = N;
			}
			else
			{
				N-= B;
				for(int j=0; j<N-1; j++)
				{
					BB x = q.poll();
					x.rettime += x.time;
					q.add(x);
				}
				res = q.poll().label;
			}
			System.out.println("Case #"+ii+": "+res);
		}
		System.out.println(System.currentTimeMillis()-t);
	}
	class BB
	{
		int label;
		long time;
		long rettime;
		public BB(int l, int t)
		{
			label = l;
			time = t;
			rettime = t;
		}
	}
	static long gcd(long a, long b)
	{
	    for (;;)
	    {
	        if (a == 0) return b;
	        b %= a;
	        if (b == 0) return a;
	        a %= b;
	    }
	}

	static long lcm(long a, long b)
	{
	    long temp = gcd(a, b);

	    return (temp > 0) ? (a / temp * b) : 0;
	}
}
