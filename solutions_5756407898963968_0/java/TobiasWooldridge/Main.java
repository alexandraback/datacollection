import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {
    public static Set<Integer>[] readRows(Scanner in) {
        Set<Integer>[] rows = new Set[4];

        for (int row = 0; row < 4; row++) {
            rows[row] = new HashSet<Integer>();

            for (int col = 0; col < 4; col++) {
                rows[row].add(in.nextInt());
            }
        }

        return rows;
    }
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        final int testCases = in.nextInt();

        for (int testCase = 1; testCase <= testCases; testCase++) {
            int firstAnswer = in.nextInt();
            Set<Integer> firstRow = readRows(in)[firstAnswer - 1];

            int secondAnswer = in.nextInt();
            Set<Integer> secondRow = readRows(in)[secondAnswer - 1];

            Set<Integer> common = new HashSet<Integer>();
            for (int card : firstRow) {
                if (secondRow.contains(card)) {
                    common.add(card);
                }
            }

            System.out.print("Case #" + testCase + ": ");
            if (common.size() == 1) {
                System.out.println(common.iterator().next());
            }
            else if (common.size() == 0) {
                System.out.println("Volunteer cheated!");
            }
            else {
                System.out.println("Bad Magician!");
            }
        }
    }
}
