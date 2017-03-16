import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

/**
 * by dt on 4/11/14, 8:01 PM
 */
public class A {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int j = 1; j <= t; j ++) {
            int a1 = sc.nextInt();
            Set<Integer> c1 = readCards(sc, a1);
            int a2 = sc.nextInt();
            Set<Integer> c2 = readCards(sc, a2);
            c1.retainAll(c2);
            System.out.println("Case #" + j + ": " + (c1.size() == 1 ? c1.iterator().next() :
                    c1.size() == 0 ? "Volunteer cheated!" : "Bad magician!"));
        }
    }

    private static Set<Integer> readCards(Scanner sc, int a) {
        for (int i = 1; i <= (a - 1) * 4; i ++) {
            sc.nextInt();
        }
        Set<Integer> c = new HashSet<Integer>(4);
        for (int i = 0; i < 4; i ++) {
            c.add(sc.nextInt());
        }
        for (int i = a * 4 + 1; i <= 16; i ++) {
            sc.nextInt();
        }
        return c;
    }
}
