
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

/**
 *
 * @author zhs
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        for (int cnt = 1; cnt <= t; cnt++) {
            Set<Integer> a = new HashSet<>();
            int r1 = scanner.nextInt() - 1;
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    int n = scanner.nextInt();
                    if (i == r1) {
                        a.add(n);
                    }
                }
            }
            int r2 = scanner.nextInt() - 1;
            Set<Integer> res = new HashSet<>();
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    int n = scanner.nextInt();
                    if (i == r2 && a.contains(n)) {
                        res.add(n);
                    }
                }
            }
            System.out.print("Case #" + cnt + ": ");
            if (res.isEmpty()) {
                System.out.println("Volunteer cheated!");
            } else if (res.size() == 1) {
                for (Integer n : res) {
                    System.out.println(n);
                }
            } else {
                System.out.println("Bad magician!");
            }
        }
    }
}
