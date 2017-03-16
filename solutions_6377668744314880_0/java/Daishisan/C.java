import java.io.PrintStream;
import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.Scanner;


public class C {

	private static PrintStream out = System.out;
	
	private static class Triple implements Comparable<Triple> {
		
		public double angle;
		public long x;
		public long y;
		
		public Triple(double angle, long x, long y) {
			this.angle = angle;
			this.x = x;
			this.y = y;
		}
		
		@Override
		public int compareTo(Triple o) {
			if (angle != o.angle)
				return angle < o.angle ? -1 : 1;
			if (x != o.x)
				return x < o.x ? -1 : 1;
			if (y != o.y)
				return y < o.y ? -1 : 1;
			return 0;
		}

	}
	
	private static long righthandrule(Triple p, Triple q, Triple r) {
		return (q.x - p.x)*(r.y - q.y) - (q.y - p.y)*(r.x - q.x);
	}
	
	private static int getAns(boolean reversed, int curr) {
		int ret = Integer.MAX_VALUE;
		for (int i = 0; i < n - 1; ++i) {
			int p = 0;
			int q = 0;
			for (int j = 0; j < n - 1; ++j) {
				long rhr = righthandrule(sorted[i], unsorted[curr], sorted[j]);
				if (rhr > 0)
					++p;
				else if (rhr < 0)
					++q;
			}
			ret = Math.min(ret, p);
			ret = Math.min(ret, q);
		}
		return ret;
	}
	
	public static int n;
	public static Triple[] unsorted;
	public static Triple[] sorted;
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int numTests = in.nextInt();
		for (int test = 1; test <= numTests; ++test) {
			// read input
			n = in.nextInt();
			unsorted = new Triple[n];
			for (int i = 0; i < n; ++i)
				unsorted[i] = new Triple(-1, in.nextLong(), in.nextLong());
			// begin outputting answer
			out.println("Case #" + test + ":");
			// go through each tree one at a time
			sorted = new Triple[n - 1];
			for (int curr = 0; curr < n; ++curr) {
				// sort other trees radially from the point of view of the current tree
				unsorted[curr].angle = -1000;
				for (int i = 0; i < n; ++i) {
					if (i != curr) {
						unsorted[i].angle = Math.atan2(unsorted[i].y - unsorted[curr].y, unsorted[i].x - unsorted[curr].x);
						sorted[(i < curr) ? i : i - 1] = unsorted[i]; 
					}
				}
				Arrays.sort(sorted);
				// go through other trees
				int ans = Integer.MAX_VALUE;
				ans = Math.min(ans, getAns(false, curr));
				//reverse(sorted);
				//ans = Math.min(ans, getAns(true, curr));
				out.println(ans);
			}
		}
	}

}
