package codejam;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.Writer;
import java.util.StringTokenizer;

public class MushroomMonster {
  private static final String OUTPUT_FILE = "task.out";

  public static void main(String[] args) throws IOException {
    FileWriter writer = new FileWriter(OUTPUT_FILE);
    try {
      FastScanner sc = new FastScanner();
      int T = sc.nextInt();
      for(int t = 1; t <= T; t++) {
        int N = sc.nextInt();
        int[] m = new int[N];
        for(int i = 0; i < N; i++) {
          m[i] = sc.nextInt();
        }
        long first = solveFirst(m);
        long second = solveSecond(m);
        printResult(writer, t, first, second);
      }
    } finally {
      writer.close();
    }
  }

  private static long solveFirst(int[] m) {
    long result = 0;
    for(int i = 0; i < m.length - 1; i++) {
      if(m[i + 1] < m[i]) {
        result += m[i] - m[i + 1];
      }
    }
    return result;
  }

  private static long solveSecond(int[] m) {
    long result = 0;

    int minSpeed = 0;
    for(int i = 0; i < m.length - 1; i++) {
      if(m[i + 1] < m[i]) {
        minSpeed = Math.max(minSpeed, m[i] - m[i + 1]);
      }
    }

    for(int i = 0; i < m.length - 1; i++) {
      if(m[i] >= minSpeed) {
        result += minSpeed;
      } else {
        result += m[i];
      }
    }

    return result;
  }

  private static void printResult(Writer writer, int t, long first, long second) throws IOException {
    writer.append("Case #" + t + ": " + first + " " + second + "\n");
    //System.out.println("Case #" + t + ": " + first + " " + second);
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
