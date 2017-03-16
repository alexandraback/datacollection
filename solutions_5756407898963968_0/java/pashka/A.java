
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class A {

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File(A.class.getSimpleName() + ".in"));
        PrintWriter out = new PrintWriter(new File(A.class.getSimpleName() + ".out"));
        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            String s = "Case #" + (i + 1) + ": " + new A().solve(in);
            out.println(s);
            System.out.println(s);
        }
        out.close();
    }

    private String solve(Scanner in) {
        Set<Integer> x = getSet(in);
        Set<Integer> y = getSet(in);
        Set<Integer> res = new HashSet<Integer>();
        for (Integer integer : x) {
            if (y.contains(integer)) {
                res.add(integer);
            }
        }
        if (res.size() == 1) {
            return "" + res.iterator().next();
        } else if (res.size() == 0) {
            return "Volunteer cheated!";
        } else {
            return "Bad magician!";
        }
    }

    private Set<Integer> getSet(Scanner in) {
        int x = in.nextInt();
        Set<Integer> res = new HashSet<Integer>();
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                int c = in.nextInt();
                if (i == x - 1) {
                    res.add(c);
                }
            }
        }
        return res;
    }
}