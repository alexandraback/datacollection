import java.io.File;
import java.io.PrintWriter;
import java.util.*;

public class Squirrel{
//	static Scanner chk;
	static PrintWriter out;
	
	static double EPS = 1e-9;
	
	public static void main(String[] args) throws Exception{
		Scanner reader = new Scanner(System.in);
//		chk = new Scanner(new File("c_small.out"));
		out = new PrintWriter(new File("c_large.out"));
		
		int times = reader.nextInt();
		for(int t = 1; t <= times; t++){
			int n = reader.nextInt();
			
			Point[] p = new Point[n];
			for(int i = 0; i < n; i++)
				p[i] = new Point(reader.nextInt(), reader.nextInt());
			
			int[] sol = new int[n];
//			for(int i = 0; i < n; i++){
//				int cnt = n;
//				for(int j = 0; j < n; j++){
//					if(i == j) continue;
//					int above = 0;
//					int below = 0;
//					for(int k = 0; k < n; k++){
//						if(p[k].sub(p[i]).cross(p[j].sub(p[i])) > EPS)
//							above++;
//						else if(p[k].sub(p[i]).cross(p[j].sub(p[i])) < -EPS)
//							below++;
//					}
//					cnt = Math.min(cnt, Math.min(above, below));
//				}
//				sol[i] = cnt;
//			}
			
		/*
1
5
0 0
10 0
10 10
0 10
5 5
		 */
			
			if(n == 1) sol[0] = 0;
			else{
				for(int k = 0; k < n; k++){
					Angle[] angs = getAngles(k, p);
					TreeMap<Angle, Integer> f = new TreeMap<Angle, Integer>();
					TreeSet<Angle> events = new TreeSet<Angle>();
					
					int above = 0;
					int below = 0;
					
					for(int i = 0; i < angs.length; i++){
//						System.out.println(angs[i].t + " " + (angs[i].t > EPS && angs[i].t < Math.PI - EPS));
						
						if(!f.containsKey(angs[i]))
							f.put(angs[i], 0);
						f.put(angs[i], f.get(angs[i]) + 1);

						events.add(angs[i]);
						events.add(angs[i].opp());
						
						if(angs[i].t >= -EPS && angs[i].t < Math.PI - EPS)
							above ++;
						if(angs[i].t >= Math.PI - EPS && angs[i].t < 2*Math.PI - EPS)
							below ++;
					}
					
					events.add(new Angle(0));
					events.add(new Angle(Math.PI));
					
					int best = n-1;
					int headCnt = 0;
					int tailCnt = 0;
					
//					System.out.println(above + " " + below);
					
					for(Angle e : events){
						above += tailCnt;
						below += headCnt;
						headCnt = get(e, f);
						tailCnt = get(e.opp(), f);
						above -= headCnt;
						below -= tailCnt;
						
						best = Math.min(best, Math.min(above, below));
//						System.out.println(headCnt + " " + tailCnt + " " + above + " " + below);
					}
					
					sol[k] = best;
				}
			}
			
			print("Case #"+t+":");
			for(int i = 0; i < n; i++)
				print(sol[i]+"");
		}
		
		out.close();
	}
	
	public static void print(String msg){
//		String sample = chk.nextLine();
//		if(!sample.equals(msg)){
//			System.err.println("=================OH NO");
//			System.exit(0);
//		}
		out.println(msg);
//		System.out.println(msg);
	}
	
	public static int get(Angle a, TreeMap<Angle, Integer> map){
		if(!map.containsKey(a))
			return 0;
		return map.get(a);
	}
	
	public static Angle[] getAngles(int s, Point[] p){
		Angle[] ret = new Angle[p.length-1];
		int at = 0;
		for(int i = 0; i < p.length; i++){
			if(i == s) continue;
			ret[at++] = new Angle(p[i].sub(p[s]).ang());
		}
		return ret;
	}
	
	public static class Angle implements Comparable<Angle>{
		double t;
		public Angle(double _t){
			t = _t;
		}
		public Angle opp(){
			return new Angle((t + Math.PI) % (2 * Math.PI));
		}
		public int compareTo(Angle a){
			double d = Math.abs(t-a.t);
			if(Math.min(d, 2*Math.PI-d) < EPS)
				return 0;
			return Double.compare(t, a.t);
		}
	}
	
	public static class Point implements Comparable<Point>{
		double x,y;
		public Point(double _x, double _y){
			x = _x; y = _y;
		}
		public Point sub(Point p){
			return new Point(x-p.x, y-p.y);
		}
		public Point add(Point p){
			return new Point(x+p.x, y+p.y);
		}
		public Point scale(double s){
			return new Point(x*s, y*s);
		}
		public Point rot(double t){ //Rotate t radians counter-clockwise
			double c = Math.cos(t);
			double s = Math.sin(t);	
			return new Point(x*c-y*s, x*s+y*c);
		}
		public Point orthoCCW(){ //Rotate 90 degrees counter-clockwise
			return new Point(-y, x);
		}
		public Point orthoCW(){ //Rotate 90 degrees clockwise
			return new Point(y, -x);
		}
		public Point norm(){ //Return a vector with same angle and magnitude 1
			return new Point(x/mag(), y/mag());
		}
		public Point project(Point p){ //Return projection of this onto p
			return p.scale(dot(p)/p.dot(p));
		}
		public double dot(Point p){
			return x*p.x + y*p.y;
		}
		public double cross(Point p){
			return x*p.y-y*p.x;
		}
		public double mag(){
			return Math.sqrt(x*x + y*y);
		}
		public double dis(Point p){
			return sub(p).mag();
		}
		public double ang(){
			return (Math.atan2(y,x) + 2*Math.PI)%(2*Math.PI);
		}
		public double angBetween(Point p){ //Returns inner angle between two vectors
			double d = Math.abs(ang()-p.ang());
			return Math.min(d, 2*Math.PI-d);
		}
		public int compareTo(Point p){
			if(Math.abs(x - p.x) > EPS)
				return Double.compare(x,p.x);
			if(Math.abs(y - p.y) > EPS)
				return Double.compare(y,p.y);
			return 0;
		}
		public String toString(){
			return "("+x+", "+y+")";
		}
	}
}
