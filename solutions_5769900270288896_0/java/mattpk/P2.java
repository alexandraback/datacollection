import java.io.*;
import java.util.*;

public class P2
{
  public static void main (String[] args) throws Exception
  {
    Scanner in = new Scanner(new File("B-small-attempt5.in"));
    //Scanner in = new Scanner(System.in);
    PrintWriter out = new PrintWriter(new FileWriter("out.txt"));
    int times = in.nextInt();
    for(int t =0; t<times; t++)
    {
      int get = -66;
      int r = in.nextInt();
      int c = in.nextInt();
      int n = in.nextInt();
      
      int yo =(int)(Math.ceil((r*c)/2.0));
      if (n<= yo) get = 0;
      else if (r == 1)
      {
        n-=((int)(Math.ceil((r*c)/2.0)));
        get = 0;
        if (c%2 == 0){
          n--;
          get++;
        }
        if (n >= 0)
        get += n*2;
      }
      else if (c == 1)
      {
        n-=((int)(Math.ceil((r*c)/2.0)));
        get = 0;
        if (r%2 == 0){
          n--;
          get++;
        }
        if (n >= 0)
          get += n*2;
        }
      //else if ((r*c-n)<=((int)(Math.ceil((r-2)*(c-2)/2.0)))) get = (2*r*c-r-c)-((r*c-n)*4);
      else
      {
        System.out.println("try");
        int corners = 0;
        int centers = 0;
        int sides =0;
        boolean fill = false;
        for (int x =1; x<= r; x++)
        {
          for (int y =1; y<=c; y++)
          {
            if(fill)
            {
              if ((x==1 && y ==1)||(x==1&&y==c)||(x==r&&y==1)||(x==r&&y==c)) corners++;
              else if (x==1 || y== 1 || x == r || y == c) sides++;
              else centers++;
              fill = false;
            }
            else fill = true;
          }
        }
        
        System.out.println(centers + " " + sides + " " + corners);
        get = (2*r*c-r-c);
        int empty = (r*c-n);
        if (empty <= centers)
        {
          get -= empty*4;
        }
        else
        {
          empty-=centers;
          get -= centers*4;
          if (empty <= sides)
          {
            get -= empty*3;
          }
          else
          {
            empty -=sides;
            get -= sides*3;
            if (empty <= corners)
            {
              get -= empty*2;
            }
            else
              System.out.println("BUG");
          }
        }
      }
      String ans = ""+get;
      out.println("Case #" + (t+1) + ": " + ans);
      System.out.println("Case #" + (t+1) + ": " + ans);
    }
    in.close();
    out.close();
  }
}