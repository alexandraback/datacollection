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
            out.println("Case #"+i+": "+solve(Integer.parseInt(in.readLine()),in.readLine()));
        }
        out.close();
    }
    public static String solve(int n,String input){
        int[] numbers = new int[n];
        StringTokenizer st = new StringTokenizer(input);
        for(int i=0;i<n;i++) numbers[i] = Integer.parseInt(st.nextToken());
        int maxdecrease = 0;
        int answer1 = 0;
        for(int i=0;i<n-1;i++){
            if(numbers[i+1]<numbers[i]){
                maxdecrease = Math.max(maxdecrease,numbers[i]-numbers[i+1]);
                answer1 += numbers[i]-numbers[i+1];
            }
        }
        int answer2 = 0;
        for(int i=0;i<n-1;i++){
            answer2 += Math.min(maxdecrease,numbers[i]);
        }
        return answer1+" "+answer2;
    }
}
