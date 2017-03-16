
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;


public class Main {
    
    public static void main(String args[]) throws FileNotFoundException {
        
        final Scanner in = new Scanner(new File("/home/mikel/Desktop/codejam/input.txt"));
        final PrintWriter out = new PrintWriter(new File("/home/mikel/Desktop/codejam/output.txt"));
        
        final int t = in.nextInt();
        for (int it = 1; it <= t; it++) {
            
            
            final boolean[] chosen = new boolean[16];
            int row = in.nextInt();
            for (int i = 1; i <= 4; i++) {
                for (int j = 1; j <=4; j++) {
                    final int val = in.nextInt();
                    if (row == i) {
                        chosen[val-1] = true;
                    }
                }
            }
            
            int matches = 0;
            int lastMatch = -1;
            row = in.nextInt();
            for (int i = 1; i <= 4; i++) {
                for (int j = 1; j <=4; j++) {
                    final int val = in.nextInt();
                    if (row == i) {
                        if (chosen[val-1]) {
                            matches++;
                            lastMatch = val;
                        }
                    }
                }
            }
            
            out.print("Case #" + it + ": ");
            if (matches == 1) out.println(lastMatch);
            else if (matches == 0) out.println("Volunteer cheated!");
            else out.println("Bad magician!");
        }
        
        out.close();
    }
    
}
