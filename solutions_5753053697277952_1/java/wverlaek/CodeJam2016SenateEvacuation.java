import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Scanner;

public class CodeJam2016SenateEvacuation {
    static Scanner sc = new Scanner(System.in);

    int N;
    int total = 0;
    int[] members;
    Queue<Party> Q;
    public CodeJam2016SenateEvacuation() {
        N = sc.nextInt();
        members = new int[N];
        for (int i = 0; i < N; i++) {
            members[i] = sc.nextInt();
            total += members[i];
        }
        Q = new PriorityQueue<>((o1, o2) -> -Integer.compare(o1.nSenators, o2.nSenators));
        for (int i = 0; i < N; i++) {
            Q.add(new Party(i, members[i]));
        }
    }

    class Party {
        int id;
        int nSenators;
        public Party(int id, int nSenators) {
            this.id = id;
            this.nSenators = nSenators;
        }
    }

    void solve(int c) {
        StringBuilder out = new StringBuilder();

        // Get it to an even number
        if (total % 2 != 0) {
            Party p = Q.poll();

            p.nSenators--;
            out.append(Character.toString((char) ('A' + p.id))).append(" ");
            if (p.nSenators > 0) Q.add(p);
        }

        while (Q.size() >= 2) {
            Party p1 = Q.poll();
            Party p2 = Q.poll();

            p1.nSenators--;
            p2.nSenators--;

            out.append(Character.toString((char) ('A' + p1.id)))
                    .append(Character.toString((char) ('A' + p2.id)))
                    .append(' ');

            if (p1.nSenators > 0) Q.add(p1);
            if (p2.nSenators > 0) Q.add(p2);
        }

        if (!Q.isEmpty()) {
            Party p = Q.poll();
            out.append(Character.toString((char) ('A' + p.id)));
        }

        String result = out.toString().trim();

        System.out.println("Case #" + c + ": " + result);
    }

    public static void main(String[] args) {
        int n = sc.nextInt();
        for (int i = 1; i <= n; i++) new CodeJam2016SenateEvacuation().solve(i);
    }
}
