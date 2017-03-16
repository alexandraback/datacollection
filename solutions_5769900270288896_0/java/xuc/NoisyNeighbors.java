package NoisyNeighbors;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Created by xuchen on 5/2/15.
 */
public class NoisyNeighbors {

    public static int countHappyValue(boolean[][] grid, int R, int C){
        int cnt = 0;

        for (int i = 0; i < R; i++){
            for (int j = 0; j < C; j++){
                //only check left and right
                if (grid[i][j]){

                    if (j+1 < C){
                        if (grid[i][j+1]) cnt++;
                    }

                    if (i+1 < R){
                        if (grid[i+1][j]) cnt++;
                    }

                }

            }
        }

        return cnt;
    }

    public static boolean[][] generateGrid(int R, int C, int J){

        boolean[][] grid = new boolean[R][C];

        for (int i = 0; i < R*C; i++){

            int row = i/C;
            int col = i%C;

            if ((J & 1) == 1){
                grid[row][col] = true;
            }

            J >>= 1;

        }

        return grid;
    }

    public static void main(String[] args) {
        try {
            Scanner scanner = new Scanner(new File("src/NoisyNeighbors/B-small-attempt0.in"));
            PrintWriter writer = new PrintWriter(new File("src/NoisyNeighbors/result.txt"));

            int caseCnt = scanner.nextInt();

            for (int i = 0; i < caseCnt; i++){

                int R = scanner.nextInt();
                int C = scanner.nextInt();
                int num = scanner.nextInt();
                boolean[][] grid = null;

                int happyValue = Integer.MAX_VALUE;

                for (int j = 0; j < Math.pow(2,R*C); j++){

                    int oneCnt = 0;
                    int copyJ = j;

                    while (copyJ != 0){
                        if ((copyJ & 1) == 1) oneCnt++;
                        copyJ>>=1;
                    }

                    if (oneCnt == num){

                        grid = generateGrid(R,C,j);

                        happyValue = Math.min(happyValue,countHappyValue(grid,R,C));

                    }


                }


                writer.println("Case #" + (i + 1) + ": " + happyValue);
            }

            writer.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

}
