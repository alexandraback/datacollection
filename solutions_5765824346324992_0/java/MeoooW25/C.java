import java.io.*;
import java.util.*;

class C {
    public static void main(String args[]) throws Exception {
        //BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedReader br = new BufferedReader(new FileReader("B-small-attempt1.in"));
        PrintWriter pw = new PrintWriter("A.txt");
        int n = Integer.parseInt(br.readLine());
        String line;

        for (int x = 1; x <= n; x++) {
            line = br.readLine() +" "+ br.readLine();
            Scanner sc = new Scanner(line);
            int b = sc.nextInt();
            int q = sc.nextInt();
            int bar[][]=new int[b][2];
            int LCM=1;
            for(int i=0;i<b;i++) {
                bar[i][0] = sc.nextInt();
                LCM=findLCM(LCM,bar[i][0]);
            }

            int ans;
            int total=0;
            for(int i=0;i<b;i++)
                total+=LCM/bar[i][0];

            if(q%total==0){
                int min = 0;
                for (int a = 1; a < b; a++)
                    if (bar[a][0] <= bar[min][0])
                        min = a;
                ans=min;
            }
            else {
                q=q%total;
                int i;
                lp:
                while (true) {
                    int min = bar[0][1];
                    for (int a = 1; a < b; a++)
                        if (bar[a][1] < min)
                            min = bar[a][1];

                    for (i = 0; i < b; i++) {
                        bar[i][1] -= min;
                        if (bar[i][1] == 0) {
                            q--;
                            if (q == 0)
                                break lp;
                            bar[i][1] = bar[i][0];
                        }
                    }
                }
                ans=i;
            }
            pw.println("Case #"+x+": "+(ans+1));
            System.out.println(x + "> " + (ans + 1));
        }
        pw.close();
    }

    static int findLCM(int a, int b){
        if(b<a){
            int t=b;
            b=a;
            a=t;
        }
        for(int i=1;i<=a;i++){
            if(b*i%a==0)
                return b*i;
        }
        return 0;
    }
}
