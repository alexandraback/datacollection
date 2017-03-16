import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.PriorityQueue;
import java.util.Scanner;

public class A {

    public static void main(String[] args) throws IOException {

        Scanner sc = new Scanner(new File("A-large (2).in"));
        FileWriter fw = new FileWriter(new File("a.out"));
        int n = sc.nextInt();
        for (int i = 1; i <= n; i++) {
            fw.append(String.format("Case #%d: %s", i, new A().solve(sc))).append('\n');
        }
        fw.close();
        sc.close();

    }

    private String solve(Scanner sc) {

        System.out.println("-----------");

        StringBuilder sb = new StringBuilder();
        int N = sc.nextInt();

        PriorityQueue<Party> parties = new PriorityQueue<>((a, b) -> b.members - a.members);

        for (int i = 0; i < N; i++) {
            parties.add(new Party(sc.nextInt(), (char) (i + 'A')));
        }

        System.out.println(parties);

        while (!parties.isEmpty()) {

            Party first = parties.poll();

            boolean noti = true;

            if (!parties.isEmpty()) {

                Party second = parties.poll();

                System.out.println(first.members);
                System.out.println(second.members);

                if (second.members == first.members && !(first.members == 1 && parties.size() == 1)) {
                    noti = false;
                    sb.append(first.name);
                    sb.append(second.name);

                    if (first.members > 1) {
                        parties.add(first.dec());
                    }
                    if (second.members > 1) {
                        parties.add(second.dec());
                    }
                } else {
                    parties.add(second);
                }
            }

            if (noti) {
                sb.append(first.name);
                if (first.members > 1) {
                    parties.add(first.dec());
                }
            }

            sb.append(' ');

        }

        String temp = sb.toString();
        return temp.substring(0, temp.length() - 1);

    }

    static class Party {

        int members;
        char name;

        public Party(int members, char name) {
            this.members = members;
            this.name = name;
        }

        public Party dec() {
            members--;
            return this;
        }

        @Override
        public String toString() {
            return "Party{" +
                    "members=" + members +
                    ", name=" + name +
                    '}';
        }
    }

}
