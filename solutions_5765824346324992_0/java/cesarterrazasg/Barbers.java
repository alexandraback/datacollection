package v2015.round1a;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.*;

/**
 * Created by cesarterrazas on 17/04/15.
 */
public class Barbers {
    public static void main(String[] args) throws IOException {
        final String INPUT_FILE = "src/v2015/round1a/B.in";
        final String OUTPUT_FILE = "src/v2015/round1a/B.out";
        final Scanner scanner = new Scanner(new File(INPUT_FILE));
        final FileWriter fw = new FileWriter(new File(OUTPUT_FILE));
        try {
            StringBuilder stringBuilder = new StringBuilder();
            int t = scanner.nextInt();
            for (int i = 1; i <= t; i++) {
                int b = scanner.nextInt();
                long n = scanner.nextLong();
                List<Integer> times = new ArrayList<Integer>();
                List<Integer> remainingHaircut = new ArrayList<Integer>();
                for (int j = 0; j < b; j++) {
                    times.add(scanner.nextInt());
                    remainingHaircut.add(0);
                }
                System.out.println(i);
                stringBuilder.append(String.format("Case #%d: %d\n", i, getOutput(n, times, remainingHaircut)));
            }
            fw.write(stringBuilder.toString());
        } finally {
            fw.close();
            scanner.close();
        }
    }

    private static long getOutput(long n, List<Integer> t, List<Integer> r) {
        if (n < t.size())
            return n;
        int a = 0;
        long p = clientsPerRound(t);
        n = n % p;
        if(n == 0){
            n = p;
        }
        while (true) {
            int min = Collections.min(r);
            for (int i = 0; i < r.size(); i++) {
                r.set(i, r.get(i) - min);
                if (r.get(i) == 0) {
                    a++;
                    if (a == n) {
                        return i + 1;
                    }
                    r.set(i, t.get(i));
                }
            }
        }
    }

    private static long gcd(long a, long b) {
        while (b > 0) {
            long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    private static long lcm(long a, long b) {
        return a * (b / gcd(a, b));
    }

    private static long lcm(List<Integer> n) {
        long result = n.get(0);
        for (int i = 1; i < n.size(); i++) result = lcm(result, n.get(i));
        return result;
    }

    private static long clientsPerRound(List<Integer> n) {
        long lcm = lcm(n);
        long a = 0;
        for (int i = 0; i < n.size(); i++) {
             a += lcm / n.get(i);
        }
        return a;
    }
}
