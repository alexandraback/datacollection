import java.util.ArrayList;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;

public class B {
    public static void main(String[] argv) {
        Scanner sc = new Scanner(System.in);

        long T = sc.nextLong();

        for (long i = 0; i < T; i++) {
            testCase(i+1, sc);
        }
    }

    private static void testCase(long caseNumber, Scanner sc) {
        int B = sc.nextInt();
        long N = sc.nextLong();

        long[] m = new long[B];
        for (int i = 0; i < B; i++) {
            m[i] = sc.nextLong();
        } 

        long time = 0;
        while (true) {
            if (proccessedAt(m, time) < N) {
                time = time*10 + 1;
            } else {
                break;
            }

            if (time < 0) {
                time = Long.MAX_VALUE;
                break;
            }
        }

        long min = time / 10;
        long max = time;

        while (min < max) {
            long mid = (min + max)/2;
            if (proccessedAt(m, mid) < N) {
                min = mid + 1;
            } else {
                max = mid;
            }
        }

        //max--;
        assert proccessedAt(m, max) >= N;
        assert proccessedAt(m, max-1) < N;

        long barber = -1;
        long tot = proccessedAt(m, max-1);
        for (int i = 0; i < B; i++) {
            if (max % m[i] == 0) {
                tot++;
                if (tot == N) {
                    barber = i+1;
                    break;
                }
            }
        }

        //System.out.prlongln(max);

        assert barber != -1;

        System.out.printf("Case #%d: %d\n", caseNumber, barber);
    }

    private static long proccessedAt(long[] m, long time) {
        if (time < 0) { return 0; }
        if (time == 0) { return m.length; }

        long tot = 0;
        for (int i = 0; i < m.length; i++) {
            tot += time / ((long)m[i]);
            tot++;
        }

        return tot;
    }
}
