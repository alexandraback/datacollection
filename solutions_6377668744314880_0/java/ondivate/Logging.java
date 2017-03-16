import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;


public class Logging {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		int T=Integer.parseInt(br.readLine());
		for(int cn=1;cn<=T;cn++){
			int N=Integer.parseInt(br.readLine());
			int x[]=new int[N];
			int y[]=new int[N];
			Point p[]=new Point[N];
			for(int i=0;i<N;i++){
				st=new StringTokenizer(br.readLine());
				x[i]=Integer.parseInt(st.nextToken());
				y[i]=Integer.parseInt(st.nextToken());
				p[i]=new Point(x[i],y[i]);
			}
			bw.append("Case #"+cn+":\n");
			for(int ni=0;ni<N;ni++){
				int min=N;
				for(int i=0;i<N;i++){
					for(int j=i+1;j<N;j++){
						int left=0, right=0;
						for(int k=0;k<N;k++){
							if(k==ni)
								continue;
							if(isLeft(p[i],p[j],p[k]))
								left++;
							if(isRight(p[i],p[j],p[k]))
								right++;
						}
						if(isLeft(p[i],p[j],p[ni]))
							min=Math.min(min, left);
						else if(isRight(p[i],p[j],p[ni]))
							min=Math.min(min, right);
						else
							min=Math.min(min, Math.min(left, right));
					}
				}
				bw.append(min+"\n");
			}
		}
		bw.flush();
	}
	static class Point{
		int x, y;
		public Point(int a, int b){
			x=a;
			y=b;
		}
	}
	static boolean isLeft(Point a, Point b, Point c){
	     return ((b.x - a.x)*(c.y - a.y) - (b.y - a.y)*(c.x - a.x)) > 0;
	}
	static boolean isRight(Point a, Point b, Point c){
	     return ((b.x - a.x)*(c.y - a.y) - (b.y - a.y)*(c.x - a.x)) < 0;
	}
}
