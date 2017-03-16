package codejam.c1;

import java.io.IOException;
import java.nio.file.FileSystems;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.Arrays;
import java.util.List;
import java.util.PriorityQueue;

public class First {
    public static void main(String[] args) throws IOException {
        Path path = FileSystems.getDefault().getPath("in", "c1a.txt");
        List<String> allLines = Files.readAllLines(path);
        int num = Integer.parseInt(allLines.get(0));
        for (int i = 1; i <= num; i++) {
            solve(i, Integer.parseInt(allLines.get(i * 2 - 1)), allLines.get(i * 2));
        }

    }

    static class Party implements Comparable<Party> {
        final char name;
        final int count;

        public Party(char name, int count) {
            this.name = name;
            this.count = count;
        }

        @Override
        public String toString() {
            return "Party{" +
                   "name=" + name +
                   ", count=" + count +
                   '}';
        }

        static Party decrease(Party p) {
            return new Party(p.name, p.count - 1);
        }

        @Override
        public int compareTo(Party o) {
            return -Integer.compare(count, o.count);
        }
    }

    private static void solve(int no, int num, String countStr) {
        int[] counts = Arrays.stream(countStr.split("\\s")).mapToInt(Integer::parseInt).toArray();
        char p = 'A';
        PriorityQueue<Party> parties = new PriorityQueue<>();
        for (int i = 0; i < counts.length; i++) {
            parties.add(new Party((char) (p + i), counts[i]));
        }
        Party pp;
        String r = "";
        while ((pp = parties.poll()) != null) {
            if (pp.count == 1 && parties.size() == 1) {
                parties.add(pp);
                r += " ";
                break;
            }
            Party newP = Party.decrease(pp);
            if (r.length() != 0 && r.charAt(r.length() - 1) != ' ') {
                r += newP.name;
                r += " ";
            } else {
                r += newP.name;
            }
            if (newP.count != 0) {
                parties.add(newP);
            }
        }
        if (parties.size() == 2) {
            r += parties.poll().name;
            r += parties.poll().name;
        }
        r = r.replaceAll("\\s\\s", " ");

        System.out.println("Case #" + no + ": " + r);
    }

}
