import java.util.*;

public class Num1
{
    public static void main(String args[])
    {
        Scanner scan = new Scanner(System.in);
        
        int t = scan.nextInt();
        for(int x = 1; x <= t; ++x)
        {
            String out = "Case #" + x + ": ";
            int n = scan.nextInt();
            String s[] = new String[n];
            String test = "";
            boolean OK = true;
            for(int i = 0; i < n; ++i)
            {
                s[i] = scan.next();
                String tmp = "" + s[i].charAt(0);
                for(int j = 1; j < s[i].length(); ++j)
                {
                    if(s[i].charAt(j) != tmp.charAt(tmp.length()-1))
                    {
                        tmp += s[i].charAt(j);
                    }
                }
                if(i == 0)
                {
                    test = tmp;
                }
                if(!test.equals(tmp))
                {
                    System.out.println(out + "Fegla Won");
                    for(int j = i + 1; j < n; ++j)
                    {
                        s[j] = scan.next();
                    }
                    OK = false;
                    break;
                }
            }
            if(!OK) continue;
            
            int counts[][] = new int[test.length()][n];
            for(int i = 0; i < n; ++i)
            {
                String tmp = "" + s[i].charAt(0);
                int cur = 0;
                counts[cur][i]++;
                for(int j = 1; j < s[i].length(); ++j)
                {
                    if(s[i].charAt(j) != tmp.charAt(tmp.length()-1))
                    {
                        tmp += s[i].charAt(j);
                        cur++;
                    }
                    counts[cur][i]++;
                }
            }
            int ans = 0;
            for(int i = 0; i < counts.length; ++i)
            {
                Arrays.sort(counts[i]);
                for(int j = 0; j < n; ++j)
                {
                    ans += Math.abs(counts[i][counts[i].length/2] - counts[i][j]);
                }
            }
            System.out.println(out + ans);
        }
    }
}
