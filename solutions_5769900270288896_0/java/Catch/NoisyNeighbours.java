import java.io.*;
import java.util.*;

public class NoisyNeighbours
{
  public static void main (String [] args) throws IOException
  {
    BufferedReader input = new BufferedReader (new FileReader ("B-small-attempt8.in"));
    PrintWriter output = new PrintWriter (new FileWriter ("output.txt"));
    int count = Integer.parseInt (input.readLine ());
    for (int counter = 1; counter <= count; counter ++)
    {
      String [] inputs = input.readLine ().split (" ");
      int rows = Integer.parseInt (inputs [0]);
      int columns = Integer.parseInt (inputs [1]);
      int tenants = Integer.parseInt (inputs [2]);
      int unhappiness = 0;
      if (rows % 2 == 0 && columns % 2 == 0)
      {
        if (tenants > rows*columns/2)
        {
          tenants -= rows * columns / 2;
          if (tenants <= 2)
          {
            unhappiness += 2 * tenants;
            tenants = 0;
          }
          else
          {
            unhappiness += 4;
            tenants -= 2;
            if (tenants <= 2 * (rows/2 - 1) + 2 * (columns/2 - 1))
            {
              unhappiness += 3 * tenants;
              tenants = 0;
            }
            else
            {
              tenants -= 2 * (rows/2 - 1) + 2 * (columns/2 - 1);
              unhappiness += 3 * (2 * (rows/2 - 1) + 2 * (columns/2 - 1));
              
              unhappiness += 4 * tenants;
              tenants = 0;
            }
          }
        }
      }
      else if (rows % 2 == 1 && columns % 2 == 1)
      {
        if (rows == 1 || columns == 1)
        {
          if (tenants > (rows*columns + 1)/2)
          {
            tenants -= (rows*columns + 1)/2;
            unhappiness += 2 * tenants;
          }
        }
        else
        {
          if (tenants == rows*columns - ((rows + 1) * columns / 2 - (columns + 1)/2))
          {
            tenants = 0;
            unhappiness = 0;
          }
          else if (tenants == rows*columns - ((rows + 1) * columns / 2 - (columns + 1)/2) + 1)
          {
            tenants = 0;
            unhappiness = 3;
          }
          else if (tenants > (rows+1) * columns / 2 - (columns + 1)/2)
          {
            tenants -= (rows+1) * columns / 2 - (columns + 1)/2;
            if (tenants <= 4)
            {
              unhappiness += 2 * tenants;
              tenants = 0;
            }
            else
            {
              unhappiness += 8;
              tenants -= 4;
              if (tenants <= (rows -3) + (columns - 3))
              {
                unhappiness += 3 * tenants;
                tenants = 0;
              }
              else
              {
                tenants -= (rows -3) + (columns - 3);
                unhappiness += ((rows -3) + (columns - 3))*3;
                
                unhappiness += 4 * tenants;
                tenants = 0;
              }
            }
          }
        }
      }
      else
      {
        //rows odd, columns even
        if (rows % 2 == 0)//rows becomes odd
        {
          int temp = rows;
          rows = columns;
          columns = temp;
        }
        if (rows == 1)
        {
          if (tenants > columns/2)
          {
            tenants-=columns/2;
            if (tenants == 1)
              unhappiness = 1;
            else
              unhappiness += 1 + (tenants-1)*2;
            tenants = 0;
          }
        }
        else
        {
          if (tenants > (rows * columns / 2))
          {
            tenants -= (rows*columns/2);
            if (tenants <= 2)
            {
              unhappiness += tenants*2;
              tenants = 0;
            }
            else
            {
              unhappiness += 4;
              tenants -= 2;
              if (tenants <= ((rows-1)/2)+((rows-3)/2) + 2*(columns/2 - 1))
              {
                unhappiness += 3 * tenants;
                tenants = 0;
              }
              else
              {
                tenants -= ((rows-1)/2)+((rows-3)/2) + 2*(columns/2 - 1);
                unhappiness += 3 * (((rows-1)/2)+((rows-3)/2) + 2*(columns/2 - 1));
                
                unhappiness += 4 * tenants;
                tenants = 0;
              }
            }
          }
        }
      }
      output.println ("Case #" + counter + ": " + unhappiness);
    }
    output.close ();
  }
}