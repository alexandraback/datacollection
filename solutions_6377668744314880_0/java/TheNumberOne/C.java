package rounds.qualification.Round1A;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class C {

    List<int[]> input;

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
        List<int[]> trees = new ArrayList<>();

        for (int i = 0; i < N; i++) {
            trees.add(new int[]{in.nextInt(), in.nextInt()});
        }

        int[] solution = new C(trees).solve();

        out.printf("Case #%d:\n", id);

        for (int s : solution){
            out.println(s);
        }
    }

    public C(List<int[]> input) {
        this.input = input;
    }

    int[] solve() {
        int[] solution = new int[input.size()];
        for (int i = 0; i < input.size(); i++) {
            solution[i] = solveCase(i);
        }
        return solution;
    }

    private int solveCase(int i) {
        int[] squirrel = input.get(i);

        int leastCost = Integer.MAX_VALUE;
        for (int[] point : input) {
            if (point == squirrel) {
                continue;
            }
            int cost1 = 0;
            int cost2 = 0;
            int x0 = point[0];
            int y0 = point[1];
            int x1 = squirrel[0];
            int y1 = squirrel[1];
            for (int[] p : input) {
                if (p == point || p == squirrel) {
                    continue;
                }
                int x2 = p[0];
                int y2 = p[1];
                if (x1 == x0) {
                    if (x2 == x1) {
                        continue;
                    }
                    if (x2 < x1) {
                        cost1++;
                    } else {
                        cost2++;
                    }
                    continue;
                }
                if (y2 < (x2 - x0) * (y1 - y0) / (x1 - x0) + y0) {
                    cost1++;
                } else if (y2 > (x2 - x0) * (y1 - y0) / (x1 - x0) + y0) {
                    cost2++;
                }
            }
            leastCost = Math.min(Math.min(cost1, cost2), leastCost);
        }
        return leastCost == Integer.MAX_VALUE ? 0 : leastCost;
    }

}