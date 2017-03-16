import java.awt.Point;
import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Currency;
import java.util.HashSet;
import java.util.List;
import java.util.Stack;
import java.util.StringTokenizer;

/**
 * @author Jens Staahl
 */

public class hull {

	// some local config
	// static boolean test = false ;
	private boolean test = System.getProperty("ONLINE_JUDGE") == null;
	static String testDataFile = "C-small-attempt1.in";
//	 static String testDataFile = "testdata.txt";
	private static String ENDL = "\n";
	// Just solves the acutal kattis-problem
	ZKattio io;
	class Point implements Comparable<Point>
	{
		long x,y;
		Point(long x, long y)
		{
			this.x = x;
			this.y = y;
		}
	 
		// sort first on x then on y
		public int compareTo(Point other)     
		{

			if( x == other.x) 
				return Long.compare(y, other.y);
//				return y - other.y;
			else 
				return Long.compare(x, other.x);
//				return x - other.x;
		}
	 
	        // cross product of two vectors
		public long cross( Point p)
		{
			return x * p.y - y * p.x;
		}
	 
	        // subtraction of two points
		public Point sub( Point p)
		{
			return new Point( x - p.x, y - p.y );
		}
	 
	}
	 
	 
	public Point[] findHull( Point[] points)
	{
		int n = points.length;
		Arrays.sort( points);
		Point[] ans = new Point[2 * n];		        // In between we may have a 2n points
		int k = 0;
		int start = 0;					// start is the first insertion point
	 
	 
	 
		for(int i = 0; i < n; i ++)                     // Finding lower layer of hull
		{
			Point p = points[i];
			while( k - start >= 2 && p.sub( ans[k-1] ).cross(p.sub( ans[k-2] ) ) > 0 )
				k--;
			ans[k++] = p; 
		}
	 
		k--; 						// drop off last point from lower layer
		start = k ;						
	 
		for(int i = n-1 ; i >= 0 ; i --)                // Finding top layer from hull
		{
			Point p = points[i];
			while( k - start >= 2 && p.sub( ans[k-1] ).cross(p.sub( ans[k-2] ) ) > 0 )
				k--;
			ans[k++] = p; 
		}
		k--;						// drop off last point from top layer
	 
		return Arrays.copyOf(ans, k);                   // convex hull is of size k
	}
		
	int cnt = 0, max = 0;
	private void solve() throws Throwable {
		io = new ZKattio(stream);

		int n = io.getInt();
		for (int i = 0; i < n; i++) {
			solveIt(i+1);
			
		}
		out.flush();
	}


	private void solveIt(int casenr) {
		int n = io.getInt();
		Point[] pts = new Point[n];
		for (int i = 0; i < n; i++) {
			pts[i] = new Point(io.getLong(), io.getLong());
		}
		int[] ans = new int[n];
		Arrays.fill(ans, Integer.MAX_VALUE/2);
		if(n == 1) {
			ans[0] = 0;
		}
		for (int i = 1; i < (1 << n) ; i++) {
			int bitCount = Integer.bitCount(i);
			Point[] pp = new Point[bitCount];
			int cur = 0;
			for (int j = 0; j < n; j++) {
				if((i & (1 << j)) > 0) {
					pp[cur] = pts[j];
					cur ++;
				}
			}

			Point[] findHull = findHull(pp);
			for (int j = 0; j < pts.length; j++) {
				for (int k = 0; k < findHull.length; k++) {
					Point a = pts[j];
					Point b = findHull[k];
					if(a.x == b.x && a.y == b.y) {
						ans[j] = Math.min(ans[j], n - bitCount);
					}
				}
				
			}
		}

		print("Case #" + casenr + ":" );
		for (int i = 0; i < ans.length; i++) {
			print(ans[i] + "");
		}
	}


	private void print(String string) {
		out.println(string);
		System.out.println(string);
	}


	public static void main(String[] args) throws Throwable {
		new hull().solve();
	}

	public hull() throws Throwable {
		if (test) {
			stream = new FileInputStream(testDataFile);
		}
	}

	InputStream stream = System.in;
	PrintWriter out = new PrintWriter(new File(this.getClass().getCanonicalName() + ".out")); 

	public class ZKattio extends PrintWriter {
		public ZKattio(InputStream i) {
			super(new BufferedOutputStream(System.out));
			r = new BufferedReader(new InputStreamReader(i));
		}

		public ZKattio(InputStream i, OutputStream o) {
			super(new BufferedOutputStream(o));
			r = new BufferedReader(new InputStreamReader(i));
		}

		public boolean hasMoreTokens() {
			return peekToken() != null;
		}

		public int getInt() {
			return Integer.parseInt(nextToken());
		}

		public double getDouble() {
			return Double.parseDouble(nextToken());
		}

		public long getLong() {
			return Long.parseLong(nextToken());
		}

		public String getWord() {
			return nextToken();
		}

		private BufferedReader r;
		private String line;
		private StringTokenizer st;
		private String token;

		private String peekToken() {
			if (token == null)
				try {
					while (st == null || !st.hasMoreTokens()) {
						line = r.readLine();
						if (line == null)
							return null;
						st = new StringTokenizer(line);
					}
					token = st.nextToken();
				} catch (IOException e) {
				}
			return token;
		}

		private String nextToken() {
			String ans = peekToken();
			token = null;
			return ans;
		}
	}
	// System.out;

}