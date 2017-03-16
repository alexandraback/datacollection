package round1a;

import java.io.*;
import java.util.*;

public class Logging implements Runnable {

	// file names for IO
	private static final String INPUT_FILE = "C-small-attempt2.in";
	private static final String OUTPUT_FILE = "C-small-attempt2.out";
	
	// 
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out) );
	static StringTokenizer st = new StringTokenizer("");

	public static String next() {
		try {
			while (!st.hasMoreTokens()) {
				String s = br.readLine();
				if (s == null)
					return null;
				st = new StringTokenizer(s);
			}
			return st.nextToken();
		} catch (Exception e) {
			return null;
		}
	}

	public static void main(String[] asda) throws Exception {
		
		br = new BufferedReader( new FileReader(INPUT_FILE) );
		out = new PrintWriter(new FileWriter(OUTPUT_FILE) );
		
		new Thread(null, new Logging(), "Main", 1 << 26).start();
	}

	public void run() {
		int CASES = Integer.parseInt( next() );
		for (int c = 1; c <= CASES; c++)	{
			out.println( String.format("Case #%d:", c ) );
			solve();
		}
		//
		out.flush();
		System.exit(0);
	}
	
	private void solve()	{
		int N = Integer.parseInt( next() );
		Point2D [] pts = new Point2D[N];
		for (int i = 0; i < N; i++)	{
			long x = Integer.parseInt( next() );
			long y = Integer.parseInt( next() );
			
			pts[i] = new Point2D(i, x, y);
		}
	//	GrahamScan gs = new GrahamScan(pts);
		
		int [] ans = new int [N];
		Arrays.fill(ans, INF);
		
		for (int mask = 1; mask < 1 << N; mask++)	{
			int used = Integer.bitCount(mask);
			
			Point2D [] npts = new Point2D[used];
			int len = 0;
			for (int k = 0; k < N; k++)	if	( ((1 << k) & mask) != 0 )
				npts[len++] = pts[k];

			/*
			out.println( len );
			for (Point2D p : npts)
				out.println(p);
			*/

			// find points in the hull
			GrahamScan gs = new GrahamScan(npts);
			Point2D [] hull = gs.hull.toArray( new Point2D [] {} );
			boolean [] inHull = new boolean [N];
			for (Point2D p : hull)	{
				ans[ p.id ] = Math.min( ans[p.id], N - used );
				inHull[ p.id ] = true;
			}
			
			/*
			out.println("hull");
			for (Point2D p : hull)
				out.println(p);
			
			out.println();
			*/
			if	( used < 4 )
				continue;
			
			// find points collinear to the points in hull
			int M = used - hull.length;	// points in npts but not in hull
			if	( M == 0 )
				continue;
			
			for (Point2D p : npts)	if	( !inHull[ p.id ] )	{
				// check if p is the hull
				for (int k = 0; k < hull.length; k++)	{
					int kk = (k + 1) % hull.length;
					Point2D a = hull[k], b = hull[kk];
					
					boolean can = Point2D.ccw(a, b, p) == 0;
					can |= Point2D.ccw(a, p, b) == 0;
					can |= Point2D.ccw(p, a, b) == 0;
					can |= Point2D.ccw(b, a, p) == 0;
					can |= Point2D.ccw(b, p, a) == 0;
					can |= Point2D.ccw(p, b, a) == 0;
					if	( can )
						ans[ p.id ] = Math.min( ans[p.id], N - used );
				}
			}
		}
		
		for (int x : ans)
			out.println(x);
		
	}
	final int INF = 100000000;
}


class GrahamScan {
	// hull will contains the boundary points in counter clocwise
    Stack<Point2D> hull = new Stack<Point2D>();

    public GrahamScan(Point2D[] points) {
    	int N = points.length;
    	if	( N < 4 )	{
    		for (int i = 0; i < N; i++)
    			hull.push( points[i] );
    		return;
    	}
        // preprocess so that points[0] has lowest y-coordinate; break ties by x-coordinate
        // points[0] is an extreme point of the convex hull
        int min = 0;
        for (int i = 1; i < N; i++)	{
        	if	( points[i].compareTo( points[min] ) < 0 )
        		min = i;
        }
        Point2D aux = points[0];
        points[0] = points[min];
        points[min] = aux;
        
        // sort by polar angle with respect to base point points[0],
        // breaking ties by distance to points[0]
        Arrays.sort(points, 1, N, points[0].POLAR_ORDER);

        hull.push(points[0]);       // p[0] is first extreme point

        // find index k1 of first point not equal to points[0]
        int k1 = 0;

        for (k1 = 1; k1 < N; k1++)
            if (!points[0].equals(points[k1])) break;
        if (k1 == N) return;        // all points equal

        // find index k2 of first point not collinear with points[0] and points[k1]
        int k2;
        for (k2 = k1 + 1; k2 < N; k2++)
            if (Point2D.ccw(points[0], points[k1], points[k2]) != 0)
            	break;
        
        hull.push(points[k2-1]);    // points[k2-1] is second extreme point

        // Graham scan; note that points[N-1] is extreme point different from points[0]
        for (int i = k2; i < N; i++) {
            Point2D top = hull.pop();
            while ( !hull.isEmpty() && Point2D.ccw(hull.peek(), top, points[i]) <= 0) {
                top = hull.pop();
            }
            hull.push(top);
            hull.push(points[i]);
        }
    }
}

class Point2D implements Comparable<Point2D> {
    public static final Comparator<Point2D> X_ORDER = new XOrder();
    public static final Comparator<Point2D> Y_ORDER = new YOrder();
    public static final Comparator<Point2D> R_ORDER = new ROrder();

    public final Comparator<Point2D> POLAR_ORDER = new PolarOrder();
    public final Comparator<Point2D> ATAN2_ORDER = new Atan2Order();
    public final Comparator<Point2D> DISTANCE_TO_ORDER = new DistanceToOrder();

    final long x;    // x coordinate
    final long y;    // y coordinate
    final int id;

    // create a new point (x, y)
    public Point2D(int id, long x, long y) {
        this.x = x;
        this.y = y;
        this.id = id;
    }

    // return the x-coorindate of this point
    public long x() { return x; }

    // return the y-coorindate of this point
    public long y() { return y; }

    // return the radius of this point in polar coordinates
    public double r() { return Math.sqrt(x*x + y*y); }

    // return the angle of this point in polar coordinates
    // (between -pi/2 and pi/2)
    public double theta() { return Math.atan2(y, x); }

    // return the polar angle between this point and that point (between -pi and pi);
    // (0 if two points are equal)
    private double angleTo(Point2D that) {
    	long dx = that.x - this.x;
    	long dy = that.y - this.y;
        return Math.atan2(dy, dx);
    }

    // is a->b->c a counter-clockwise turn?
    // -1 if clockwise, +1 if counter-clockwise, 0 if collinear
    public static int ccw(Point2D a, Point2D b, Point2D c) {
    	long area2 = (b.x-a.x)*(c.y-a.y) - (b.y-a.y)*(c.x-a.x);
        if      (area2 < 0) return -1;
        else if (area2 > 0) return +1;
        else                return  0;
    }

    // twice signed area of a-b-c
    public static long area2(Point2D a, Point2D b, Point2D c) {
        return (b.x-a.x)*(c.y-a.y) - (b.y-a.y)*(c.x-a.x);
    }

    // return Euclidean distance between this point and that point
    public double distanceTo(Point2D that) {
    	long dx = this.x - that.x;
        long dy = this.y - that.y;
        return Math.sqrt(dx*dx + dy*dy);
    }

    // return square of Euclidean distance between this point and that point
    public long distanceSquaredTo(Point2D that) {
    	long dx = this.x - that.x;
    	long dy = this.y - that.y;
        return dx*dx + dy*dy;
    }

    // compare by y-coordinate, breaking ties by x-coordinate
    public int compareTo(Point2D that) {
        if (this.y < that.y) return -1;
        if (this.y > that.y) return +1;
        if (this.x < that.x) return -1;
        if (this.x > that.x) return +1;
        return 0;
    }

    // compare points according to their x-coordinate
    private static class XOrder implements Comparator<Point2D> {
        public int compare(Point2D p, Point2D q) {
            if (p.x < q.x) return -1;
            if (p.x > q.x) return +1;
            return 0;
        }
    }

    // compare points according to their y-coordinate
    private static class YOrder implements Comparator<Point2D> {
        public int compare(Point2D p, Point2D q) {
            if (p.y < q.y) return -1;
            if (p.y > q.y) return +1;
            return 0;
        }
    }

    // compare points according to their polar radius
    private static class ROrder implements Comparator<Point2D> {
        public int compare(Point2D p, Point2D q) {
            double delta = (p.x*p.x + p.y*p.y) - (q.x*q.x + q.y*q.y);
            if (delta < 0) return -1;
            if (delta > 0) return +1;
            return 0;
        }
    }
 
    // compare other points relative to atan2 angle (bewteen -pi/2 and pi/2) they make with this Point
    private class Atan2Order implements Comparator<Point2D> {
        public int compare(Point2D q1, Point2D q2) {
            double angle1 = angleTo(q1);
            double angle2 = angleTo(q2);
            if      (angle1 < angle2) return -1;
            else if (angle1 > angle2) return +1;
            else                      return  0;
        }
    }

    // compare other points relative to polar angle (between 0 and 2pi) they make with this Point
    private class PolarOrder implements Comparator<Point2D> {
        public int compare(Point2D q1, Point2D q2) {
        	long dx1 = q1.x - x;
        	long dy1 = q1.y - y;
        	long dx2 = q2.x - x;
        	long dy2 = q2.y - y;

            if      (dy1 >= 0 && dy2 < 0) return -1;    // q1 above; q2 below
            else if (dy2 >= 0 && dy1 < 0) return +1;    // q1 below; q2 above
            else if (dy1 == 0 && dy2 == 0) {            // 3-collinear and horizontal
                if      (dx1 >= 0 && dx2 < 0) return -1;
                else if (dx2 >= 0 && dx1 < 0) return +1;
                else                          return  0;
            }
            else return -ccw(Point2D.this, q1, q2);     // both above or below

            // Note: ccw() recomputes dx1, dy1, dx2, and dy2
        }
    }

    // compare points according to their distance to this point
    private class DistanceToOrder implements Comparator<Point2D> {
        public int compare(Point2D p, Point2D q) {
            double dist1 = distanceSquaredTo(p);
            double dist2 = distanceSquaredTo(q);
            if      (dist1 < dist2) return -1;
            else if (dist1 > dist2) return +1;
            else                    return  0;
        }
    }


    // does this point equal y?
    public boolean equals(Object other) {
        if (other == this) return true;
        if (other == null) return false;
        if (other.getClass() != this.getClass()) return false;
        Point2D that = (Point2D) other;
        return this.x == that.x && this.y == that.y;
    }

    // convert to string
    public String toString() {
        return "(" + x + ", " + y + ")";
    }

}
