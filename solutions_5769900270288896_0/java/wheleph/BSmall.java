package wheleph.gcj2015.round1b;

import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class BSmall {
    private static final String INPUT_FILE = "/B-small-attempt0.in";
    private static final String OUTPUT_FILE = "src/main/resources/B-small-attempt0.out";

    public static void main(String[] args) throws FileNotFoundException {
        InputStream inputStream = BSmall.class.getResourceAsStream(INPUT_FILE);
        Scanner scanner = new Scanner(inputStream);

        PrintWriter printWriter = new PrintWriter(new FileOutputStream(OUTPUT_FILE));

        int t = scanner.nextInt();
        for (int i = 0; i < t; i++) {
            int r = scanner.nextInt();
            int c = scanner.nextInt();
            int n = scanner.nextInt();
            List<Integer> unhappinessIndices = new ArrayList<Integer>();

            processSubsets(unhappinessIndices, r, c, n);

            int minUnhappinessIndex = Integer.MAX_VALUE;
            for (int j : unhappinessIndices) {
                if (j < minUnhappinessIndex) {
                    minUnhappinessIndex = j;
                }
            }

            printWriter.print(String.format("Case #%d: %d%n", i + 1, minUnhappinessIndex));
        }

        scanner.close();
        printWriter.close();
    }

    static void processSubsets(List<Integer> unhappinessIndices, int r, int c, int k) {
        int[] subset = new int[r * c];
        processLargerSubsets(unhappinessIndices, r, c, k, subset, 0, 0);
    }

    static void processLargerSubsets(List<Integer> unhappinessIndices, int r, int c, int k, int[] subset, int subsetSize, int nextIndex) {
        int n = r * c;
        if (subsetSize == k) {
            process(unhappinessIndices, r, c, n, subset);
        } else {
            for (int j = nextIndex; j < n; j++) {
                subset[j] = 1;
                processLargerSubsets(unhappinessIndices, r, c, k, subset, subsetSize + 1, j + 1);
                subset[j] = 0;
            }
        }
    }

    private static void process(List<Integer> unhappinessIndices, int r, int c, int n, int[] subset) {
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (subset[i] == 1) {
                // Look for the neighbour over the vertical wall
                if (i % r != 0 && subset[i - 1] == 1) {
                    count++;
                }

                if (i >= r && subset[i - r] == 1) {
                    count++;
                }
            }
        }

        unhappinessIndices.add(count);

//        for (int i : subset) {
//            System.out.print(i + " ");
//        }
//        System.out.println();
    }
}
