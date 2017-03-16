import java.awt.geom.Point2D;
import java.util.Arrays;
import java.util.Scanner;


public class C {

	public static void main(String[] args) {
		

		Scanner s = new Scanner(System.in);
		
		int numCases = s.nextInt();
		
		for(int numC = 0; numC < numCases; ++numC)
		{
			
			int n = s.nextInt();
			
			int[] xx = new int[n];
			int[] yy = new int[n];
			
			for(int i = 0; i < n; ++i)
			{
				int x = s.nextInt();
				int y = s.nextInt();
				
				xx[i] = x;
				yy[i] = y;
			}
			
			System.out.print("Case #");
			System.out.print(numC+1);
			System.out.println(": ");
			
			for(int bla = 0; bla < n; ++bla)
			{
				int rootX = xx[bla];
				int rootY = yy[bla];
				Point2D.Double root = new Point2D.Double(rootX, rootY);
				double[] angles = new double[n-1];
				int curr = 0;
				for(int i = 0; i < n; ++i)
				{
					if(i == bla)
					{
						continue;
					}
					
					int x = xx[i];
					int y = yy[i];
					Point2D.Double p = new Point2D.Double(x, y);
					double angle = getAngle(root, p);
					
					angles[curr] = angle;
					
					++curr;
				}
				
				Arrays.sort(angles);
				
				int min = 10000000;
				int end = 0;
				double currDeg = 0.0;
				for(int start = 0; start < angles.length; ++start)
				{
					// TODO...
					while(currDeg < 180.0)
					{
						double before = angles[end];
						end = (end+1) % (angles.length);
						double diff = angles[end] - before; 
						if(diff < 0)
						{
							diff = 360+ angles[end] - before;
						}
						currDeg += diff;
						if(start == end)
						{
							break;
						}
					}
					int val = end - start;
					if(start == end)
					{
						val = angles.length;
					}
					if(val < 0)
					{
						val = angles.length - start + end;
					}
					if(val < min)
					{
						min = val;
					}
					
					// dieser Teil ist nicht mehr enthalten...
					if(start != angles.length-1)
					{
						currDeg -= angles[start+1]-angles[start];
					}
					
				}
				if(min == 10000000)
				{
					min = 1;
				}
				if(n-min < 1)
				{
					// System.out.println("wrong!!!");
				}
				System.out.println(min-1);
				
			}
			
			/*System.out.print("Case #");
			System.out.print(numC+1);
			System.out.print(": ");
			System.out.println(numAdded);*/
		}

	}
	
	
	static public double getAngle(Point2D.Double tar, Point2D.Double o) {
	    double angle = Math.toDegrees(Math.atan2(tar.y - o.y, tar.x - o.x));

	    if(angle < 0)
	    {
	        angle += 360;
	    }

	    return angle;
	}

}
