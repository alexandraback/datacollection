import java.util.*;
public class b {
	public static int[] dx = {0, 1};
	public static int[] dy = {1, 0};
	public static void main(String[] args){
		Scanner br = new Scanner(System.in);
		
		int t = br.nextInt();
	
		for(int cc = 1;cc<=t;cc++){
			int r = br.nextInt();
			int c = br.nextInt();
			int n = br.nextInt();
			int ans = r*c*4;
			int max = (1<<(r*c));
			
			for(int i = 0;i<max;i++){
				if(Integer.bitCount(i) != n){
					continue;
				}
				
				int[][] filled = new int[r][c];
				for(int j = 0;j<r;j++){
					for(int k = 0;k<c;k++){
						int pos = j*c+k;
						if((i & (1<<pos)) > 0){
							filled[j][k] = 1;
						}
					}
				}
				int res = 0;
				for(int j = 0;j<r;j++){
					for(int k = 0;k<c;k++){
						if(filled[j][k] == 1){
							for(int l = 0;l<dx.length;l++){
								int nr = j+dx[l];
								int nc = k+dy[l];
								if(nr >= 0 && nr < r && nc >= 0 && nc < c && filled[nr][nc] == 1){
									res++;
								}
							}
						}
					}
				}
				ans = Math.min(ans, res);
			}
			System.out.println("Case #"+cc+": "+ans);
		}
	}
}
