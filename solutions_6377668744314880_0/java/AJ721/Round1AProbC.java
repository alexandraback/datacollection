import java.util.*;
import java.io.*;
public class Round1AProbC {
	static 	double epsilon = 0.00000001;
	public static void main(String[] args) throws Exception
	{
		String file = "Round1A/C-small-attempt0.in";

		BufferedReader br = new BufferedReader(new FileReader(file));
		PrintWriter writer = new PrintWriter("Round1A/outCsmall.txt", "UTF-8");
		String line;

		int T = Integer.parseInt(br.readLine());
		for(int test=0;test<T;test++)
		{
			int N = Integer.parseInt(br.readLine());
			
			//int[] X = new int[N];
			//int[] Y = new int[N];
			Set<Point> trees = new HashSet<Point>();
			Point[] list = new Point[N];
			for(int i=0;i<N;i++)
			{
				String[] parts = br.readLine().split(" ");
				int X = Integer.parseInt(parts[0]);
				int Y = Integer.parseInt(parts[1]);
				Point tree = new Point(X,Y);
				trees.add(tree);
				list[i] = tree;
			}
			
			writer.println("Case #"+(test+1)+":");
			for(Point squirrel:list)
			{
				int count = countTrees(trees,squirrel);
				writer.println(count);
			}
		}
		writer.close();
	}
	public static int countTrees(Set<Point> trees, Point squirrel)
	{
		if(trees.size()<=3)
		{
			//System.out.println("Not enough trees");
			return 0;
		}
		Set<Point> trees2 = new HashSet<Point>();
		trees2.addAll(trees);
		int count = 0;
		for(Point tree:trees)
		{
			if(tree!=squirrel)
			{
				Point center = getCenter(trees, tree);
				double distBefore = distanceToEdge(trees, squirrel, center);
				if(distBefore<=0)
				{
					//System.out.println("0 dist");
					return 0;
				}
				trees2.remove(tree);
				double distAfter = distanceToEdge(trees2, squirrel, center);
				if(distAfter<distBefore)
				{
					return 1 + countTrees(trees2, squirrel);
				}
				trees2.add(tree);
			}
		}
		//throw new RuntimeException("Ouch");
		return 0;
	}
	public static Point getCenter(Set<Point> trees, Point exclude)
	{
		double sumX = 0;
		double sumY = 0;
		int i=0;
		for(Point tree:trees)
		{
			if(tree!=exclude)
			{
				sumX += tree.x;
				sumY += tree.y;
				i++;
				if(i>=3) break;
			}
		}
		double avgX = sumX / i;
		double avgY = sumY / i;
		return new Point(avgX, avgY);
	}
	
	public static double distanceToEdge(Set<Point> trees, Point squirrel, Point center)
	{
		if(trees.size()<=3)
		{
			//System.out.println("trigger0");
			return 0.0;
		}
		
		Point argMaxCounter = null;
		Point argMaxClock = null;
		double maxCounter = 0.0;
		double maxClock = 0.0;
		double fixed = center.getAngle(squirrel);
		for(Point tree:trees)
		{
			if(!tree.equalish(center) && tree!=squirrel)
			{
				double changing = center.getAngle(tree);
				double counter = counterDistance(fixed,changing);
				double clock = clockDistance(fixed,changing);
				if(counter<Math.PI-epsilon && (argMaxCounter == null || counter<maxCounter) && counter>0) //
				{
					argMaxCounter = tree;
					maxCounter = counter;
				}
				if(clock<=Math.PI && (argMaxClock == null || clock<maxClock) && clock > 0) //
				{
					argMaxClock = tree;
					maxClock = clock;
				}
			}
		}
		
		if(argMaxCounter == null || argMaxClock ==null)
		{
			//System.out.println("triggernull");
			return -1.0;
		}
		
		maxCounter = center.getAngle(argMaxCounter);
		maxClock = center.getAngle(argMaxClock);
		

		
		
		double counterRad = center.getRadius(argMaxCounter);
		double clockRad = center.getRadius(argMaxClock);
		double myRad = center.getRadius(squirrel);
		//System.out.println(argMaxCounter+"/"+argMaxClock+"/"+squirrel+"/"+center);
		
		if(myRad>=counterRad-epsilon && myRad >= clockRad-epsilon)
		{
			//System.out.println("trigger1");
			return -1.0;
		}
		if(clockDistance(maxClock,maxCounter)<counterDistance(maxClock,maxCounter)) //Math.PI
		{
			//System.out.println("trigger2");
			return -1.0;
		}
		double fullAngle = clockDistance(maxCounter,maxClock);
		//System.out.println(maxCounter+";"+maxClock);
		//System.out.println("!"+fullAngle);
		double fullDist = Math.sqrt(counterRad*counterRad + clockRad*clockRad-2*clockRad*counterRad*Math.cos(fullAngle));//law of cosines
		
		//System.out.println(".."+fullAngle+".."+fullDist);
		double clockAngle2 = Math.asin(counterRad*Math.sin(fullAngle)/fullDist);
		double clockAngle1 = clockDistance(fixed,maxClock);
		double clockAngle3 = Math.PI - clockAngle2-clockAngle1;
		//System.out.println(clockAngle1+":"+clockAngle2+":"+clockAngle3);
		double goal = Math.sin(clockAngle2)/Math.sin(clockAngle3)*clockRad;
		if(Math.abs(goal-myRad)<epsilon)
		{
			//System.out.println("trigger3");
			return -1.0;
		}
		if(goal<myRad)
		{
			//System.out.println("trigger4");
			return -1.0;
		}
		//System.out.println("trigger/"+(goal-myRad));
		return goal-myRad;
	}
	
	//radians
	public static double counterDistance(double fixed, double changing)
	{
		double diff = changing-fixed;
		if(0<=diff && diff<Math.PI * 2)
		{
			return diff;
		}
		else
		{
			return diff + Math.PI * 2;
		}
	}
	
	public static double clockDistance(double fixed, double changing)
	{
		double diff = fixed-changing;
		if(0<=diff && diff<Math.PI * 2)
		{
			return diff;
		}
		else
		{
			return diff + Math.PI * 2;
		}
	}
	
}

class Point
{
	double x;
	double y;
	
	double epsilon = 0.00000001;
	
	public String toString()
	{
		return "("+x+","+y+")";
	}
	public Point(double x, double y)
	{
		this.x=x;
		this.y=y;
	}
	public boolean equalish(Point edge)
	{
		return Math.abs(edge.x-this.x)<epsilon && Math.abs(edge.y-this.y)<epsilon;
	}
	public double getAngle(Point edge)
	{
		double dx = edge.x-this.x;
		double dy = edge.y-this.y;
		double temp = Math.atan2(dy,dx);
		if(temp<0) temp += Math.PI*2;
		return temp;
	}
	public double getRadius(Point edge)
	{
		double dx = edge.x-this.x;
		double dy = edge.y-this.y;
		return Math.sqrt(dx*dx+dy*dy);
	}
}