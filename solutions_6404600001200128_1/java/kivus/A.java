import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintWriter;

/**
 *
 *
 */
public class A {
    public static void main(String[] args) {
         try {
             Scanner scanner = (new Scanner(new File("c:/users/rafal/ideaprojects/src/Ain.txt")));


             FileOutputStream out = new FileOutputStream("c:/users/rafal/ideaprojects/src/Aout.txt");

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

        int n = scanner.nextInt();

        int []nn = new int[n];
        for (int i = 0; i < n; i++) {
            nn[i] = scanner.nextInt();
        }

        int maxDiff = 0;
        int result1 = 0;
        for (int i = 1; i < n; i++) {
            if (nn[i] < nn[i-1]) {
                int diff = nn[i-1] - nn[i];
                if (diff > maxDiff) {
                    maxDiff = diff;
                }
                result1 += diff;
            }
        }

        int result2 = 0;
        for (int i = 0; i < n - 1; i++) {
            if (nn[i] >= maxDiff) {
                result2 += maxDiff;
            } else {
                result2 += nn[i];
            }
        }

        wr.println("Case #" + caseNumber + ": " + result1 + " " + result2);
        System.out.println("Case #" + caseNumber + ": " + result1 + " " + result2);
        // ...

    }



}