
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;


public class Logging {
	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws NumberFormatException, IOException {
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		double epsilon = 1e-6;
		
		 BufferedReader br = new BufferedReader(new FileReader("C-small-attempt0.in"));
		int cases = Integer.parseInt(br.readLine());
		for(int i =0; i<cases; i++){
			int numTrees = Integer.parseInt(br.readLine());
			ArrayList<SqTree> trees = new ArrayList<>();
			for(int j = 0; j < numTrees; j++) {
				String[] nums = br.readLine().split(" ");
				trees.add(new SqTree(j, Integer.parseInt(nums[0]), Integer.parseInt(nums[1])));
			}
			ArrayList<SqTree> hull = quickHull(((ArrayList<SqTree>)trees.clone()));
			
			int[] logs = new int [numTrees];
			for(int j = 0; j < hull.size(); j++) {
				logs[hull.get(j).idx] = -1;
//				System.out.printf("%d %d %d\n", hull.get(j).idx, hull.get(j).x, hull.get(j).y);
			}
			System.out.println("Case #" + (i+1) +  ":");
//			System.out.println(hull.size());
			for(int j = 0; j < numTrees; j++) {
				if(logs[j] == -1) {
					System.out.println(0);
				} else {
//					System.out.println("not on edge");
					ArrayList<Double> hullPts = new ArrayList<>();
					for(int k = 0; k < hull.size(); k++){
//						System.out.println(getAngleToPoint(trees.get(j), hull.get(k)));
						hullPts.add(getAngleToPoint(trees.get(j), hull.get(k)));
					}
					Collections.sort(hullPts);
					for(int k = 1; k < hullPts.size(); k++) {
						double maxDiff = 0;
						for(int h = 0; h < hullPts.size(); h++) {
							double diff = (360 + hullPts.get((h + k+ 1) % hullPts.size()) - hullPts.get(h))%360;
//							System.out.println(diff);
							if(diff > maxDiff) maxDiff = diff;
						}
						if(Math.abs(maxDiff - 180) <= epsilon) { 
							System.out.println(k);
							break;
						}
					}
				}
			}
//			int maxDecrease = 0;
//			int case1shrooms = 0;
//			int case2shrooms = 0;
//			for(int j = 1; j < numTimes; j++) {
//				int diff = shrooms[j-1]-shrooms[j];
////				System.out.println(diff);
//				if(diff > 0) {
//					case1shrooms += diff;
//				}
//				if(diff > maxDecrease) {
//					maxDecrease = diff;
//				}
//			}
////			System.out.println(maxDecrease);
//			for(int j = 0; j < numTimes-1; j++) {
//				if(shrooms[j] < maxDecrease) {
//					case2shrooms += shrooms[j];
//				} else {
//					case2shrooms += maxDecrease;
//				}
//			}
//			System.out.println("Case #" + (i+1) +  ": " + myBarb);
		}
	}
	
	public static double getAngleToPoint(SqTree P1, SqTree P2) {
		int deltaY = P2.y - P1.y;
		int deltaX = P2.x - P1.x;
		return Math.atan2(deltaY, deltaX) * 180/Math.PI;
		
	}
	 public static ArrayList<SqTree> quickHull(ArrayList<SqTree> SqTrees)
	    {
	        ArrayList<SqTree> convexHull = new ArrayList<SqTree>();
	        if (SqTrees.size() < 3)
	            return (ArrayList) SqTrees.clone();
	 
	        int minSqTree = -1, maxSqTree = -1;
	        int minX = Integer.MAX_VALUE;
	        int maxX = Integer.MIN_VALUE;
	        for (int i = 0; i < SqTrees.size(); i++)
	        {
	            if (SqTrees.get(i).x < minX)
	            {
	                minX = SqTrees.get(i).x;
	                minSqTree = i;
	            }
	            if (SqTrees.get(i).x > maxX)
	            {
	                maxX = SqTrees.get(i).x;
	                maxSqTree = i;
	            }
	        }
	        SqTree A = SqTrees.get(minSqTree);
	        SqTree B = SqTrees.get(maxSqTree);
	        convexHull.add(A);
	        convexHull.add(B);
	        SqTrees.remove(A);
	        SqTrees.remove(B);
	 
	        ArrayList<SqTree> leftSet = new ArrayList<SqTree>();
	        ArrayList<SqTree> rightSet = new ArrayList<SqTree>();
	 
	        for (int i = 0; i < SqTrees.size(); i++)
	        {
	            SqTree p = SqTrees.get(i);
	            if (SqTreeLocation(A, B, p) <= 0)
	                leftSet.add(p);
	            else if (SqTreeLocation(A, B, p) == 1)
	                rightSet.add(p);
	        }
	        hullSet(A, B, rightSet, convexHull);
	        hullSet(B, A, leftSet, convexHull);
	 
	        return convexHull;
	    }
	 
	    public static int distance(SqTree A, SqTree B, SqTree C)
	    {
	        int ABx = B.x - A.x;
	        int ABy = B.y - A.y;
	        int num = ABx * (A.y - C.y) - ABy * (A.x - C.x);
	        if (num < 0)
	            num = -num;
	        return num;
	    }
	 
	    public static void hullSet(SqTree A, SqTree B, ArrayList<SqTree> set,
	            ArrayList<SqTree> hull)
	    {
	        int insertPosition = hull.indexOf(B);
	        if (set.size() == 0)
	            return;
	        if (set.size() == 1)
	        {
	            SqTree p = set.get(0);
	            set.remove(p);
	            hull.add(insertPosition, p);
	            return;
	        }
	        int dist = Integer.MIN_VALUE;
	        int furthestSqTree = -1;
	        for (int i = 0; i < set.size(); i++)
	        {
	            SqTree p = set.get(i);
	            int distance = distance(A, B, p);
	            if (distance > dist)
	            {
	                dist = distance;
	                furthestSqTree = i;
	            }
	        }
	        SqTree P = set.get(furthestSqTree);
//	        System.out.printf("FURTHEST %d %d %d\n", P.idx, P.x, P.y);
	        set.remove(furthestSqTree);
	        hull.add(insertPosition, P);
	 
	        // Determine who's to the left of AP
	        ArrayList<SqTree> leftSetAP = new ArrayList<SqTree>();
	        for (int i = 0; i < set.size(); i++)
	        {
	            SqTree M = set.get(i);
	            if (SqTreeLocation(A, P, M) >= 0)
	            {
	                leftSetAP.add(M);
	            }
	        }
	 
	        // Determine who's to the left of PB
	        ArrayList<SqTree> leftSetPB = new ArrayList<SqTree>();
	        for (int i = 0; i < set.size(); i++)
	        {
	            SqTree M = set.get(i);
	            if (SqTreeLocation(P, B, M) >= 0)
	            {
//	            	if(!leftSetAP.contains(M)) {
		                leftSetPB.add(M);
//	            	}
	            }
	        }
	        hullSet(A, P, leftSetAP, hull);
	        hullSet(P, B, leftSetPB, hull);
	 
	    }
	 
	    public static int SqTreeLocation(SqTree A, SqTree B, SqTree P)
	    {
	        int cp1 = (B.x - A.x) * (P.y - A.y) - (B.y - A.y) * (P.x - A.x);
	        if (cp1 > 0)
	            return 1;
	        else if (cp1 == 0)
	            return 0;
	        else
	            return -1;
	    }
	    
	    public static class SqTree implements Comparable<SqTree>{
	    	public int x;
	    	public int y;
	    	public int idx;
	    	public double angle;
	    	public SqTree(int idx, int x, int y) {
	    		this.idx = idx;
	    		this.x = x;
	    		this.y = y;
	    		this.angle = 0;
	    	}
	    	
	    	public SqTree(int idx, double angle) {
	    		this.idx = idx;
	    		this.x = 0;
	    		this.y = 0;
	    		this.angle = angle;
	    	}
	    	
			@Override
			public int compareTo(SqTree o) {
				if(this.angle > o.angle) {
					return 1;
				} else if (this.angle == o.angle) {
					return 0;
				} else {
					return -1;
				}
			}
	    }
}
