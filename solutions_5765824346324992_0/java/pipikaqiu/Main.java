package main;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.TreeSet;

public class Main {

  public static String changeLine = System.getProperty("line.separator");

  public static void main(String[] args) throws FileNotFoundException, IOException {
    new Main();
  }

  long n;
  int t;
  int [] data;
  String base;
  int result;

  public Main() throws FileNotFoundException, IOException {
    BufferedReader br = new BufferedReader(new FileReader("D:/B-small-attempt2.in"));
    BufferedWriter bw = new BufferedWriter(new FileWriter("D:/result.txt"));
    int cases = Integer.parseInt(br.readLine());
    for (int caseNum = 0; caseNum < cases; caseNum++) {
      String[] split = br.readLine().split(" ");
      t = Integer.parseInt(split[0]);
      n = Long.parseLong(split[1]);
      split = br.readLine().split(" ");
      data = new int[t+10];
      for (int i = 1; i <= t; i++) {
        data[i] = Integer.parseInt(split[i-1]);
      }
      int gcd = 1;
      for (int i = 1; i <= t;i++) {
        gcd = gcd * data[i];
      }
      int loop = 0;
      for (int i = 1; i <= t; i++) {
        loop += (gcd / data[i]);
      }
      n = (n - 1)  % loop + 1;
      TreeSet<Barb> tree = new TreeSet<Barb>();
      for (int i = 1; i <= t; i++) {
        tree.add(new Barb(0, i));
      }
      for (long i = 1; i < n; i++) {
        Barb temp = tree.pollFirst();
        temp.time = temp.time + data[temp.no];
        tree.add(temp);
      }
      Barb temp = tree.pollFirst();
      result = temp.no;
      // output
      System.out.println("Case #" + (caseNum + 1) + ": " + getResult());
      bw.write("Case #" + (caseNum + 1) + ": " + getResult());
      bw.write(changeLine);
    }
    br.close();
    bw.close();
  }

  public String getResult() {
    return Integer.toString(result);
  }

  public static class Barb implements Comparable {

    long time;
    int no;

    public Barb(long time, int no) {
      this.time = time;
      this.no = no;
    }

    @Override
    public int compareTo(Object o) {
      if (o instanceof Barb) {
        Barb that = (Barb) o;
        if (this.time < that.time) {
          return -1;
        } else if (this.time > that.time) {
          return 1;
        } else {
          if (this.no < that.no) {
            return -1;
          } else {
            // There is no case that no = no
            return 1;
          }
        }
      }
      return 0;
    }

  }
}
