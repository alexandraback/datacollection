/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package yasmin;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.HashSet;
import java.util.LinkedList;

/**
 *
 * @author Tito
 */
public class QR {
    
    private static String inputFileName = "x.in";
    private static String outputFileName = "x.out";
    
    
    private static void writeOutputToFile(String str) {
        Path file = Paths.get(outputFileName);
        try {
            Files.write(file, str.getBytes());
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    
    public static void main(String args[]) throws IOException{
        //input
        BufferedReader br = new BufferedReader(new FileReader(inputFileName));
        //to store output
        StringBuilder out = new StringBuilder();

        int testNo = Integer.parseInt(br.readLine());
        for(int i=1; i <= testNo; i++){
            
            //solution of this test case
            String sol = "";
            int found = 0;
            String answer = "";
            
            HashSet<String> set = new HashSet<>();
            int rowNum = Integer.parseInt(br.readLine());
            //read lines of this test case
            for(int j=1; j<=4;j++){
                String line = br.readLine();
                if(j==rowNum){
                    String[] row = line.split(" ");
                    for(String s : row){
                        set.add(s);
                    }
                }

            }
            
            int rowNum2 = Integer.parseInt(br.readLine());
            
            for(int j=1; j<=4;j++){
                String line = br.readLine();
                if(j==rowNum2){
                    String[] row = line.split(" ");
                    for(String s : row){
                        if(set.contains(s)){
                            found++;
                            answer=s;
                        }
                    }
                }

            }
            
            // solve the problem
            
            switch(found){
                case 0: sol = "Volunteer cheated!"; break;
                case 1: sol = answer; break;
                default : sol = "Bad magician!";
            }
            
            System.out.println(sol);
            out.append("Case #").append(i).append(": ").append(sol);
            out.append("\n");
        }
        writeOutputToFile(out.toString());
    }
    
}
