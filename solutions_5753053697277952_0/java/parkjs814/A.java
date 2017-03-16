import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

/**
 * Created by fleeon on 5/8/16.
 */
public class A {

    static class Senate {
        char initial;
        int num;

        Senate(char initial, int num) {
            this.initial = initial;
            this.num = num;
        }

        @Override
        public String toString() {
            return this.initial + " " + num;
        }
    }

    public static void main(String[] args) throws FileNotFoundException {
        Scanner scanner = new Scanner(new File("A.in"));
        PrintWriter writer = new PrintWriter("A.out");
        int T = scanner.nextInt();
        for (int t = 0; t < T; t++) {
            int N = scanner.nextInt();
            ArrayList<Senate> senates = new ArrayList<Senate>();
            int total = 0;
            for (int n = 0; n < N; n++) {
                int num = scanner.nextInt();
                senates.add(new Senate((char) ('A' + n), num));
                total += num;
            }

            writer.printf("Case #%d: ", t + 1);
            while (total > 0) {
                Senate max1 = new Senate('\0', 0), max2 = new Senate('\0', 0);
                for (Senate senate : senates) {
                    if (max1.num < senate.num) {
                        max2 = max1;
                        max1 = senate;
                    } else if (max2.num < senate.num) {
                        max2 = senate;
                    }
                }
                if (max1.num > 0) {
                    max1.num--;
                    total--;
                    writer.print(max1.initial);
                    if (max2.num > 0) {
                        max2.num--;
                        total--;
                        boolean ok = true;
                        for (Senate senate : senates) {
                            if (senate.num > total / 2) {
                                ok = false;
                                break;
                            }
                        }
                        if (ok) {
                            writer.print(max2.initial);
                        } else {
                            max2.num++;
                            total++;
                        }
                    }
                    writer.print(" ");
                }
            }
            writer.println();
        }
        writer.close();
    }
}
