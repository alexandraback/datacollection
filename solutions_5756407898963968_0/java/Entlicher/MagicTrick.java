/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package magictrick;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.Arrays;

/**
 *
 * @author martin
 */
public class MagicTrick {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {
        TestCase[] tcs = readTestCases(new File(args[0]));
        for (int i = 0; i < tcs.length; i++) {
            String y = getCard(tcs[i]);
            System.out.println("Case #"+(i+1)+": "+y);
        }
    }
    
    private static TestCase[] readTestCases(File f) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader(f));
        String line = br.readLine(); // Number of test cases
        int n = Integer.parseInt(line);
        //System.err.println("Have "+n+" test cases.");
        TestCase[] testCases = new TestCase[n];
        for (int i = 0; i < n; i++) {
            TestCase tc = new TestCase();
            line = br.readLine();
            tc.row1 = Integer.parseInt(line);
            //System.err.println(" Selected row1 = "+tc.row1);
            for (int r = 0; r < 4; r++) {
                line = br.readLine();
                int pos = 0;
                for (int c = 0; c < 4; c++) {
                    int pos2 = line.indexOf(' ', pos);
                    if (pos2 < 0) pos2 = line.length();
                    tc.cards1[r][c] = Integer.parseInt(line.substring(pos, pos2));
                    pos = pos2 + 1;
                }
            }
            line = br.readLine();
            //System.err.println(" Selected row2 = "+line);
            tc.row2 = Integer.parseInt(line);
            for (int r = 0; r < 4; r++) {
                line = br.readLine();
                int pos = 0;
                for (int c = 0; c < 4; c++) {
                    int pos2 = line.indexOf(' ', pos);
                    if (pos2 < 0) pos2 = line.length();
                    tc.cards2[r][c] = Integer.parseInt(line.substring(pos, pos2));
                    pos = pos2 + 1;
                }
            }
            testCases[i] = tc;
        }
        return testCases;
    }

    private static String getCard(TestCase testCase) {
        int[] set1 = testCase.cards1[testCase.row1 - 1];
        int[] set2 = testCase.cards2[testCase.row2 - 1];
        //System.err.println("set1 = "+Arrays.toString(set1));
        //System.err.println("set2 = "+Arrays.toString(set2));
        String card = null;
        for (int i = 0; i < set1.length; i++) {
            for (int j = 0; j < set2.length; j++) {
                if (set1[i] == set2[j]) {
                    if (card == null) {
                        card = Integer.toString(set1[i]);
                    } else {
                        // Second match
                        return "Bad magician!";
                    }
                }
            }
        }
        //System.err.println("  card = "+card);
        if (card != null) {
            return card;
        } else {
            return "Volunteer cheated!";
        }
    }
    
    private static class TestCase {
        int[][] cards1 = new int[4][4];
        int row1;
        int[][] cards2 = new int[4][4];
        int row2;
    }
    
}
