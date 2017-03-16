import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;


public class Haircut {

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
			st=new StringTokenizer(br.readLine());
			int B=Integer.parseInt(st.nextToken());
			int N=Integer.parseInt(st.nextToken());
			st=new StringTokenizer(br.readLine());
			int m[]=new int[B];
			int LCM=1;
			for(int i=0;i<B;i++){
				m[i]=Integer.parseInt(st.nextToken());
				LCM*=m[i];
			}
			int lim=0;
			for(int i=0;i<B;i++){
				lim+=LCM/m[i];
			}
			int a[]=new int[lim];
			int left[]=new int[B];
			for(int i=0;i<lim;i++){
				int min=Integer.MAX_VALUE;
				for(int j=0;j<B;j++){
					min=Math.min(min, left[j]);
				}
				for(int j=0;j<B;j++){
					left[j]-=min;
				}
				for(int j=0;j<B;j++){
					if(left[j]==0){
						a[i]=j+1;
						left[j]=m[j];
						break;
					}
				}
			}
//			System.out.println(lim);
//			System.out.println(Arrays.toString(a));
			int ans=a[(N-1)%lim];
			bw.append("Case #"+cn+": "+ans+"\n");
		}
		bw.flush();
	}
	static int gcd(int a, int b){
		if(b==0)
			return a;
		else
			return gcd(b, a%b);
	}
}
