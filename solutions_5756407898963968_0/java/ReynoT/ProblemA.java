import java.io.*; 
import java.util.*; 

public class ProblemA
{
    
    public static void main (String [] args) throws IOException
    {
      Scanner in = new Scanner (new FileReader ("A-small-attempt0.in")); 
      PrintWriter out = new PrintWriter (new FileWriter ("Aout.txt")); 
      int asdfg = in.nextInt (); 
      for (int cases = 0; cases < asdfg; cases++)
      {
        
        int row1 = in.nextInt () - 1; 
        int [] [] array = new int [4] [4]; 
        for (int x = 0; x < 4; x++)
        {
          for (int y = 0; y < 4; y++)
          {
            array [x] [y] = in.nextInt ();
          }
        }
        
        int [] answer1 = new int [4]; 
        for (int x = 0; x < 4; x++)
        {
          answer1 [x] = array [row1][x];  
        }
        
        int row2 = in.nextInt () - 1; 
        int [] [] array1 = new int [4] [4]; 
        for (int x = 0; x < 4; x++)
        {
          for (int y = 0; y < 4; y++)
          {
            array1 [x] [y] = in.nextInt ();
          }
        }
        int [] answer2 =  new int [4]; 
        for (int x = 0; x < 4; x++)
        {
          answer2 [x] = array1 [row2][x];  
        }
        int y1 = 0;
        boolean tooMuch = false; 
        lol:
        for (int x = 0; x < 4; x++)
        {
          for (int y = 0; y < 4; y++)
          {
            if (answer1 [x] == answer2 [y])
            {
            if (y1 != 0)
            {
              tooMuch = true;
              break lol;
            }
              y1 = answer1 [x]; 
            }
          }
        }
        if (tooMuch)
          out.println ("Case #" + (cases + 1) + ": Bad magician!");
        else if (y1 == 0)
          out.println ("Case #" + (cases + 1) + ": Volunteer cheated!");
        else 
          out.println ("Case #" + (cases + 1) + ": " + y1);
      }    
      in.close ();
      out.close ();
    }
}
