import java.io.PrintStream;
import java.util.Scanner;

public class A {


    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int T = s.nextInt();
        for (int i = 1; i <= T; i++) {
            System.out.println("Case #" + i + ": " + solve(s));
        }
    }

    private static String solve(Scanner s) {
        int n = s.nextInt();

        char[] names = new char[n];
        for (int i = 0; i < n; i++) {
            names[i] = (char) ('A' + i);
        }
        StringBuilder plan = new StringBuilder(26000);

        int total = 0;
        int[] num = new int[n];
        for (int i = 0; i < n; i++) {
            num[i] = s.nextInt();
            total += num[i];
        }

        int a = -1; // highest
        int b = -1; // second highest

        int as = 0;
        int bs = 0;

        for (int i = 0; i < n; i++) {
            if (num[i] > as) {
                b = a;
                bs = as;

                a = i;
                as = num[i];
            } else if (num[i] > bs) {
                bs = num[i];
                b = i;
            }

        }

        log("" + a + " " + b);

        while (as > bs) {
            as--;
            plan.append(names[a]).append(" ");
        }

        for (int i = 0; i < n; i++) {
            if (i == a || i == b) continue;

            while (num[i] > 0) {
                plan.append(names[i]).append(" ");
                num[i]--;
            }
        }

        while (as > 0) {
            as--;

            plan.append(names[a]).append(names[b]).append(" ");
        }

        return plan.toString();
    }

    private static PrintStream notes
            = null;// = System.out;

    public static void log(String msg) {
        if (notes != null) notes.println(msg);
    }
}
