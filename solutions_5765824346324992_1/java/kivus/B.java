import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.PriorityQueue;
import java.util.Scanner;

/**
 *
 *
 */
public class B {
    public static void main(String[] args) {
         try {
             Scanner scanner = (new Scanner(new File("c:/users/rafal/ideaprojects/src/Bin.txt")));


             FileOutputStream out = new FileOutputStream("c:/users/rafal/ideaprojects/src/Bout.txt");

             int numberOfCases;
             numberOfCases = scanner.nextInt();
             scanner.nextLine();

             PrintWriter wr = new PrintWriter(out);
             for (int i = 0; i < numberOfCases; i++) {
                 doCase(i + 1, scanner, wr);
                 if (i < numberOfCases - 1)
                    scanner.nextLine();
             }
             wr.close();
             out.close();

         } catch (IOException e) {
             System.out.println("Error: " + e);
         }
     }

    private static void doCase(int caseNumber, Scanner scanner, PrintWriter wr) {

//        int result = 0;
        int b = scanner.nextInt();
        int n = scanner.nextInt();

        int m[] = new int[b];
        for (int i = 0; i < b; i++) {
            m[i] = scanner.nextInt();
        }

        long time = 1000;
        while (num(m, time) < n) {
            time = time * 2;
        }
        long low = 0, high = time;
        while (low < high - 1) {
            long mid = (high + low) / 2;
            if (num(m, mid) < n) {
                low = mid;
            } else {
                high = mid;
            }
        }
        long r1 = num(m, low);
        long r2 = num(m, high);
        if (n <= r1) {
            time = low;
        } else if (n <= r2) {
            time = high;
        } else {
            throw new RuntimeException("Error!");
        }

        long queueSizeBefore = num(m, time-1);
        assert(queueSizeBefore < n);
        int result = -1;
        for (int i = 0; i < m.length; i++) {
            if (time % m[i] == 0) {
                queueSizeBefore++;
                if (queueSizeBefore == n) {
                    result = i;
                    break;
                }
            }
        }

        assert(result >= 0);
        result++;

        wr.println("Case #" + caseNumber + ": " + result);
        System.out.println("Case #" + caseNumber + ": " + result);
        // ...

    }


    // how many people are handled at time 'time'
    static private long num(int []m, long time) {
        if (time < 0) {
            return 0;
        }
        long result = 0;
        for (int i = 0; i < m.length; i++) {
            result = result + 1 + time / m[i];
        }
        return result;
    }

}