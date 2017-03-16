import java.util.*;

public class B {
    static Scanner s;
    public static void main(String[] args) {
        s = new Scanner(System.in);
        int t = s.nextInt();
        for (int i = 0; i < t; i++) {
            solve(i+1);
        }
    }

    public static void solve(int x) {
        int B = s.nextInt();
        int N = s.nextInt() - 1;
        int[] arr = new int[B];
        long mult = 1L;
        for (int i = 0; i < B; i++) {
            arr[i] = s.nextInt();
            mult = mult * arr[i] / gcd(mult, arr[i]);
        }
        // find how many each barber cuts during each lcm
        long count = 0;
        for (int i = 0 ; i < B; i++) {
            count += mult / arr[i];
        }
        long rem = N % count;
        if (rem < B) {
            System.out.println("Case #" + x + ": " + (rem+1));
            return;
        }
        
        // binary search on the time taken to reach rem
        long lo = 0;
        long hi = mult;
        while (lo < hi - 1) {
            long mid = (lo + hi) / 2;
            count = 0;
            for (int i = 0; i < B; i++) {
                count += mid / arr[i];
            }
            if (count <= rem - B) {
                lo = mid;
            } else {
                hi = mid;
            }
        }
        // lo now holds the max time he hasnt sat down yet
        count = 0;
        for (int i = 0; i < B; i++) {
            count += lo / arr[i];
        }
        count = rem - B - count;
        int pos = -1;
        for (int i = 0; i < B && count >= 0; i++) {
            if ((lo + 1) % arr[i] == 0) {
                pos = i;
                count--;
            }
        }

        System.out.println("Case #" + x + ": " + (pos+1));
    }

    public static long gcd(long a, long b) {
        if (b==0) return a;
        return gcd(b,a%b);
    }
}
