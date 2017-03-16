package round.one.b;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

public class B
{

   public static void main(String[] args) throws FileNotFoundException
   {
      System.setOut(new PrintStream(new File("small.out")));
      Scanner scan = new Scanner(new File("small.in"));

      int numCases = scan.nextInt();
      for (int z = 1; z <= numCases; z++)
      {
         int r = scan.nextInt();
         int c = scan.nextInt();
         int tenants = scan.nextInt();
         
         int bitmask = 1 << (r * c);
         
         int best = Integer.MAX_VALUE / 2;
         for (int i = 0; i < bitmask; i++)
         {
            if (Integer.bitCount(i) == tenants)
            {
               boolean [][]grid = new boolean[r][c];
               for (int j = 0; (1<<j) < bitmask; j++)
               {
                  if ((i & (1<<j)) > 0)
                  {
                     int row = j / c;
                     int col = j % c;
                     grid[row][col] = true;
                  }
               }
               
               int cur = 0;
               for (int j = 0; j < r; j++)
               {
                  for (int k = 0; k < c; k++)
                  {
                     if (j < r-1 && grid[j][k] && grid[j+1][k])
                        cur++;
                     if (k < c-1 && grid[j][k] && grid[j][k+1])
                        cur++;
                  }
               }
               
               best = Math.min(best, cur);
            }
         }
         
         System.out.println("Case #" + z + ": " + best);
      }

      scan.close();
   }

}

