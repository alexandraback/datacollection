package gcj;

import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class MagicTrick {
    public static void main(String[] args) {
        try (InputStream is = MagicTrick.class.getResourceAsStream("/MagicTrick.txt");
             Scanner in = new Scanner(is);
             FileWriter fw = new FileWriter("C:\\Temp\\MagicTrick.txt");
             BufferedWriter bw = new BufferedWriter(fw)) {
            int numCases = in.nextInt();
            for (int i = 1; i <= numCases; i++) {
                int firstAnswer = in.nextInt();
                int[][] firstArrangement = readMatrix(in);
                int secondAnswer = in.nextInt();
                int[][] secondArrangement = readMatrix(in);
                int[] firstRow = firstArrangement[firstAnswer - 1];
                int[] secondRow = secondArrangement[secondAnswer - 1];
                List<Integer> intersection = calculateIntersection(firstRow, secondRow);
                if (intersection.size() == 1) {
                    bw.write("Case #" + i + ": " + intersection.get(0) + "\n");
                } else if (intersection.isEmpty()) {
                    bw.write("Case #" + i + ": Volunteer cheated!\n");
                } else {
                    bw.write("Case #" + i + ": Bad magician!\n");
                }
            }

        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    private static List<Integer> calculateIntersection(int[] firstRow, int[] secondRow) {
        List<Integer> intersection = new ArrayList<>();
        for (int i : firstRow) {
            for (int j : secondRow) {
                if (i == j) {
                    intersection.add(i);
                }
            }
        }
        return intersection;
    }

    private static int[][] readMatrix(Scanner in) {
        int[][] matrix = new int[4][4];
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                matrix[i][j] = in.nextInt();
            }
        }
        return matrix;
    }
}
