import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

class Point
{
	double x,y;
	Point (double x, double y)
	{
		this.x=x;
		this.y=y;
	}
	double dot(Point p)
	{
		return x*p.x+y*p.y;
	}
	double cross(Point q)
	{
		return x*q.y-y*q.x;
	}
	Point minus(Point p)
	{
		return new Point(x-p.x, y-p.y);
	}
	Point add(Point p)
	{
		return new Point(x+p.x, y+p.y);
	}
	double atan()
	{
		return Math.atan2(y, x);
	}
}

public class Main
{
	public static final double eps = 1e-8;
	
	public static int sign(double t)
	{
		if (Math.abs(t)<eps)
			return 0;
		if (t<0)
			return -1;
		return 1;
	}

	Scanner scan=new Scanner(System.in);
	int N;
	Point[] point;
	void input()
	{
		N=scan.nextInt();
		point=new Point[N];
		for (int i=0;i<N;i++)
		{
			point[i]=new Point(
					scan.nextDouble(), scan.nextDouble());
		}
	}
	boolean feasible(Point from, Point to)
	{
		if (sign(from.cross(to))>=0)
		{
			return true;
		}
		return false;
	}
	int solve(int p)
	{
		Point[] vec=new Point[N-1];
		int cnt=0;
		for (int i=0;i<N;i++)
		{
			if (i==p)
				continue;
			vec[cnt++]=point[i].minus(point[p]);
		}
		Arrays.sort(vec, new Comparator<Point>(){

			@Override
			public int compare(Point o1, Point o2) {
				return Double.compare(o1.atan(), o2.atan());
			}
			
		});
		int res = N-1;
		for (int i=0,o=0;i<cnt;i++)
		{
			if (o<i)
				o=i;
			int j = o;
			do
			{
				if (feasible(vec[i], vec[j]))
				{
					o=j;
					j++;
					if (j==cnt)
						j=0;
				}
				else
				{
					break;
				}
			} while (j!=i);
			res = Math.min(res,N-2-( o-i>=0?o-i:o+cnt-i));
		}
		return res;
	}
	void solve()
	{
		for (int i=0;i<N;i++)
		{
			System.out.println(solve(i));
		}
	}
	void run()
	{
		int T=scan.nextInt();
		for (int t=0;t<T;t++)
		{
			input();
			System.out.printf("Case #%d:\n", t+1);
			solve();
		}
	}
	public static void main(String[] args)
	{
		new Main().run();
	}
}
