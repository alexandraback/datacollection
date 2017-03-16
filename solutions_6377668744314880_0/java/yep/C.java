package round1A;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class C {
	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(new BufferedReader(new FileReader("C.in")));
		PrintStream out = new PrintStream("C.out");
		int T = in.nextInt();
		for (int k = 1; k <= T; k++) {
			int N = in.nextInt();
			Point[] ps = new Point[N];
			for(int i=0;i<N;i++){
				int x = in.nextInt();
				int y = in.nextInt();
				ps[i] = new Point(x,y);
			}
			out.println("Case #" + k + ":");
			System.out.println(N);
			for(int i=0;i<N;i++){
				int min = N;
				for(int j=0;j<N;j++)
					if (j!=i){
						int neg = 0;
						int pos = 0;
						for(int c = 0; c< N;c++)
							if (c!=i&&c!=j){
								long cross = cross(ps[c],ps[i],ps[j]);
								if (cross<0) neg++;
								if (cross>0) pos++;
							}
						
						if (pos<min) min = pos;
						if (neg<min) min = neg;
					}
				if (N==1) out.println(0);
				else out.println(min);
			}
		}
		in.close();
		out.close();
	}
	static long cross(Point c, Point a, Point b) {
		return (c.x - a.x) * (a.y - b.y) - (c.y - a.y) * (a.x - b.x);
	}
}

class Point {// 平面上的一个点
	long x;
	long y;
	public Point(int x, int y){
		this.x = x;
		this.y = y;
	}
}