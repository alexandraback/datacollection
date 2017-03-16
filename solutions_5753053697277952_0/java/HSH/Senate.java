import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.lang.StringBuilder;

public class Senate {
    
    private Integer total = 0;
    private int A;
    
    public Senate() {

        Scanner s = new Scanner(System.in);
        
        A = (int) 'A';

        int trials = s.nextInt();
        int lines = 0;

        
        for (int j = 0; j < trials; j++) {
            s.nextLine();
            int size = s.nextInt();
            int[] parties = new int[size];
            for (int i = 0; i < size; i++) {
                parties[i] = s.nextInt();
            }
            lines++;
            
            total = 0;
            for (int i = 0; i < size; i++) {
                total += parties[i];
            }
            
            StringBuilder output = new StringBuilder();
            
            while (total != 0) {
                System.err.println("This is the parties " + total);
                for (int i = 0; i < size; i++) {
                    System.err.print(parties[i] + " ");
                }
                remove(parties, output);
            }
            
            if (lines == 1)
                System.out.print("Case #" + lines + ": " + output);
            else
                System.out.print("\nCase #" + lines + ": " + output);
        }

    }
    
    private void remove(int[] x, StringBuilder out) {
        int max = 0;
        int index = -1;
        for (int i = 0; i < x.length; i++) {
           if (x[i] > max) {
               index = i;
               max = x[i];
           }
        }
        if (index == -1) return;
        x[index]--;
        total = total - 1;
        out.append((char) (A + index));

        int half = (total - 1) / 2;
        max = 0;
        index = -1;
        for (int i = 0; i < x.length; i++) {
           if (x[i] > max) { 
               index = i;
               max = x[i];
           }
        }
        if (index == -1) {
            out.append(' ');
            return;
        }
        for (int i = 0; i < x.length; i++) {
            if (index != i) {
                if (x[i] > half) {
                    out.append(' ');
                    return;
                }
            }
        }
        out.append((char) (A+index));
        out.append(' ');
        total = total - 1;
        x[index]--;
    }
    
    public static void main(String args[]) {

        Senate save = new Senate();
    }
   

   
}