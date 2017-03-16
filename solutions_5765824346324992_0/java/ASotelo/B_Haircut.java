// Author: Alejandro Sotelo Arevalo
package round1;

import java.io.*;
import java.math.*;
import java.util.*;

public class B_Haircut {
  // --------------------------------------------------------------------------------
  private static String ID="B";
  private static String NAME="small-attempt1";
  private static String STAGE="round1";
  private static boolean STANDARD_OUTPUT=false;
  // --------------------------------------------------------------------------------
  private static BufferedReader reader=null;
  private static PrintStream output=null;
  // --------------------------------------------------------------------------------
  public static void main(String[] args) throws Throwable {
    try (BufferedReader bufferedReader=reader=new BufferedReader(new FileReader(new File("data/"+STAGE+"/"+ID+"-"+NAME+".in")))) {
      try (PrintStream printStream=output=STANDARD_OUTPUT?System.out:new PrintStream(new File("data/"+STAGE+"/"+ID+"-"+NAME+".out"))) {
        process();
      }
    }
  }
  // --------------------------------------------------------------------------------
  private static void process() throws Throwable {
    for (int c=1,T=Integer.parseInt(reader.readLine()); c<=T; c++) {
      StringTokenizer st=new StringTokenizer(reader.readLine());
      int B=Integer.parseInt(st.nextToken());
      int N=Integer.parseInt(st.nextToken());
      int M[]=new int[B];
      st=new StringTokenizer(reader.readLine());
      for (int i=0; i<B; i++) {
        M[i]=Integer.parseInt(st.nextToken());
      }
      output.println("Case #"+c+": "+solveSlow(B,N,M));
    }
  }
  private static int solveSlow(int B, int N, int[] M) {
    int n=N-1;
    long gcd=0;
    for (int m:M) {
      gcd=gcd(gcd,m);
    }
    BigInteger lcm=BigInteger.ONE;
    for (int m:M) {
      lcm=lcm.multiply(BigInteger.valueOf(m));
    }
    lcm=lcm.divide(BigInteger.valueOf(gcd));
    BigInteger sum=BigInteger.ZERO;
    for (int m:M) {
      BigInteger v=lcm.divide(BigInteger.valueOf(m));
      sum=sum.add(v);
    }
    if (BigInteger.valueOf(n).compareTo(sum)>0) {
      n=n%sum.intValue();
    }
    int answer=-1;
    int next[]=new int[B];
    int time=0;
    loop: for (int i=0; i<=n; i++) {
      for (int b=0; b<B; b++) {
        if (next[b]==time) {
          answer=b;
          next[b]+=M[b];
          continue loop;
        }
      }
      int index=-1,min=Integer.MAX_VALUE;
      for (int b=0; b<B; b++) {
        if (next[b]<min) {
          min=next[b];
          index=b;
        }
      }
      int b=index;
      answer=b;
      next[b]+=M[b];
      time=min;
    }
    return answer+1;
  }
  static long gcd(long A, long B) {
    long a=A,b=B,t;
    while (b!=0) {
      t=b;
      b=a%b;
      a=t;
    }
    return a;
  }
}
