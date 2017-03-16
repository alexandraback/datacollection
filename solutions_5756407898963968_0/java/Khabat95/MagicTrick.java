import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Created by khabat95 on 13/04/14.
 */
public class MagicTrick {

    public static String alg(int[][] arr1, int[][] arr2, int row1, int row2) {
        int res = 0;
        for (int i=0; i<4; i++) {
            for (int j=0; j<4; j++) {
                if (arr1[row1-1][i] == arr2[row2-1][j]) {
                    if (res != 0) {
                        return "Bad magician!";
                    }
                    res = arr1[row1-1][i];
                }
            }
        }
        if (res == 0) {
            return "Volunteer cheated!";
        }
        return String.valueOf(res);
    }

    public static void main(String args[]) {
        try {
            Scanner sc = new Scanner(new FileReader("/home/khabat95/Downloads/A-small-attempt0.in"));
            PrintWriter pw = new PrintWriter("/home/khabat95/Downloads/A-small.out");

            int T = sc.nextInt();
            for (int i = 0; i < T; i++) {
                int row1 = sc.nextInt();
                int[][] arr1 = new int[4][4];
                for (int j=0; j<4; j++) {
                    for (int k=0; k<4; k++) {
                        arr1[j][k] = sc.nextInt();
                    }
                }
                int row2 = sc.nextInt();
                int[][] arr2 = new int[4][4];
                for (int j=0; j<4; j++) {
                    for (int k=0; k<4; k++) {
                        arr2[j][k] = sc.nextInt();
                    }
                }
                System.out.println("Test case " + (i + 1) + "...");
                pw.println("Case #" + (i + 1) + ": " + alg(arr1, arr2, row1, row2));
            }

            pw.flush();
            pw.close();
            sc.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }
}
