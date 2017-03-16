import java.io.*;
import java.util.*;
public class A
{
    public String bd (String s)
    {
        int len = s.length();
        String n = "";
        for (int i = 0; i < len; i++)
        {
            char cur = s.charAt(i);
            if (i == 0)
            {
                n+=cur;
            }
            else
            {
                if (cur != s.charAt(i-1))
                {
                    n+=cur;
                }
            }
        }
        return n;
    }

    public static void main (String[] args) throws IOException
    {
        FileReader fin = new FileReader ("A.in");
        BufferedReader in = new BufferedReader (fin);
        
        int t;
        t = Integer.parseInt(in.readLine());
        
        A ob = new A ();
        
        for (int i = 0; i < t; i++)
        {
            int n;
            n = Integer.parseInt(in.readLine());
            String s [] = new String [n];       
            for (int j = 0; j < n; j++)
            {
                s[j] = in.readLine();
                
            }
            
            String w = ob.bd(s[0]);
            String cur = "";
            boolean fegla = false;
            int len = w.length();
            int d [][] = new int [n][len];
            for (int j = 0; j < n; j++)
            {
                cur = ob.bd(s[j]);
                if (cur.equals(w) == false)
                {
                    fegla = true;
                    break;
                }
                else
                {
                    int pos = 0;
                    for (int k = 0; k < len; k++)
                    {
                        int ctr = 0;
                        while (pos < s[j].length() && s[j].charAt(pos) == w.charAt(k))
                        {
                            pos++;
                            ctr++;
                        }
                        d[j][k] = ctr;
                    }
                }
            }
            
            if (!fegla)
            {
                int ans = 0;
                for (int j = 0; j < len; j++)
                {
                    int tot = 0;
                    for (int k = 0; k < n; k++)
                    {
                        tot+= d[k][j];
                    }
                    tot /= n;
                    for (int k = 0; k < n; k++)
                    {
                        ans += Math.abs(d[k][j] - tot);
                    }
                }
                System.out.println ("Case #"+(i+1)+": "+ans);
            }
            else
            {
                System.out.println ("Case #"+(i+1)+": Fegla Won");
            }
        }
    }
}