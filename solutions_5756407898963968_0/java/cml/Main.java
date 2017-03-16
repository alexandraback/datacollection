import java.util.Scanner;

public class Main {
    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);
        int trials = sc.nextInt(); // [1,100]
        for (int i = 0; i < trials; i++) {
            int firstAnswer = sc.nextInt();
            int[][] one = new int[4][4];
            int[][] two = new int[4][4];
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    one[j][k] = sc.nextInt();
                }
            }
            int secondAnswer = sc.nextInt();
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    two[j][k] = sc.nextInt();
                }
            }
            System.out.println("Case #" + (i + 1) + ": "
                    + solve(firstAnswer, one, secondAnswer, two));
        }
    }

    private static String solve (int firstAnswer, int[][] one,
            int secondAnswer, int[][] two) {
        String answer = "0";
        int count = 0;
        int[] welp = one[firstAnswer - 1];
        int[] okay = two[secondAnswer - 1];
        for (int i = 0; i < welp.length; i++) {
            for (int j = 0; j < okay.length; j++) {
                if (welp[i] == okay[j]) {
                    count++;
                    answer = Integer.toString(welp[i]);
                }
            }
        }
        if (count > 1) {
            return "Bad magician!";
        } else if ((count == 1) && (answer != "0")) {
            return answer;
        } else {
            return "Volunteer cheated!";
        }
    }
}
