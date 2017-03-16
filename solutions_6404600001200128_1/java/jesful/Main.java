import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main
{
	Scanner scan=new Scanner(System.in);
	int N;
	int[] M;
	void input()
	{
		N=scan.nextInt();
		M=new int[N];
		for (int i=0;i<N;i++)
		{
			M[i]=scan.nextInt();
		}
	}
	int method1()
	{
		int res=0;
		for (int i=1;i<N;i++)
		{
			if (M[i]<M[i-1])
				res+=M[i-1]-M[i];
		}
		return res;
	}
	int method2()
	{
		ArrayList<Integer> speeds=new ArrayList<Integer>();
		speeds.add(0);
		for (int i=1;i<N;i++)
		{
			if (M[i]<M[i-1])
				speeds.add(M[i-1]-M[i]);
		}
		Collections.sort(speeds);
		int speed = speeds.get(speeds.size()-1);
		int res = 0;
		for (int i=1;i<N;i++)
		{
			if (M[i-1]-speed<0)
				res+=M[i-1];
			else
				res+=speed;
		}
		return res;
	}
	void run()
	{
		int T=scan.nextInt();
		for (int t=0;t<T;t++)
		{
			input();
			System.out.printf("Case #%d: %d %d\n", t+1, method1(), method2());
		}
	}
	public static void main(String[] args)
	{
		new Main().run();
	}
}
