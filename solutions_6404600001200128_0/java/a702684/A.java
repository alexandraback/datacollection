import java.util.Scanner;

public class A {
    public static void main(String[] argv) {
        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();

        for (int i = 0; i < T; i++) {
            testCase(i+1, sc);
        }
    }

    private static void testCase(int caseNumber, Scanner sc) {
        int N = sc.nextInt();
        int[] m = new int[N];

        for (int i = 0; i < N; i++) {
            m[i] = sc.nextInt();
        }

        long diff_tot = 0;
        int diff_max = 0;
        int prev = m[0];
        for (int i = 1; i < N; i++) {
            int diff = m[i] - m[i-1];

            if (diff <= 0) {
                diff_tot -= diff;
                diff_max = Math.max(diff_max, -diff);
            }

            prev = m[i];
        }

        long e2_tot = 0;
        for (int i = 0; i < N - 1; i++) {
            if (m[i] >= diff_max) {
                e2_tot += diff_max;
            } else {
                //if (m[i+1] == 0) {
                e2_tot += m[i];
            }
        }

        System.out.printf("Case #%d: %d %d\n", caseNumber, diff_tot, e2_tot);
    }
}
