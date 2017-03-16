import java.io.*;
import java.util.*;

public class B{
  
  public static void main (String[] args) throws Exception{
    Scanner in = new Scanner (new FileReader("B-small-attempt2.in"));
    PrintWriter out = new PrintWriter ("B.out");
    int cases = in.nextInt();
    for (int casenum = 1; casenum <= cases; casenum++){
      int b = in.nextInt();
      int n = in.nextInt();
      int[] barbers = new int[b];
      int lcm = 1;
      for(int i = 0; i < b; i++){
        barbers[i] = in.nextInt();
        int base = lcm;
        while (lcm % barbers[i] != 0){
          //System.out.println (lcm + " " + base);
          lcm += base;
        }
      }
      int cuts = 0;
      for (int i = 0; i <b; i++){
        cuts += lcm / barbers[i];
      }
      n %= cuts;
      //System.out.println (n);
      if (n == 0)
        n += cuts;
      int j = 0;
      timeLoop:
      for (int i = 0; n > 0; i++){
        for (j = 1; j <= b && n > 0; j++){
          if (i % barbers[j-1] == 0){
            n--;
            //System.out.println (j + " " + n);
          }
          if (n == 0)
            break timeLoop;
        }
      }
      
      out.println ("Case #" + casenum + ": " + j);
    }
    out.close();
    in.close();
  }
}