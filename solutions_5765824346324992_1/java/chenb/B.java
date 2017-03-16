import java.util.PriorityQueue;
import java.util.Scanner;

/**
 * Created with IntelliJ IDEA.
 * User: chenbin
 * Date: 4/18/15
 * Time: 9:25 AM
 * To change this template use File | Settings | File Templates.
 */
public class B {

    public static void main(String... args) {
        B b = new B();
        Scanner scanner = new Scanner(System.in);
        int caseNum = scanner.nextInt();
        for(int i=0; i< caseNum; i++) {


            int B = scanner.nextInt();
            int N = scanner.nextInt();
            long[] time = new long[B];
            for(int j=0; j< B; j++) {
                time[j] = scanner.nextInt();
            }


            System.out.println(String.format("Case #%d: %d", i+1, b.solution(time, N)));
        }
    }


    private static long count(long[] times, int b, int x, int N) {
        long time = times[b] * (long) (x - 1);
        long count = 0;
        for (int i = 0; i < times.length; i++) {
            count += time / times[i];
            if (time % times[i] != 0) {
                count++;
            }
            if (i < b && time % times[i] == 0) {
                count++;
            }
            if (count > N) {
                return Integer.MAX_VALUE;
            }
        }
        return count;
    }

    private int solution(long[] time, int N) {
        int B = time.length;
        if (B == 1 || N == 1) {
            return 1;
        }
        for (int b = 0; b < B; b++) {
            int l = 1;
            int r = N;
            while (l <= r) {
                int m = (l + r) / 2;
                long count = count(time, b, m, N);
                if (count == N - 1) {
                    return b + 1;
                } else if (count < N - 1) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
        }
        return 0;
    }

}
