package RoundA;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

class Point{
	int x, y;
	Point(int x, int y){
		this.x = x; this.y = y;
	}
}
class Line{
	Point a;
	Point b;
	Line(Point a, Point b){
		this.a = a; this.b = b;
	}
	public int side(Point c)
	{
		long s1 = (c.y - b.y);
		long s2 = (c.x - b.x);
		s1 *= (a.x - b.x);
		s2 *= (a.y - b.y);
		if(s1 - s2 > 0)
			return 1;
		else if (s1 == s2)
			return 0;
		else
			return -1;
//		return (c.y - b.y) * (a.x - b.x) - (c.x - b.x) * (a.y - b.y);
	}
	public boolean oneSide(Point[] ps){
		int s = 0;
		for(Point x: ps)
		{
			int temp = side(x);
			if(s == 0)
				s = temp;
			else if(temp != 0)
			{
				if(s != temp)
					return false;
			}
		}
		return true;
	}
	public int minOneSide(Point[] ps){
		int a = 0, b = 0;
		for(Point x: ps)
		{
			int temp = side(x);
			if(temp > 0)
				a++;
			else if(temp < 0)
				b++;
		}
		return Math.min(a, b);
	}
}
public class C_Logging {

	public static int minLog(Point[] ps, Point p)
	{
		if(ps.length <= 3)
			return 0;
		int min = Integer.MAX_VALUE;
		for(Point x: ps)
			if(x != p)
			{
				int m = new Line(x, p).minOneSide(ps);
				if(m < min)
					min = m;
			}
		return min;
	}

	public static void main(String[] args) {
		File fin = new File("src/RoundA/C-small-attempt1.in");
		Scanner scan;
		try {
			scan = new Scanner(fin);
		
			PrintWriter output = new PrintWriter("src/RoundA/C-small-attempt1.out.txt");
			int N = scan.nextInt();
			for(int i = 0; i < N; i++)
			{
				Point[] ps = new Point[scan.nextInt()];
				for(int i1 = 0; i1 < ps.length; i1++)
					ps[i1] = new Point(scan.nextInt(), scan.nextInt());
				
				output.println("Case #" + (i + 1) + ": " );
				for(int i1 = 0; i1 < ps.length; i1++)
					output.println(minLog(ps, ps[i1]));
			}
			scan.close();
			output.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
}
