import java.util.*;

public class A
{
    public static void main (String [] args)
    {
        Scanner sc = new Scanner(System.in);
        int noCase = sc.nextInt();
        for(int ind =1; ind<=noCase; ind++)
        {
            int M = sc.nextInt();
            long [] arr = new long[M];
            for(int i=0; i<M; i++)
                arr[i] = sc.nextLong();
            long m1 = solve1(arr);
            long m2 = solve2(arr);
            System.out.printf("Case #%d: %d %d\n", ind, m1, m2);
        }
    }
    public static long solve1(long [] arr)
    {
        long soln = 0L;
        for(int i=0; i<arr.length-1; i++)
            if(arr[i]>arr[i+1])
                soln+=arr[i]-arr[i+1];
        return soln;
    }

    public static long solve2(long [] arr)
    {
        long soln = 0L;
        long maxD = 0L;
        for(int i=0; i<arr.length-1; i++)
            maxD = Math.max(arr[i]-arr[i+1], maxD);
        for(int i=0; i<arr.length-1; i++)
            soln+=Math.min(maxD, arr[i]);
        return soln;


    }

}
