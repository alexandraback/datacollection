package cj.y2015.r1a;

import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;
import java.util.Scanner;

/**
 * Created by admin on 4/6/2015.
 */
public class B {

    private Scanner scanner;
    private Writer writer;

    public static void main(String[] args) throws IOException {
        B a = new B();
        a.meat();
    }

    private void meat() throws IOException {
        scanner = new Scanner(new FileInputStream("src/cj/y2015/r1a/B-small-attempt1.in"));
        writer = new FileWriter("src/cj/y2015/r1a/B-small-attempt1.out", false);
        int t = scanner.nextInt();
        for (int i=0; i<t; i++) {
            int b = scanner.nextInt();
            long n = scanner.nextLong();
            long lcs = 1;
            long one_round_sum = 0;
            int[] m = new int[b];
            long[] mt = new long[b];
            for (int j=0; j<b; j++) {
                m[j] = scanner.nextInt();
                lcs = lcs(lcs, m[j]);
            }
            for (int j=0; j<b; j++) {
                mt[j] = lcs/m[j];
                one_round_sum += mt[j];
            }
            n %= one_round_sum;
            if (n==0)
                n = one_round_sum;
            // small
            long count = 0;
            long time = 0;
            int choose = -1;
            while (count<n) {
                for (int j=0; j<b; j++) {
                    if (time%m[j]==0) {
                        choose = j+1;
                        ++count;
                    }
                    if (count==n) {
                        break;
                    }
                }
                System.out.println("time="+time+", count="+count);
                ++time;
            }

            writer.write("Case #" +(i+1)+": "+choose+"\n");
            System.out.println("Case #" + (i + 1) + ": " + choose);
        }
        scanner.close();
        writer.close();
    }

    private long ceilingDiv(long a, long b) {
        if (a%b==0)
            return a/b;
        else
            return (a/b)+1;
    }

    private long lcs(long a, long b) {
        long gcd = gcd(a, b);
        return (a/gcd)*b;
    }

    private long gcd(long a, long b) {
        if (a<b)
            return gcd(b, a);
        if (a==1)
            return b;
        long r = a % b;
        if (r==0)
            return b;
        return gcd(b, r);
    }
}
