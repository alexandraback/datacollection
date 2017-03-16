import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class A {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int cases = sc.nextInt();
        for (int caseNum = 1; caseNum <= cases; caseNum++) {
            int first = sc.nextInt();
            Set<Integer> possible = getPossible(sc, first);
            int second = sc.nextInt();
            possible.retainAll(getPossible(sc, second));
            System.out.print("Case #" + caseNum + ": ");
            if (possible.size() == 0) {
                System.out.println("Volunteer cheated!");
            } else if (possible.size() == 1) {
                System.out.println(possible.iterator().next());
            } else {
                System.out.println("Bad magician!");
            }
        }
    }

    private static Set<Integer> getPossible(Scanner sc, int row) {
        Set<Integer> possible = new HashSet<Integer>();
        for (int i = 0; i < 16; i++) {
            int n = sc.nextInt();
            if (i / 4 + 1 == row) {
                possible.add(n);
            }
        }
        return possible;
    }
}
