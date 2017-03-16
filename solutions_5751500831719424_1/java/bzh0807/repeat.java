import java.util.*;
import java.io.*;
public class repeat
{
   public static void main(String[] args) throws IOException
   {
      Scanner in = new Scanner(new File("A-large (1).in"));
      PrintStream out = new PrintStream(new File("repeatlarge.out"));
      int a = Integer.parseInt(in.nextLine());
      for(int k = 0; k < a; k++)
      {
         int b = Integer.parseInt(in.nextLine());
         String[] arr = new String[b];
         for(int l = 0; l < b; l++)
         {
            arr[l] = in.nextLine();
         }
         String[] na = new String[b];
         for(int l = 0; l < b; l++)
         {
            na[l] = process(arr[l]);
         }
         if(!allequal(na))
         {
            out.println("Case #"+(k+1)+": "+"Fegla Won");
         }
         else
         {
            int tot = 0;
            String c = na[0];
            for(int z = 0; z < c.length(); z++)
            {
               int[] tem = processtotal(arr);
               Arrays.sort(tem);
               int y = tem.length/2;
               int x = tem[y];
               for(int w = 0; w < tem.length; w++)
               {
                  tot+=Math.abs(x-tem[w]);
               }
            }
            out.println("Case #"+(k+1)+": "+tot);

         }
      }
      //System.out.println(process("aaabccddddd"));
      
   }
   public static int[] processtotal(String[] b)
   {
      int[] n = new int[b.length];
      for(int k = 0; k < b.length; k++)
      {
         int start = 0;
         int ug = 0;
         while(start < b[k].length()-1 && b[k].substring(start, start+1).equals(b[k].substring(start+1, start+2)))
         {
            start++;
            ug++;
         }
         b[k] = b[k].substring(start+1);
         n[k] = ug;
      }
      return n;
   }
   public static boolean allequal(String[] b)
   {
      String comp = b[0];
      for(int k = 0; k < b.length; k++)
      {
         if(!b[k].equals(comp))
         {
            return false;
         }
      }
      return true;
   }
   public static String process(String s)
   {
      int ind = 0;
      String fin = "";
      for(int k = 0; k < s.length(); k++)
      {
         if(k == s.length()-1 || !s.substring(k, k+1).equals(s.substring(k+1, k+2)))
         {
            fin += s.substring(k, k+1);
         }
      }
      return fin;
   }
}