package codejam2016;

import java.util.*;
import java.io.*;

public class A {

    private static Scanner in;

    public static void main(String[] args) throws FileNotFoundException
    {
        final File file = new File(args[0]);

        in = new Scanner(file);
        //Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        final int t = in.nextInt();
        //in.nextLine();

        for (int i = 0; i < t; i++)
        {
            final int n = in.nextInt();
            final int[] p = new int[n];
            for (int j = 0; j < n; j++)
            {
                p[j] = in.nextInt();
            }
            System.out.println("Case #" + (i + 1) + ": " + calc(p));
        }  
    }

    private static String calc(final int[] p)
    {
        String ret = "";
        while (!empty(p))
        {
            ret += removeMax(p) + " ";
        }
        return ret;
    }
    
    private static String removeMax(final int[] p)
    {
        int i = 0;
        int j = -1;
        for (int k = 1; k < p.length; k++)
        {
            if (p[k] > p[i])
            {
                i = k;
                j = -1;
            }
            else if (p[k] == p[i])
            {
                if (j < 0)
                    j = k;
                else
                    j = -1;
            }
        }
        p[i]--;
        if (j >= 0) p[j]--;
        return "" + character(i) + (j>=0 ? "" + character(j) : "");
    }

    private static boolean empty(final int[] p)
    {
        for (int pi : p)
        {
            if (pi != 0)
                return false;
        }
        return true;
    }
    
    private static char character(int pi)
    {
        return (char) ('A' + pi);
    }
}
