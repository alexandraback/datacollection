import java.util.Scanner;

/**
 * Created by poly on 4/18/15.
 */
public class Haircut {
    public static void main(String argv[]) {
        Scanner scanner = new Scanner(System.in);
        int T = scanner.nextInt();
        for (int t = 0; t < T; t++) {
            int b = scanner.nextInt();
            int n = scanner.nextInt();
            int[] m = new int[b];
            for (int i = 0; i < b; i++) {
                m[i] = scanner.nextInt();
            }
            long low = -1L;
            long high = (Long.MAX_VALUE >> 4);
//            System.out.println(high);
            while (high > low + 1L) {
                long mid = (low + high) / 2L;
//                System.out.println(mid);
                long started = 0;
                for (int i = 0; i < b; i++) {
                    started += (mid / m[i]) + 1;
                }
                if (started >= n) high = mid;
                else low = mid;
            }
            long started = 0;
            for (int i = 0; i < b; i++) {
                started += (high / m[i]);
                if (high % m[i] > 0) started++;
            }
//            System.out.println(high + ":" + started);
            int ans = 0;
            for (int i = 0; i < b; i++) {
                if (high % m[i] == 0) {
                    if (++started == n) {
                        ans = i + 1;
                        break;
                    }
                }
            }
            System.out.println("Case #" + (t + 1) + ": " + ans);
        }
    }
}
