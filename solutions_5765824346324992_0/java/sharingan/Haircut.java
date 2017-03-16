
import java.util.Arrays;
import java.util.Scanner;

/**
 * Created by misanand on 4/18/15.
 */
public class Haircut {
    static int gcd(int a, int b) {
        if( b == 0 ) return a;
        return gcd(b,a%b);
    }
    static int lcm(int a, int b) {

        return (a*b/gcd(a,b));
    }
    public static void main(String [] args) {
        Scanner scanner = new Scanner(System.in);
        int T = scanner.nextInt();
        for (int tt = 1; tt <= T; tt++) {
            int B = scanner.nextInt();
            int N = scanner.nextInt();
            int [] barbers = new int[B];
            for (int i=0;i<B;i++) barbers[i] = scanner.nextInt();
            Arrays.sort(barbers);
            int [] lcm = new int[B];
            int [] cuts = new int[B];
            lcm[0] = barbers[0];
            cuts[0] = 1;
            for (int i=1;i<B;i++) {
                lcm[i] = lcm(lcm[i-1],barbers[i]);
                cuts[i] = (lcm[i]/lcm[i-1])*cuts[i-1] + (lcm[i]/barbers[i]);
                //System.out.println("lcm = "+lcm[i]+" cuts = "+cuts[i]);
            }
            int current = -1;
            for (int i=cuts.length-1;i>0;i--) {
              if (N >= cuts[i]) {
                  N %= cuts[i];
                  current = i;
              }
            }
            String ans = "Case #"+tt+": ";
            if (N == 0) System.out.println(ans+(current+1));
            else if (N < barbers[1]) System.out.println(ans+(1));
            else System.out.println(ans+(N));
        }
    }
}
