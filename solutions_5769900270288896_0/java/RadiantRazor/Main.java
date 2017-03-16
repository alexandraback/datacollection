package ramanvesh.codejam._2_1B_2015;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.stream.IntStream;

/**
 * Created by ram.kasam on 11/04/15.
 */
public class Main {

    public static void main(String[] args) {
        File testCaseFile = new File("2_1B_2015/testcase.txt");
        try (Scanner scanner = new Scanner(testCaseFile)) {
            String line = getNextLine(scanner);
            int noOfTasks = Integer.parseInt(line.trim());

            IntStream.range(1, noOfTasks + 1)
                    .forEach(testCaseNumber -> {
                        String[] split = getNextLine(scanner).split("\\s+");
                        int R = Integer.parseInt(split[0]);
                        int C = Integer.parseInt(split[1]);
                        int N = Integer.parseInt(split[2]);
                        int unhappiness = 0;
                        int numOfCells = R * C;
                        if(numOfCells%2 == 0 && N <= numOfCells/2){

                        } else if(numOfCells%2 == 1 && N <= (numOfCells/2) + 1){

                        } else {
                            boolean[][] apartment =  new boolean[R][C];
                            int[][] cost = new int[R][C];
                            int count = 0;
                            int fours = 0;
                            int threes = 0;
                            int twos = 0;
                            for(int r = 0; r < R; r++){
                                for(int c = 0; c < C; c++){
                                    if(r%2 == 0){
                                        if(c%2 == 0){
                                            apartment[r][c] = true;
                                            count++;
                                        } else {
                                            if((r == 0 || r == R-1) && (c == 0 || c == C -1)){
                                                cost[r][c] = 2;
                                                twos++;
                                            } else if ((r == 0 || r == R-1) || (c == 0 || c == C -1)){
                                                cost[r][c] = 3;
                                                threes++;
                                            } else {
                                                cost[r][c] = 4;
                                                fours++;
                                            }
                                        }
                                    } else {
                                        if(c%2 == 1){
                                            apartment[r][c] = true;
                                            count++;
                                        } else {
                                            if((r == 0 || r == R-1) && (c == 0 || c == C -1)){
                                                twos++;
                                                cost[r][c] = 2;
                                            } else if ((r == 0 || r == R-1) || (c == 0 || c == C -1)){
                                                cost[r][c] = 3;
                                                threes++;
                                            } else {
                                                cost[r][c] = 4;
                                                fours++;
                                            }
                                        }
                                    }
                                }
                            }
                            boolean foursPossible = R > 2 && C > 2;
                            int left = N - count;
                            if ( twos >= left){
                                unhappiness += left * 2;
                            } else {
                                unhappiness += twos * 2;
                                left -= twos;
                                if(threes >= left){
                                    if(threes == left + 1 && foursPossible && fours == 0){
                                        unhappiness += threes*2;
                                    } else {
                                        unhappiness += left * 3;
                                    }
                                } else {
                                    unhappiness += threes * 3;
                                    left -= threes;
                                    unhappiness += fours*4;
                                }
                            }
                        }
                        System.out.println("Case #"+testCaseNumber+": " + unhappiness);
                    });
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    private static long printTime(String message, long time) {
//        long newTime = System.nanoTime();
//        System.out.println(message + (newTime -time));
//        return newTime;
        return 0;
    }

    private static String getNextLine(Scanner scanner) {
        String nextLine;
        do {
            nextLine = scanner.nextLine().trim();
        } while (nextLine.startsWith("//"));
        return nextLine;
    }
}
