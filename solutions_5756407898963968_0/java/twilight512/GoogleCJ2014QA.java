import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;


public class GoogleCJ2014QA {

  public static boolean isTest = false;
  public static boolean isSmall = true;
  
  public static int getIntersect(int[] row1, int[] row2) {
    int answer = 0;
    int count = 0;
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        if (row1[i] == row2[j]) {
          count--;
          answer = row1[i]; 
        }
      }
    }
    if (count != -1) {
      return count;
    }
    return answer;
  }
  
  public static void main(String[] args) {
    try {
      BufferedReader br;
      BufferedWriter bw;
      if (isTest) {
        br = new BufferedReader(new FileReader("test.txt"));
        bw = new BufferedWriter(new FileWriter("test_out.txt"));
      }
      else {
        if (isSmall) {
          br = new BufferedReader(new FileReader("A-small-attempt0.in"));
          bw = new BufferedWriter(new FileWriter("A-small-out.txt"));
        }
        else {
          br = new BufferedReader(new FileReader("A-large.in"));
          bw = new BufferedWriter(new FileWriter("A-large-out.txt"));
        }
      }
      String[] line = br.readLine().trim().split("\\s+");
      int numProbs = Integer.parseInt(line[0]);
      for (int i = 1; i <= numProbs; i++) {
        int[] firstRow = new int[4];
        int[] secondRow = new int[4];
        line = br.readLine().trim().split("\\s+");
        int rowNum = Integer.parseInt(line[0]);
        for (int j = 1; j <= 4; j++) {
          line = br.readLine().trim().split("\\s+");
          if (j == rowNum) {
            firstRow[0] = Integer.parseInt(line[0]);
            firstRow[1] = Integer.parseInt(line[1]);
            firstRow[2] = Integer.parseInt(line[2]);
            firstRow[3] = Integer.parseInt(line[3]);
          }
        }
        line = br.readLine().trim().split("\\s+");
        rowNum = Integer.parseInt(line[0]);
        for (int j = 1; j <= 4; j++) {
          line = br.readLine().trim().split("\\s+");
          if (j == rowNum) {
            secondRow[0] = Integer.parseInt(line[0]);
            secondRow[1] = Integer.parseInt(line[1]);
            secondRow[2] = Integer.parseInt(line[2]);
            secondRow[3] = Integer.parseInt(line[3]);
          }
        }
        int result = getIntersect(firstRow, secondRow);
        if (result == 0) {
          bw.write("Case #" + i + ": Volunteer cheated!\n");
        }
        else if (result < -1) {
          bw.write("Case #" + i + ": Bad magician!\n");
        }
        else {
          bw.write("Case #" + i + ": " + result + "\n");
        }
      }
      br.close();
      bw.close();
    }
    catch (IOException e) {
      System.out.println("Error in IO");
    }
  }

}
