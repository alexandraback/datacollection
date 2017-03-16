// Code by PepeOfMath
//
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class Problem3 {

    public static void main(String[] args) throws FileNotFoundException {

        //hard code the file location
        //open file
        //get number of test cases
        File f = new File("C-small-attempt1.in");
        Scanner s = new Scanner(f);
        String line = s.nextLine();
        int T = Integer.parseInt(line);

        //open output file
        File f2 = new File("smallresult.txt");
        PrintWriter p = new PrintWriter(f2);

        for (int i = 1; i <= T; i++) {
            p.println("Case #" + i + ":");
            int nt = s.nextInt();
            
            int[][] trees = new int[nt][2];
            for (int j = 0; j < nt; j++) {
                trees[j][0] = s.nextInt();
                trees[j][1] = s.nextInt();
            }
            for (int j = 0; j < nt; j++) {
                int mincount = nt;
                for (int k = 0; k < nt; k++) {
                    if (j == k) {
                        continue;
                    }
                    long a1 = trees[j][0] - trees[k][0];
                    long a2 = trees[j][1] - trees[k][1];
                    
                    
                    int c1 = 0;
                    int c2 = 0;
                    for (int l = 0; l < nt; l++) {
                        long b1 = trees[j][0] - trees[l][0];
                        long b2 = trees[j][1] - trees[l][1];
                        
                        long value = a1*b2 - a2*b1;
                        if (value < 0) {
                            c1++;
                        }
                        if (value > 0) {
                            c2++;
                        }
                    }
                    mincount = Math.min(mincount, Math.min(c1, c2));
                }
                p.println(mincount);
                //s.nextLine();
            }
        }

        p.close();
        s.close();
    }
}

