package codeJam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;

public class TheRepeater {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new FileReader("_input.in"));
        BufferedWriter bw = new BufferedWriter(new FileWriter("_output.in"));

        br.readLine();//first line for the case count
        String line = null;
        int index = 1;
        
        while((line = br.readLine())!=null){
            int numLines = Integer.parseInt(line);
            String[] lines = new String[numLines];
            String[] shortest = new String[numLines];
            for(int i=0; i<numLines; i++){
                StringBuffer sb = new StringBuffer();
                lines[i] = br.readLine();
                sb.append(lines[i].charAt(0));
                for(int j=1; j<lines[i].length(); j++){
                    if(lines[i].charAt(j)!=lines[i].charAt(j-1)){
                        sb.append(lines[i].charAt(j));
                    }
                }
                shortest[i] = sb.toString();
            }
            boolean allthesame = true;
            for(int i=0; i<shortest.length-1; i++){
                if(!shortest[i].equals(shortest[i+1])){
                    allthesame = false;
                    break;
                }
            }
            if(!allthesame){
                bw.append("Case #" + index++ + ": Fegla Won\n");
                continue;
            }
            else{
                int[][] freq = new int[numLines][shortest[0].length()];
                for(int i=0; i<numLines; i++){
                    int count = 0;
                    freq[i][count] = 1;
                    for(int k=1; k<lines[i].length(); k++){
                        if(lines[i].charAt(k)==lines[i].charAt(k-1)){
                            freq[i][count]++;
                        }
                        else{
                            count++;
                            freq[i][count]++;
                        }
                    }
                }
                int numActions = 0;
                for(int i=0; i<freq[0].length; i++){
                    int[] column = new int[freq.length];
                    for(int j=0; j<freq.length; j++){
                        column[j] = freq[j][i];
                    }
                    numActions += minActions(column);
                }
                bw.append("Case #" + index++ + ": " + numActions + "\n");
            }
        }

        bw.close();
        br.close();
    }
    
    public static int minActions(int[] val){
        int min = Integer.MAX_VALUE;
        for(int i : val){
            int numActions = 0;
            for(int j : val){
                numActions += Math.abs(i-j);
            }
            min = (numActions<min) ? numActions : min;
        }
        return min;
    }

}
