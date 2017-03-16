package main;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class Main {

  public static String changeLine = System.getProperty("line.separator");

  public static void main(String[] args) throws FileNotFoundException, IOException {
    new Main();
  }

  int l,x,n;
  int [] data;
  String base;
  int result1, result2;

  public Main() throws FileNotFoundException, IOException {
    BufferedReader br = new BufferedReader(new FileReader("D:/A-large.in"));
    BufferedWriter bw = new BufferedWriter(new FileWriter("D:/result.txt"));
    int cases = Integer.parseInt(br.readLine());
    for (int caseNum = 0; caseNum < cases; caseNum++) {
      n = Integer.parseInt(br.readLine());
      String[] split = br.readLine().split(" ");
      data = new int[n];
      for (int i = 0; i < n; i++) {
        data[i] = Integer.parseInt(split[i]);
      }
      result1 = 0;
      result2 = 0;
      for (int i = 1 ;i < n;i++) {
        if (data[i] < data[i-1]) {
          result1 += data[i-1]-data[i];
        }
      }
      int maxEat = 0;
      for (int i = 1 ;i < n;i++) {
        if (data[i-1] - data[i] > maxEat) {
          maxEat = data[i-1] - data[i];
        }
      }
      result2 = maxEat * (n-1);
      for (int i = 0 ;i < n-1;i++) {
        if (data[i] < maxEat) {
          result2 -= (maxEat - data[i]);
        }
      }
      // output
      System.out.println("Case #" + (caseNum + 1) + ": " + getResult());
      bw.write("Case #" + (caseNum + 1) + ": " + getResult());
      bw.write(changeLine);
    }
    br.close();
    bw.close();
  }

  public String getResult() {
    return result1 + " " + result2;
  }
}
