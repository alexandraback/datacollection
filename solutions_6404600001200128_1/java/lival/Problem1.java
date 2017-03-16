
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Pivis
 */
public class Problem1 {

    public static void main(String[] args) throws FileNotFoundException, IOException {
        File f = new File("C:\\Users\\Pivis\\Documents\\NetBeansProjects\\GCJ2\\src\\a.in");
        File out = new File("C:\\Users\\Pivis\\Documents\\NetBeansProjects\\GCJ2\\src\\a.out");
        Scanner in = new Scanner(new FileReader(f));
        BufferedWriter output = new BufferedWriter(new FileWriter(out));
        
        int t = in.nextInt();
        for (int i = 0; i < t; i++) {
            int N = in.nextInt();
            int[] plate = new int[N];
            for (int j = 0; j < N; j++) {
                plate[j] = in.nextInt();
            }
            String text = "Case #" + (i+1) + ": " + findMinMushroom(plate) + "\n";
            output.write(text);
            
        }
        output.close();
    }
        
    public static String findMinMushroom(int[] a) {
        String res = "";
        int n = a.length;
        if (n <= 1) return "0 0";
        int max = 0, sum = 0, pred = a[0];
        
        for (int i = 1; i < n; i++) {
            if (pred > a[i]) {
                int diff = pred - a[i];
                sum += diff;
                max = Math.max(diff, max);
                
            }
            pred = a[i];
        }
        res += String.valueOf(sum);
        
        if (max == 0) {
            return res + " 0";
        }
        pred = a[0]; sum = 0;
        for (int i = 1; i < n; i++) {
            if (pred >= max) {
                sum += max;
            } else {
                sum += pred;
            }
            pred = a[i];
        }
        return res + " " + String.valueOf(sum);
    }
}
