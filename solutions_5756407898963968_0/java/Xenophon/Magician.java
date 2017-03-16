package org.active.nerd.magic;

import java.io.BufferedReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.Collection;
import java.util.LinkedList;
import java.util.List;

import org.active.nerd.code.jam.InOutProcessor;
import org.active.nerd.code.jam.LineReader;
import org.active.nerd.code.jam.Result;
import org.active.nerd.code.jam.Utility;
import org.active.nerd.magic.Magician.Trick;

public class Magician extends LineReader<Trick> {

    private static final String infileName = "A-small-attempt0.in";

    public static void main(String[] args) {
        InOutProcessor<Magician, Trick> reader = new InOutProcessor<Magician, Trick>(
                infileName, new Magician());
        try {
            reader.processFile();
        } catch (NumberFormatException | IOException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
    }

    public static class Trick implements Result {

        private Integer[] row1;
        private Integer[] row2;

        public Trick(Integer[] row1Nums, Integer[] row2Nums) {
            this.row1 = row1Nums;
            this.row2 = row2Nums;
        }

        @Override
        public String getResult() {
            List<Integer> possibleNums = new LinkedList<Integer>(
                    Arrays.asList(row1));
            possibleNums.retainAll(Arrays.asList(row2));
            if (possibleNums.size() == 0) {
                return "Volunteer cheated!";
            } else if (possibleNums.size() == 1) {
                return String.valueOf(possibleNums.iterator().next());
            } else {
                return "Bad magician!";
            }
        }
    }

    @Override
    public Collection<Result> parse(BufferedReader reader)
            throws NumberFormatException, IOException {
        int cases = Integer.parseInt(reader.readLine());
        List<Result> results = new LinkedList<Result>();

        for (int i = 0; i < cases; i++) {
            int rowChoice = Integer.parseInt(reader.readLine());
            Integer[][] firstRows = new Integer[4][4];
            for (int j = 0; j < firstRows.length; j++) {
                firstRows[j] = Utility.toIntgerArray(reader.readLine(), " ");
            }

            int secondRowChoice = Integer.parseInt(reader.readLine());
            Integer[][] secondRows = new Integer[4][4];
            for (int j = 0; j < secondRows.length; j++) {
                secondRows[j] = Utility.toIntgerArray(reader.readLine(), " ");
            }

            results.add(new Trick(firstRows[rowChoice - 1],
                    secondRows[secondRowChoice - 1]));
        }

        return results;
    }
}
