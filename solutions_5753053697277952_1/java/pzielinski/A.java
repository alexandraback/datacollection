package gcj.round1C;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * Created by Piotr Zielinski on 5/8/16.
 */
public final class A {

    public static void main(final String... args) {
        final Scanner sc = new Scanner(System.in);
        final int t = sc.nextInt();
        for (int i = 0; i < t; ++i) {
            System.out.println(String.format("Case #%d: %s", i+1, testcase(sc)));
        }
    }

    private static String testcase(final Scanner sc) {
        final int n = sc.nextInt();
        final List<Integer> senators = new ArrayList<>();
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            senators.add(sc.nextInt());
            sum += senators.get(senators.size() - 1);
        }

        final StringBuilder results = new StringBuilder();

        if (sum % 2 == 1) {
            int best_idx = 0;
            for (int i = 1; i < n; ++i) {
                if (senators.get(i) > senators.get(best_idx)) {
                    best_idx = i;
                }
            }
            senators.set(best_idx, senators.get(best_idx) - 1);
            results.append((char)('A' + best_idx));
            results.append(" ");
        }

        while (true) {

            for (int j = 0; j < 2; ++j) {
                int best_idx = 0;
                for (int i = 1; i < n; ++i) {
                    if (senators.get(i) > senators.get(best_idx)) {
                        best_idx = i;
                    }
                }

                if (senators.get(best_idx) == 0) {
                    return results.toString();
                }

                senators.set(best_idx, senators.get(best_idx) - 1);
                results.append((char)('A' + best_idx));
            }
            results.append(" ");
        }
    }
}
