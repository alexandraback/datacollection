package com.gmail.danielcomsa.codejam.y2014.qualification;

import com.gmail.danielcomsa.codejam.Utility;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * Created by daniel on 4/12/14.
 */
public class MagicTrick {

    private static final String BAD_MAGICIAN = "Bad magician!";
    private static final String VOLUNTEER_CHEATED = "Volunteer cheated!";
    private static final int LENGTH = 4;


    public String solve(int firstAnswer, int[][] firstArrangement, int secondAnswer, int[][] secondArrangement) {
        List<Integer> matches = new ArrayList<Integer>();
        int[] row = firstArrangement[firstAnswer - 1];
        int[] secondRow = new int[LENGTH];
        copyAndSortRow(secondArrangement[secondAnswer - 1], secondRow);
        for (int i = 0; i < LENGTH; i++) {
            if (Arrays.binarySearch(secondRow, row[i]) >=0) {
                matches.add(row[i]);
            }
        }

        if (matches.size() == 0) {
            return VOLUNTEER_CHEATED;
        } else if (matches.size() > 1) {
            return BAD_MAGICIAN;
        } else {
            return String.valueOf(matches.get(0));
        }
    }

    private void copyAndSortRow(int[] src, int[] dest) {
        System.arraycopy(src, 0, dest, 0, LENGTH);
        Arrays.sort(dest);
    }

    public static void main(String[] args) throws IOException {
        MagicTrick magicTrick = new MagicTrick();

        String file = "A-small-attempt1.in";
//        String file = "sample";
        BufferedReader reader = Utility.getReader(MagicTrick.class, file);
        PrintStream out = Utility.getPrintStream(MagicTrick.class, file);
        int testCases = Utility.readInt(reader);
        for (int i = 1; i <= testCases; i++) {
            int firstAnswer = Utility.readInt(reader);
            int[][] firstArrangement = Utility.readMatrix(4, 4, reader);
            int secondAnswer = Utility.readInt(reader);
            int[][] secondArrangement = Utility.readMatrix(4, 4, reader);
            String solution = magicTrick.solve(firstAnswer, firstArrangement, secondAnswer, secondArrangement);
            String response = "Case #" + i + ": " + solution;
            System.out.println(response);
            out.println(response);
        }
        out.flush();
        out.close();
    }
}
