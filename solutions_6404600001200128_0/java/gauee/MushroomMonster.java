package pl.gauee.algo.code.jam.c2015.round.one;

import java.io.*;

/**
 * Created by gauee on 4/18/15.
 */
public class MushroomMonster {
    public static final boolean IS_SOUT = false;

    static class FirstMethodResult {
        int max;
        int total;

        FirstMethodResult() {
            this.max = 0;
            this.total = 0;
        }

        void addToTotalWithMaxAnalysis(int toAdd) {
            this.total += toAdd;
            if (toAdd > max) {
                max = toAdd;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        final String pathToFile = "./src/main/resources/c2015/round.one/";
//        final String fileName = "A-test.in";
        final String fileName = "A-small-attempt1.in";

        BufferedReader reader = new BufferedReader(new FileReader(pathToFile + fileName));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(pathToFile + fileName + ".out", false));

        String line = reader.readLine();
        Integer testCases = Integer.valueOf(line);
        for (int i = 0; i < testCases; i++) {
            reader.readLine();
            String[] plateStatesStr = reader.readLine().split(" ");
            int[] plateStates = new int[plateStatesStr.length];
            for (int j = 0; j < plateStates.length; j++) {
                plateStates[j] = Integer.valueOf(plateStatesStr[j]);
            }
            FirstMethodResult firstMethodResult = computationOfFirstMethod(plateStates);
            int secondMethodResult = computationOfSecondMethod(plateStates, firstMethodResult.max);


            writeAnswer(bufferedWriter, i, firstMethodResult.total + " " + secondMethodResult);
        }

        reader.close();
        bufferedWriter.close();
    }

    private static int computationOfSecondMethod(int[] plateStates, int max) {
        int total = 0;

        for (int i = 0; i < plateStates.length - 1; i++) {
            total += Math.min(plateStates[i], max);
        }

        return total;
    }

    private static FirstMethodResult computationOfFirstMethod(int[] plateStates) {
        FirstMethodResult result = new FirstMethodResult();

        int prevAmount = plateStates[0];
        for (int i = 1; i < plateStates.length; i++) {
            if (prevAmount > plateStates[i]) {
                result.addToTotalWithMaxAnalysis(prevAmount - plateStates[i]);
            }
            prevAmount = plateStates[i];
        }

        return result;
    }

    private static void writeAnswer(BufferedWriter bufferedWriter, int i, String result) throws IOException {
        String anwer = "Case #" + (i + 1) + ": " + result;
        if (IS_SOUT) {
            System.out.println(anwer);
            return;
        }
        bufferedWriter.write(anwer);
        bufferedWriter.newLine();
    }
}
