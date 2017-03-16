package Round1C2016;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.*;

public class RoundThreeProblemOne {
    static char[] alpha = new char[26];

    public static void main(String[] args) {

//        String inPutFile = "/Users/KiRaN/Desktop/CodeBase/Google_CodeBase/SheepSleep/src/small.in";
//        String outPutFile = "/Users/KiRaN/Desktop/CodeBase/Google_CodeBase/SheepSleep/src/small.out";
        
        String inPutFile = "/Users/KiRaN/Desktop/CodeBase/Google_CodeBase/SheepSleep/src/large.in";
        String outPutFile = "/Users/KiRaN/Desktop/CodeBase/Google_CodeBase/SheepSleep/src/large.out";
        
        
        try {

            BufferedReader bufferedReader = new BufferedReader(new FileReader(inPutFile));
            BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(outPutFile));

            // Total number of test cases
            int noOfTestCases = Integer.valueOf(bufferedReader.readLine());
            
            int k = 0;
             for(int i = 0; i < 26; i++){
                  alpha[i] = (char)(65 + (k++));
            }
            
            for (int testCase = 0; testCase < noOfTestCases; testCase++){
                
                int numParties = Integer.parseInt(bufferedReader.readLine());
                String[] partyTotals=bufferedReader.readLine().split(" ");
                Map<Integer,Integer> partyTotalValues = new HashMap<>();
                int currentCountInHall = 0;
                
                
                for(int i=0; i<numParties; i++){
                    partyTotalValues.put(i, Integer.valueOf(partyTotals[i]));
                    currentCountInHall+=Integer.valueOf(partyTotals[i]);
                }
                
                List<String> outputCombination = new ArrayList<>();
                ArrayList<Integer> currMemberCount = new ArrayList<Integer>(partyTotalValues.values());
                while((sum(currMemberCount)/2) >= getMaxValue(currMemberCount) && getMaxValue(currMemberCount)!=0 ) {
                    List<Integer> maxIndiceValues = maxIndices(currMemberCount);
                    maxIndiceValues.stream().forEach(index -> {
                        int currentCountOfParty = partyTotalValues.get(index);
                        partyTotalValues.put(index, currentCountOfParty-1);
                        outputCombination.add(String.valueOf(alpha[index]));
                    });
                    outputCombination.add(" ");
                    currMemberCount = new ArrayList<Integer>(partyTotalValues.values());
                }
                
                String outputString = "";
                for(String str: outputCombination) {
                    outputString = outputString.concat(str);
                }
                
                bufferedWriter.write("Case #" + (testCase + 1) + ": " + outputString.trim());
                System.out.print("Case #" + (testCase + 1) + ": " + outputString.trim());
                bufferedWriter.write("\n");
                System.out.print("\n");
            }
                
            bufferedReader.close();
            bufferedWriter.close();

        } catch (FileNotFoundException fileNotFoundException) {

            System.out.println("Some Exception: " + fileNotFoundException.getMessage());
            fileNotFoundException.printStackTrace();

        } catch (IOException ioException) {

            System.out.println("Some Exception: " + ioException.getMessage());
            ioException.printStackTrace();

        } catch (Exception exception) {
            
            System.out.println("Some Exception: " + exception.getMessage());
            exception.printStackTrace();
        }

    }
    
    public static int sum(ArrayList<Integer> list) {
        int sum = list.stream().mapToInt(Integer::intValue).sum();
        return sum;
    }


    public static ArrayList<Integer> maxIndices(ArrayList<Integer> list) {
        ArrayList<Integer> indices = new ArrayList<Integer>();
        int max =  getMaxValue(list);
        int total = sum(list);
        boolean sendTwo = false;
        
        if(total%2 == 0) {
            sendTwo = true;
        }
        
        for (int i = 0; i < list.size(); i++) {
            
            if(max==1 && list.get(i) == max) {
                indices.add(i);
                if(!sendTwo) {
                    break;
                }
            } else if(list.get(i) == max) {
               indices.add(i);
            }
            if(indices.size() == 2) {
                break;
            }
         }

         return indices;
    }
    
    public static int getMaxValue(ArrayList<Integer> numArrayList) {
        int maxValue = Collections.max(numArrayList);
        return maxValue;
    }

}
