package com.andymur.codejam.cj2014.round1;

import java.io.*;
import java.util.ArrayList;
import java.util.List;

/**
 * Created by andymur on 5/3/14.
 */
public class Repeater {

    public static String IN_NAME = "repeater.in";
    public static String OUT_NAME = "repeater.out";

    public static List<String> feglaLines = new ArrayList();

    private static int testCasesNum;

    public static void main(String[] args) throws IOException {

        BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream(IN_NAME)));
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(OUT_NAME)));

        testCasesNum = readInt(reader);

        for (int i = 0; i < testCasesNum; i++) {
            readTestCase(reader);
            //System.out.println(feglaLines);
            int result = solveTestCase();

            if (result < 0) {
                writer.write(String.format("Case #%d: Fegla Won", i + 1));
            } else {
                writer.write(String.format("Case #%d: %d", i + 1, result));
            }

            if (i < testCasesNum - 1)
                writer.newLine();
        }

        reader.close();
        writer.close();
    }

    private static void readTestCase(BufferedReader reader) throws IOException {
        int numLines = readInt(reader);
        feglaLines.clear();

        for (int i = 0; i < numLines; i++) {
            feglaLines.add(reader.readLine());
        }
    }

    private static int solveTestCase() {
        String[][] chains = new String[feglaLines.size()][];
        int result = 0;

        buildChains(chains);

        if (!checkSize(chains)) {
            result = -1;
        } else {
            int len = chains[0].length;
            for (int i = 0; i < len; i++) {

                String [] chain = new String[chains.length];

                for (int j = 0; j < chains.length; j++) {
                    chain[j] = chains[j][i];
                }

                int chainResult = solveChains(chain);
                if (chainResult < 0)
                    return -1;
                else {
                    result += chainResult;
                }
            }

        }

        return result;
    }

    private static void buildChains(String[][] chains) {
        int i = 0;
        for (String feglaLine: feglaLines) {
            chains[i] = buildChain(feglaLine);
            i++;
        }
    }

    private static String[] buildChain(String feglaLine) {
        Character firstInLink = feglaLine.charAt(0);
        String currentLink = new String();

        List<String> result = new ArrayList<String>();

        for (Character ch: feglaLine.toCharArray()) {

            if (ch != firstInLink) {
                firstInLink = ch;
                result.add(currentLink);
                currentLink = firstInLink.toString();
            } else {
                currentLink = currentLink.concat(firstInLink.toString());
            }
        }
        result.add(currentLink);
        return result.toArray(new String[0]);
    }

    private static boolean checkSize(String[][] chains) {
        int len = chains[0].length;

        for (String[] chain: chains) {
            if (chain.length != len) {
                return false;
            }
        }

        return true;
    }

    private static int solveChains(String[] chain) {

        int min = Integer.MAX_VALUE;

        for (int i = 0; i < chain.length; i++) {
            int result = 0;

            for (int j = 0; j < chain.length; j++) {
                if (chain[i].charAt(0) != chain[j].charAt(0))
                    return -1;
                result += Math.abs(chain[i].length() - chain[j].length());
            }

            if (min > result) {
                min = result;
            }

            if (min == 0) {
                return 0;
            }
        }

        return min;
    }

    private static int readInt(BufferedReader reader) throws IOException {
        return Integer.parseInt(reader.readLine().trim());
    }
}
