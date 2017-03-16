import java.io.*;

/**
 * @author vilmantas baranauskas
 */
public class MushroomMonster {


    public static void main(String[] args) throws IOException {

        BufferedReader in = new BufferedReader(new FileReader("in.txt"));
        BufferedWriter out = new BufferedWriter(new FileWriter("out.txt"));

        // number of test cases
        int t = Integer.parseInt(in.readLine());

        for (int i = 0; i < t; i++) {
            CharSequence solution = "Case #" + (i + 1) + ": " + solveTestCase(in);
            System.out.println(solution);
            out.write(solution.toString());
            out.newLine();
        }

        in.close();
        out.close();

    }

    private static String solveTestCase(BufferedReader in) throws IOException {

        int[] n = readLineOfInts(in);
        int[] intervals = readLineOfInts(in);

        int rate = 0;
        for (int i = 1; i < intervals.length; i++) {
            rate = Math.max(rate, intervals[i - 1] - intervals[i]);
        }

        int minMax = 0;
        int minConstant = 0;
        for (int i = 1; i < intervals.length; i++) {
            int diff = intervals[i - 1] - intervals[i];
            if (diff > 0) {
                minMax += diff;
            }
            minConstant += Math.min(rate, intervals[i - 1]);
        }

        return minMax + " " + minConstant;
    }

    private static int[] readLineOfInts(BufferedReader in) throws IOException {
        String[] v1Str = in.readLine().split(" ");
        int[] items = new int[v1Str.length];
        for (int i = 0; i < v1Str.length; i++) {
            items[i] = Integer.parseInt(v1Str[i]);
        }
        return items;
    }

}
