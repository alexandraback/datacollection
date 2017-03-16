package codejam2014.round1B;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class TheRepeater {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner input = new Scanner(new File("input.txt"));
        PrintStream output = new PrintStream(new File("output.txt"));
        int numberOfCases = input.nextInt();
        for(int caseNumber = 1; caseNumber <= numberOfCases; caseNumber++) {
            int T = input.nextInt();
            String[] strings = new String[T];
            for(int i = 0; i < T; i++) {
                strings[i] = input.next();
            }
            String solution = solve(strings);
            output.format("Case #%d: %s\n", caseNumber, solution);
            System.out.format("Case #%d, with inputs :\n\t%s\n", caseNumber, solution);
        }
    }
    public static class CharWithRepetition {
        public char c;
        public int repetitions;
    }
    public static String solve(String[] strings) {
        List<List<CharWithRepetition>> sequences = new ArrayList<List<CharWithRepetition>>();
        for(String string : strings) {
            ArrayList<CharWithRepetition> list = new ArrayList<CharWithRepetition>();
            char prevChar = 0;
            for(int i = 0; i < string.length(); i++) {
                if(string.charAt(i) == prevChar) {
                    list.get(list.size() - 1).repetitions++;
                } else {
                    CharWithRepetition cw = new CharWithRepetition();
                    cw.c = string.charAt(i);
                    cw.repetitions = 1;
                    list.add(cw);
                }
                prevChar = string.charAt(i);
            }
            sequences.add(list);
        }
        int firstLength = sequences.get(0).size();
        for(int j = 0; j < sequences.size(); j++) {
            if(sequences.get(j).size() != firstLength) {
                return "Fegla Won";
            }
        }
        int[][] repetitions = new int[sequences.get(0).size()][strings.length];
        for(int i = 0; i < sequences.get(0).size(); i++) {
            char firstChar = sequences.get(0).get(i).c;
            for(int j = 0; j < sequences.size(); j++) {
                if(sequences.get(j).get(i).c != firstChar) {
                    return "Fegla Won";
                }
                repetitions[i][j] = sequences.get(j).get(i).repetitions;
            }
        }
        int result = 0;
        for(int[] singleCharRepetitions : repetitions) {
            result += solveSingleChar(singleCharRepetitions);
        }
        return Integer.toString(result);
    }
    public static int solveSingleChar(int[] singleCharRepetitions) {
        int average = 0;
        for(int i : singleCharRepetitions) {
            average += i;
        }
        average = (int) Math.round(average * 1.0 / singleCharRepetitions.length);
        
        int result = 0;
        for(int i : singleCharRepetitions) {
            result += Math.abs(i - average);
        }
        return result;
    }
}