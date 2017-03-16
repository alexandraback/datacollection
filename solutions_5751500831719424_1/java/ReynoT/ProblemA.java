import java.io.*; 
import java.util.*; 

public class ProblemA 
{
    public static int operations (int [] amount, int max)
    {
      int min = 99999; 
      for (int x = 1; x <= max; x++)
      {
        int counter = 0;
        for (int y = 0; y < amount.length; y++)
        {
          counter += Math.abs (amount[y] - x);
        }
        if (counter < min)
          min = counter;
      }
      
        //System.out.print (min);
      return min;
    }
    
    public static void main (String [] args) throws IOException
    {
      Scanner in = new Scanner (new FileReader ("A-large.in")); 
      PrintWriter out = new PrintWriter (new FileWriter ("aOut.txt")); 
      int asdf = in.nextInt ();
      lol:
      for (int cases = 1; cases <= asdf; cases++)
      {
        int n = in.nextInt (); 
        String [] strings = new String [n];   
        Block [] [] blocks = null;
        boolean falses = false;
        for (int x = 0; x < n; x++)
        {
          strings [x] = in.next();
          if (x == 0)
          {
            int counter = 0;
            for (int y = 0; y < strings[x].length (); y++)
            {
               if (y == 0 || strings[x].charAt (y) != strings[x].charAt (y-1))
                 counter++; 
            }
            blocks = new Block [n][counter];
          }
          int blockCounter = 0; 
          int counter = 1;
          try
          {
          for (int y = 0; y < strings[x].length ();y++)
          {
            for (int z = y + 1; z < strings[x].length (); z++)
            {
              if (strings[x].charAt (z) == strings[x].charAt (y))
              {
                counter++; 
                if (z == strings[x].length () - 1)
                {
                  
                  //System.out.print (strings[x].charAt (y) + " ");
                  blocks [x][blockCounter] = new Block (strings[x].charAt (y), counter);
                  y = z;
                }
              }
              else
              {
                y = z - 1;
                break;
              }
            }
            if (y != strings[x].length () - 1 || y == 0 || strings[x].charAt (y) != strings[x].charAt (y-1))
            {
              
           // System.out.print (strings[x].charAt (y) + " ");
            blocks [x][blockCounter] = new Block (strings[x].charAt (y), counter);
            blockCounter++;
            counter = 1;
            }
          }
          
          //System.out.println ();
          }
          catch (Exception e)
          {
           falses = true;
          }
        }
        if (falses)
        {
          out.println ("Case #" + cases + ": Fegla Won");
          continue lol;
        }
        try
        {
          int counter1 = 0;
          for (int x = 0; x < blocks[0].length; x++)
          {
            int [] amounts = new int [n];
            int max = 0;
            for (int y = 0;y < n; y++)
            {
            if (blocks[y][x] == null)
            {
              blocks[-1][-1] = null; 
            }
            if (blocks[y][x].letter != blocks[0][x].letter)
            {
              
              //System.out.println ("hi");
              blocks[-1][-1] = null; 
            }
            amounts [y] = blocks [y][x].amount;
            if (blocks[y][x].amount > max)
              max = blocks[y][x].amount;
            }
            counter1+= operations (amounts, max);
           //System.out.println ();
          }
          out.println ("Case #" + cases + ": " + counter1);
          }
          catch (Exception e)
          {
           out.println ("Case #" + cases + ": Fegla Won"); 
          }
        
      }    
      in.close ();
      out.close ();
    }
}
class Block
{
  char letter; 
  int amount; 
  
  public Block (char a, int b)
  {
   letter = a; 
   amount = b; 
  }
}