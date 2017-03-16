package Haircut;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Created by xuchen on 4/17/15.
 */
public class Haircut {

    public static int gcd(int a, int b) {

        if (b == 0) return a;
        return gcd(b, a % b);

    }

    public static void main(String[] args) {

        try {

            Scanner scanner = new Scanner(new File("src/Haircut/B-small-attempt2.in"));
            PrintWriter writer = new PrintWriter(new File("src/Haircut/result.txt"));

            int caseCnt = scanner.nextInt();

            for (int i = 0; i < caseCnt; i++){

                int barberCnt = scanner.nextInt();
                int N = scanner.nextInt();

                int[] barbers = new int[barberCnt];
                int[] M = new int[barberCnt];
                int LCM = scanner.nextInt();
                M[0] = LCM;

                for (int j = 1; j < barberCnt; j++){
                    M[j] = scanner.nextInt();
                    LCM = LCM * M[j] / gcd(LCM, M[j]);
                }

                int peopleInBrick = 0;

                for (int j = 0; j < barberCnt; j++) {
                    peopleInBrick += LCM / M[j];
                }

                N = N % peopleInBrick;

                if (N == 0) N += peopleInBrick;

                int minIndex = 0;

                for (int j = 0; j < N; j++) {

                    minIndex = 0;
                    int min = Integer.MAX_VALUE;

                    for (int k = 0; k < barberCnt; k++) {
                        if (barbers[k] < min) {
                            min = barbers[k];
                            minIndex = k;
                        }
                    }

                    barbers[minIndex] += M[minIndex];
                }

                writer.println("Case #" + (i + 1) + ": " + (minIndex + 1));

            }

            writer.close();
        }catch (FileNotFoundException e){
            e.printStackTrace();
        }

    }
}
