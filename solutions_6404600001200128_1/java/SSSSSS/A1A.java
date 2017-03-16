package roundA1;

import java.io.*;

/**
 * Created by szeyiu on 4/17/15.
 */
public class A1A {
    public static void main(String[] args) throws Exception {
        BufferedReader r = new BufferedReader(new InputStreamReader(new FileInputStream(new File("A1A.in"))));
        BufferedWriter w = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(new File("A1A.out"))));
        int T = Integer.valueOf(r.readLine());
        A1A a1A = new A1A();
        for(int i=0; i<T; ++i){
            r.readLine();
            String line = r.readLine();
            String[] splt = line.split(" ");
            int[] A = new int[splt.length];
            for(int j=0; j<A.length; ++j){
                A[j] = Integer.valueOf(splt[j]);
            }
            int c = i+1;
            w.write("Case #"+c+": "+ a1A.method1(A) + " "+  a1A.method2(A)+ "\n");
        }
        w.flush();
        w.close();
        r.close();
    }

    int method1(int[] A){
        int count1 = 0;
        for(int i=0; i<A.length-1; ++i){
            if(A[i]>A[i+1]){
                count1 += A[i]-A[i+1];
            }
        }
        return count1;
    }

    int method2(int[] A){
        int maxInt = -1;
        for(int i=0; i<A.length-1; ++i){
            if(A[i]-A[i+1]>maxInt) maxInt = A[i]-A[i+1];
        }
        int count = 0;
        for(int i=0; i<A.length-1; ++i){
            if(A[i]>maxInt) count+=maxInt;
            else count+=A[i];
        }
        return count;
    }
}
