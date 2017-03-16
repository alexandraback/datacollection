import java.util.*;
import java.io.*;
import java.math.*;

public class B {
    static Scanner in = new Scanner(System.in);
    
    static PrintStream out = System.out;
    
    static int ans;
    
    static int[] di = {-1, 0, 1, 0};
    
    static int[] dj = {0, 1, 0, -1};
    
    static void backtrack(boolean[][] M, int R, int C, int room, int N, int occupied){
        int r = room / C;
        int c = room % C;
        
        //out.println(String.format("r: %d, c: %d", r, c));
        
        if (r == R){
            int edges = 0;
            
            for (int i = 0; i < R; i++){
                for (int j = 0; j < C; j++){
                    for (int k = 0; k < 4; k++){
                        int I = i + di[k];
                        int J = j + dj[k];
                        
                        if (I >= 0 && I < R && J >= 0 && J < C){
                            if (M[i][j] && M[I][J]){
                                edges++;
                            }
                        }
                    }
                }
            }
            
            edges /= 2;
            
            if (occupied == N){
                ans = Math.min(ans, edges);
            }
        }
        else {
            if (occupied < N){
                M[r][c] = true;
                backtrack(M, R, C, room + 1, N, occupied + 1);
            }
            
            M[r][c] = false;
            backtrack(M, R, C, room + 1, N, occupied);
        }
    }
    
    public static void main(String[] args) {
        int T = in.nextInt();
        
        for (int t = 1; t <= T; t++){
            int R = in.nextInt();
            int C = in.nextInt();
            int N = in.nextInt();
            
            //out.println(String.format("R: %d, C: %d", R, C));
            
            boolean[][] M = new boolean[R][C];

            ans = Integer.MAX_VALUE;
            backtrack(M, R, C, 0, N, 0);
            
            out.println(String.format("Case #%d: %d", t, ans));
        }
    }
}
