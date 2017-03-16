import java.io.*;

/**
 * @author vilmantas baranauskas
 */
public class Haircut {


    public static void main(String[] args) throws IOException {

        BufferedReader in = new BufferedReader(new FileReader("in.txt"));
        BufferedWriter out = new BufferedWriter(new FileWriter("out.txt"));

        // number of test cases
        int t = Integer.parseInt(in.readLine());

        long start = System.currentTimeMillis();
        for (int i = 0; i < t; i++) {
            CharSequence solution = "Case #" + (i + 1) + ": " + solveTestCase(in);
            System.out.println(solution);
            out.write(solution.toString());
            out.newLine();
        }

        System.out.println("Took " + (System.currentTimeMillis() - start) + "ms");

        in.close();
        out.close();

    }

    private static int solveTestCase(BufferedReader in) throws IOException {

        long myPosition = readLineOfInts(in)[1] - 1;
        long[] barbers = readLineOfInts(in);
        long[] busy = new long[barbers.length];

        long gcd = barbers[0];
        long lcd = barbers[0];
        for (long b : barbers) {
            gcd = gcd(gcd, b);
            lcd = lcd * b / gcd;
        }

        int a = 0;
        for (long barber : barbers) {
            a += lcd / barber;
        }

        myPosition = myPosition % a;

        if (myPosition == 0) {
            return 1;
        }

        long currentPos = 0;
        do {
            for (int i = 0; i < barbers.length ; i++) {
                if (busy[i] > 0) {
                    busy[i] = busy[i] - 1;
                }
                if (busy[i] == 0) {
                    if (currentPos == myPosition) {
                        return i + 1;
                    }
                    busy[i] = barbers[i];
                    currentPos++;
                }
            }
        } while(true);
    }

    private static long gcd(long a, long b) {
        if (b == 0) {
            return a;
        } else {
            return gcd(b, a % b);
        }
    }

    private static long[] readLineOfInts(BufferedReader in) throws IOException {
        String[] v1Str = in.readLine().split(" ");
        long[] items = new long[v1Str.length];
        for (int i = 0; i < v1Str.length; i++) {
            items[i] = Long.parseLong(v1Str[i]);
        }
        return items;
    }

}
