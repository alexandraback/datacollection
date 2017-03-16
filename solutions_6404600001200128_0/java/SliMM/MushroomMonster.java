package codejam.round1a.a;

import codejam.InputParser;
import codejam.Solution;
import codejam.SolutionRunner;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintStream;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Scanner;

public class MushroomMonster implements Solution<int[], String>, InputParser<int[]> {
    @Override
    public int[] parse(Scanner scanner) {
        int n = scanner.nextInt();

        int[] result = new int[n];

        for (int i = 0; i < n; ++i) {
            result[i] = scanner.nextInt();
        }

        return result;
    }

    @Override
    public String solve(int[] shrooms) {
        int[] diff = new int[shrooms.length - 1];

        int maxDiff = Integer.MIN_VALUE;

        for (int i = 1; i < shrooms.length; ++i) {
            diff[i - 1] = shrooms[i - 1] - shrooms[i];
            maxDiff = Math.max(maxDiff, diff[i - 1]);
        }

        int mode1 = 0;
        int mode2 = 0;

        for (int i = 0; i < diff.length; ++i) {
            mode1 += Math.max(0, diff[i]);
            mode2 += Math.min(shrooms[i], maxDiff);
        }

        return mode1 + " " + mode2;
    }

    public static void main(String... args) throws IOException {
        MushroomMonster solution = new MushroomMonster();

        InputStream inputFile = /*System.in;//*/Files.newInputStream(Paths.get("/Users/stefan/Downloads/A-small-attempt2.in.txt"));
        PrintStream outputFile = /*System.out;//*/new PrintStream(Files.newOutputStream(Paths.get("A-small.out.txt")));
        new SolutionRunner<>(solution, solution, inputFile, outputFile);
    }
}
