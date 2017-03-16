package pl.gauee.algo.code.jam.c2015.round.one;

import java.io.*;
import java.util.ArrayList;
import java.util.HashSet;

/**
 * Created by gauee on 4/18/15.
 */
public class Barbers {
    public static final boolean IS_SOUT = !false;


    public static void main(String[] args) throws IOException {
        final String pathToFile = "./src/main/resources/c2015/round.one/B-";
        final String fileName = "test.in";
//        final String fileName = "small-attempt1.in";
//        final String fileName = "large.in";

        BufferedReader reader = new BufferedReader(new FileReader(pathToFile + fileName));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(pathToFile + fileName + ".out", false));

        String line = reader.readLine();
        Integer testCases = Integer.valueOf(line);
        for (int i = 0; i < testCases; i++) {
            System.out.println("Computing  " + (i + 1) + " of " + testCases);
            String[] firstLineParams = reader.readLine().split(" ");
            int myPosition = Integer.valueOf(firstLineParams[1]);
            String[] secondLineParams = reader.readLine().split(" ");
            int[] barbersSpeed = new int[secondLineParams.length];
            for (int j = 0; j < barbersSpeed.length; j++) {
                barbersSpeed[j] = Integer.valueOf(secondLineParams[j]);
            }

            int myBarbersIdx = getMyBarbersSmart(barbersSpeed, myPosition);

            writeAnswer(bufferedWriter, i, "" + myBarbersIdx);
        }

        reader.close();
        bufferedWriter.close();
    }

    private static int getMyBarbersSmart(int[] barbersSpeed, int myPosition) {
        int[] orderedBarbersInTime = getOrderedBarbers(barbersSpeed);

        int idx = (myPosition % orderedBarbersInTime.length);
        idx = ((idx + orderedBarbersInTime.length - 1) % orderedBarbersInTime.length);

        return orderedBarbersInTime[idx];
    }


    static int[] getOrderedBarbers(int[] barbersSpeed) {
        ArrayList<Integer> barbers = new ArrayList<>();
        HashSet<Integer> uniqueSpeed = new HashSet<>();
        HashSet<Integer> usedSpeeds = new HashSet<>();

        for (int i = 0; i < barbersSpeed.length; i++) {
            uniqueSpeed.add(barbersSpeed[i]);
            barbers.add(i + 1);
        }

        for (int i = 1; uniqueSpeed.size() != usedSpeeds.size(); i++) {
            usedSpeeds.clear();
            for (int j = 0; j < barbersSpeed.length; j++) {
                if (i % barbersSpeed[j] == 0) {
                    barbers.add(j + 1);
                    usedSpeeds.add(barbersSpeed[j]);
                }
            }
        }

        int[] result = new int[barbers.size() - barbersSpeed.length];
        for (int i = 0; i < result.length; i++) {
            result[i] = barbers.get(i);
        }
        return result;
    }

    private static int getMyBarbers(int[] barbersSpeed, int myPosition) {
        for (int curTime = 0; ; ++curTime) {
            for (int i = 0; i < barbersSpeed.length; i++) {
                if (curTime % barbersSpeed[i] == 0) {
                    if (myPosition == 1) {
                        return 1 + i;
                    }
                    --myPosition;
                }
            }
        }
    }

    private static void writeAnswer(BufferedWriter bufferedWriter, int i, String result) throws IOException {
        String anwer = "Case #" + (i + 1) + ": " + result;
        if (IS_SOUT) {
            System.out.println(anwer);
        }
        bufferedWriter.write(anwer);
        bufferedWriter.newLine();
    }
}
