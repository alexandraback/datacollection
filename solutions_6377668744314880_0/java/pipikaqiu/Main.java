package main;

import java.awt.Point;
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

  int n;
  Point [] data;
  int [] result;

  public Main() throws FileNotFoundException, IOException {
    BufferedReader br = new BufferedReader(new FileReader("D:/C-small-attempt0.in"));
    BufferedWriter bw = new BufferedWriter(new FileWriter("D:/result.txt"));
    int cases = Integer.parseInt(br.readLine());
    for (int caseNum = 0; caseNum < cases; caseNum++) {
      String[] split = br.readLine().split(" ");
      n = Integer.parseInt(split[0]);
      data = new Point[n];
      result = new int[n];
      for (int i = 0; i < n; i++) {
        split = br.readLine().split(" ");
        data[i] = new Point(Integer.parseInt(split[0]), Integer.parseInt(split[1]));
        result[i] = n;
      }
      if (n <= 3) {
        for (int i = 0; i < n; i++) {
          result[i] = 0;
        }
      } else {
        for (int i = 0; i < n; i++) {
          for (int j = i + 1; j < n; j++) {
            int left = 0;
            int right = 0;
//            if (data[i].x == data[j].x) {
//              int x = data[i].x;
//              for (int k = 0; k < n; k++) if (k != i && k != j) {
//                if (data[k].x < x) {
//                  left ++;
//                }
//                if (data[k].x > x) {
//                  right ++;
//                }
//              }
//              result[i] = min(result[i], left, right);
//              result[j] = min(result[i], left, right);
//            } else {
            for (int k = 0; k < n; k++) if (k != i && k != j) {
              // v1 = (a, b);
              int a = data[i].x - data[j].x;
              int b = data[i].y - data[j].y;
              // v2 = (aa, bb);
              int aa = data[i].x - data[k].x;
              int bb = data[i].y - data[k].y;
              long abb = ((long) a) * bb;
              long baa = ((long) b) * aa;
              if (abb < baa) {
                right ++;
              }
              if (abb > baa) {
                left ++;
              }
            }
            result[i] = min(result[i], left, right);
            result[j] = min(result[j], left, right);
          }
//          }
        }
      }
      // output
      System.out.println(getResult(caseNum));
      bw.write(getResult(caseNum));
      bw.write(changeLine);
    }
    br.close();
    bw.close();
  }

  public String getResult(int caseNum) {
    String str = "Case #" + (caseNum + 1) + ":";
    for (int i = 0; i < data.length; i++) {
      str += (changeLine + result[i]);
    }
    return str;
  }

  private int min(int a, int b, int c) {
    if (a < b) {
      return a < c ? a : c;
    } else {
      return b < c ? b : c;
    }
  }
}
