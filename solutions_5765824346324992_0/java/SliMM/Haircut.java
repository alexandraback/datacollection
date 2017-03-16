package codejam.round1a.b;

import codejam.InputParser;
import codejam.Solution;
import codejam.SolutionRunner;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintStream;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Haircut implements Solution<HaircutInput, Integer>, InputParser<HaircutInput> {

    @Override
    public HaircutInput parse(Scanner scanner) {
        HaircutInput result = new HaircutInput();

        int numBarbers = scanner.nextInt();
        result.n = scanner.nextInt();
        result.barbers = new PriorityQueue<>();
        result.lcm = 1;

        for (int i = 0; i < numBarbers; ++i) {
            Barber b = new Barber(i + 1, scanner.nextInt(), 0);
            result.barbers.add(b);
            result.lcm = lcm(result.lcm, b.speed);
        }

        return result;
    }

    @Override
    public Integer solve(HaircutInput input) {
        List<Barber> order = new ArrayList<Barber>();


        for (long time = input.lcm; time != 0; time -= input.barbers.peek().timeLeft) {
            Barber nextBarber = input.barbers.remove();

            for (Barber b : input.barbers) {
                b.timeLeft -= nextBarber.timeLeft;
            }

            nextBarber.timeLeft = nextBarber.speed;

            input.barbers.add(nextBarber);
            order.add(nextBarber);
        }

        return order.get((input.n - 1) % order.size()).id;
    }

    public static long gcd(long a, long b) {
        while (b > 0) {
            long temp = b;
            b = a % b; // % is remainder
            a = temp;
        }
        return a;
    }

    public static long lcm(long a, long b) {
        return a * (b / gcd(a, b));
    }

    public static void main(String... args) throws IOException {
        Haircut solution = new Haircut();

        InputStream inputFile = /*System.in;//*/Files.newInputStream(Paths.get("/Users/stefan/Downloads/B-small-attempt1.in.txt"));
        PrintStream outputFile = /*System.out;//*/new PrintStream(Files.newOutputStream(Paths.get("B-small.out.txt")));
        new SolutionRunner<>(solution, solution, inputFile, outputFile);
    }
}
