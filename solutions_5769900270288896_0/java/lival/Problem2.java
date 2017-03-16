
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashMap;
import java.util.Scanner;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Pivis
 */
public class Problem2 {
    public static void main(String[] args) throws FileNotFoundException, IOException {
        File f = new File("C:\\Users\\Pivis\\Documents\\NetBeansProjects\\GCJ_B\\src\\a.in");
        File out = new File("C:\\Users\\Pivis\\Documents\\NetBeansProjects\\GCJ_B\\src\\a.out");
        Scanner in = new Scanner(new FileReader(f));
        BufferedWriter output = new BufferedWriter(new FileWriter(out));
        
        int t = in.nextInt();
        for (int i = 0; i < t; i++) {
            int R = in.nextInt();
            int C = in.nextInt();
            int N = in.nextInt();
            String text = "Case #" + (i+1) + ": " + solve(R, C, N) + "\n";
            output.write(text);
            
        }
        output.close();
    }
        
    public static int solve(int R, int C, int N) {
        int square = R*C;
        int optimal = (square + 1) / 2;
        int max = (R - 1) * C + (C - 1) * R;
        if (N <= optimal) return 0;
        if (N == square) return max;
        if (R == 1 || C == 1) {
            int left = square - N;
            return max - 2 * left;
        }
        int central = ((R - 2)*(C - 2)+1)/2;
        int left = square - N;
        if (left <= central) {
            return max - 4*left;
        }
        int corner = 2;
        if (R%2!=0 && C%2!=0) corner = 0;
        if (N - optimal <= corner) return 2*(N - optimal);
        return 3 * (N - optimal - corner) + 2*corner;
        
        
    }
}
