import java.io.*;
import java.util.*;

public class A {
    static final String filename = "A";

    public static void main(String[] args) throws IOException {
        String finput = filename + ".in";
        String foutput = filename + ".out";
        Scanner s = new Scanner(new FileInputStream(finput));
        Writer w = new OutputStreamWriter(new FileOutputStream(foutput));
        A solver = new A();
        solver.solve(s, w);
        w.close();
        s.close();
    }

    void solve(Scanner s, Writer w) throws IOException {
        int T = s.nextInt();
        for (int t = 1; t <= T; t++) {
            N = s.nextInt();
            S=new String[N];
            for(int i=0;i<N;i++)
                S[i]=s.next();
            String ans = solve();
            String out = "Case #" + t + ": ";
            out += ans;
            out += "\n";
            w.write(out);
            System.out.print(out);
        }
    }

    int N;
    String[]S;
    String squeezed;
    int[][]counts;
    String solve() {
        if(!isPossible())
            return "Fegla Won";
        count();
        int ans=0;
        for(int i=0;i<squeezed.length();i++){
            int min=counts[0][i];
            int max=counts[0][i];
            for(int j=1;j<N;j++){
                min=Math.min(min,counts[j][i]);
                max=Math.max(max, counts[j][i]);
            }
            ans+=getMin(i,min,max);
        }
        return ans+"";
    }

    int getMin(int i,int l,int h){
        int best=Integer.MAX_VALUE;
        for(int k=l;k<=h;k++){
            int cnt=0;
            for(int j=0;j<N;j++){
                cnt+=Math.abs(k-counts[j][i]);
            }
            best=Math.min(best,cnt);
        }
        return best;
    }

    void count(){
        counts=new int[N][squeezed.length()];
        for(int k=0;k<N;k++){
            int c=0;
            counts[k][c]=1;
            for(int i=1;i<S[k].length();i++){
                if(S[k].charAt(i-1)==S[k].charAt(i))
                    counts[k][c]++;
                else{
                    c++;
                    counts[k][c]=1;
                }
            }
        }
        //print(counts);
    }

    boolean isPossible(){
        String[]R=new String[N];
        for(int i=0;i<N;i++)
            R[i]=squeeze(S[i]);
        Arrays.sort(R);
        squeezed=R[0];
        return R[0].equals(R[N-1]);
    }

    String squeeze(String s){
        StringBuffer sb=new StringBuffer();
        sb.append(s.charAt(0));
        for(int i=1;i<s.length();i++)
            if(s.charAt(i-1)!=s.charAt(i))
                sb.append(s.charAt(i));
        return sb.toString();
    }

    void print(int[][]A){
        for(int i=0;i<A.length;i++){
            for(int j=0;j<A[i].length;j++){
                System.out.print(A[i][j]+"\t");

            }
            System.out.println();
        }
    }
}