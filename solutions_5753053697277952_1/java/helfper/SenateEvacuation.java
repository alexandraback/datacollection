import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Scanner;

/**
 * Created by helfper on 08/05/16.
 */
public class SenateEvacuation {
    private final static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int t = sc.nextInt();

        for (int i = 1; i <= t; i++) {
            solve(i);
        }
    }

    private static void solve(int tc) {
        int n = sc.nextInt();

        PriorityQueue<Party> pq = new PriorityQueue<>();
        for (int i = 0; i < n; i++) {
            pq.add(new Party("" + (char)('A' + i), sc.nextInt()));
        }

        List<String> evacuation = new ArrayList<>();
        while (pq.size() >= 2) {
            Party first = pq.poll();
            Party second = pq.poll();

            if (first.senators == 1) {
                if (pq.size() == 1) {
                    evacuation.add(first.name);
                    pq.add(second);
                } else {
                    evacuation.add(first.name + second.name);
                }
            } else {
                if (first.senators - second.senators >= 2) {
                    evacuation.add(first.name + first.name);
                    first.senators -= 2;
                    pq.add(first);
                    pq.add(second);
                } else {
                    evacuation.add(first.name + second.name);
                    first.senators--;
                    pq.add(first);
                    second.senators--;
                    if (second.senators > 0) {
                        pq.add(second);
                    }
                }
            }
        }
        assert pq.isEmpty();

        System.out.printf("Case #%d: %s\n", tc, evacuation.toString().replaceAll("[^A-Z ]+", ""));
    }

    private static class Party implements Comparable<Party> {
        String name;
        int senators;

        public Party(String name, int senators) {
            this.name = name;
            this.senators = senators;
        }

        @Override
        public String toString() {
            return "Party{" +
                    "name='" + name + '\'' +
                    ", senators=" + senators +
                    '}';
        }

        @Override
        public int compareTo(Party o) {
            return o.senators - senators;
        }
    }
}
