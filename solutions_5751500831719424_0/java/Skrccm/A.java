import java.util.*;
import java.io.*;
public class A
{
  public static String small(String temp)
  {
    int x=0;
    while(x<temp.length()-1)
    {
      if(temp.charAt(x)==temp.charAt(x+1))
      {
        temp=temp.replaceFirst(""+temp.charAt(x)+temp.charAt(x),temp.charAt(x)+"");
      }
      else
        x++;
    }
    return temp;
  }
  public static int median(ArrayList<Integer> numbers)
  {
    if(numbers.size()%2==0)
    {
      return (numbers.get(numbers.size()/2-1)+numbers.get(numbers.size()/2))/2;
    }
    else
      return numbers.get(numbers.size()/2);
  }
  public static int[] breakdownString(String temp,int size)
  {
    int [] lolz=new int[size];
    int x=0;
    int y=0;
    int z=1;
    while(y<=size)
    {
      if(x==temp.length()-1)
      {
        lolz[size-1]=z;
        break;
      }
      else if(temp.charAt(x)==temp.charAt(x+1))
      {
        temp=temp.replaceFirst(""+temp.charAt(x)+temp.charAt(x),temp.charAt(x)+"");
        z++;
      }
      else
      {
        lolz[y]=z;
        z=1;
        x++;
        y++;
      }
    }
    //output(lolz);
    return lolz;
  }
  public static int total(int size,ArrayList<int[]>numbers)
  {
    int y=0;
    for(int x=0;x<size;x++)
    {
      ArrayList<Integer>numbers2=new ArrayList<Integer>();
      for(int z=0;z<numbers.size();z++)
      {
        numbers2.add(numbers.get(z)[x]);
      }
      Collections.sort(numbers2);
      //System.out.println(numbers2);
      int median=median(numbers2);
      //System.out.println(median);
      for(int z=0;z<numbers2.size();z++)
      {
        y+=Math.abs(numbers2.get(z)-median);
      }
    }
    return y;
  }
  public static void output(int[]temp)
  {
    for(int x=0;x<temp.length;x++)
    {
      System.out.print(temp[x]+" ");
    }
    System.out.println();
  }
  public static void main(String[]args)throws IOException
  {
    Scanner in=new Scanner(new FileReader("A-small-attempt0.in"));
    PrintWriter out=new PrintWriter(new FileWriter("A.out"));
    int num=in.nextInt();
    for(int asd=1;asd<=num;asd++)
    {
      out.print("Case #"+asd+": ");
      ArrayList<int[]> strings=new ArrayList<int[]>();
      int nums=in.nextInt();
      String tempz=in.next();
      String smallest=small(tempz);
      strings.add(breakdownString(tempz,smallest.length()));
      boolean good=true;
      
      for(int x=0;x<nums-1;x++)
      {
        String temp=in.next();
        if(!small(temp).equals(smallest)&&good)
        {
          good=false;
          out.println("Fegla Won");
        }
        else
        {
          strings.add(breakdownString(temp,smallest.length()));
        }
        //System.out.println(temp);
        //System.out.println(small(temp));
      }
      if(good)
      {
        //System.out.println(numbers);
        out.println(total(smallest.length(),strings));
      }
    }
    in.close();
    out.close();
  }
}