
import java.util.*;

class Party implements Comparable<Party> {
    int cnt = 0;
    char name = '\0';

    Party(int cnt, char name) {
        this.cnt = cnt;
        this.name = name;
    }

    @Override
    public int compareTo(Party party) {
        return Integer.compare(party.cnt, cnt);
    }
}

public class A {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();

        for (int t = 1; t <= T; ++t) {
            int n = in.nextInt();
            PriorityQueue<Party> p = new PriorityQueue<>();
            int sum = 0;
            for (int i = 0; i < n; ++i) {
                int cnt = in.nextInt();
                p.add(new Party(cnt, (char)('A' + i)));
                sum += cnt;
            }
            System.out.print("Case #" + t + ":");
            boolean sec = false;
            while (!p.isEmpty()) {
                Party pp = p.poll();
                char name = pp.name;
                pp.cnt--;
                sum--;
                if (pp.cnt > 0) {
                    p.add(pp);
                }
                if (sec && !p.isEmpty() && 2 * p.peek().cnt > sum) {
                    p.remove(pp);
                    pp.cnt++;
                    p.add(pp);
                    sum++;
                } else {
                    if (!sec) {
                        System.out.print(" ");
                    }
                    System.out.print(name);
                }
                sec = !sec;
            }
            System.out.println();
        }
    }
}