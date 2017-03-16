import java.io.BufferedReader;
import java.io.InputStreamReader;


public class B {

	public static void main(String[] args) throws Exception{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(in.readLine());
		for (int cas = 1; cas <=T; cas++) {
			String[] spl = in.readLine().split(" ");
			int R = Integer.parseInt(spl[0]);
			int C = Integer.parseInt(spl[1]);
			int N = Integer.parseInt(spl[2]);
			int max = (1<<(R*C));
			int ans = Integer.MAX_VALUE;
			for (int i = 0; i < max; i++) {
				int v = i;
				int cnt = 0;
				while(v>0)
				{
					if(v%2==1)
						cnt++;
					v/=2;
				}
				if(cnt!=N)
					continue;
				int[][] mat = new int[R][C];
				for (int j = 0; j < R; j++) {
					for (int k = 0; k < C; k++) {
						mat[j][k] = (i & (1 << (j + R*k) ))!=0? 1: 0;
					}
				}
				int numW = 0;
				for (int j = 0; j < R; j++) {
					for (int k = 0; k < C; k++) {
						if(mat[j][k]==1)
						{
							if(j>0 && mat[j-1][k]==1)
								numW++;
							if(j<R-1 && mat[j+1][k]==1)
								numW++;
							if(k>0 && mat[j][k-1]==1)
								numW++;
							if(k<C-1 && mat[j][k+1]==1)
								numW++;
						}
					}
				}
				numW/=2;
				ans = Math.min(ans, numW);
			}
			System.out.println("Case #"+cas+": "+ans);
		}

	}

	

}
