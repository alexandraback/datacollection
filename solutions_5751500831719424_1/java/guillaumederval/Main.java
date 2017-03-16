import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.OutputStreamWriter;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.Arrays;
import java.util.Locale;
import java.util.Scanner;


public class Main
{

    public static void main(String[] args) throws FileNotFoundException, UnsupportedEncodingException
    {
        //Scanner scan = new Scanner(System.in);
        //PrintStream out = System.out;
        
        Scanner scan = new Scanner(new BufferedReader(new FileReader("/Users/guillaumederval/Desktop/A-large.in")));
        PrintWriter out = new PrintWriter (new BufferedWriter(new OutputStreamWriter( new FileOutputStream("/Users/guillaumederval/Desktop/out2.txt"), "utf-8")));
        scan.useLocale(Locale.US);
        int nbTests = scan.nextInt();
        for (int test = 0; test < nbTests; test++)
        {
            int nbStrings = scan.nextInt();
            scan.nextLine();
            String[] strings = new String[nbStrings];
            String minimalString = null;
            boolean can = true;
            for (int i = 0; i < strings.length; i++)
            {
                strings[i] = scan.nextLine();
                String currentMString = "";
                for (int j = 0; j < strings[i].length(); j++)
                {
                    if(j != 0 && strings[i].charAt(j-1)==strings[i].charAt(j))
                        continue;
                    currentMString = currentMString+strings[i].charAt(j);
                }
                if(minimalString != null && !minimalString.equals(currentMString))
                {
                    can = false;
                }
                else if(minimalString == null)
                {
                    minimalString = currentMString;
                }
            }
            
            if(!can)
            {
                out.println("Case #"+(test+1)+": Fegla Won");
                continue;
            }
            
            int[][] data = new int[minimalString.length()][nbStrings];
            for (int i = 0; i < strings.length && can; i++)
            {
                int charCount = -1;
                for (int j = 0; j < minimalString.length(); j++)
                    data[j][i] = 0;
                
                for (int j = 0; j < strings[i].length(); j++)
                {
                    if(j != 0 && strings[i].charAt(j-1)==strings[i].charAt(j))
                        data[charCount][i]++;
                    else
                    {
                        charCount++;
                        data[charCount][i] = 1;
                    }
                }
            }
            
            int total = 0;
            for (int i = 0; i < minimalString.length(); i++)
            {
                Arrays.sort(data[i]);
                int median = data[i][nbStrings/2];
                for(int j = 0; j < nbStrings; j++)
                    total += Math.abs(median-data[i][j]);
            }
            out.println("Case #"+(test+1)+": "+total);
        }
        out.close();
    }

}
