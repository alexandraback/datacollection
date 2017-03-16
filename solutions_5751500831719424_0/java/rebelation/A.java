import java.util.*;
import java.io.*;
import static java.lang.Math.*;

public class A{
    public static void main(String[] args) throws Exception{
        new A().run();
    }

    private final int INF = 1<<20;
    int n;
    String[] ss;
    //String large;

    int match(String a, String b){
        int an = a.length();
        int bn = b.length();
        int[][] dp = new int[an+1][bn+1];
        for(int i = 1; i <= an; i++)
            for(int j = 1; j <= bn; j++){
                dp[i][j] = max(dp[i-1][j], max(dp[i][j-1], dp[i-1][j-1]+(a.charAt(i-1)==b.charAt(j-1)?1:0)));
            }
        return dp[an][bn];
    }

    int calc(String target){
        int ret = 0;
        for(String s : ss){
            int mn = min(s.length(), target.length());
            int res = match(s, target);
            if(res != mn)
                return INF;
            ret += max(s.length(), target.length()) - mn;
        }
        return ret;
    }

    ArrayList<String> part(String a){
        ArrayList<String> ret = new ArrayList<String>();
        int len = a.length();
        for(int i = 0; i < len; i++){
            char c = a.charAt(i);
            int j = i+1;
            while(j < len && a.charAt(j) == c)j++;
            j--;
            ret.add(a.substring(i, j+1));
            i = j;
        }
        return ret;
    }

    void run() throws Exception{
        Scanner sc = new Scanner(System.in);
        //BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
        // only sc.readLine() is available
        int T = sc.nextInt();
        loop:
        for(int o = 1; o <= T; o++){
            n = sc.nextInt();
            ss = new String[n];
            //large = "";
            for(int i = 0; i < n; i++){
                ss[i] = sc.next();
                /*
                if(large.length() < ss[i].length())
                    large = ss[i];
                */
            }
            System.out.printf("Case #%d: ", o);
            ArrayList<String>[] as = new ArrayList[n];
            for(int i = 0; i < n; i++){
                as[i] = part(ss[i]);
                if(i>0 && as[i-1].size() != as[i].size()){
                    System.out.println("Fegla Won");
                    continue loop;
                }
            }
            // check
            int col = as[0].size();
            for(int i = 0; i < col; i++){
                char c = as[0].get(i).charAt(0);
                for(int j = 1; j < n; j++)
                    if(as[j].get(i).charAt(0) != c){
                        System.out.println("Fegla Won");
                        continue loop;
                        
                    }
            }

            int ans = 0;
            for(int i = 0; i < col; i++){
                int mx = 0;
                for(int j = 0; j < n; j++)
                    mx = max(as[j].get(i).length(), mx);
                int mn = INF;
                for(int j = 1; j <= mx; j++){
                    int sum = 0;
                    for(int k = 0; k < n; k++)
                        sum += abs(as[k].get(i).length() - j);
                    mn = min(mn, sum);
                }
                ans += mn;
            }
            /*
            ans = min(ans, calc(large));
            int len = large.length();
            for(int i = 0; i < len; i++){
                char c = large.charAt(i);
                int j = i+1;
                while(j<len && large.charAt(j) == c)j++;
                j--;
                if(i != j){
                    String head = large.substring(0, i);
                    String tail = large.substring(j+1);
                    int m = j-i+1;
                    String temp = ""+c;
                    for(int k = 1; k < m; k++){
                        ans = min(ans, calc(head+temp+tail));
                        temp = temp + c;
                    }
                }
                i = j;
            }
            */
            //System.out.printf("Case #%d: %s\n", o, ans==INF?"Fegla Won":""+ans);
            System.out.println(ans);
        }
    }
}
