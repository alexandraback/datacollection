import java.io.*;
import java.util.*;

public class P3 {
	static int[] ans;
	static boolean isLeft(Point a, Point b, Point c) {
		int det = (b.x - a.x)*(c.y - a.y) - (b.y - a.y)*(c.x - a.x);
		if (det > 0)
			return true;
		if (det < 0)
			return false;
	     if (a.x != b.x) {
	    	 if (a.x > b.x && c.x > a.x)
	    		 return false;
	    	 if (a.x < b.x && c.x < a.x)
	    		 return false;
	    	 return true;
	     }
	     if (a.y > b.y && c.y > a.y)
    		 return false;
    	 if (a.y < b.y && c.y < a.y)
    		 return false;
    	 return true;
	}
	static boolean isRight(Point a, Point b, Point c){
		int det = (b.x - a.x)*(c.y - a.y) - (b.y - a.y)*(c.x - a.x);
    	 return det <= 0;
	}
	public static void main (String[] args) throws FileNotFoundException {
//		Scanner sc = new Scanner (System.in);
//		PrintStream op = System.out;
		Scanner sc = new Scanner (new FileInputStream ("D:\\Internet\\C-small-attempt0.in"));
		PrintStream op = new PrintStream ("D:\\Dropbox\\SRMs\\GCJ151A\\src\\C-output.txt");
		int T = sc.nextInt();
		for (int t = 1; t <= T; t++) {
			int n = sc.nextInt();
			Point[] p = new Point [n];
			ans = new int [n];
			for (int i = 0; i < n; i++)
				p[i] = new Point (sc.nextInt(), sc.nextInt());
			for (int i = 0; i < n; i++) {
				int h = i, e = i;
				Set<Integer> s = new HashSet <Integer> ();
				boolean[] checked = new boolean [n];
				checked[i] = true;
				do {
					e = i;
					s.add(h);
					for (int j = 0; j < n; j++) {
						if (j != h && j != e && isLeft (p[h], p[e], p[j]))
							e = j;
					}
					if (h == i || e == i) {
						for (int j = 0; j < n; j++) {
							if (isRight (p[h], p[e], p[j]))
								checked[j] = true;
						}
					}
					h = e;
				} while (!s.contains(h));
				ans[i] = 0;
				for (int j = 0; j < n; j++) {
					if (!checked[j])
						ans[i]++;
				}
			}
			op.println("Case #" + t + ":");
			for (int i = 0; i < n; i++)
				op.println(ans[i]);
		}
		sc.close();
		op.close();
	}
}
class Point implements Comparable<Point> {
	int x, y, ind;
	Point (int a, int b) {
		x = a;
		y = b;
	}
	@Override
	public int compareTo(Point o) {
		return x - o.x;
	}
}