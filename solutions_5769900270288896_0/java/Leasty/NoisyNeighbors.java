package googlecodejam;

import java.util.Scanner;

/**
 *
 * @author Tom
 */
public class NoisyNeighbors {
    private int R;
    private int C;
    private int N;
    
    public static NoisyNeighbors[] readFile(Scanner input) {
        NoisyNeighbors[] puzzles = new NoisyNeighbors[input.nextInt()];
        for(int i = 0; i < puzzles.length; ++i) {          
            puzzles[i] = new NoisyNeighbors(input.nextInt(), input.nextInt(), input.nextInt());
        }
        
        return puzzles;
    }
    
    public NoisyNeighbors(int R, int C, int N) {
        this.R = R;
        this.C = C;
        this.N = N;
    }

    public String solve() {
        int result = Integer.MAX_VALUE;        
        
        int[] powers = new int[(R * C) + 1];
        powers[0] = 1;
        for(int i = 1; i < powers.length; ++i) {
            powers[i] = 2 * powers[i - 1];            
        }
        
        for(int i = 0; i < powers[R * C]; ++i) {
            int count = 0;
            boolean[][] grid = new boolean[R][C];            
            int temp = i;
            for(int j = 0; j < R; ++j) {
                for(int k = 0; k < C; ++k) {
                    if(temp%2 == 1) {
                        ++count;
                        grid[j][k] = true;                        
                    }
                    
                    temp /= 2;
                }
            }
            
            if(count == N) {
                int unhappy = 0;
                for(int j = 0; j < R; ++j) {
                    for(int k = 0; k < C; ++k) {
                        if(grid[j][k]) {
                            if(j + 1 < R && grid[j + 1][k]) {
                                ++unhappy;
                            }
                            
                            if(k + 1 < C && grid[j][k + 1]) {
                                ++unhappy;
                            }
                        }
                    }
                }
                
                result = Math.min(result, unhappy);
            }
        }        
        
        return "" + result;
    }    
}
