import java.util.*;
import java.io.*;
//code by cl3488
public class noise {
	public static void main(String[] args) throws IOException{
		BufferedReader f = new BufferedReader(new FileReader("noise.in"));
		PrintWriter out = new PrintWriter(new FileWriter("noise.out"));
		int T = Integer.parseInt(f.readLine());
		for(int tc=1;tc<=T;tc++){
			out.print("Case #" + tc + ": ");
			StringTokenizer st = new StringTokenizer(f.readLine());
			int R = Integer.parseInt(st.nextToken());
			int C = Integer.parseInt(st.nextToken());
			int tenants = Integer.parseInt(st.nextToken());
			int N = R * C;
			System.out.println(R + "      " + C + "       " + tenants);
			int ans = Integer.MAX_VALUE;
			for(int s = 0; s < (1<<N); s++){
				int num = 0;
				for(int i=0;i<N;i++){
					if((s & (1<<i))!=0){
						num++;
					}
				}
				if(num != tenants){
					continue;
				}
				int here = 0;
				for(int i=0;i<R;i++){
					for(int j=0;j<C-1;j++){
						int one = i * C + j;
						int two = i * C + j + 1;
						if((s & (1<<one)) != 0 && (s & (1<<two)) != 0){
							here++;
						}
					}
				}
				for(int j=0;j<C;j++){
					for(int i=0;i<R-1;i++){
						int one = i * C + j;
						int two = (i+1) * C + j;
						if((s & (1<<one)) != 0 && (s & (1<<two)) != 0){
							here++;
						}
					}
				}
				ans = Math.min(ans, here);
			}
			out.println(ans);
		}
		out.close();
	}
}
