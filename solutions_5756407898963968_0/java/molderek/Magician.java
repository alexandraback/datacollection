package codejam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Arrays;

public class Magician {
    
    public static MagicianTestCase[] testCases;
    public static String[] results;
    
    public static void main(String[] args) {
        
        if (args.length != 1) {
            System.out.println("usage: java Magician <input.file>");
            return;
        }
        
        readInput(args[0]);
        
        results = new String[testCases.length];
        for (int i = 0; i < testCases.length; i++) {
            results[i] = solveCase(testCases[i]);
        }
        
        writeOutput();
        
        System.out.println("done!");
    }

    private static String solveCase(MagicianTestCase testCase) {
        System.out.println("solving " + testCase);
        
        int firstAnswer = 0;
        int [] row1 = testCase.firstRow;
        int [] row2 = testCase.secondRow;
        
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (row1[i] == row2[j]) {
                    if (firstAnswer == 0) {
                        firstAnswer = row1[i];
                    } else {
                        return "Bad magician!";
                    }
                }
            }
        }
        
        if (firstAnswer == 0) {
            return "Volunteer cheated!";
        }
        
        return firstAnswer + "";
    }

    private static void writeOutput() {

        Path file = Paths.get("output.out") ;
        Charset charset = Charset.forName("US-ASCII");

        System.out.println("writing to path: " + file.toUri());

        try (BufferedWriter writer = Files.newBufferedWriter(file, charset)) {
            
            for (int i = 0; i < results.length; i++) {
                writer.write("Case #" + (i + 1) + ": " + results[i] + "\n");
            }
        } catch (IOException e) {
            System.err.format("IOException: %s%n", e);
        }
    }

    private static void readInput(String fileName) {
        
        Path file = Paths.get(fileName) ;
        Charset charset = Charset.forName("US-ASCII");

        System.out.println("reading from path: " + file.toUri());

        try (BufferedReader reader = Files.newBufferedReader(file, charset)) {
            String line = reader.readLine();
            int testCaseNumber = Integer.valueOf(line);
            testCases = new MagicianTestCase[testCaseNumber];
            
            int testCaseCount = 0;
            String[] lines = new String[4];
            
            while ((line = reader.readLine()) != null) {
                MagicianTestCase testCase = new MagicianTestCase();

                int firstAnswer = Integer.valueOf(line);
                lines[0] = reader.readLine();
                lines[1] = reader.readLine();
                lines[2] = reader.readLine();
                lines[3] = reader.readLine();
                
                String firstRow = lines[firstAnswer - 1];
                stringToIntArray(firstRow, testCase.firstRow);
                
                int secondAnswer = Integer.valueOf(reader.readLine());
                lines[0] = reader.readLine();
                lines[1] = reader.readLine();
                lines[2] = reader.readLine();
                lines[3] = reader.readLine();

                String secondRow = lines[secondAnswer - 1];
                stringToIntArray(secondRow, testCase.secondRow);
             
                //System.out.println("read test case: " + testCase);
                
                testCases[testCaseCount++] = testCase;
            }
        } catch (IOException e) {
            System.err.format("IOException: %s%n", e);
        }
    }

    private static void stringToIntArray(String string, int[] array) {
        String[] split = string.split(" ");
        
        array[0] = Integer.valueOf(split[0]);
        array[1] = Integer.valueOf(split[1]);
        array[2] = Integer.valueOf(split[2]);
        array[3] = Integer.valueOf(split[3]);
    }

}

class MagicianTestCase {
    
    public int[] firstRow = new int[4];
    public int[] secondRow = new int[4];
    
    @Override
    public String toString() {
        return Arrays.toString(firstRow) + " - " + Arrays.toString(secondRow);
    }
    
}
