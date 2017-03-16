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
        
        /*int[] powers = new int[(R * C) + 1];
        powers[0] = 1;
        for(int i = 1; i < powers.length; ++i) {
            powers[i] = 2 * powers[i - 1];            
        }
        
        int best = -1;
        
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
                
                if(unhappy < result) {
                    result = unhappy;
                    best = i;
                }
            }
        }*/
        
        /*System.out.println(R + " " + C + " " + N);
        
        int temp = best;
        for(int j = 0; j < R; ++j) {
            for(int k = 0; k < C; ++k) {
                if(temp%2 == 1) {
                    System.out.print('1');
                } else {
                    System.out.print('0');
                }

                temp /= 2;
            }
            
            System.out.println();
        }*/
        
        if(R < C) {
            int temp = R;
            R = C;
            C = temp;
        }
        
        int A = R * C;
        int alt = 0;
        if(C == 1) {
            if(A%2 == 0) {
                if(N <= A/2) {
                    //nothing
                } else {
                    int remain = N - A/2;
                    alt++;
                    remain--;
                    
                    alt += remain * 2;
                }
            } else {
                if(N <= A/2 + 1) {
                    //nothing
                } else {
                    alt += 2 * (N - (A/2 + 1));
                }
            }
        } else if(A%2 == 0) {
            if(N * 2 <= A) {
               //nothing
            } else {
                int remain = N - (A/2);

                if(remain == 1) {
                    alt += 2;
                    --remain;
                } else {
                    alt += 4;
                    remain -= 2;
                }
                
                if(remain < R + C - 4) {
                    alt += remain * 3;
                    remain = 0;
                } else {
                    alt += 3 * (R + C - 4);
                    remain -= (R + C - 4);
                }
                
                alt += 4 * remain;
            }
        } else {
            if(N <= A/2 + 1) {
               //nothing
            } else {
                int remain = N - (A/2 + 1);

                if(remain < (R/2) * 2 + (C/2) * 2) {
                    alt += remain * 3;
                    remain = 0;
                } else {
                    alt += 3 * ((R/2) * 2 + (C/2) * 2);
                    remain -= ((R/2) * 2 + (C/2) * 2);
                }

                alt += 4 * remain;
                
                int otherAlt = 0;                
                remain = N - (A/2);

                if(remain < 4) {
                    otherAlt += remain * 2;
                    remain = 0;
                } else {
                    otherAlt += 4 * 2;
                    remain -= 4;
                }

                if(remain < (R/2) * 2 + (C/2) * 2 - 4) {
                    otherAlt += remain * 3;
                    remain = 0;
                } else {
                    otherAlt += 3 * ((R/2) * 2 + (C/2) * 2 - 4);
                    remain -= ((R/2) * 2 + (C/2) * 2 - 4);
                }                
                
                otherAlt += 4 * remain;
                
                alt = Math.min(alt, otherAlt);
            }
        }
        
        /*if(A%2 == 0) {
            if(alt != result) {
                System.out.println(R + " " + C + " " + N);
                System.out.println(result + " " + alt);
            }
        } else if(A%2 == 1) {
            if(alt != result) {
                System.out.println(R + " " + C + " " + N);
                System.out.println(result + " " + alt);
            }
        }*/
        
        result = alt;
        
        return "" + result;
    }    
}
