
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author David
 */
public class Repeater {
    public static void main (String[] args) throws IOException
    {
         Scanner in = new Scanner(new BufferedReader(new FileReader("input.in")));
        PrintWriter out = new PrintWriter(new FileWriter("output.txt"));
        int cases = Integer.parseInt(in.next());
        for(int i = 1; i <= cases; i++)
        {
            out.printf("Case #%d: ", i);
            int n = Integer.parseInt(in.next());
            String[] array = new String[n];
            for (int j = 0; j < n; j++)
            {
                array[j] = in.next();
            }
            String base = strip(array[0]);
            boolean okay = true;
            for (String line : array)
            {
                if(!strip(line).equals(base))
                {
                    out.println("Fegla Won");
                    okay = false;
                    break;
                }
            }
            if(!okay) continue;
            Integer[][] counts = new Integer[n][];
            int index = 0;
            for (String line : array)
            {
                counts[index] = split(line);
                index++;
            }
            int change = 0;
            for(int j = 0; j < counts[0].length; j++)
            {
                int min = Integer.MAX_VALUE;
                for (int k = 1; k <= 100; k++)
                {
                    boolean changed = false;
                    int diff = 0;
                    for (int m = 0; m < counts.length; m++)
                    {
                        diff += Math.abs(k - counts[m][j]);
                        if(k - counts[m][j] < 0) changed = true;
                    }
                    min = Math.min(diff, min);
                    if (!changed) break;
                }
                change += min;
            }
            out.println(change);
        }
        out.close();
    }
    public static Integer[] split(String word)
    {
        char[] temp = word.toCharArray();
        ArrayList<Integer> count = new ArrayList<Integer>();
        
        char curr = temp[0];
        int currcount = 1;
        for (int i = 1; i < temp.length; i++)
        {
            if (temp[i] != curr)
            {
                curr = temp[i];
                count.add(currcount);
                currcount = 1;
            }
            else
            {
                currcount++;
            }
        }
        count.add(currcount);
        return count.toArray(new Integer[count.size()]);
    }
    public static String strip(String word)
    {
        char[] temp = word.toCharArray();
        String result = "";
        result += temp[0];
        char curr = temp[0];
        for (int i = 1; i < temp.length; i++)
        {
            if (temp[i] != curr)
            {
                curr = temp[i];
                result += curr;
            }
        }
        return result;
    }
}
