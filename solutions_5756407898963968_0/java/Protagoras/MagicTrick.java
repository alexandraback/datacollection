import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

/**
 * Created by jouke on 4/12/14.
 */
public class MagicTrick {

    public static void main(String[] args) {
        try {
            Scanner scanner = new Scanner(new File("input/A-small-attempt0.in"));
            BufferedWriter outputWriter = new BufferedWriter(new FileWriter(new File("output/MagicTrickOutput")));

            int testCases = scanner.nextInt();

            for (int i = 0; i < testCases; i++) {
                String output = "Case #" + (i+1) + ": " + handleTestCase(scanner);
                System.out.println(output);
                outputWriter.write(output + "\n");
            }

            scanner.close();
            outputWriter.close();

        } catch (IOException e) {
            System.out.println("IOException !!!");
        }

    }

    public static String handleTestCase(Scanner scanner) {
        int answer1 = scanner.nextInt();
        int[] row1 = answerRow(answer1, scanner);

        int answer2 = scanner.nextInt();
        int[] row2 = answerRow(answer2, scanner);

        int matches = 0;
        int match = 0;
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                if (row1[j] == row2[k]) {
                    match = row1[j];
                    matches++;
                }
            }
        }

        switch (matches) {
            case 0:
                return "Volunteer cheated!";
            case 1:
                return String.valueOf(match);
            default:
                return "Bad magician!";
        }
    }
    public static int[] answerRow(int answer, Scanner scanner) {
        int[] poss = new int[4];

        for (int j = 0, k = 0; j < 16; j++) {
            if (j / 4 + 1 == answer) {
                poss[k++] = scanner.nextInt();
            } else {
                scanner.nextInt();
            }
        }

        return poss;
    }
}
