import java.io.*;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * Created by noMoon on 2015-04-17.
 */
public class Haircut {
    public static void main(String[] args) throws IOException {
        File file = new File("B-small-attempt0.in.txt");
//        File file = new File("Haircut.in");
        File outputFile = new File("Haircut.out");
        BufferedWriter bw = new BufferedWriter(new FileWriter(outputFile));
        BufferedReader br = new BufferedReader(new InputStreamReader(
                new FileInputStream(file)));
        int numberOfTestCases = Integer.valueOf(br.readLine());
        int count = 0;
        while (count++ < numberOfTestCases) {
            String[] paramsOne=br.readLine().split(" ");
            int b=Integer.valueOf(paramsOne[0]);
            int n=Integer.valueOf(paramsOne[1]);
            String[] paramsTwo=br.readLine().split(" ");
            int[] time=new int[b];
            long multiplyer=1;
            for (int i=0;i<b;i++){
                time[i]=Integer.valueOf(paramsTwo[i]);
                long div=divisor(multiplyer,time[i]);
                multiplyer/=div;
                multiplyer*=time[i];
            }
            Map<Long,List<Integer>> table=new HashMap<Long, List<Integer>>();
            for (int i=0;i<b;i++){
                long m=multiplyer/time[i];
                for (long j=0;j<m;j++){
                    long minute=time[i]*j;
                    if(table.containsKey(minute)){
                        List<Integer> temp=table.get(minute);
                        temp.add(i);
                        table.put(minute,temp);
                    }else{
                        List<Integer> temp=new ArrayList<Integer>();
                        temp.add(i);
                        table.put(minute,temp);
                    }
                }
            }
            List<Integer> list=new ArrayList<Integer>();
            for (long i=0;i<multiplyer;i++){
                if(table.containsKey(i)){
                    list.addAll(table.get(i));
                }
            }
            long size=list.size();
            long mod=n%size-1;
            if(mod<0) mod=size-1;
            bw.write("Case #" + String.valueOf(count) + ": " + String.valueOf(list.get((int)mod)+1));
            bw.newLine();
        }

        bw.close();
        br.close();
    }

    public static long divisor(long a,long b){
        long c=a>b?a:b;
        long d=a>b?b:a;
        while (d!=0){
            long t=c%d;
            c=d;
            d=t;
        }
        return c;
    }
}
