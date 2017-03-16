import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.Arrays;
import java.util.Scanner;

/**
 * Created by burger on 4/12/14.
 */
public class MagicTrick {
    private static Scanner sc;

    public static void main(String[] args) {
        try {
            sc = new Scanner(new File("small.in"));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }

        try {
            PrintWriter writer = new PrintWriter("answer.out", "UTF-8");

            int T = sc.nextInt();
            for (int t = 1; t <= T; t++) {
                writer.write("Case #" + t + ": " + new MagicTrick().solve() + "\n");
            }
            writer.close();

        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (UnsupportedEncodingException e) {
            e.printStackTrace();
        }
    }

    private String solve() {
        int r = sc.nextInt();
        for (int i = 0; i < r; i++)
            sc.nextLine();

        int[] first = new int[4];
        for (int i = 0; i < 4; i++)
            first[i] = sc.nextInt();

        for (int i = r; i <= 4; i++)
            sc.nextLine();

        r = sc.nextInt();
        for (int i = 0; i < r; i++)
            sc.nextLine();

        int[] second = new int[4];
        for (int i = 0; i < 4; i++)
            second[i] = sc.nextInt();

        for (int i = r; i <= 4; i++)
            sc.nextLine();

        Arrays.sort(first);
        Arrays.sort(second);

        int count = 0, num = 0;
        for (int i = 0; i < 4; i++) {
            if (Arrays.binarySearch(first, second[i]) >= 0) {
                count++;
                num = second[i];
            }
        }

        String res;
        if (count == 1) {
            res = Integer.toString(num);
        } else if (count > 1) {
            res = "Bad magician!";
        } else {
            res = "Volunteer cheated!";
        }
        return res;
    }
}
