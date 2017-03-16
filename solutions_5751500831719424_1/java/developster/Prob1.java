package codejam.y2014.r1b;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

public class Prob1 {
    
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(new File("/Users/octavian/codejam/A-large.in.txt"));
        FileWriter writer = new FileWriter(new File("/Users/octavian/codejam/A-large.out.txt"));
        int C = scanner.nextInt();
        int c = 1, n;
        String[] t = new String[100];
        int[][] p = new int[100][];
        for (int i = 0; i < C; i++) {
            n = scanner.nextInt();
            scanner.nextLine();
            for (int j = 0; j < n; j++) {
                t[j] = scanner.nextLine();
            }
            
//            System.out.println("case " + (i + 1));
//            System.out.println(t[0]);
//            System.out.println(t[1]);
            
            boolean possible = true;
            for (int j1 = 0; possible && j1 < n; j1++) {
                p[j1] = dist(t[j1], t[0]);
                if (p[j1] == null) {
                    possible = false;
                }
            }
            int res = 0;
            if (possible) {
                int k = distK(t[0]);
                for (int j1 = 0; j1 < k; j1++) {
                    int minDist = 1000000;
                    for (int j2 = 0; j2 < n; j2++) {
                        int dist = 0;
                        for (int j3 = 0; j3 < n; j3++) {
                            dist += Math.abs(p[j2][j1] - p[j3][j1]);
                        }
                        minDist = Math.min(minDist, dist);
                    }
                    res += minDist;
                }
            }
            writer.write("Case #" + (c++) + ": ");
            if (possible) {
                writer.write("" + res);
//                System.out.println("res = " + res);
            } else {
                writer.write("Fegla Won");
//                System.out.println("res = Fegla Won");
            }
            writer.write("\n");
        }
        writer.close();
        scanner.close();
    }
    
    private static int[] dist(String a, String b) {
        int[] ca = new int[100];
        int i = 0, j = 0, k = 0;
        while (i < a.length() && j < b.length()) {
            char ch_a = a.charAt(i);
            char ch_b = b.charAt(j);
            if (ch_a != ch_b) {
                return null;
            } else {
                while (i < a.length() && a.charAt(i) == ch_a) { ca[k]++; i++; }
                while (j < b.length() && b.charAt(j) == ch_b) { j++; }
            }
            k++;
        }
        if (i != a.length() || j != b.length()) {
            return null;
        }
        return ca;
    }

    private static int distK(String a) {
        int i = 0, k = 0;
        while (i < a.length()) {
            char ch_a = a.charAt(i);
            while (i < a.length() && a.charAt(i) == ch_a) i++;
            k++;
        }
        return k;
    }
}
