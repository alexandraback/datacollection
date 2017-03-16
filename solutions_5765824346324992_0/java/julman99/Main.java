import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

/**
 * @autor: julio
 */
public class Main {

    public static void main(String[] args) throws IOException {

        Scanner scanner = new Scanner(new InputStreamReader(Thread.currentThread().getContextClassLoader().getResourceAsStream("in.small")));
        int T = scanner.nextInt();

        for(int t=0;t<T;t++) {
            int B = scanner.nextInt();
            int N = scanner.nextInt();
            long[] b = new long[B];

            for(int i=0;i<B;i++) {
                b[i] = scanner.nextInt();
            }

            long lcm = lcm(b);
            int totalPerLcm = 0;
            for(int i=0;i<B;i++) {
                totalPerLcm += lcm / b[i];
            }

            if(N > totalPerLcm) {
                N %= totalPerLcm;
            }


            int barberRes = getBarberRes(B, N, b);

            if(barberRes == -1) {
                barberRes = getBarberRes(B, totalPerLcm, b);
            }

            System.out.println("Case #" + (t+1) + ": " + (barberRes + 1));
        }
    }

    private static int getBarberRes(int b, int n, long[] b2) {
        int temp=0;
        int barberRes = -1;
        long[] bbusy = new long[b];
        while (n >0) {
            for(int i=0;i< b;i++) {
                if(bbusy[i] == 0){
                    bbusy[i] = b2[i];
                    n--;
                    if(n == 0) {
                        barberRes = i;
                        break;
                    }
                }


            }
            temp++;
            for(int i=0;i< b;i++) {
                if (bbusy[i] > 0) {
                    bbusy[i]--;
                }
            }
        }
        return barberRes;
    }


    private static long gcd(long a, long b)
    {
        while (b > 0)
        {
            long temp = b;
            b = a % b; // % is remainder
            a = temp;
        }
        return a;
    }

    private static long gcd(long[] input)
    {
        long result = input[0];
        for(int i = 1; i < input.length; i++) result = gcd(result, input[i]);
        return result;
    }

    private static long lcm(long a, long b)
    {
        return a * (b / gcd(a, b));
    }

    private static long lcm(long[] input)
    {
        long result = input[0];
        for(int i = 1; i < input.length; i++) result = lcm(result, input[i]);
        return result;
    }

}
