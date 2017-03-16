import java.util.*;
public class bb {
	public static int[] dx = {0, 1, 0, -1};
	public static int[] dy = {1, 0, -1, 0};
	public static int rr, rc;
	public static void main(String[] args){
		Scanner br = new Scanner(System.in);
		
		int t = br.nextInt();
	
		for(int cc = 1;cc<=t;cc++){
			int r = br.nextInt();
			int c = br.nextInt();
			rr = r;
			rc = c;
			int n = br.nextInt();
			int sub = r*c-n;
			int ans1 = 0;
			int ans2 = 0;
			int[][] filled = new int[r][c];
			
			//Checkerboard 1
			int put = 0;
			for(int i = 0;i<r;i++){
				for(int j = 0;j<c;j++){
					if((i+j)%2 == 0){
						filled[i][j] = 1;
						put++;
					}
				}
			}
			PriorityQueue<Integer> qu = new PriorityQueue<Integer>();
			for(int i = 0;i<r;i++){
				for(int j = 0;j<c;j++){
					if(filled[i][j] == 0){
						int res = 0;
						for(int k = 0;k<dx.length;k++){
							int nr = i+dx[k];
							int nc = j+dy[k];
							if(nr >= 0 && nc >= 0 && nr < r && nc < c && filled[nr][nc] == 1){
								res++;
							}
						}
						qu.add(res);
					}
				}
			}
			while(put < n){
				put++;
				ans1+=qu.poll();
			}
			
			
			//Checkerboard 2
			filled = new int[r][c];
			put = 0;
			for(int i = 0;i<r;i++){
				for(int j = 0;j<c;j++){
					if((i+j)%2 == 1){
						filled[i][j] = 1;
						put++;
					}
				}
			}
			qu = new PriorityQueue<Integer>();
			for(int i = 0;i<r;i++){
				for(int j = 0;j<c;j++){
					if(filled[i][j] == 0){
						int res = 0;
						for(int k = 0;k<dx.length;k++){
							int nr = i+dx[k];
							int nc = j+dy[k];
							if(nr >= 0 && nc >= 0 && nr < r && nc < c && filled[nr][nc] == 1){
								res++;
							}
						}
						qu.add(res);
					}
				}
			}
			while(put < n){
				put++;
				ans2+=qu.poll();
			}
			
			
			System.out.println("Case #"+cc+": "+Math.min(ans1, ans2));
		}
	}
	public static class Cell implements Comparable<Cell>{
		int r, c;
		boolean alive;
		int save;
		
		public Cell(int a, int b, boolean d){
			r = a;
			c = b;
			alive = d;
			save = 0;
			for(int k = 0;k<dx.length;k++){
				int nr = r+dx[k];
				int nc = c+dy[k];
				if(nr >= 0 && nr < rr && nc >= 0 && nc < rc){
					save++;
				}
			}
		}
		
		public int compareTo(Cell o){
			if(save == o.save){
				if(r == o.r){
					return c-o.c;
				}
				return r-o.r;
			}
			return o.save-save;
		}
		
	}
}
