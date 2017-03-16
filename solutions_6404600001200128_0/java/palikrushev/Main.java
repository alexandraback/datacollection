import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.StringTokenizer;

 
public class Main {
  
  public static void main(String[] args) throws IOException {
    
    BufferedReader br = new BufferedReader(new FileReader(new File("A-small-attempt1.in")));
    BufferedWriter bw = new BufferedWriter(new FileWriter(new File("A-small-attempt1.out")));
    
    int testCases = Integer.parseInt(br.readLine());
    
    for (int i = 0; i < testCases; i++) {
      
      int size = Integer.parseInt(br.readLine());
      
      int[] input = new int[size];
      
      StringTokenizer st = new StringTokenizer(br.readLine());
      
      for (int j = 0; j < size; j++) {
        input[j] = Integer.parseInt(st.nextToken());
      }
      
      String outString = A.mushrooms(input);
      
      bw.write("Case #" + String.valueOf(i+1) + ": " + outString + "\n");
    }
    
    br.close();
    bw.close();    
    
  }

}
