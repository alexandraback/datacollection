import java.util.*;

public class B
{
    public static void main(String args[])
    {
        Scanner scan = new Scanner(System.in);

        int T = scan.nextInt();
        for(int ca=1;ca <= T;ca++)
        {
            int B = scan.nextInt();
            int N = scan.nextInt();
            int[] a = new int[B];
            for(int i=0;i < B;i++)
                a[i] = scan.nextInt();

            long lo = -1;
            long hi = 1000000000000000L;
            while(lo + 100001 < hi)
            {
                long mid = (hi+lo) / 2;
                long cuts = cuts(mid, a, B);

                if(cuts > N)
                    hi = mid;
                else
                    lo = mid;
            }

            //System.err.println("lo " + lo);

            // find the real value
            long val = -1;
            long prevCuts = cuts(lo, a, B);
            for(long i=lo+1;i <= hi+1;i++)
            {
                long cuts = cuts(i, a, B);
                //System.err.println("cuts " + i + " " + cuts);
                if(cuts >= N && prevCuts < N)
                {
                    val = i;
                    break;
                }
                prevCuts = cuts;
            }

            if(val == -1) throw new RuntimeException("FUCKING BS");
            
            int ans = 0;
            for(int i=0;i < B;i++)
            {
                if(val % a[i] == 0)
                {
                    prevCuts++;
                    if(prevCuts == N)
                    {
                        ans = i+1;
                        break;
                    }
                }
            }

            
            System.out.println("Case #" + ca + ": " + ans);
        }
    }

    public static long cuts(long t, int[] a, int B)
    {
        if(t < 0) return 0;

        long cuts = 0;
        for(int i=0;i < B;i++)
            cuts += t / a[i];
        cuts += B; // Number of customers out of the queue
        return cuts;
    }
}