import java.util.*;
import java.io.*;

public class CodeJamHaircut{
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder out = new StringBuilder();
        int t = Integer.parseInt(br.readLine());
        for(int k = 1; k <= t; k++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int b = Integer.parseInt(st.nextToken());
            int n = Integer.parseInt(st.nextToken());
            int[] m = new int[b];
            st = new StringTokenizer(br.readLine());
            long max = 0;
            for(int i = 0; i < b; i++){
                m[i] = Integer.parseInt(st.nextToken());
                max = Math.max(max,m[i]);
            }
            max *= n;
            long min = 0;
            long a = (max + min)/2;
            int ind = -1;
            while(max > min){
                long cust = 0;
                ArrayList<Integer> al = new ArrayList<Integer>();
                for(int i = 0; i < b; i++){
                    long curr = (long)Math.ceil(1.0*a/m[i]);
                    if(curr * m[i] == a) al.add(i);
                    cust += curr;
                }
                if((n-1) - cust >= 0 && (n-1) - cust < al.size()){
                    ind = al.get((int)((n-1) - cust));
                    break;
                }
                if(cust >= n) max = a;
                else min = a;
                a = (max + min)/2;
                //System.out.println(max + " " + a + " " + min);
            }
            //System.out.println("yay");
            out.append(String.format("Case #%d: %d\n",k,ind+1));
        }
        System.out.print(out);
    }
}