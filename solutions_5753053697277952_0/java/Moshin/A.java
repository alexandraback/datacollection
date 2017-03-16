package round1C2016;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.*;

public class A {

    public static void main(String[] args) {

		String in = "/Users/Moshin/Code Jam//small.in";
		String out = "/Users/Moshin/Code Jam/small.out";
//		String in = "/Users/Moshin/Code Jam/large.in";
//		String out = "/Users/Moshin/Code Jam/large.out";        
        
        try {

        	
            BufferedReader bufferedReader = new BufferedReader(new FileReader(in));
            BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(out));

            char[] a = new char[26];

            // Total number of test cases
            int noOfTestCases = Integer.valueOf(bufferedReader.readLine());
            
            int k = 0;
             for(int i = 0; i < 26; i++){
                  a[i] = (char)(65 + (k++));
            }
            
            for (int testCase = 0; testCase < noOfTestCases; testCase++){
                
                int numParties = Integer.parseInt(bufferedReader.readLine());
                String[] partyTotals=bufferedReader.readLine().split(" ");
                Map<Integer,Integer> partyTotalValues = new HashMap<>();
                
                
                for(int i=0; i<numParties; i++){
                    partyTotalValues.put(i, Integer.valueOf(partyTotals[i]));
                }
                
                List<String> oc = new ArrayList<>();
                ArrayList<Integer> cmc = new ArrayList<Integer>(partyTotalValues.values());
                while((sum(cmc)/2) >= getMaxValue(cmc) && getMaxValue(cmc)!=0 ) {
                    List<Integer> maxIndiceValues = maxIndices(cmc);
                    maxIndiceValues.stream().forEach(index -> {
                        int currentCountOfParty = partyTotalValues.get(index);
                        partyTotalValues.put(index, currentCountOfParty-1);
                        oc.add(String.valueOf(a[index]));
                    });
                    oc.add(" ");
                    cmc = new ArrayList<Integer>(partyTotalValues.values());
                }
                
                String outputString = "";
                for(String str: oc) {
                    outputString = outputString.concat(str);
                }
                
                bufferedWriter.write("Case #" + (testCase + 1) + ": " + outputString.trim());
                System.out.print("Case #" + (testCase + 1) + ": " + outputString.trim());
                bufferedWriter.write("\n");
                System.out.print("\n");
            }
                
            bufferedReader.close();
            bufferedWriter.close();

        }catch (Exception exception) {
            
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

