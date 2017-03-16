import java.io.*;
import java.util.*;

public class Problem1
{
  public static void main (String [] args) throws IOException
  {
    BufferedReader read = new BufferedReader (new FileReader ("A-small-attempt0.in"));
    PrintWriter print = new PrintWriter (new FileWriter ("output.txt"));
    int iterations = Integer.parseInt (read.readLine ());
    for (int x = 1; x <= iterations; x ++)
    {
      int row = Integer.parseInt (read.readLine ());
      String [] numbers = new String [4];
      for (int y = 1; y <= 4; y ++)
      {
        if (y == row)
          numbers = read.readLine ().split (" ");
        else
          read.readLine ();
      }
      int [] integers = new int [4];
      for (int y = 0; y < 4; y ++)
        integers [y] = Integer.parseInt (numbers [y]);
      
      row = Integer.parseInt (read.readLine ());
      for (int y = 1; y <= 4; y ++)
      {
        if (y == row)
          numbers = read.readLine ().split (" ");
        else
          read.readLine ();
      }
      int value = 0;
      for (int y = 0; y < 4; y ++)
      {
        for (int z = 0; z < 4; z ++)
        {
          if (value != -1 && integers [y] == Integer.parseInt (numbers [z]))
          {
            if (value == 0)
              value = integers [y];
            else
              value = -1;
          }
        }
      }
      if (value == -1)
        print.println ("Case #" + x + ": Bad magician!");
      else if (value == 0)
        print.println ("Case #" + x + ": Volunteer cheated!");
      else
        print.println ("Case #" + x + ": " + value);
    }
    print.close ();
  }
}