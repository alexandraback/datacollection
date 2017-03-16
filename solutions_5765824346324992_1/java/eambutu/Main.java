/**
 * Created by Phillip on 4/17/2015.
 */
import java.io.*;
import java.util.*;
public class Main {
    public static void main(String[] args)throws IOException{
        BufferedReader in = new BufferedReader(new FileReader("input.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("output.out")));
        int t = Integer.parseInt(in.readLine());
        for(int i=1;i<=t;i++){
            StringTokenizer st = new StringTokenizer(in.readLine());
            out.println("Case #"+i+": "+solve(Integer.parseInt(st.nextToken()),Integer.parseInt(st.nextToken()),in.readLine()));
            System.out.println("done");
        }
        out.close();
        System.exit(0);
    }
    public static String solve(int b,int n,String input){
        int[] barbers = new int[b];
        StringTokenizer st = new StringTokenizer(input);
        int mintime = Integer.MAX_VALUE;
        for(int i=0;i<b;i++){
            barbers[i] = Integer.parseInt(st.nextToken());
            mintime = Math.min(mintime,barbers[i]);
        }
        long high = ((long)mintime) * (n-1);
        long low = 0;
        while(high!=low){
            long temp = (high+low+1)/2;
            long numcustomers = 0;
            for(int i=0;i<b;i++){
                numcustomers += (long)Math.ceil((double)temp/barbers[i]);
            }
            System.out.println(temp+" "+numcustomers);
            if(numcustomers>=n){
                high = temp-1;
            }
            else{
                low = temp;
            }
        }
        System.out.println(high);
        int customersbefore = 0;
        for(int i=0;i<b;i++){
            customersbefore += (int)Math.ceil((double)high/barbers[i]);
        }
        System.out.println(customersbefore);
        int numof = 0;
        for(int i=0;i<b;i++){
            System.out.println(i+" "+barbers[i]);
            if((high)%barbers[i]==0){
                numof++;
                if(numof+customersbefore==n) return (i+1)+"";
            }
        }
        return "Failure";
    }
}
