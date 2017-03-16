package c2014_c;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class Z1_1 {

    public static void main(String[] args) throws Exception {
        FileWriter fw = new FileWriter("C:\\output.txt");
        BufferedWriter out = new BufferedWriter(fw);
        //String pathname = "C:\\tests\\2014\\z1.txt";
        String pathname = "C:\\Users\\YC14rp1\\Downloads\\A-small-attempt0 (2).in";
        //String pathname = "C:\\Users\\YC14rp1\\Downloads\\D-large.in";
        Scanner scanner = new Scanner(new File(pathname));
        int tn = scanner.nextInt();
        scanner.nextLine();
        for (int ti = 1; ti <= tn; ti++) {
            int x1 = scanner.nextInt();
            int [][]m1 = new int[4][4];
            for (int i=0;i<4;i++) {
                for (int j=0;j<4;j++) {
                    m1[i][j] = scanner.nextInt();
                }
            }
            int x2 = scanner.nextInt();
            int [][]m2 = new int[4][4];
            for (int i=0;i<4;i++) {
                for (int j=0;j<4;j++) {
                    m2[i][j] = scanner.nextInt();
                }
            }
            int fl = 0;
            int solution = 0;
            for (int i=0;i<4;i++) {
                for (int j=0;j<4;j++) {
                    if (m1[x1-1][i]==m2[x2-1][j]) {
                        fl++;
                        solution = m1[x1-1][i];
                    }
                }
            }
            String s;
            if (fl==0) {
                s = "Case #" + ti + ": Volunteer cheated!";
            } else if (fl==1) {
                s = "Case #" + ti + ": " + solution;
            } else {
                s = "Case #" + ti + ": Bad magician!";
            }
            System.out.println(s);
            out.write(s);
            out.write("\n");
        }
        out.close();
    }

}
