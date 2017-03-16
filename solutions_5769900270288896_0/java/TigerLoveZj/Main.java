import java.util.Scanner;


public class Main {
	static int ans;
	static int r;
	static int c;
	static int n;
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in); 
		int T=sc.nextInt();
		for (int t=1;t<=T;t++){
			r=sc.nextInt();
			c=sc.nextInt();
			n=sc.nextInt();
			if (n<=1){
				System.out.println("Case #"+t+": "+0);
				continue;
			}
			boolean[][] map=new boolean[r][c];	
			ans=1000000;
			dfs(map,0,0,0);
			System.out.println("Case #"+t+": "+ans);
		}
	}

	private static void dfs(boolean[][] map, int x, int y, int now) {
		if (x==r){
			if (now<n){
				return;
			}
			int temp=0;
			for (int i=0;i<r;i++){
				for (int j=1;j<c;j++){
					if (map[i][j]&&map[i][j-1]){
						temp++;
					}
				}
			}
			for (int i=1;i<r;i++){
				for (int j=0;j<c;j++){
					if (map[i][j]&&map[i-1][j]){
						temp++;
					}
				}
			}
			if (temp<ans){
				ans=temp;
			}
			return;
		}
		if (now==n){
			if (y==c-1){
				dfs(map,x+1,0,now);
			}else{
				dfs(map,x,y+1,now);
			}
		}else{
			if (y==c-1){
				dfs(map,x+1,0,now);
			}else{
				dfs(map,x,y+1,now);
			}
			map[x][y]=true;
			if (y==c-1){
				dfs(map,x+1,0,now+1);
			}else{
				dfs(map,x,y+1,now+1);
			}
			map[x][y]=false;
		}
	}
}
