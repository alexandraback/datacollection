import java.io.*;
import java.util.*;

public class NoisyNeighbors
{
    static boolean[][] apt;
    static int rows, cols, n;
    static int best;
    public static void main (String[] args) throws IOException
    {
        Scanner scan = new Scanner(new File("B-small-attempt0.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("B-small-attempt0.out")));
        
        int t = scan.nextInt();
        for (int i=1; i<=t; i++)
        {
            rows = scan.nextInt();
            cols = scan.nextInt();
            n = scan.nextInt();
            best = 1000000;
            
            apt = new boolean[rows][cols];
            search(0, 0, 0, 0);
            out.println("Case #" + i + ": " + best);
        }
        out.close();
        System.exit(0);
    }
    
    static void search(int r, int c, int cnt, int unh)
    {
        if (r==rows)
        {
            if (cnt==n && unh<best)
                best = unh;
            return;
        }
        
        int nextr = (c+1==cols)?(r+1):r;
        int nextc = (c+1==cols)?0:c+1;
        
        // no tenant
        search(nextr, nextc, cnt, unh);
        
        // yes tenant
        apt[r][c] = true;
        int nextunh = unh;
        if (c!=0 && apt[r][c-1])
            nextunh++;
        if (r!=0 && apt[r-1][c])
            nextunh++;
        search(nextr, nextc, cnt+1, nextunh);
        apt[r][c] = false;
    }
}
                