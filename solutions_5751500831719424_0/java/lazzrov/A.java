import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;


public class A {

  static String inputFile = "A-small-attempt0.in";
  static String outputFile = "A-small-attempt0.out";
  static PrintWriter out;
  
  public static void main(String[] args) throws FileNotFoundException {
    Scanner in = new Scanner(new File(inputFile));
    out = new PrintWriter(new File(outputFile));
    
    int T = in.nextInt();
    
    for (int t = 1; t <= T; t++) {
      
      int n = in.nextInt();
      
      String s[] = new String[n];
      for (int i = 0; i < s.length; i++) {
        s[i] = in.next();
      }
      
      String base[] = new String[n];
      ArrayList<Integer> baseCount[] = new ArrayList[n];
      for (int i = 0; i < baseCount.length; i++) {
        baseCount[i] = new ArrayList<Integer>();
      }
      
      
      for (int i = 0; i < n; i++) {
        
        base[i] = "" + s[i].charAt(0);
        baseCount[i].add(1);
        
        for (int j = 1; j < s[i].length(); j++) {
          char c = s[i].charAt(j);
          if(c == base[i].charAt(base[i].length() - 1)) {
            int lastIndex = baseCount[i].size() - 1;
            Integer count = baseCount[i].get(lastIndex) + 1;
            baseCount[i].remove(lastIndex);
            baseCount[i].add(count);
            continue; 
          } else {
            base[i] += c;
            baseCount[i].add(1);
          }
        }
      }
      
      int ok = 1;
      for (int i = 1; i < base.length; i++) {
        if(!base[i].equals(base[i-1])) {
          ok = 0;
          break;
        }
      }
      
      if(ok == 0) {
        out.println("Case #" + t + ": Fegla Won");
      } else {
        
        int best = 0;
        
        for (int col = 0; col < baseCount[0].size(); col++) {
          
          int low = Integer.MAX_VALUE;
          int high = Integer.MIN_VALUE;
          for (int i = 0; i < n; i++) {
            low = Math.min(low, baseCount[i].get(col));
            high = Math.max(high, baseCount[i].get(col));
          }
          
          int min = Integer.MAX_VALUE;
          
          for (int v = low; v <= high; v++) {
            int res = 0;
            for (int i = 0; i < n; i++) {
              res += Math.abs(v - baseCount[i].get(col));
            }
            min = Math.min(min, res);
          }
          
          best += min;
        }
        
//        System.out.println(best);
        out.println("Case #" + t + ": " + best);
      }
      
    }
    
    
    out.close();
    
  }

  
}
