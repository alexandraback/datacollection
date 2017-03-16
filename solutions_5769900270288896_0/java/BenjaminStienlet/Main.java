package GCJ2015.round1B.problemB;

import org.paukov.combinatorics.Factory;
import org.paukov.combinatorics.Generator;
import org.paukov.combinatorics.ICombinatoricsVector;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws Exception {
        new Main();
    }

    public Main() throws Exception {
        solve();
    }

    private void solve() throws Exception {
        System.out.println(">>> Input: ");
        Scanner sc = new Scanner(System.in);
        BufferedWriter out = new BufferedWriter(new FileWriter("output.txt"));

        int test_cases = sc.nextInt();
        int R, C, N;

        for (int test_case = 1; test_case <= test_cases; test_case++) {
            R = sc.nextInt();
            C = sc.nextInt();
            N = sc.nextInt();

            String result = "Case #" + test_case + ": " + getResult(R, C, N);
            out.write(result + "\n");
            System.out.println(result);
        }

        out.flush();
        out.close();
        sc.close();
    }

    private String getResult(int R, int C, int N) {
        int min = Integer.MAX_VALUE;
        // Create the initial vector
        List<Integer> list = new ArrayList<>();
        for (int i = 1; i <= R*C; i++) {
            list.add(i);
        }

        ICombinatoricsVector<Integer> initialVector = Factory.createVector(list.toArray(new Integer[R*C]));

        // Create a simple combination generator to generate 3-combinations of the initial vector
        Generator<Integer> gen = Factory.createSimpleCombinationGenerator(initialVector, N);

        // Print all possible combinations
        int cost;
        for (ICombinatoricsVector<Integer> combination : gen) {
            cost = getCost(combination.getVector(), R, C);
            if (cost < min) {
                min = cost;
            }
        }
        return "" + min;
    }

    private int getCost(List<Integer> list, int R, int C) {
        int cost = 0;
        for (int i : list) {
            // check right
            if (i%C != 0 && list.contains(i+1)) {
                cost++;
            }
            // check under
            if (i+C <= R*C && list.contains(i+C)) {
                cost ++;
            }
        }
        return cost;
    }
}