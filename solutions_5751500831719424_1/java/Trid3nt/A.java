import java.util.*;
import java.io.*;
import java.util.Arrays;

public class A{
  public static void main(String[] args){
    File file = new File("Ainput.txt");
    BufferedWriter writer = null;
    try {
      Scanner in = new Scanner(file);
      writer = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("Aoutput.txt"), "utf-8"));
      
      int T = in.nextInt();
      for (int t = 1; t <= T; t++){
        int n = in.nextInt();
        in.nextLine();
        //System.out.println(n);
        
        String[] words = new String[n];
        for (int i = 0; i < n; i++){
          words[i] = in.nextLine();
         // System.out.println(words[i]);
        }
        
        String test = words[0];
        String[] chars = new String[101];
        int pos = 0;
        
        for (int i = 0; i < test.length(); i++){
          if (pos==0)
            chars[pos++] = test.substring(i, i+1);
          else if (test.substring(i, i+1).equals(chars[pos-1])){}
          else
            chars[pos++] = test.substring(i, i+1);
        }
        
      //  for (int i = 0; i < pos; i++)
        //  System.out.println(chars[i]);
        
        
        int[][] mat = new int[100][101];
        
        boolean impossible = false;
        for (int i = 0; i < n; i++){
          for (int k = 0; k < pos; k++){
          //  System.out.println(chars[k] + " " + words[i].substring(0,1));
            if (words[i].length() == 0){
              impossible = true;
              break;
            }
            
            if (!words[i].substring(0,1).equals(chars[k])){
              impossible = true;
              break;
            }

            int next = 0;
            while (words[i].charAt(next) == words[i].charAt(0)){
              if (next < (words[i].length()-1))
                next++;
              else{
                next++;
                break;
              }
            }
            
            mat[k][i] = next;
           // System.out.println(mat[k][i] + " " + chars[k] + " " + words[i]);
            words[i] = words[i].substring(next);
            
            if (mat[k][i] == 0)
              impossible = true;
            if (impossible)
              break;
          }
          if (impossible)
            break;
        }
        
        for (int i = 0; i < n; i++){
          if (!words[i].equals("")){
            impossible = true;
            break;
          }
        }
        
        if (impossible){
          writer.write("Case #" + t + ": Fegla Won");
          if (t!=T)
            writer.newLine();
          continue;
        }
        
        int totsum = 0;
        for (int i = 0; i < pos; i++){
          
          Integer[] col = new Integer[n];
          for (int y = 0; y < n; y++)
            col[y] = (Integer)mat[i][y];
          
          Arrays.sort(col, Collections.reverseOrder());
          int median = getMed(col, n);
          for (int j = 0; j < n; j++){
           // System.out.println(col[j] + " " + median);
            totsum += Math.abs(col[j] - median);
          }
        }
       // System.out.println();
        
        writer.write("Case #" + t + ": " + totsum);
        if (t!=T)
          writer.newLine();
      }
      in.close();
      writer.close();
    } catch (Exception e){
      e.printStackTrace();
    }
  }
  
  public static int getMed(Integer[] col, int n){
    int middle = n/2;
    if (n%2 == 1){
      return col[middle];
    }
    else
      return col[middle-1];
  }
}