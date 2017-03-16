// Author: Alejandro Sotelo Arevalo
package round1b;

import java.io.*;
import java.util.*;

public class A_TheRepeater {
  // --------------------------------------------------------------------------------
  private static String ID="A";
  private static String NAME="small-attempt0";
  private static String STAGE="round1b";
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
  private static int N,L;
  private static void process() throws Throwable {
    for (int c=1,T=Integer.parseInt(reader.readLine()); c<=T; c++) {
      int N=Integer.parseInt(reader.readLine());
      boolean ok=true;
      Case cases[]=new Case[N];
      for (int i=0; i<N; i++) {
        cases[i]=getCase(reader.readLine());
        if (i>=1&&!Arrays.equals(cases[i].string,cases[0].string)) ok=false;
      }
      if (!ok) {
        output.println("Case #"+c+": Fegla Won");
      }
      else {
        long score=0;
        int M=cases[0].repetitions.length,numbers[]=new int[N];
        for (int j=0; j<M; j++) {
          for (int i=0; i<N; i++) {
            numbers[i]=cases[i].repetitions[j];
          }
          Arrays.sort(numbers);
          long min=Long.MAX_VALUE;
          for (int number1:numbers) {
            long sum=0L;
            for (int number2:numbers) {
              sum+=Math.abs(number2-number1);
            }
            if (sum<min) min=sum;
          }
          if (min!=Long.MAX_VALUE) score+=min;
        }
        output.println("Case #"+c+": "+score);
      }
    }
  }
  private static Case getCase(String text) {
    char[] array=text.toCharArray();
    char string[]=new char[array.length];
    int repetitions[]=new int[array.length];
    int k=0;
    for (int i=0; i<array.length; ) {
      int j=i+1;
      while (j<array.length&&array[j]==array[i]) {
        j++;
      }
      string[k]=array[i];
      repetitions[k]=j-i;
      k++;
      i=j;
    }
    return new Case(Arrays.copyOf(string,k),Arrays.copyOf(repetitions,k));
  }
  private static class Case {
    private char[] string;
    private int[] repetitions;
    public Case(char[] string, int[] repetitions) {
      this.string=string;
      this.repetitions=repetitions;
    }
  }
  
  
  private static final Comparator<char[]> comparator=new Comparator<char[]>() {
    @Override
    public int compare(char[] array1, char[] array2) {
      for (int j=0; j<L; j++) {
        if (array1[j]!=array2[j]) return (array1[j]-'0')-(array2[j]-'0');
      }
      return 0;
    }
  };

  private static int process(char[][][] matrix, int j) {
    if (j==L) {
      return 0;
    }
    int min=1<<20;
    for (int v=0; v<2; v++) {
      Arrays.sort(matrix[0],comparator);
      boolean bad=false;
      for (int i=0; !bad&&i<N; i++) {
        for (int k=0; !bad&&k<=j; k++) {
          if (matrix[0][i][k]!=matrix[1][i][k]) bad=true;
        }
      }
      if (!bad) {
        int option=v+process(matrix,j+1);
        if (option<min) min=option;
      }
      for (int i=0; i<N; i++) {
        matrix[0][i][j]=matrix[0][i][j]=='0'?'1':'0';
      }
    }
    return min;
  }
}
