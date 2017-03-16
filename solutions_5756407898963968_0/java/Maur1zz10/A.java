import java.io.*;
import java.util.*;

public class A {
    static final String filename = "A";

    public static void main(String[] args) throws IOException {
        String finput = filename+".in";
        String foutput = filename+".out";
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
            B1=new int[L][L];
            B2=new int[L][L];
            A1=s.nextInt();
            for(int i=0;i<L;i++)for(int j=0;j<L;j++)B1[i][j]=s.nextInt();
            A2=s.nextInt();
            for(int i=0;i<L;i++)for(int j=0;j<L;j++)B2[i][j]=s.nextInt();
            String ans=solve();
            String out="Case #" + t + ": ";
            out+=ans;
            out+="\n";
            w.write(out);
            System.out.print(out);
        }
    }
    int A1,A2;
    int[][]B1,B2;
    int L=4;
    String solve(){
        String ans="";
        int n=-1;
        int cnt=0;
        Set<Integer>set=new HashSet<Integer>();
        for(int i=0;i<L;i++)set.add(B1[A1-1][i]);
        for(int i=0;i<L;i++){
            int x=B2[A2-1][i];
            if(set.contains(x)){
                cnt++;
                n=x;
            }
        }
        if(cnt==1)
            ans=n+"";
        else
            if(cnt==0)
                ans="Volunteer cheated!";
            else
                ans="Bad magician!";
        return ans;
    }
}