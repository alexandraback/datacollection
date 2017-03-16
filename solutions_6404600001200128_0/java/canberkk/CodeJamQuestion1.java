/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package codejamquestion1;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 *
 * @author Canberk
 */
public class CodeJamQuestion1 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        try {
            Scanner in = new Scanner(new File("A-small-attempt0.in"));
            PrintWriter out = new PrintWriter("A-small-attempt0.out");

            int cases = Integer.parseInt(in.nextLine());
            
            for (int c = 1; c <= cases; c++) {
                String answer = "Case #" + c + ": ";
                in.nextLine();
                String[] input = in.nextLine().split(" ");
                int y = 0;
                int z = 0;
                int max = 0;
                int[] table = new int[input.length];
                for(int i = 0; i < input.length;i++){
                    table[i] = Integer.parseInt(input[i]);
                }
                for(int i = 0; i < table.length-1;i++){
                    y += Math.max(0,table[i]-table[i+1]);
                    max = Math.max(max,table[i]-table[i+1]);
                }
                for(int i = 0; i < table.length-1;i++){
                    if(max < Math.max(0,table[i])) z += max;
                    else z+= Math.max(0,table[i]);
                }
                out.println(answer + y + " " + z );
            }

            in.close();
            out.close();
        } catch (FileNotFoundException ex) {
            System.out.println("ERROR");
        }

    }
    
}
