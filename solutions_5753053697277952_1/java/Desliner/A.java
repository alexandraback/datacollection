package codejam.y2016.round1.subroundC;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.*;

/**
 * @author Max Myslyvtsev
 * @since 4/30/16
 */
public class A {

    public static void main(String[] args) throws Exception {
        //Scanner in = new Scanner(new FileInputStream("/Users/max/Work/Source/foobar/src/main/resources/input.txt"));
        Scanner in = new Scanner(new FileInputStream("/Users/max/Downloads/A-large.in"));
        PrintStream out = new PrintStream(new FileOutputStream("/Users/max/Work/Source/foobar/src/main/resources/output.txt"));
        int T = in.nextInt();
        in.nextLine();
        for (int t = 1; t <= T; t++) {
            int N = in.nextInt();
            int[] P = new int[N];
            for (int i = 0; i < N; i++) {
                P[i] = in.nextInt();
            }
            String a = solve(P);
            String answ = "Case #" + t + ": " + a;
            out.println(answ);
            System.out.println(answ);
        }
    }


    static class Party implements Comparable<Party> {
        public static final Comparator<Party> PARTY_COMPARATOR = Comparator.<Party>comparingInt(x -> -x.count).thenComparing(x -> x.id);

        int id;
        int count;

        public Party(int id, int count) {
            this.id = id;
            this.count = count;
        }

        @Override
        public int compareTo(Party o) {
            return PARTY_COMPARATOR.compare(this, o);
        }
    }

    private static String solve(int[] P) {
        StringBuilder sb = new StringBuilder();
        TreeSet<Party> set = new TreeSet<>();
        int total = 0;
        for (int i = 0; i < P.length; i++) {
            total += P[i];
            set.add(new Party(i, P[i]));
        }
        while (!set.isEmpty()) {
            Party first = set.first();
            Party second = null;
            if (set.size() > 1) {
                second = set.tailSet(first, false).first();
            }

            if (set.size() == 3) {
                if (first.count == 1 && second != null && second.count == 1) {
                    second = null;
                }
            }

            char ch = (char)('A' + first.id);
            sb.append(ch);
            if (second != null) {
                ch = (char)('A' + second.id);
                sb.append(ch);
            }

            set.remove(first);
            first.count--;
            if (first.count > 0) {
                set.add(first);
            }
            if (second != null) {
                set.remove(second);
                second.count--;
                if (second.count > 0) {
                    set.add(second);
                }
            }

            if (!set.isEmpty()) {
                sb.append(" ");
            }

            {
                total--;
                if (second != null) {
                    total--;
                }
                if (1.0 * first.count / total > 0.5) {
                    throw new RuntimeException("PIZDA");
                }
                if (second != null) {
                    if (1.0 * second.count / total > 0.5) {
                        throw new RuntimeException("PIZDA 2");
                    }
                }
            }
        }
        return sb.toString();
    }


}
