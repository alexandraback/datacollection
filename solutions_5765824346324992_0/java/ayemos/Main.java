import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    final String LINE_SPR = System.getProperty("line.separator");
    final int BIG_MOD = 1000000007;

    class Man {
        long time;
        long availableIn;
        public Man(long time) {
            this.time = time;
            this.availableIn = 0;
        }
    }

    void run() throws Exception {
        int nt = ni();
        for(int t = 0; t < nt; t++) {
            String[] bn = ns().split(" ");
            int b = Integer.parseInt(bn[0]);
            long n = Long.parseLong(bn[1]);
            String[] ms = ns().split(" ");
            long[] M = new long[b];
            for(int i = 0; i < b; i++) 
                M[i] = Long.parseLong(ms[i]);

            Man[] MS = new Man[b];
            for(int i = 0; i < b; i++) 
                MS[i] = new Man(M[i]);

            long lcm = 1;
            for(int i = 0; i < b; i++) {
                lcm = getLCM(lcm, M[i]);
            }

            // num of customers barbers can handle in lcm time.
            long unit = 0;
            for(int i = 0; i < b; i++) 
                unit += lcm / M[i];
            n %= unit;

            if(n == 0) {
                n = unit;
            }
            int res = 0;
            int count = 0;
            boolean fin = false;
            while(!fin) {
                for(int i = 0; i < b; i++) {
//                    System.out.println(count);
                    if(MS[i].availableIn == 0) {
                        MS[i].availableIn = MS[i].time;
                        count++;
                        if(count == n) {
                            res = i;
                            fin = true;
                        }
                    }

                    MS[i].availableIn -= 1;
                }
            }
            gcjPrint(Integer.toString(res + 1), t + 1);

        }
    }


    /*
     * Templates
     */
    void dumpObjArr(Object[] arr, int n) {
        for(int i = 0; i < n; i++) {
            System.out.print(arr[i]);
            if(i < n - 1)
                System.out.print(" ");
        }
        System.out.println("");
    }

    void dumpObjArr2(Object[][] arr, int m, int n) {
        for(int j = 0; j < m; j++) 
            dumpObjArr(arr[j], n);
    }

    int ni() throws Exception {
        return Integer.parseInt(br.readLine().trim());
    }

    long nl() throws Exception {
        return Long.parseLong(br.readLine().trim());
    }

    String ns() throws Exception {
        return br.readLine();
    }

    boolean isPrime(int n) {
        for(int i=2;i<n;i++) {
            if(n%i==0)
                return false;
        }
        return true;
    }

    int getPrime(int n) {
        List<Integer> primes = new ArrayList<Integer>();
        primes.add(2);
        int count = 1;

        int x = 1;
        while(primes.size() < n) {
            x+=2;
            int m = (int)Math.sqrt(x);
            for(int p : primes) {
                if(p > m) {
                    primes.add(x);
                    break;
                }

                if(x % p == 0) 
                    break;
            }
        }

        return primes.get(primes.size() - 1);
    }

    public long getGCD(long a, long b) {
        if(a > b) {
            long tmp;
            tmp = a;
            a = b;
            b = tmp;
        }

        while(a != 0) {
            long tmp = a;
            a = b%a;
            b = tmp;
        }

        return b;
    }

    public long getLCM(long a, long b) {
        return (a * b)/getGCD(a, b);
    }

    void gcjPrint(String str, int t) {
        System.out.println("Case #" + t + ": " + str);
    }

    public static void main(String[] args) throws Exception {
        new Main().run();
    }
}




