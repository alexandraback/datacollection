import java.util.*;
public class A {
    static Scanner s;
    public static void main(String[] args) {
        s = new Scanner(System.in);
        int n = s.nextInt();
        for (int i = 1; i <= n; i++) {
            System.out.printf("Case #%d: %s\n", i, solve());
        }
    }

    public static String solve() {
        int n = s.nextInt();
        Set<Integer> A = new HashSet<Integer>();
        for (int i = 1; i <= 4; i++) {
            if (i == n) {
                A.add(s.nextInt());
                A.add(s.nextInt());
                A.add(s.nextInt());
                A.add(s.nextInt());
            } else {
                s.nextInt();
                s.nextInt();
                s.nextInt();
                s.nextInt();
            }
        }

        n = s.nextInt();
        Set<Integer> B = new HashSet<Integer>();
        for (int i = 1; i <= 4; i++) {
            if (i == n) {
                B.add(s.nextInt());
                B.add(s.nextInt());
                B.add(s.nextInt());
                B.add(s.nextInt());
            } else {
                s.nextInt();
                s.nextInt();
                s.nextInt();
                s.nextInt();
            }
        }

        A.retainAll(B);
        if (A.size() == 0) {
            return "Volunteer cheated!";
        } else if (A.size() > 1) {
            return "Bad magician!";
        } else {
            for (Integer k : A) {
                return "" + k;
            }
        }
        return "";
    }
}
