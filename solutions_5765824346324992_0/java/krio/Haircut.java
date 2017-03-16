package codejam;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.Writer;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Haircut {
  private static final String OUTPUT_FILE = "task.out";

  public static void main(String[] args) throws IOException {
    FileWriter writer = new FileWriter(OUTPUT_FILE);
    try {
      FastScanner sc = new FastScanner();
      int T = sc.nextInt();
      for(int t = 1; t <= T; t++) {
        int B = sc.nextInt();
        int N = sc.nextInt();
        int[] m = new int[B];
        for(int i = 0; i < B; i++) {
          m[i] = sc.nextInt();
        }
        long num = solve(m, N);
        printResult(writer, t, num);
      }
    } finally {
      writer.close();
    }
  }

  /*
   * x - moment of cut for N
   * x/M1 + x/M2 + x/M3 + x/M4 <= N
   */
  private static long solve(int[] m, int N) {
    double div = 0;
    for(int mi : m) {
      div += 1.0/mi;
    }
    long maxTime = (long)(N * (1/div) + 1);
    while(true) {
      long currentBarbed = barbedBefore(m, maxTime);
      long previousBarbed = barbedBefore(m, maxTime - 1);
      if(currentBarbed >= N && previousBarbed < N) {
        return getBarber(m, maxTime, (int)(N - previousBarbed));
      }
      maxTime--;
    }
  }

  private static int getBarber(int[] m, long t, int num) {
    ArrayList<Integer> barbersAtT = new ArrayList<Integer>();
    for(int i = 0; i < m.length; i++) {
      if(t % m[i] == 0) {
        barbersAtT.add(i + 1);
      }
    }
    Collections.sort(barbersAtT);
    return barbersAtT.get(num - 1);
  }

  private static long barbedBefore(int[] m, long t) {
    long result = 0;
    for(int mi : m) {
      result += t/mi;
    }
    result += m.length;
    return result;
  }

  private static void printResult(Writer writer, int t, long num) throws IOException {
    writer.append("Case #" + t + ": " + num + "\n");
    //System.out.println("Case #" + t + ": " + num);
  }

  private static class FastScanner {
    BufferedReader br;
    StringTokenizer st;

    public FastScanner(String s) {
      try {
        br = new BufferedReader(new FileReader(s));
      } catch (FileNotFoundException e) {
        e.printStackTrace();
      }
    }

    public FastScanner() {
      br = new BufferedReader(new InputStreamReader(System.in));
    }

    String nextToken() {
      while (st == null || !st.hasMoreElements())
        try {
          st = new StringTokenizer(br.readLine());
        } catch (IOException e) {
          e.printStackTrace();
        }
      return st.nextToken();
    }

    int nextInt() {
      return Integer.parseInt(nextToken());
    }

    long nextLong() {
      return Long.parseLong(nextToken());
    }

    double nextDouble() {
      return Double.parseDouble(nextToken());
    }
  }
}
