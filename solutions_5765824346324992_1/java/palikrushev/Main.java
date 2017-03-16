import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.StringTokenizer;

 
public class Main {
  
  public static void main(String[] args) throws IOException {
    
    BufferedReader br = new BufferedReader(new FileReader(new File("B-large.in")));
    BufferedWriter bw = new BufferedWriter(new FileWriter(new File("B-large.out")));
    
    int testCases = Integer.parseInt(br.readLine());
    
    for (int i = 0; i < testCases; i++) {
      
      StringTokenizer st = new StringTokenizer(br.readLine());
      
      int B = Integer.parseInt(st.nextToken());
      int N = Integer.parseInt(st.nextToken());
      
      st = new StringTokenizer(br.readLine());
      long[] input = new long[B];
      
      for (int j = 0; j < B; j++) {
        input[j] = Long.parseLong(st.nextToken());
      }
      
      String outString = String.valueOf(B1.barber(input, N));
      
      bw.write("Case #" + String.valueOf(i+1) + ": " + outString + "\n");
    }
    
    br.close();
    bw.close();    
    
  }

}
