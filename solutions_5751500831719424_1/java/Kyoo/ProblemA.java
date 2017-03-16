package codejamA2014;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

/**
 *
 * @author Kyoo
 */
public class ProblemA {
    public static void main(String[] args)throws IOException{
        BufferedReader in= new BufferedReader(new InputStreamReader(System.in));
        int T=Integer.parseInt(in.readLine());
        for (int i = 1; i <= T; i++) {
            int N =Integer.parseInt(in.readLine());
            StringBuilder[] data= new StringBuilder[N];
            String[] dataRed= new String[N];
            for (int j = 0; j < N; j++) {
                data[j]=new StringBuilder(in.readLine());
                dataRed[j]=removeDup(data[j].toString());
            }
            if(isPossible(dataRed)){
                int r=solve(data,dataRed[0]);
                System.out.printf("Case #%d: %s%n",i,r+"");
            }
            else
                System.out.printf("Case #%d: Fegla Won%n",i);
        }
    }

    private static int solve(StringBuilder[] data,String dataRed) {
        int s=0;
        for (int i = 0; i < dataRed.length(); i++) {
            int[] vals= new int[data.length];
            for (int j = 0; j < data.length; j++) {
                int c=0;
                while(data[j].length()>0 && data[j].charAt(0)==dataRed.charAt(i)){
                    data[j].deleteCharAt(0);
                    c++;
                }
                vals[j]=c;
            }
            Arrays.sort(vals);
            int v=vals[vals.length/2];
            for (int j = 0; j < vals.length; j++) 
                s+=Math.abs(v-vals[j]);
        }
        return s;
    }

    private static String removeDup(String s) {
        StringBuilder sb= new StringBuilder("");
        int i=0;
        while(i<s.length()){
            while(i+1<s.length() && s.charAt(i)==s.charAt(i+1))i++;
            sb.append(s.charAt(i++));
        }
        return sb.toString();
    }

    private static boolean isPossible(String[] dataRed) {
        for (int i = 1; i < dataRed.length; i++)
            if(dataRed[i].compareTo(dataRed[i-1])!=0)
                return false;
        return true;
    }
}