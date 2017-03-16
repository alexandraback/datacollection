import java.io.InputStreamReader;
import java.util.Scanner;
 
public class Main {
	public static void main(String[] args) {
		try(Scanner scan = new Scanner(new InputStreamReader(System.in))){
			int T = scan.nextInt();
			
			for(int i = 1; i<=T; i++){
				int R = scan.nextInt();
				int C = scan.nextInt();
				int N = scan.nextInt();
				solve(i, R, C, N);
			}
			
		}
	}
	
	private static void solve(final int testNum, final int R, final int C, final int N){
		int ans = Integer.MAX_VALUE;
		int lim = 1 << (R*C);
		
		for(int set = 0; set <= lim; set++){
			if(numOfElmnt(set) != N) {continue;}
			
			int tmp = countUnhappy(R,C,set);
			if(ans > tmp){
				ans = tmp;
			}
		}
		
		System.out.println("Case #" + testNum + ": " + ans);
	}
	
	private static int countUnhappy(int R, int C, int set) {
		int ans = 0;
		for(int i = 0; i<R; i++){
			for(int j = 0; j<C; j++){
				if(isTrue(i, j, R, C, set)){
					if(i+1<R && isTrue(i+1, j, R, C, set)) ans++;
					if(j+1<C && isTrue(i, j+1, R, C, set)) ans++;
				}
			}
		}
		return ans;
	}
	
	private static boolean isTrue(int r, int c, int R, int C, int set){
		boolean ans = ((set & (1 << (C*r+c))) >= 1); 
		return ans;
	}

	private static int numOfElmnt(int set){
		int ans = 0;
		while(set>0){
			if((set & 1) == 1){
				ans++;
			}
			set >>= 1;
		}
		return ans;
	}
	
}
