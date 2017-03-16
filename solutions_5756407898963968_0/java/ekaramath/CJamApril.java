/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

/**
 *
 * @author ehsan
 */
public class CJamApril {

    /**
     * @param args the command line arguments
     */
    public static class TestCase {
        int[][] table_1 = new int[4][4];
        int[][] table_2 = new int[4][4];
        int value_1, value_2;
        int solution;
    }
    public static void main(String[] args) throws FileNotFoundException, IOException {
        // TODO code application logic here        
        Scanner in = new Scanner(new File("/home/ehsan/Downloads/asmall.in"));
        int ntest = in.nextInt();
        TestCase[] tests = new TestCase[ntest];
        for (int i = 0; i < ntest; i++) {
            tests[i] = new TestCase();
            tests[i].value_1 = in.nextInt() - 1;
            for (int k = 0; k < 4; k++) {
                for (int m = 0; m < 4; m++) {
                    tests[i].table_1[k][m] = in.nextInt() - 1;
                }
            }
            tests[i].value_2 = in.nextInt() - 1;
            
            for (int k = 0; k < 4; k++) {
                for (int m = 0; m < 4; m++) {
                    tests[i].table_2[k][m] = in.nextInt() - 1;
                }
            }
        }
        for (int k = 0; k < tests.length; k++) {
            solve(tests[k]);
        }
        BufferedWriter bw = new BufferedWriter(new FileWriter("/home/ehsan/result.txt"));
        for (int k = 0; k < tests.length; k++) {
            String msg = "" + (tests[k].solution + 1);
            if (tests[k].solution == 17) {
                msg = "Volunteer cheated!";
            }
            else if (tests[k].solution == 18) {
                msg = "Bad magician!";
            }
            bw.write("Case #" + (k + 1) + ": " + msg + "\n");
            System.out.println("Case #" + (k + 1) + ": " + msg);
        }
        bw.close();
    }
    
    private static void solve(TestCase t) {
        boolean[] nums = new boolean[16];
        for (int i = 0; i < 4; i++) {
            nums[t.table_1[t.value_1][i]] = true;
        }
        t.solution = 17;
        boolean flag = false;
        for (int i = 0; i < 4; i++) {
            if (nums[t.table_2[t.value_2 ][i]]) {
                if (flag) {
                    t.solution = 18;
                    break;
                    
                } else {
                    flag = true;                
                t.solution = t.table_2[t.value_2][i];
                }
            }
        }
    }
    
}
