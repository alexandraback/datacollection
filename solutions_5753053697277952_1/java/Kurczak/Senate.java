package pl.kurczak.gcj;

import java.io.PrintStream;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.time.Duration;
import java.time.Instant;
import java.util.Comparator;
import java.util.Scanner;
import java.util.stream.IntStream;

/**
 * @author Andrzej Kurczewski
 */
public class Senate {
    public static void main(String[] args) throws Exception {
        try (Scanner in = new Scanner(Files.newBufferedReader(Paths.get("s-in.txt")));
             PrintStream out = new PrintStream("s-out.txt", "UTF-8")
//             PrintStream out = System.out
        ) {
            Instant before = Instant.now();
            solve(in, out);
            Instant after = Instant.now();
            System.out.println(Duration.between(before, after));
        }
    }

    private static void solve(Scanner in, PrintStream out) throws Exception {
        int tests = in.nextInt();
        for (int i = 1; i <= tests; i++) {
            int parties = in.nextInt();
            int[] counts = new int[parties];
            int allCount = 0;
            for (int j = 0; j < parties; j++) {
                counts[j] = in.nextInt();
                allCount += counts[j];
            }
            out.format("Case #%d: %s%n", i, solve(counts, allCount));
        }
    }

    private static String solve(int[] counts, int allCount) {
        StringBuilder solution = new StringBuilder();
        if (counts.length == 2) {
            for (int i = 0; i < counts[0]; i++) {
                solution.append("AB ");
            }
            return solution.toString();
        }
        Party[] parties = IntStream.range(0, counts.length)
                                   .mapToObj(i -> new Party(counts[i], (char) ('A' + i)))
                                   .sorted(Comparator.comparingInt(p -> -p.count)).toArray(Party[]::new);
        int currentMax = parties[0].count;
        while (currentMax > 1) {
            for (int i = 0; i < parties.length && parties[i].count == currentMax; i++) {
                solution.append(parties[i].name).append(" ");
                parties[i].count--;
            }
            currentMax = parties[0].count;
        }
        for (int i = 0; i < parties.length - 2; i++) {
            solution.append(parties[i].name).append(" ");
        }
        solution.append(parties[parties.length - 2].name).append(parties[parties.length - 1].name);
        return solution.toString();
    }

    private static class Party {
        private int count;
        private char name;

        private Party(int count, char name) {
            this.count = count;
            this.name = name;
        }

        @Override
        public String toString() {
            return name + ": " + count;
        }
    }
}
