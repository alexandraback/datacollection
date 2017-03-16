import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

public class A {

    public static void main(String[] args) throws FileNotFoundException {
        //Scanner scanner = new Scanner(System.in);
        Scanner scanner = new Scanner(new File("inputSmall.txt"));
        int tests = scanner.nextInt();
        for (int test=1; test<=tests; test++) {
            scanner.nextLine();
            int parties = scanner.nextInt();
            scanner.nextLine();
            int total = 0;
            int[] senators = new int[parties];
            List<Party> list = new ArrayList<Party>();
            for (int i=0; i<parties; i++) {
                senators[i] = scanner.nextInt();
                list.add(new Party((char)('A'+i), senators[i]));
                total += senators[i];
            }
            System.out.print("Case #" + test + ": ");
            while (total > 0) {
                Collections.sort(list, Comparator.reverseOrder()); /* n < 27 */
                list.get(0).val--;
                total--;
                System.out.print(list.get(0).id);
                if (2 * list.get(1).val > total) {
                    list.get(1).val--;
                    total--;
                    System.out.print(list.get(1).id);
                }
                System.out.print(" ");
            }
            System.out.println();
        }
        scanner.close();
    }

    private static class Party implements Comparable<Party> {
        char id;
        int val;

        public Party(char id, int val) {
            this.id = id;
            this.val = val;
        }

        @Override
        public int compareTo(Party o) {
            return this.val - o.val;
        }
    }
}
