package codejam.y2014.r1b;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Locale;
import java.util.Scanner;

/**
 * @author Cronos
 */
public class Task1 {

    static Scanner input;
    static BufferedWriter output;

    public static void main(String[] args) throws Exception {
        Locale.setDefault(Locale.US);
        input = new Scanner(new File("input.txt"));
        output = new BufferedWriter(new FileWriter("output.txt"));
        int T = input.nextInt();
        for (int i = 1; i <= T; i++) {
            String result = getResult();
            System.out.println("Case #" + i + ": " + result);
            output.write("Case #" + i + ": " + result);
            output.newLine();
        }
        output.close();
    }

    public static String getResult() {
        int N = input.nextInt();
        input.nextLine();
        String[] strings = new String[N];
        for (int i = 0; i < N; i++) {
            strings[i] = input.nextLine();
        }
        int D = 1;
        for (int i = 1; i < strings[0].length(); i++) {
            if (strings[0].charAt(i) != strings[0].charAt(i - 1)) D++;
        }
        char[] chars = new char[D];
        int[][] nums = new int[N][D];
        chars[0] = strings[0].charAt(0);
        nums[0][0] = 1;
        int d = 0;
        for (int i = 1; i < strings[0].length(); i++) {
            if (strings[0].charAt(i) == strings[0].charAt(i - 1)) {
                nums[0][d]++;
            } else {
                d++;
                chars[d] = strings[0].charAt(i);
                nums[0][d] = 1;
            }
        }
        for (int i = 1; i < N; i++) {
            d = 0;
            nums[i][0] = 1;
            if (strings[i].charAt(0) != chars[0]) return "Fegla Won";
            for (int j = 1; j < strings[i].length(); j++) {
                if (strings[i].charAt(j) == strings[i].charAt(j - 1)) {
                    nums[i][d]++;
                } else {
                    d++;
                    if (d >= D) return "Fegla Won";
                    if (chars[d] != strings[i].charAt(j)) return "Fegla Won";
                    nums[i][d] = 1;
                }
            }
            if (d != D-1) return "Fegla Won";
        }
        int result = 0;
        for (int i = 0; i < D; i++) {
            result += Math.abs(nums[0][i] - nums[1][i]);
        }
        return "" + result;
    }
}
