import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;


public class NoisyNeighbors {

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
			int R=Integer.parseInt(st.nextToken());
			int C=Integer.parseInt(st.nextToken());
			int N=Integer.parseInt(st.nextToken());
			int bs=0;
			int ans=Integer.MAX_VALUE;
			while(bs<(1<<(R*C))){
				if(Integer.bitCount(bs)!=N){
					bs++;
					continue;
				}
				//horizontal
				int unhappiness=0;
				for(int i=1;i<R;i++){
					for(int j=0;j<C;j++){
						int a=1<<(R*j+i);
						int b=1<<(R*j+i-1);
						if(((bs&a)!=0)&&((bs&b)!=0))
							unhappiness++;
					}
				}
				for(int i=0;i<R;i++){
					for(int j=1;j<C;j++){
						int a=1<<(R*j+i);
						int b=1<<(R*(j-1)+i);
						if(((bs&a)!=0)&&((bs&b)!=0))
							unhappiness++;
					}
				}
				ans=Math.min(ans, unhappiness);
				bs++;
			}
			bw.append("Case #"+cn+": "+ans+"\n");
		}
		bw.flush();
	}

}
