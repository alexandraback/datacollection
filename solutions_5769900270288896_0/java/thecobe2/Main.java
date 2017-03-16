import java.util.*;

public class Main {
	
	static long answ;
	static boolean grid[][];
	
	public static void main(String args[]){
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		
		int R, C, N;
		grid = new boolean[16][16];
		
		for(int z = 1; z <= T; z++){ 
			R = in.nextInt();
			C = in.nextInt();
			N = in.nextInt();
			answ = 1000000000l;
			for(int mask = 0; mask < (1 << (R*C)); mask++){
				if(Integer.bitCount(mask) != N)continue;
				answ = Math.min(answ, compute(mask, N, R, C));
			}
			
			System.out.println("Case #" + z + ": " + answ);
		}
	}
	
	static long compute(int mask, int N, int R, int C){
		int bit = 0;
		long count = 0;
		for(int i = 0; i < R; i++)
			for(int j = 0; j < C; j++){
				grid[i][j] = false;
				bit = 1 << (i * C + j);
				if((mask & bit) != 0){
					grid[i][j] = true;
					if(i - 1 >= 0 && grid[i-1][j])
						count++;
					if(j - 1 >= 0 && grid[i][j-1])
						count++;
				}
			}
		return count;
	}
	
	
	
	
}
