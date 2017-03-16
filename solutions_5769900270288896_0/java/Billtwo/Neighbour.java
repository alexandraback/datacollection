import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashSet;
import java.io.PrintStream;
import java.io.FileOutputStream;
import java.util.Set;
import java.util.ArrayList;
import java.lang.Math;
public class Neighbour
{
  public static void main(String args[]) throws Exception
  { 
      BufferedReader input = null;
      PrintStream output = null;
      String currentLine;
      int testNo=0;
      int R=0,C=0,N=0;
      try
      {
          input = new BufferedReader(new FileReader(args[0]));
          output = new PrintStream(new FileOutputStream(args[1]));
          if((currentLine=input.readLine())!=null)
          {
              testNo=Integer.parseInt(currentLine);
          }
          
          for(int i=1;i<=testNo;i++)
          {
              if((currentLine=input.readLine())!=null)
              {
                  String[] items = currentLine.split(" ");
                  R = Integer.parseInt(items[0]);
                  C = Integer.parseInt(items[1]);
                  N = Integer.parseInt(items[2]);
              }
              else
                  throw new IOException("Cannot get data");

          
              output.println("Case #"+ i +": " + noise(R,C,N));
          }
      }
      catch (Exception e)
      {
          System.err.println(e);
      }
      finally
      {
          try
          {
              input.close();
              output.close();
          }
          catch (Exception e)
          {
              System.err.println(e);
          }
      }
  }
    
    private static int noise(int R, int C, int N)
    {
        int lowest = Integer.MAX_VALUE;
        int totalNo = R*C;
        boolean[] rent =new boolean[totalNo];
        for(int i=0;i<Math.pow(2,totalNo);i++)
        {
            for(int j=0;j<totalNo;j++)
            {
                rent[j]=(((i/(int)Math.pow(2,j)))%2==0);
            }
            
            if(rentNo(rent)!=N)
                continue;
            
            int unhappy=0;

            for(int j=0;j<totalNo;j++)
            {
                if(!rent[j])
                    continue;
                if(j%C!=C-1)
                {
                    if(rent[j+1])
                        unhappy++;
                }
                if(j+C<totalNo)
                {
                    if(rent[j+C])
                        unhappy++;
                }
            }
            if(lowest>unhappy)
                lowest=unhappy;
        }
        return lowest;
    }
    
    private static int rentNo(boolean[] rent)
    {
        int count=0;
        for(boolean thisR : rent)
            if(thisR)
                count++;
        return count;
    }
    
}
