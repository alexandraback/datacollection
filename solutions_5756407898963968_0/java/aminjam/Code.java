/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package code;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.*;

/**
 *
 * @author amina
 */
public class Code
{

    /**
     * @param args the command line arguments
     * @throws java.io.IOException
     */
    public static void main(String[] args) throws IOException
    {
        // TODO code application logic here
        main_A("C:\\Users\\amina\\Downloads\\A-small-attempt0.in");
    }
    
    public static void main_A(String name) throws IOException
    {
        BufferedReader br = new BufferedReader(new FileReader(name));
        PrintWriter pw = new PrintWriter(new FileWriter("C:\\Users\\amina\\Desktop\\output.txt"));
        int T = Integer.parseInt(br.readLine());
        
        mainloop: for (int co1 = 0; co1 < T; co1++)
        {
            int a1 = Integer.parseInt(br.readLine());
            int[][] arr1 = new int[4][4];
            for (int co2 = 0; co2 < 4; co2++)
            {
                String st = br.readLine();
                String parts[] = st.split(" ");
                for (int co3 = 0; co3 < 4; co3++)
                {                
                    arr1[co2][co3] = Integer.parseInt(parts[co3]);
                }
            }
            int a2 = Integer.parseInt(br.readLine());
            int[][] arr2 = new int[4][4];
            for (int co2 = 0; co2 < 4; co2++)
            {
                String st = br.readLine();
                String parts[] = st.split(" ");
                for (int co3 = 0; co3 < 4; co3++)
                {                
                    arr2[co2][co3] = Integer.parseInt(parts[co3]);
                }
            }           
            int matches = 0;
            int match = 0;
            for (int co2 = 0; co2 < 4; co2++)
            {
                for (int co3 = 0; co3 < 4; co3++)
                {
                    if (arr1[a1 - 1][co2] == arr2[a2 - 1][co3])
                    {
                        matches++;
                        if (matches > 1)
                        {
                            pw.println("Case #" + (co1 + 1) + ": " + "Bad magician!");
                            continue mainloop;
                        }
                        match = arr1[a1 - 1][co2];
                    }
                }
            }
            if (matches == 1)
            {
                pw.println("Case #" + (co1 + 1) + ": " + match);
            }
            else
            {
                pw.println("Case #" + (co1 + 1) + ": " + "Volunteer cheated!");
            }
        }                
        pw.close();
        br.close();
    }   
}
