import java.io.*;
import java.util.*;

public class B{
    int[] sol=new int[1000];
    int[] m=new int[1000];
    int solver(int B, int N, int[] m){
        if(B>=N) return N;
        int[] time=Arrays.copyOf(m,B);
        int serv=0;
        int min,in; 
        boolean test;
        for(int i=B+1; i<=N;){
            //System.out.println(Arrays.toString(time) + " " + i);
            min=time[0];
            for(int j=1; j<B; j++) if(min>time[j]){
                    min=time[j];
                }
            for(int j=0; j<B; j++) if(time[j]==min){
                if(i==N) return j+1;
                time[j]=m[j];
                i++;
            }else
                time[j]-=min;
            
            test=true;
            for(int j=0; j<B; j++) if(time[j]!=m[j])
                test=false;

            //test=false;

            if(test){
                i = B+((N-B)/(i-B-1))*(i-B-1)+1;
            //    System.out.println(Arrays.toString(time) + " " + i);
            }

        }
        return B;
    }
    public static void main(String[] argin) {
        B inst = new B();
        try{
            BufferedReader in = new BufferedReader(new FileReader(argin[0]));
            PrintStream out = System.out;
            String inputLine = in.readLine();
            String[] strArr;
            int B,N;
            int T = Integer.parseInt(inputLine.trim());
            for(int ii=1; ii<=T; ii++){
                strArr=in.readLine().trim().split("[\\s]+");
                B=Integer.parseInt(strArr[0]); 
                N=Integer.parseInt(strArr[1]);
                strArr=in.readLine().trim().split("[\\s]+");
                for(int i=0; i<B; i++)
                    inst.m[i]=Integer.parseInt(strArr[i]);
                out.printf("Case #%d: %d\n", ii, inst.solver(B,N,inst.m));
            }
            in.close();
            out.close();
        }catch(Exception e){
            System.err.println(e);
        }
    }
}

