/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package codejam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.UnsupportedEncodingException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 *
 * @author Savvas
 */
public class Codejam {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws FileNotFoundException, UnsupportedEncodingException, IOException {
        // TODO code application logic here
        
        BufferedWriter output = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("output.txt")));
        BufferedReader input = new BufferedReader(new InputStreamReader(new FileInputStream("input.txt"), "cp1253"));
        
        Scanner in = new Scanner(input);
        int numOfCases = in.nextInt();
        
        List<String> fegla;
        int n;
        
        for (int ppp = 0; ppp < numOfCases; ppp++) {        
        
            fegla = new ArrayList<>();
            n = in.nextInt();
            in.nextLine();
            for (int i = 0; i < n; i++) {
                fegla.add(in.nextLine());                
            }
            
            StringBuilder chars = new StringBuilder(), chars2 = new StringBuilder();
            char c;
            
            c = fegla.get(0).charAt(0);
            chars.append(c);
            for (int i = 1; i < fegla.get(0).length(); i++) {
                if(fegla.get(0).charAt(i)!=c){
                    c = fegla.get(0).charAt(i);
                    chars.append(c);
                }                
            }
            
            c = fegla.get(1).charAt(0);
            chars2.append(c);
            for (int i = 1; i < fegla.get(1).length(); i++) {
                if(fegla.get(1).charAt(i)!=c){
                    c = fegla.get(1).charAt(i);
                    chars2.append(c);
                }                
            }
            
            output.append("Case #"+(ppp+1)+": ");
            
            if(chars2.toString().equals(chars.toString())){
                int[] a = new int[chars.length()], b = new int[chars.length()];
                c = fegla.get(0).charAt(0);
                int counter = 0, c2 = 0;
                
                for (int i = 1; i < fegla.get(0).length(); i++) {
                    counter++;
                    if(fegla.get(0).charAt(i)!=c){
                        c = fegla.get(0).charAt(i);
                        a[c2] = counter;
                        if(ppp==2) System.out.println(counter);
                        c2++;
                        counter = 0;
                    }                
                }
                a[c2] = counter;
                
                c = fegla.get(1).charAt(0);
                counter = 0;
                c2 = 0;
                
                for (int i = 1; i < fegla.get(1).length(); i++) {
                    counter++;
                    if(fegla.get(1).charAt(i)!=c){
                        c = fegla.get(1).charAt(i);
                        b[c2++] = counter;
                        counter = 0;
                    }                
                }
                b[c2] = counter;
                int result = 0;
                
                for (int q = 0; q < b.length; q++) {
                    result += Math.abs(b[q]-a[q]);                    
                }
                
                output.append("" + result);
            }
            else{
                output.append("Fegla Won");
            }
            
            
            
            
            
            
            
            output.newLine();
        }
        output.close();
        
    }
}
