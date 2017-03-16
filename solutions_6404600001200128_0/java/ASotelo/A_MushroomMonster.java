// Author: Alejandro Sotelo Arevalo
package round1;

import java.io.*;
import java.util.*;

public class A_MushroomMonster {
  // --------------------------------------------------------------------------------
  private static String ID="A";
  private static String NAME="small-attempt0";
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
      int N=Integer.parseInt(reader.readLine()),array[]=new int[N];
      StringTokenizer st=new StringTokenizer(reader.readLine());
      for (int i=0; i<N; i++) {
        array[i]=Integer.parseInt(st.nextToken());
      }
      output.println("Case #"+c+": "+solve1(array.clone())+" "+solve2(array.clone()));
    }
  }
  private static long solve1(int[] array) {
    int N=array.length;
    long answer=0L;
    for (int i=0; i<N-1; i++) {
      if (array[i]>array[i+1]) {
        answer+=array[i]-array[i+1];
      }
    }
    return answer;
  }
  private static long solve2(int[] array) {
    int N=array.length,M=0;
    for (int v:array) {
      M=Math.max(M,v);
    }
    long answer=Long.MAX_VALUE;
    loop:for (int m=0; m<=M*10; m++) {
      long total=0L;
      for (int i=1; i<N; i++) {
        int current=Math.max(0,array[i-1]-m);
        long eaten=array[i-1]-current;
        if (current>array[i]) continue loop;
        total+=eaten;
      }
      answer=Math.min(answer,total);
    }
    return answer;
  }
}
