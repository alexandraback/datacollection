import java.util.*;

public class A
{
    public static void main(String args[])
    {
        Scanner scan = new Scanner(System.in);

        int T = scan.nextInt();
        for(int ca=1;ca <= T;ca++)
        {
            int n = scan.nextInt();
            int[] p = new int[n];
            String[] a = new String[n];
            for(int i=0;i < n;i++)
                a[i] = scan.next() + 'X';

            int ans = 0;

            while(true)
            {
                // Confirm
                boolean good = true;
                char c = a[0].charAt(p[0]);
                for(int i=1;i < n;i++)
                {
                    if(a[i].charAt(p[i]) != c)
                    {
                        good = false;
                        break;
                    }
                }

                if(!good)
                {
                    ans = -1;
                    break;
                }

                if(c == 'X') break;

                int[] count = new int[n];
                int min = 999;
                int max = 0;
                for(int i=0;i < n;i++)
                {
                    while(true)
                    {
                        boolean stop = a[i].charAt(p[i]) != a[i].charAt(p[i]+1);
                        count[i]++;
                        p[i]++;
                        if(stop) break;
                    }
                    min = Math.min(min, count[i]);
                    max = Math.max(max, count[i]);
                }

                int best = 999999999;
                for(int k=min;k <= max;k++)
                {
                    int cur = 0;
                    for(int i=0;i <n;i++)
                        cur += Math.abs(count[i] - k);
                    best = Math.min(cur, best);
                }
                ans += best;
            }

            System.out.println("Case #" + ca +": " + (ans >= 0 ? ans : "Fegla Won"));
        }
    }
}