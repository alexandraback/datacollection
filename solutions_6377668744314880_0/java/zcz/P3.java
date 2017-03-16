package gcj;


import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

public class P3 {

	Scanner scio=new Scanner(System.in);
	int caseNum=0;
	
	class Point {
		long x, y;
		int min=Integer.MAX_VALUE;
		public Point(int x, int y) {
			this.x=x;
			this.y=y;
		}
	}
	
	long dotProduct(Point p, Point a, Point b) {
		return((a.x-p.x)*(b.y-p.y)-(a.y-p.y)*(b.x-p.x));
	}
	
	ArrayList<Point> solveConv(ArrayList<Point> b) {
		if (b.size()<=3) return b;
		ArrayList<Point> c=new ArrayList<Point>();
		for(Point p : b) {
			boolean flag_p=false;
			for(Point prev : b) {
				if (prev.equals(p)) continue;
				int cnt=0;
				for (Point q : b) {
					if (q.equals(p) || q.equals(prev)) continue;
					if (dotProduct(p, prev, q)<=0) {
						++cnt;
					}
				}
				if (cnt+2==b.size()) {
					flag_p=true;
					break;
				}
			}
			if (flag_p==true) {
				c.add(p);
			}
		}
		return c;
	}

	void work() {
		ArrayList<Point> a=new ArrayList<Point>();
		int n=this.scio.nextInt();
		for(int i=0;i<n;++i) {
			int x=this.scio.nextInt();
			int y=this.scio.nextInt();
			a.add(new Point(x,y));
		}
		
		for(int t=0;t<(1<<n);++t) {
			ArrayList<Point> b=new ArrayList<Point>();
			int numCut=0;
			int tt=t;
			for(int i=0;i<n;++i) {
				if (tt%2==1) {
					++numCut;
				} else {
					b.add(a.get(i));
				}
				tt=tt/2;
			}
			b=solveConv(b);
			for(Point p : b) {
				p.min=Math.min(p.min, numCut);
			}
		}
		
		System.out.println("case #"+this.caseNum+":");
		for(Point p: a) {
			System.out.println(p.min);
		}
	}
	
	void run() {

		try {
			File file=new File("C-small-attempt1.in");//
//			File file=new File("input.txt");

			this.scio=new Scanner(file); 
		} catch (FileNotFoundException e) {}
		
		int t=scio.nextInt();
		for(int i=0;i<t;++i) {
			this.caseNum=i+1;
			work();
		}
	}
	
	public static void main(String[] args) {
		new P3().run();
	}

}
