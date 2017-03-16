package gcj14.qualification;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class MagicTrick {
    void solve(Scanner scan) {
        int firstAns = scan.nextInt();
        firstAns--;
        int[][] firstGrid = new int[4][4];
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                firstGrid[i][j] = scan.nextInt();
            }
        }

        int secondAns = scan.nextInt();
        secondAns--;
        int[][] secondGrid = new int[4][4];
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                secondGrid[i][j] = scan.nextInt();
            }
        }

        List<Integer> candidates = new ArrayList<Integer>();
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (firstGrid[firstAns][i] == secondGrid[secondAns][j]) {
                    candidates.add(firstGrid[firstAns][i]);
                }
            }
        }

        String output = null;
        switch (candidates.size()) {
            case 0:
                output = "Volunteer cheated!";
                break;
            case 1:
                output = candidates.get(0).toString();
                break;
            default:
                output = "Bad magician!";
        }

        System.out.println(output);
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int t = scan.nextInt();
        for (int i = 1; i <= t; i++) {
            System.out.printf("Case #%d: ", i);
            new MagicTrick().solve(scan);
        }
    }
}
