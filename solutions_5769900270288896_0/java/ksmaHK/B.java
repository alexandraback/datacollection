import java.util.*;

public class B {
public static void main(String [] args) {
	Scanner scanner = new Scanner(System.in);
	int nCase = scanner.nextInt();
	
	for (int nc = 1; nc <= nCase; nc++) {
		int R = scanner.nextInt();
		int C = scanner.nextInt();
		int N = scanner.nextInt();
		int fullN = R*C;
		
		boolean[][] has = new boolean[R][C];
		int ans = fullN*4;
		for (int m = 0; m < (1 << fullN); m++) {
			if (Integer.bitCount(m) == N) {
				for (int i = 0; i < R; i++)
				for (int j = 0; j < C; j++)
					if (((1 << (i*C + j)) & m) > 0)
						has[i][j] = true;
					else 
						has[i][j] = false;
				int cnt = 0;
				for (int i = 0; i < R; i++)
				for (int j = 0; j < C-1; j++)
					if (has[i][j] && has[i][j+1])
						cnt++;
				
				for (int i = 0; i < R-1; i++)
				for (int j = 0; j < C; j++)
					if (has[i][j] && has[i+1][j])
						cnt++;
				if (cnt < ans)
					ans = cnt;
			}
			
		}
		
		System.out.println("Case #" + nc + ": " + ans);
	}
}
}