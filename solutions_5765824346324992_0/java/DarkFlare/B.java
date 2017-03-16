import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.StringTokenizer;

/**
 * Created by Sumedh on 11-04-2015.
 */
public class B {
    public static void main(String[] args) {
        try{
            FileReader fr = new FileReader("E:/codejam/B-small-attempt1.in");			//
            BufferedReader br = new BufferedReader(fr);
            FileWriter fw =new FileWriter("E:/codejam/out.txt");
            BufferedWriter bw = new BufferedWriter(fw);
            int T = Integer.parseInt(br.readLine());
            for(int x=0;x<T;x++){
                //System.out.println("case is "+x);
                StringTokenizer st = new StringTokenizer(br.readLine());
                int B = Integer.parseInt(st.nextToken());
                long N = Long.parseLong(st.nextToken());
                st = new StringTokenizer(br.readLine());
                long[] m = new long[B];
                long lcm = 0;
                long served = 0;
                for(int i=0;i<B;i++){
                    m[i] = Long.parseLong(st.nextToken());
                }
                lcm = lcmofarray(m,0,B);
                for(int i=0;i<B;i++){
                    served+=lcm/m[i];
                }
                N = N%served;
                if(N==0)N=served;
                long min=1;
                int barber=-1;
                if(N<=B){
                    barber = (int)N;
                }
                else {
                    N = N-B;
                    //System.out.println("N is "+N);
                    while(N!=0){
                        for(int i=0;i<B;i++) {
                            if (min % m[i] == 0) {
                                N--;
                                if(N==0){
                                    //System.out.println("min is " +min);
                                    barber = i+1;
                                    break;
                                }
                            }
                        }
                        min++;
                    }
                }
                //System.out.println(min);
                String ans="Case #"+(x+1)+": "+barber;
                bw.write(ans);
                bw.newLine();
            }
            bw.flush();
            bw.close();
        }catch(Exception e){e.printStackTrace();}
    }
    public static long gcd(long a, long b){
        if (a<b) return gcd(b,a);
        if (a%b==0) return b;
        else return gcd(b, a%b);
    }
    public static long lcm(long a, long b){
        return ((a*b)/gcd(a,b));

    }
    public static long lcmofarray(long[] arr, int start, int end){
        if ((end-start)==1) return lcm(arr[start],arr[end-1]);
        else return (lcm (arr[start], lcmofarray(arr, start+1, end)));
    }
}
