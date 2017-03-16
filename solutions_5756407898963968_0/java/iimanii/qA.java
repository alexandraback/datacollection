/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package Jam2014;

import base.base;
import java.util.Queue;

/**
 *
 * @author Ahmed Tarek    Apr 12, 2014
 */
public class qA extends base {
    static String jam = "Jam2014";
    static String round = "Qualification";
    
    static String problem = "A";
    static String inputSize = "small";
    
    public static void main(String[] args) throws Exception {  
        checkDir("input/"+jam+"/"+round); 
        checkDir("output/"+jam+"/"+round);
        Queue<String> file = file("input/"+jam+"/"+round+"/"+problem+"-"+inputSize+"-attempt0.in");
        StringBuilder output = new StringBuilder(200);
        
        int T = Integer.parseInt(file.poll());
        for(int i=0; i < T && !file.isEmpty(); i++) {
            /* store the target 2 rows only */
            int a[][] = new int[2][4];
            for(int n=0; n < 2; n++) {
                int x = Integer.parseInt(file.poll());
                for(int j=0; j < 4; j++) {
                    String[] t = file.poll().split(" ");
                    if(j+1 == x)
                       for(int k=0; k < 4; k++)
                          a[n][k] = Integer.parseInt(t[k]);
                }
            }
            
            output.append("Case #").append(i+1).append(": ").append(solution(a[0], a[1])).append("\r\n");
        }
        
        writeFile("output/"+jam+"/"+round+"/"+problem+"-"+inputSize+"-practice.out", output.toString());
        System.out.println(output);
    }
    
    public static String solution(int a[], int b[]) {
        int x = 0, y = 0;
        
        for(int i:a) for(int j:b) if(i == j) {x++; y=i;}
        
        return x == 0 ? "Volunteer cheated!" : x == 1 ? Integer.toString(y) : "Bad magician!";
    }
}
