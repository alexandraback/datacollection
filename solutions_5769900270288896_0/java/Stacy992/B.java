import java.util.*;
public class B {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		for(int z = 1; z <= t; z++){
			n = in.nextInt();
			m = in.nextInt();
			memo = new int[1<<(n*m+1)];
			k = in.nextInt();
			Arrays.fill(memo, -1);
			System.out.println("Case #" + z + ": " + go(0));
		}
	}
	static int[] memo;
	static int k;
	static int n;
	static int m;
	public static int go (int mask){
		if(Integer.bitCount(mask) == k){
			return getAns(mask);
		}
		if(memo[mask] != -1)
			return memo[mask];
		int ans = 987654321;
		for(int i = 0; i < n*m; i ++){
			if((mask & (1<<i)) == 0){
				 ans = Math.min(ans, go(mask | (1<<i)));
			}
		}
		return memo[mask] = ans;
	}
	public static int getAns(int mask){
		int ans = 0;
		for(int i = 1; i < n; i ++){
			for(int j = 0; j < m; j ++){
				if(getBit(mask, i, j) && getBit(mask, i - 1, j))
					ans++;
			}
		}
		for(int i = 0; i < n; i ++){
			for(int j = 1; j < m; j ++){
				if(getBit(mask, i, j) && getBit(mask, i, j - 1))
					ans++;
			}
		}
		return ans;
	}
	
	public static boolean getBit(int mask, int i, int j){
		return (mask & (1 << (i * m + j))) > 0;
	}
}
