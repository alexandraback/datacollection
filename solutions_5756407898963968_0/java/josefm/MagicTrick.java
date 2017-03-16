package codejam2014;


import java.io.File;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

/**
 * Title: Magic Trick
 * 
 * Link: https://code.google.com/codejam/contest/2974486/dashboard#s=p0
 */
public class MagicTrick {
    public static void main(String... args) throws Exception {
        //resolve("2014-QR-magic-tiny");
        resolve("2014-QR-magic-small0");
    }
    
    private static void resolve(String dataFile) throws Exception {
        // Initialize input and output.
        Scanner scanner = new Scanner(new File(dataFile + ".in"));
        PrintWriter printer = new PrintWriter(dataFile + ".out");
        
        // Read number of test cases.
        int T = scanner.nextInt();
        
        // Evaluate each test case.
        for(int t=0; t<T; t++) {
            // Read input.
            int answer1 = scanner.nextInt();
            int cards1[][] = new int[4][4];
            for(int i=0; i<4; i++)
                for(int j=0; j<4; j++)
                    cards1[i][j] = scanner.nextInt();
            int answer2 = scanner.nextInt();
            int cards2[][] = new int[4][4];
            for(int i=0; i<4; i++)
                for(int j=0; j<4; j++)
                    cards2[i][j] = scanner.nextInt();
            
            // Calculate result.
            String result = resolveTestCase(answer1, cards1, answer2, cards2);
            
            // Print output.
            String message = "Case #" + (t+1) + ": " + result + "\n";
            System.out.print(message);
            printer.append(message);
        }
        
        printer.flush();
        printer.close();
    }
    
    private static String resolveTestCase(final int answer1, final int[][] cards1, 
                                          final int answer2, final int[][] cards2) {
        // Select first row.
        int[] row1 = cards1[answer1-1];
        
        // Intersect selected rows.
        List<Integer> res = new ArrayList<>();
        for(int i=0; i<4; i++) {
            for(int j=0; j<4; j++) {
                if(row1[i] == cards2[answer2-1][j]) {
                    res.add(row1[i]);
                }
            }
        }
        
        // Return result.
        if(res.size() == 1) return res.get(0) + "";
        if(res.size() > 1) return "Bad magician!";
        return "Volunteer cheated!";
    }
}
