/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package googlecodejam;
import java.io.*;
import java.util.*;
import java.util.logging.Level;
import java.util.logging.Logger;
import java.lang.Math;
/**
 *
 * @author akhilesh.m
 */
public class Repeater
{
    String [] mStrings;
    int N;
    StringBuilder mBaseString;
    public Repeater()
    {
        mBaseString = new StringBuilder();
        N = 0;
    }
    void CreateBaseString()
    {
        int j = 1;
        int s = 0;
        mBaseString = new StringBuilder();
        mBaseString.append(mStrings[0].charAt(s));
        while(j < mStrings[0].length())
        {
            if(mStrings[0].charAt(s) == mStrings[0].charAt(j))
            {
            }
            else
            {
                mBaseString.append(mStrings[0].charAt(j)); 
                s = j;
            }
            j++;
        }
    }
    boolean Match(int i)
    {
        int j = 1;
        int s = 0;
        StringBuilder newString = new StringBuilder();
        newString.append(mStrings[i].charAt(s));
        while(j < mStrings[i].length())
        {
            if(mStrings[i].charAt(s) == mStrings[i].charAt(j))
            {
            }
            else
            {
                newString.append(mStrings[i].charAt(j)); 
                s = j;
            }
            j++;
        }
        boolean retval;
        if(newString.toString().equals(mBaseString.toString()))
        {
            retval = true;
        }
        else
        {
            retval = false;
        }
        return retval;
    }
    int FindFrequency(int strIdx, int i)
    {
        String str = mStrings[strIdx];
        int idx = -1;
        int x = 1;
        int b = 0;
        while(x < str.length())
        {
            if(str.charAt(b) == str.charAt(x))
            {
                
            }
            else
            {
                idx++;
                if(idx == i)
                {
                    return x - b;
                }
                b = x;
            }
            x++;
        }
        idx++;
        if(idx == i)
        {
            return x - b;
        }
        return -1;
    }
    
    int GetMoves()
    {
        CreateBaseString();
        for(int i = 1; i < N; i++)
        {
            if(Match(i) == false)
            {
                return -1;
            }
        }
        
        int numChars = mBaseString.length();
        int moves = 0;
        for(int i = 0; i < numChars; i++)
        {
            int[] freq = new int[N];
            for(int j = 0; j < N; j++)
            {
                freq[j] = FindFrequency(j, i);
           
            }
            Arrays.sort(freq);
           
            if(N%2 == 1)
            {
                for(int k = 0; k < N; k++)
                {
                    moves += Math.abs(freq[k] - freq[k/2]);
                }
            }
            else
            {
                int amoves = 0;
                for(int k = 0; k < N; k++)
                {
                    amoves += Math.abs(freq[k] - freq[N/2]);
                }
                int bmoves = 0;
                for(int k = 0; k < N; k++)
                {
                    bmoves += Math.abs(freq[k] - freq[N/2 - 1]);
                }
                if(amoves < bmoves)
                {
                    moves += amoves;
                }
                else
                {
                    moves += bmoves;
                }
            }
            
        }
        return moves;
       
    }

    
    public void Solve() throws FileNotFoundException
    {
        File Inputfil = new File("Input.txt");
        Scanner scanner = new Scanner(Inputfil);        
        
        File Outputfile = new File("Output.txt");

        // if Ouput file doesnt exists, then create it
        if (!Outputfile.exists()) 
        {
            try 
            {
                Outputfile.createNewFile();
            } 
            catch (IOException ex)
            {
                Logger.getLogger(Repeater.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
        
        //File writer to write to a file
        FileWriter fw = null;
        try 
        {
            fw = new FileWriter(Outputfile);
        } 
        catch (IOException ex) 
        {
            Logger.getLogger(Repeater.class.getName()).log(Level.SEVERE, null, ex);
        }
        
        
	BufferedWriter bw = new BufferedWriter(fw);
        
        
        int numTestCases = 0;
        if(scanner.hasNextInt())
        {
            numTestCases = scanner.nextInt();
        }
        int CaseItr = 0;
        while(CaseItr < numTestCases)
        {
            //Insert from input file here
            N = scanner.nextInt();
            scanner.nextLine();
            mStrings = new String[N];
            for(int i = 0; i < N; i++)
            {
                mStrings[i] = new String();
                mStrings[i]  = scanner.nextLine();
            }
            //Algorithm space
            
            int moves = GetMoves();
            
            
            
            
            //Algorithm ends here
            
            String answer = new String();
            answer += "Case #";
            answer += Integer.toString(CaseItr + 1);
            answer += ": ";
            //Write relevant answer here
            if(moves == -1)
            {
                answer += "Fegla Won";
            }
            else
            {
                answer += Integer.toString(moves);
            }
            //Printing answer to a file
            answer += "\n";
            try 
            {
                bw.write(answer);
                System.out.println(answer);
            } 
            catch (IOException ex) 
            {
                Logger.getLogger(Repeater.class.getName()).log(Level.SEVERE, null, ex);
               // bw.close();
            }
            CaseItr++;
        }
        try 
        {
            bw.close();
        } 
        catch (IOException ex) 
        {
            Logger.getLogger(Repeater.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    
   
    public static void main(String[] args) 
    {
        // TODO code application logic here
        Repeater solver = new Repeater();
        
        try 
        {
            solver.Solve();
        } 
        catch (FileNotFoundException ex) 
        {
            Logger.getLogger(Repeater.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
}
