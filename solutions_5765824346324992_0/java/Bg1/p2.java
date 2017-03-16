import java.util.*;
import java.io.*;

public class p2 
{
  static int low=0;
  static int counter=0;
  public static void main (String[]args)throws IOException
  {
    Scanner s=new Scanner (new File("B-small-attempt1 (3).in"));
    PrintWriter out=new PrintWriter(new FileWriter("out.txt"));
    //Scanner s=new Scanner (new File("in.txt"));
    
    int cases=s.nextInt();
    for (int k=0;k<cases;k++)
    {
      counter=0;
      int ans=0;
      int b=s.nextInt();
      int n=s.nextInt();
      int []time=new int[b];
      for (int x=0;x<b;x++)
      {
        time[x]=s.nextInt();
      }
      int lcm=lcm(time);
      ArrayList<Integer>list=new ArrayList<Integer>();
      int []current=new int[b];
      Arrays.fill(current,0);
      for (int x=0;x<n;x++)
      {
        if (counter==lcm)break;
        next(current);
        if (low!=9999&&current[low]==0)
        {
          current[low]+=time[low];
          list.add(low+1);
        }
        else 
        {
          pass(current);
          x--;
        }
      }
      ans=list.get((n-1)%list.size());
      out.println ("Case #"+(k+1)+": "+(ans));
      System.out.println ("Case #"+(k+1)+": "+(ans));
    }
    out.close();
  }
  public static void pass (int []arr)
  {
    for (int x=0;x<arr.length;x++)
    {
      if (arr[x]>0)
        arr[x]--;
    }
    counter++;
  }
  
  public static void next (int []arr)
  {
    low=9999;
    for (int x=0;x<arr.length;x++)
    {
      if (arr[x]==0&&x<low)
      {
        low=x;
        return;
      }
    }
  }
  private static int gcd(int a, int b)
  {
    while (b > 0)
    {
      int temp = b;
      b = a % b; // % is remainder
      a = temp;
    }
    return a;
  }
  private static int lcm(int a, int b)
  {
    return a * (b / gcd(a, b));
  }
  
  private static int lcm(int[] input)
  {
    int result = input[0];
    for(int i = 1; i < input.length; i++) result = lcm(result, input[i]);
    return result;
  }
  
}