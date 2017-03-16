import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

public class Barber {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("B-large.in"));
        int loopvar = in.nextInt();
        PrintWriter out = new PrintWriter(new File("barb.out"));
        for (int loop = 0; loop < loopvar; loop++) {

            int numBarbers = in.nextInt();
            int place = in.nextInt();

            int[] times = new int[numBarbers];
            for (int i = 0; i < numBarbers; i++) {
                times[i] = in.nextInt();
            }

            int ans = 0;
            if(place <= numBarbers) {
                ans = place - 1;
            }
            else {

                long min = 0;
                long max = Long.MAX_VALUE - 1;
//            max = 100; //FIX
                long result = 0;
                while (min < max) {
                    long mid = (max - min + 1) / 2 + min;
                    long served = 0;
                    for (int mins : times) {
                        served += mid / mins + 1;
                        if (served < 0) //overflow
                            break;
                    }
                    if (served < 0 || served >= place) { //-1?
                        max = mid - 1;
                    } else {
                        min = mid;
                    }
                }

                ArrayList<Integer> barbs = new ArrayList<Integer>();
                long offset = Integer.MAX_VALUE;
                for (int barb = 0; barb < numBarbers; barb++) {
                    long off = (min + 1) % times[barb];
                    if (off < offset) {
                        barbs = new ArrayList<>();
                        offset = off;
                    }
                    if (off == offset) {
                        barbs.add(barb);
                    }
                }

                long bleh = 0;
                long oneless = min;
                for (int mins : times) {
                    bleh += oneless / mins + 1;
                }
                if (place - bleh - 1 == -1) {
                    System.out.println("what");
                }
                ans = barbs.get((int) (place - bleh - 1));

            }
            out.printf("Case #%d: %d%n", loop + 1, ans + 1);

        }
        out.close();
    }
}