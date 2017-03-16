import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.*;

import static java.util.Collections.*;
import static java.lang.Math.*;


public class A {


//    public static final String INPUT_FILE = "A-small-attempt0";
    public static final String INPUT_FILE = "A-large";
//    public static final String INPUT_FILE = "A-test";

    Scanner sc;
    PrintWriter out;


    String senate() {
        StringBuilder sb = new StringBuilder();
        int N = sc.nextInt();
        List<Integer> p = new ArrayList<>();
        int sum = 0;
        for (int i = 0; i < N; i++) {
            int pi = sc.nextInt();
            p.add(pi);
            sum += pi;
        }

        while (sum > 0) {
            int max = Integer.MIN_VALUE;
            int maxi = 0;
            for (int i = 0; i < p.size(); i++) {
                if (p.get(i) > max) {
                    max = p.get(i);
                    maxi = i;
                }
            }
            p.set(maxi, max - 1);
            sb.append((char) ('A' + maxi));
            if (sum % 2 == 1) {
                sb.append(" ");
            }
            sum--;
        }
        return sb.toString();
    }

    void out(int cas, Object result) {
        String s = String.format("Case #%d: %s", cas, result);
        System.out.println(s);
        out.println(s);
    }

    void run() throws FileNotFoundException {
        sc = new Scanner(new File(INPUT_FILE + ".in"));
        out = new PrintWriter(INPUT_FILE + ".out");
        int c = sc.nextInt();
        for (int i = 0; i < c; i++) {
            out(i+1, senate());
        }
        sc.close();
        out.close();
    }


    public static void main(String[] args) throws FileNotFoundException {
        new A().run();
    }

}
