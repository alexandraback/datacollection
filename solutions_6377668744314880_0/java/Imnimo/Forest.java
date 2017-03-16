import java.io.File;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;


public class Forest {
	public static void main(String[] args) throws Exception {
		
		//System.out.println(isCounterClockwise())
		FileWriter out = new FileWriter("forestOut.txt");
		Scanner s = new Scanner(new File("C-small-attempt2.in"));
		int numCases = Integer.parseInt(s.nextLine());
		
		for(int currentCase = 1;currentCase<=numCases;currentCase++) {
			int numTrees = Integer.parseInt(s.nextLine());
			ArrayList<Point> trees = new ArrayList<Point>();
			for(int i = 0;i<numTrees;i++) {
				String treeString = s.nextLine();
				String[] treeArr = treeString.split("\\s+");
				trees.add(new Point(Integer.parseInt(treeArr[0]),Integer.parseInt(treeArr[1])));
				
			}
			//System.out.println(giftWrap(trees));
			System.out.println("Case #" + currentCase + ":");
			out.write("Case #" + currentCase + ":\n");
			for(int i = 0;i<numTrees;i++) {
				System.out.println(findMinRemove(trees.get(i),trees,0));
				out.write(findMinRemove(trees.get(i),trees,0) + "\n");
				
			}
			
		}
		out.flush();
		out.close();
		
	}
	

   
	
	public static long isCounterClockwise(Point a, Point b, Point c) {
		
		return -1*((b.y - a.y)*(c.x - b.x) - (b.x - a.x)*(c.y - b.y));
		
		
	}
	
	
	public static List<Point> giftWrap(ArrayList<Point> trees) {
		Point lowestY = trees.get(0);
		int lowestYIndex = 0;
		for(int i = 1;i<trees.size();i++) {
			Point p = trees.get(i);
			if(p.y<lowestY.y) {
				lowestY = p;
				lowestYIndex = i;
			} else if(p.y==lowestY.y && p.x<lowestY.x) {
				lowestY = p;
				lowestYIndex = i;
			}
		}
		
		ArrayList<Point> hull = new ArrayList<Point>();
		
		Point p = lowestY;
		while(true) {
			hull.add(p);
			Point endpoint = trees.get(0);
			for(int i = 0;i<trees.size();i++) {
				 if (endpoint.equals(p) ||  isCounterClockwise(p,endpoint,trees.get(i)) > 0 || 
						 (isCounterClockwise(p,endpoint,trees.get(i))==0 && distance(p,trees.get(i))>distance(p,endpoint))
						 ) {
					 endpoint = trees.get(i);
				 }
			}
			if(endpoint.equals(lowestY)) {
				break;
			}
			p = endpoint;
			//System.out.println(hull  + " " + p);
			//if(hull.size()>2)
			//System.exit(1);
					
		}
		return hull;
		
	}
	
	public static  double distance(Point a, Point b) {
		return Math.sqrt((a.x - b.x)*(a.x-b.x) + (a.y - b.y)*(a.y - b.y));
	}
	
	public static List<Point> grahamScan(ArrayList<Point> trees) {
		
		if(trees.size()<=3) {
			ArrayList<Point> hull = new ArrayList<Point>();
			for(Point p : trees) {
				hull.add(p);
			}
			return hull;
		}
		
		
		Point lowestY = trees.get(0);
		int lowestYIndex = 0;
		for(int i = 1;i<trees.size();i++) {
			Point p = trees.get(i);
			if(p.y<lowestY.y) {
				lowestY = p;
				lowestYIndex = i;
			} else if(p.y==lowestY.y && p.x<lowestY.x) {
				lowestY = p;
				lowestYIndex = i;
			}
		}
		
		ArrayList<Point> otherTrees = new ArrayList<Point>();
		for(int i = 0;i<trees.size();i++) {
			if(i!=lowestYIndex) {
				otherTrees.add(trees.get(i));
			}
		}
		
		//System.out.println("ANCHOR IS " + lowestY);
		Point temp = trees.get(0);
		trees.set(0, lowestY);
		trees.set(lowestYIndex,temp);
		
		PolarComparator c = new PolarComparator(lowestY);
		Collections.sort(otherTrees,c);
		//System.out.println(otherTrees);
		
		//System.out.println(c.getPolarAngle(new Point(-10,1)));
		
		
		
		
		ArrayList<Point> hull = new ArrayList<Point>();
		Point[] stack = new Point[trees.size()];
		stack[0] = lowestY;
		stack[1] = otherTrees.get(0);
		stack[2] = otherTrees.get(1);
		//System.out.println("STACK IS: " + Arrays.toString(stack));
		
		int stackTop = 2;
		for(int i = 2;i<otherTrees.size();i++) {
			//System.out.println("Processing " + otherTrees.get(i));
			//System.out.println(isCounterClockwise(stack[stackTop-1],stack[stackTop],otherTrees.get(i)));
			while(isCounterClockwise(stack[stackTop-1],stack[stackTop],otherTrees.get(i)) < 0) {
				
				
				
				stackTop--;
			}
			stack[stackTop+1] = otherTrees.get(i);
			stackTop++;
			//System.out.println(Arrays.toString(stack));
		}
		
		for(int i = 0;i<=stackTop;i++) {
			hull.add(stack[i]);
		}
		return hull;
	}
	
	public static boolean onHull(Point p, List<Point> hull) {
		for(Point h : hull) {
			if(h.equals(p)) return true;
		}
		for(int i = 0;i<hull.size()-1;i++) {
			if(isCounterClockwise(hull.get(i),p,hull.get(i+1))==0) {
				return true;
			}
		}
		if(isCounterClockwise(hull.get(hull.size()-1),p,hull.get(0))==0) {
			return true;
		}
		
		return false;
	}
	
	public static int findMinRemove(Point p, ArrayList<Point> trees, int limit) {
		List<Point> hull = giftWrap(trees);
		/*if(p.equals(new Point(5,5))) {
		System.out.println("Testing for " + p + " from " + trees);
		System.out.println("HULL IS NOW " + hull);
		}*/
		
		if(onHull(p,hull)) { 
			/*if(p.equals(new Point(5,5))) {
				System.out.println("FOUND IT");
			}*/
			return 0;
		}
		
		int min = 100;
		for(int removeIndex = limit;removeIndex<trees.size();removeIndex++) {
			
			if(trees.get(removeIndex).equals(p)) continue;
			
			ArrayList<Point> copy = new ArrayList<Point>(trees);
			copy.remove(removeIndex);
			int cost = 1 + findMinRemove(p,copy,removeIndex);
			if(cost<min) min = cost;
			if(min==1) break;
		}
		return min;
		
	}
	
}

class PolarComparator implements Comparator<Point> {
	Point anchor;
	public PolarComparator(Point anchor) {
		this.anchor = anchor;
	}
	
	@Override
	public int compare(Point arg0, Point arg1) {
		Double a = getPolarAngle(arg0);
		Double b = getPolarAngle(arg1);
		return a.compareTo(b);
	}
	
	public double getPolarAngle(Point p) {
		double angle = Math.atan2(p.y-anchor.y, p.x-anchor.x);
		if(angle<0) angle+=Math.PI*2;
		return angle;
	}
	
}

class Point {
	long x,y;
	public Point(long x, long y) {
		this.x = x;
		this.y = y;
	}
	public String toString() {
		return "(" + x + "," + y + ")";
	}
	public int hashCode() {
		return (int)(x + 31*y);
	}
	public boolean equals(Object o) {
		if(o instanceof Point) {
			Point other = (Point)o;
			return x==other.x && y==other.y;
		}
		return false;
	}
}
