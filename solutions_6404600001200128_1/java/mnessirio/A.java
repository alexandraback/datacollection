package gcj2015_Round_1A;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class A {

    static Scanner in;
//    static String taskname = "A-small";
//    static String taskname = "A-small-attempt0";
//    static String taskname = "A-small-attempt1";
    static String taskname = "A-large";
//    static String taskname = "A-small-practice";

    public static String solve() {

        int N = in.nextInt();
        int [] m = new int[N];
        int y = 0;
        int z = 0;

        m[0] = in.nextInt();
        int maxDiff = 0;

        for (int i=1; i<N; i++) {
            m[i] = in.nextInt();
            if (m[i-1] > m[i]) {
                int foo = m[i-1] - m[i];
                y += foo;
                if (maxDiff < foo) maxDiff = foo;
            }
        }

        for (int i=0; i < N-1; i++) {
            if ( m[i] < maxDiff ) z+= m[i];
            else z += maxDiff;
        }

        return "" + y + " " + z;
    }

    public static void main(String[] args) {

        try {
            PrintWriter pW = new PrintWriter(new FileOutputStream("output/"
                    + taskname + ".out"));
            try {
                in = new Scanner(new FileInputStream("input/"
                        + taskname + ".in"));
                int T = in.nextInt();
                for (int caseNumber = 1; caseNumber <= T; caseNumber++) {
                    pW.println("Case #" + caseNumber + ": " + solve());
                }
                in.close();
                pW.close();
            } catch (IOException e) {
                System.out.println("Can not find file " + taskname + ".in");
            }
        } catch (IOException e) {
            System.out.println("Open or create exception with "
                    + taskname + ".out");
        }
    }
}

