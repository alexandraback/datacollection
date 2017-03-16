import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Comparator;
import java.util.Scanner;

public class cLogging {
	static final double EPS = 1e-10;
	static final double INF = 1 << 31;
	static final double PI = Math.PI;

	public static BufferedReader in;
	public static PrintWriter out;

	StringBuilder sb = new StringBuilder();


	public void run() throws IOException {
		in =new BufferedReader(new FileReader("in.txt"));
		out=new PrintWriter(new FileWriter("out.txt"));
		
		Scanner sc = new Scanner(in);
		StringBuilder sb = new StringBuilder();
		int T = sc.nextInt();
		
		for (int t=1; t<=T; t++){
			int n = sc.nextInt();
			P[] tree = new P[n];
			for (int i=0; i<n; i++)
				tree[i] = new P (sc.nextInt(),sc.nextInt());
			int [] min = new int[n];
			for (int i=0; i<n; i++)
				min[i]=n;
			for (int i=0; i<n-1; i++)
				for (int j=i+1; j<n; j++){
					int cc=0,ccw=0;
					for (int k=0; k<n; k++){
						int res = P.ccw(tree[i], tree[j], tree[k]);
						if (res==-1) ccw++;
						if (res==1) cc++;
					}
					int cMin =Math.min(ccw, cc);
					min[i] = Math.min(min[i], cMin);
					min[j] = Math.min(min[j], cMin);
				}
					
			sb.append("Case #" + t + ":\n");
			for (int i=0; i<n; i++)
				sb.append(min[i] + "\n");
		}
		ln(sb);
		sc.close();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new cLogging().run();
	}
	public static void ln(Object obj) {
		out.print(obj);
	}
	static class P{
		//geo
			static final double EPS=1e-10;
			static final double INF = 1<<31;
			static final double PI = Math.PI;
			static int signum(double x){
				return x<-EPS?-1:x>EPS?1:0;
			}
		static Comparator<P> comp=new Comparator<P>(){
			public int compare(P p1, P p2) {
				return signum(p1.x-p2.x)!=0?signum(p1.x-p2.x):signum(p1.y-p2.y);
			}
		};
		public static  final P O=new P(0,0);
		final double x,y;
		P(double _x,double _y){
			x=_x;y=_y;
		}
		//四則
		P add(P a){
			return new P(x+a.x,y+a.y);
		}
		P sub(P a){
			return new P(x-a.x,y-a.y);
		}
		P mul(P a){
			return new P(x*a.x-y*a.y,x*a.y+y*a.x);
		}
		P div(P a){
			double d2=a.dist2(O);
			return new P(dot(a,this)/d2,cross(a,this)/d2);
		}
		//共役
		P conj(){
			return new P(x,-y);
		}
		//内積　a・b=|a||b|cosθ=a.x*b.x+a.y*b.y
		static double dot(P a,P b){
			return  a.x*b.x+a.y*b.y;
		}
		//外積　a×b=|a||b|sinθ=a.x*b.y-a.y*b.x
		static double cross(P a,P b){
			return  a.x*b.y-a.y*b.x;
		}
		//二乗距離
		double dist2(P p){
			return (x-p.x)*(x-p.x)+(y-p.y)*(y-p.y);
		}
		//a,b間の距離
		double dist(P p){
			return Math.sqrt(dist2(p));
		}
		public double norm(){
			return dist(O);
		}
		// a→b→cと進むときの向き
		static int ccw(P a,P b,P c){
			b=b.sub(a);c=c.sub(a);
			if(cross(b,c)>EPS)return 1;//counter clockwise
			if(cross(b,c)<-EPS)return -1;//clockwise
			if(dot(b,c)<-EPS)return 2;//c--a--b on line
			if(b.norm()<c.norm()-EPS)return -2;//a--b--c on line
			return 0;//a--c--b on line (or b==c)
		}
	}
}
