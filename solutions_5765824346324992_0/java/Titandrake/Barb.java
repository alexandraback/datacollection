import java.io.*;
import java.util.*;
import java.lang.*;

class Pair implements Comparable<Pair> {
    public int i;
    public long l;

        public int compareTo(Pair p2) {
            if (l < p2.l) { return -1; }
            else if (l > p2.l) { return 1;}
            else return (i - p2.i);
        }
}

public class Barb {

    public static void print(Object o) {
        System.out.println(o);
    }

    // debugging
    public static void printArray(int[] arr) {
        for (int i : arr) {
            System.out.print(i + " ");
        }
        System.out.println();
    }

    public static long numPeople(long time, long[] times) {
        long total = 0;
        for (long t : times) {
            total += 1 + (time / t);
        }
        return total;
    }

    public static int solve(long n, long[] times, int b) {
        // start at max
        long m = Long.MIN_VALUE;
        for (long l : times) { m = Math.max(m, l); }

        long low = 0;
        long high = m * n;
        long found = -1;


        // find largest time such that < n served
        while (true) {
            if (high - low <= 1) { break; }
            long avg = (low + high) / 2;
            long np = numPeople(avg, times);
            if (np >= n) {
                high = avg;
            } else if (np < n) {
                low = avg;
            } else {
                high = avg;
            }
        }
        // now we have a time
        long nbefore = numPeople(low, times);
        //print(low);print(high);print(nbefore);
        // this many people finished serving by this time
        // now fill gaps
        long[] diffs = new long[b];
        int[] inds = new int[b];
        Pair[] p = new Pair[b];
        for (int i =0; i < b; i++) {
            p[i] = new Pair();
            p[i].i = i;
            // compute time the barber will finish current person
            // low % times = time current person has been there
            // new person can join in b - this time
            p[i].l = times[i] - (low % times[i]);
        }
        Arrays.sort(p);
        int diff = (int) (n - nbefore);
        return p[(diff-1)].i+1;
        /*
        for (int i =0; i < b; i++) {
            if (low % times[i] != 0) {
                diff--;
                if (diff == 0) {
                    return i+1;
                }
            }
        }
        return -1;
        */
        // step time by time
    }

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int cases = Integer.parseInt(br.readLine());
        int b;
        long n;
        for (int i = 1; i <= cases; i++) {
       //     print(String.format("Case %d", i));
            StringTokenizer st = new StringTokenizer(br.readLine());
            b = Integer.parseInt(st.nextToken());
            n = Long.parseLong(st.nextToken());
            long[] times = new long[b];
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < b; j++) { times[j] = Long.parseLong(st.nextToken()); }
            if (n <= b) {
                System.out.println(String.format("Case #%d: %d", i, n));
            } else {
                System.out.println(String.format("Case #%d: %d", i, solve(n, times, b)));
            }
        }
    }
}
