package roundA1;

import java.io.*;

/**
 * Created by szeyiu on 4/17/15.
 */
public class A1B {

    public static void main(String[] args) throws Exception {
        BufferedReader r = new BufferedReader(new InputStreamReader(new FileInputStream(new File("A1B.in"))));
        BufferedWriter w = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(new File("A1B.out"))));
        int T = Integer.valueOf(r.readLine());
        A1B a1B = new A1B();
        for(int i=0; i<T; ++i){
            String line = r.readLine();
            String[] splt = line.split(" ");
            int N = Integer.valueOf(splt[1]);
            line = r.readLine();
            splt = line.split(" ");
            int[] M = new int[splt.length];
            for(int j=0; j<M.length; ++j){
                M[j] = Integer.valueOf(splt[j]);
            }
            int rst = a1B.findBarbaer(N, M);
            int c = i+1;
            w.write("Case #"+c+": "+rst+"\n");
        }
        w.flush();
        w.close();
        r.close();
    }

    public int findBarbaer(long N, int[] M){
        int[] m = new int[M.length];
        for(int i=0; i<M.length; ++i){
            m[i] = M[i];
        }
        long div = smallMulArr(M);
        long turn = 0;
        for(int i=0; i<M.length; ++i){
            turn += div/M[i];
        }
        N = N%turn;
        if(N==0) N = turn;
        if(N <= M.length) return (int)N;
        else N -= M.length;
        int curEmpty = -1;
        while(N>0){
            int minBar = Integer.MAX_VALUE;
            for(int i=0; i<M.length; ++i){
                if(m[i]<minBar) minBar=m[i];
            }
            for(int i=0; i<M.length; ++i){
                m[i] -= minBar;
                if(m[i]==0){
                    m[i] = M[i];
                    curEmpty = i;
                    N--;
                    if(N==0) break;
                }
            }
        }
        return curEmpty+1;
    }

    public long smallMulArr(int[] A){
        long cur = A[0];
        for(int i=1; i<A.length; ++i){
            cur = smallMul(cur, A[i]);
        }
        return cur;
    }
    public long smallMul(long i, long j){
        long div = getGcd(i,j);
        return i*j/div;
    }
    public long getGcd(long i, long j) {
        long k;
        while ((k=i%j) != 0) {
            i = j;
            j = k;
        }
        return j;
    }
}
