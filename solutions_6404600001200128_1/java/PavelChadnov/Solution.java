import sun.security.util.BigInt;

import java.io.*;
import java.math.BigInteger;
import java.util.*;


public class Solution {
  BufferedReader reader;

  int nextInt() throws IOException {
    tokenizer.nextToken();
    return (int) tokenizer.nval;
  }

  String next() throws IOException {
    tokenizer.nextToken();
    return tokenizer.sval;
  }

  StreamTokenizer tokenizer;
  Scanner in;


  void run() throws IOException {
//    in = new Scanner(System.in);
//    PrintWriter out = new PrintWriter(System.out);
    in = new Scanner(new File("input.txt"));
    PrintWriter out = new PrintWriter(new File("output.txt"));
    reader = new BufferedReader(new InputStreamReader(System.in));
    tokenizer = new StreamTokenizer(reader);
    solve();


    in.close();
    reader.close();
    out.close();
  }


  void solve() throws IOException {
    int tcs;
    tcs = in.nextInt();
    for (int tc = 1; tc <= tcs; tc++) {
      int n = in.nextInt();
      int[] m = new int[n];
      for (int i = 0; i < n; i++) {
        m[i] = in.nextInt();
      }
      int sum1 = 0;
      for (int i = 1; i < n; i++) if (m[i] < m[i - 1]) sum1 += m[i - 1] - m[i];
      int sum2 = 0;
      int max=0;
      for(int i=1;i<n;i++) {
        max=Math.max(max, m[i-1]-m[i]);
      }
      for(int i=0;i<n-1;i++) {
        sum2 += Math.min(m[i], max);
      }


      System.out.println("Case #" + tc + ": " + sum1+" "+sum2);
    }
  }

  public static void main(String[] args) throws IOException {
    new Solution().run();
  }
}

