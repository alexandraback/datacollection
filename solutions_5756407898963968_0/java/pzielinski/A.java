import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class A {

    private static Set<Integer> fillSet(final Scanner sc, final int row) {
        final Set<Integer> s = new HashSet<>();
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                final int x = sc.nextInt();
                if (i == row) {
                    s.add(x);
                }
            }
        }
        return s;
    }

    static void testcase(final Scanner sc) {
        final Set<Integer> s1 = fillSet(sc, sc.nextInt()-1);
        final Set<Integer> s2 = fillSet(sc, sc.nextInt()-1);
        final Set<Integer> result = new HashSet<>();
        for (final int x : s1) {
            if (s2.contains(x)) {
                result.add(x);
            }
        }
        switch (result.size()) {
            case 0:
                System.out.println("Volunteer cheated!");
                break;
            case 1:
                System.out.println(result.iterator().next());
                break;
            default:
                System.out.println("Bad magician!");
                break;
        }
    }

    public static void main(String... args) {
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        final int n = sc.nextInt();
        for (int i = 0; i < n; ++i) {
            System.out.print(String.format("Case #%d: ", i+1));
            testcase(sc);
        }
    }
}
