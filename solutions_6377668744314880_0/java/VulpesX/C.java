import java.util.*;
import java.awt.*;

public class C
{
    static int N;
    static Point[] a;

    public static void main(String args[])
    {
        Scanner scan = new Scanner(System.in);

        int T = scan.nextInt();
        for(int ca=1;ca <= T;ca++)
        {
            N = scan.nextInt();
            a = new Point[N];
            for(int i=0;i < N;i++)
                a[i] = new Point(scan.nextInt(), scan.nextInt());

            System.out.println("Case #" + ca + ":");
            for(int i=0;i < N;i++)
            {
                int ans = 999;
                for(int mask=0;mask < (1 << N);mask++)
                {
                    if((mask & (1 << i)) == 0) continue;
                    if(onbound(i, mask))
                        ans = Math.min(ans, N - ones(mask));
                }
                
                System.out.println(ans);
            }
        }
    }

    public static int ones(int mask)
    {
        int ans = 0;
        while(mask > 0)
        {
            if(mask % 2 == 1) ans++;
            mask /= 2;
        }
        return ans;
    }

    public static String bits(int mask)
    {
        String str = "";
        while(mask > 0)
        {
            if(mask % 2 == 1) str += "1";
            else str += "0";
            mask /= 2;
        }
        return str;
    }

    public static boolean onbound(int k, int mask)
    {
        if(N <= 3) return true;
        if(ones(mask) <= 3) return true;

        for(int i=0;i < N;i++)
        {
            if(i == k) continue;
            if((mask & (1 << i)) == 0) continue;
            boolean pos = false;
            boolean neg = false;

            for(int j=0;j < N;j++)
            {
                if(j == i || j == k) continue;
                if((mask & (1 << j)) == 0) continue;
                long cp = cp(k, i, j);
                if(cp > 0) pos = true;
                if(cp < 0) neg = true;
            }

            if(!(pos && neg)) return true;
        }

        return false;
    }

    public static long cp(int i, int j, int k)
    {
        long ax = a[j].x - a[i].x;
        long ay = a[j].y - a[i].y;
        long bx = a[k].x - a[i].x;
        long by = a[k].y - a[i].y;

        return ax*by - ay*bx;
    }
}