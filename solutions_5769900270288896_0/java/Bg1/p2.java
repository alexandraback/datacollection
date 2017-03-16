import java.util.*;
import java.io.*;

public class p2 
{
  static int ans=0;
  public static void main (String[]args)throws IOException
  {
    Scanner s=new Scanner (new File("B-small-attempt0 (2).in"));
    PrintWriter out=new PrintWriter(new FileWriter("out.txt"));
    //Scanner s=new Scanner (new File("in.txt"));  
    int cases=s.nextInt();
    for (int tt=0;tt<cases;tt++)
    {
      ans=0;
      int r=s.nextInt();
      int c=s.nextInt();
      int n=s.nextInt();
      int[][]hap=new int[r][c];
      for (int y=0;y<r;y++)
      {
        for (int x=0;x<c;x++)
        {
          if (y>0)
            hap[y][x]++;
          if (y<r-1)
            hap[y][x]++;
          if (x>0)
            hap[y][x]++;
          if (x<c-1)
            hap[y][x]++;
          ans+=hap[y][x];
        }
      }
//      for (int y=0;y<r;y++)
//      {
//        for (int x=0;x<c;x++)
//        {
//          System.out.print (hap[y][x]+" ");
//        }
//        System.out.println ();
//      }
      int counter=0;
      while (counter<r*c-n)
      {
        int yc=0;
        int xc=0;
        int good=0;
        for (int y=0;y<r;y++)
        {
          for (int x=0;x<c;x++)
          {
            if (hap[y][x]>good)
            {
              yc=y;
              xc=x;
              good=hap[y][x];
            }
            if (good==4)break;
          }
          if (good==4)break;
        }
        ans-=hap[yc][xc];
        hap[yc][xc]=0;
        if (yc>0&&hap[yc-1][xc]>0)
        {
          ans--;
          hap[yc-1][xc]--;
        }
        if (yc<r-1&&hap[yc+1][xc]>0)
        {
          ans--;
          hap[yc+1][xc]--;
        }
        if (xc>0&&hap[yc][xc-1]>0)
        {
          ans--;
          hap[yc][xc-1]--;
        }
        if (xc<c-1&&hap[yc][xc+1]>0)
        {
          ans--;
          hap[yc][xc+1]--;
        }
        counter++;
      }
      out.println ("Case #"+(tt+1)+": "+(ans/2));
      System.out.println ("Case #"+(tt+1)+": "+(ans/2));
    }
    out.close();
    s.close();
  }
}