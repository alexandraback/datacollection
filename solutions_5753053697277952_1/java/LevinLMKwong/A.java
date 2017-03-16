package gcj2016.roundOneC;

import java.util.*;

/**
 * Created by LevinLMKwong on 8/5/16.
 */
public class A {
    private static class Party {
        int count = 0;
        int index = 0;
    }
    private static boolean check(List<Party> P, int total) {
        for (Party p : P) {
            if (p.count > total/2) {
                return false;
            }
        }
        return true;
    }
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        for (int t=1; t<=T; t++) {
            int N = in.nextInt();
            int total = 0;
            List<Party> P = new ArrayList<>();
            for (int i = 0; i < N; i++) {
                Party p = new Party();
                p.count = in.nextInt();
                p.index = i;
                P.add(p);
                total += p.count;
            }
            StringBuilder ans = new StringBuilder();
            while (total > 0) {
                Collections.sort(P, new Comparator<Party>() {
                    public int compare(Party p1, Party p2) {
                        if (p1.count > p2.count) return -1;
                        if (p1.count == p2.count) return 0;
                        return 1;
                    }
                });
                P.get(0).count -= 1;
                if (check(P, total-1)) {
                    ans.append(' ');
                    ans.append((char) (P.get(0).index + 'A'));
                    total -= 1;
                } else {
                    P.get(1).count -= 1;
                    ans.append(' ');
                    ans.append((char) (P.get(0).index + 'A'));
                    ans.append((char) (P.get(1).index + 'A'));
                    total -= 2;
                }
            }
            System.out.format("Case #%d:%s\n", t, ans.toString());
        }
    }
}
