package rounds.qualification.Round1A;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

public class A {

    int[] input;

    static Scanner in;
    static PrintStream out;

    public static void main(String[] args) throws FileNotFoundException {
        out = new PrintStream("out.txt");
        in = new Scanner(new File(args[0]));

        int N = in.nextInt();
        in.nextLine();

        for (int i = 0; i < N; i++) {
            runTestCase(i + 1);
        }
    }

    private static void runTestCase(int id) {
        int N = in.nextInt();
        int[] mushrooms = new int[N];

        for (int i = 0; i < N; i++) {
            int number = in.nextInt();
            mushrooms[i] = number;
        }

        int[] solution = new A(mushrooms).solve();

        out.printf("Case #%d: %d %d\n", id , solution[0], solution[1]);
    }

    public A(int[] input) {
        this.input = input;
    }

    int[] solve() {
        int firstSolution = 0;
        int secondSolution = 0;
        int bestRate = 0;

        for (int i = 1; i < input.length; i++) {
            if (input[i] < input[i - 1]) {
                firstSolution += input[i - 1] - input[i];
                bestRate = Math.max(input[i - 1] - input[i], bestRate);
            }
        }

        for (int i = 0; i < input.length - 1; i++) {
            secondSolution += Math.min(bestRate, input[i]);
        }

        return new int[]{firstSolution, secondSolution};
    }

}