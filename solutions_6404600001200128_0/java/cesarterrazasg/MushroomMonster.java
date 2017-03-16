package v2015.round1a;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

/**
 * Created by cesarterrazas on 17/04/15.
 */
public class MushroomMonster {
    public static void main(String[] args) throws IOException {
        final String INPUT_FILE = "src/v2015/round1a/A-small.in";
        final String OUTPUT_FILE = "src/v2015/round1a/A-small.out";
        final Scanner scanner = new Scanner(new File(INPUT_FILE));
        final FileWriter fw = new FileWriter(new File(OUTPUT_FILE));
        try {
            StringBuilder stringBuilder = new StringBuilder();
            int t = scanner.nextInt();
            for (int i = 1; i <= t; i++) {
                int n = scanner.nextInt();
                int[] numberOfMushrooms = new int[n];
                for (int j = 0; j < n; j++) {
                    numberOfMushrooms[j] = scanner.nextInt();
                }
                stringBuilder.append(String.format("Case #%d: %d %d\n", i, getOutputMethod1(numberOfMushrooms), getOutputMethod2(numberOfMushrooms)));
            }
            fw.write(stringBuilder.toString());
        } finally {
            fw.close();
            scanner.close();
        }
    }

    private static int getOutputMethod1(int[] numberOfMushrooms) {
        int minMushroomsEaten = 0;
        for (int i = 0; i < numberOfMushrooms.length - 1; i++) {
            if (numberOfMushrooms[i] > numberOfMushrooms[i + 1]) {
                minMushroomsEaten += numberOfMushrooms[i] - numberOfMushrooms[i + 1];
            }
        }
        return minMushroomsEaten;
    }

    private static int getOutputMethod2(int[] numberOfMushrooms) {
        int minMushroomsEaten = 0;
        int rate = 0;
        for (int i = 0; i < numberOfMushrooms.length - 1; i++) {
            if (numberOfMushrooms[i] > numberOfMushrooms[i + 1]) {
                int possibleRate = numberOfMushrooms[i] - numberOfMushrooms[i + 1];
                if (possibleRate >= 0 && possibleRate > rate)
                    rate = possibleRate;
            }
        }
        for (int i = 0; i < numberOfMushrooms.length - 1; i++) {
            if (numberOfMushrooms[i]  > rate) {
                minMushroomsEaten += rate;
            } else {
                minMushroomsEaten += numberOfMushrooms[i];
            }
        }
        return minMushroomsEaten;
    }
}
