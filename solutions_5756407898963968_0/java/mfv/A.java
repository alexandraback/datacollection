import java.io.*;
import java.util.*;

class A {

    static class Assert {
        static void check(boolean e) {
            if (!e) {
                throw new Error();
            }
        }
    }

    Scanner in;
    PrintWriter out;

    Set<Integer> readCards() {
        int row = in.nextInt();
        Set<Integer> set = new HashSet<>();
        for (int i = 1; i <= 4; i++) {
            for (int j = 1; j <= 4; j++) {
                int value = in.nextInt();
                if (i == row) {
                    set.add(value);
                }
            }
        }
        return set;
    }

    String solveOne() {
        Set<Integer> set1 = readCards();
        Set<Integer> set2 = readCards();
        set1.retainAll(set2);
        if (set1.size() == 1) {
            return set1.iterator().next().toString();
        } else if (set1.size() == 0) {
            return "Volunteer cheated!";
        } else {
            Assert.check(set1.size() > 1);
            return "Bad magician!";
        }
    }

    void solve() {
        int nCases = in.nextInt();
        for (int i = 1; i <= nCases; i++) {
            out.printf("Case #%d: %s%n", i, solveOne());
        }
    }

    void run() {
        in = new Scanner(System.in);
        out = new PrintWriter(System.out);
        try {
            solve();
        } finally {
            out.close();
        }
    }

    public static void main(String args[]) {
        new A().run();
    }
}
