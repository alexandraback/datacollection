import com.sun.scenario.effect.impl.sw.sse.SSEBlend_SRC_OUTPeer;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;


public class A {

    public static void main(String[] args) throws NumberFormatException, IOException {
        String name = "A";
        // TODO READER
        boolean isSmall = true;

        BufferedReader br;//= new BufferedReader(new FileReader("bum.in"));
        if(isSmall) br = new BufferedReader(new FileReader(name+"-small-attempt0.in"));
        else br = new BufferedReader(new FileReader(name+"-large.in"));

        PrintWriter pw;
        if(isSmall) pw = new PrintWriter(name+"-small.txt", "UTF-8");
        else pw = new PrintWriter(name+"-large.txt", "UTF-8");

        int T=Integer.parseInt(br.readLine());
        for(int i = 0; i < T; i++){
            int N=Integer.parseInt(br.readLine());
            String[] tab =br.readLine().split(" ");
            int[] bff = new int[N];

            for(int j = 0; j < N; j++){
                bff[j]=Integer.parseInt(tab[j]);
            }
            String a = solution(N, bff);


            System.out.print("Case #"+(i+1)+": "+a+"\n");
            pw.write("Case #"+(i+1)+": "+a+"\n");

        }
        pw.close();
    }


    static String solution(int N, int[] tab){
        int index1=-1;
        int index2 =-1;
        for(int i=0;i<N;i++){
            if(index1<0 ||tab[index1]<tab[i]){
                index1=i;
            }
        }
        for(int i=0;i<N;i++){
            if((index2<0 ||tab[index2]<tab[i])&&i!=index1){
                index2=i;
            }
        }
        String res="";
        for(int j=0; j<tab[index1]-tab[index2];j++){
            res+=((char)(65+index1))+" ";
        }
        for(int j=0; j<N;j++){
            if(j!=index1&&j!=index2){
                for(int i=0;i<tab[j];i++){
                    res+=((char)(65+j))+" ";
                }
            }
        }
        for(int j=0; j<tab[index2];j++){


                    res+=""+((char)(65+index1))+((char)(65+index2))+" ";


        }



        return res;
    }
}