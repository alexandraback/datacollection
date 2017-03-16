package GCJ2015.round1A.problemA;

import java.io.BufferedWriter;
import java.io.FileWriter;
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

        for (int test_case = 1; test_case <= test_cases; test_case++) {

            int n = sc.nextInt();
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = sc.nextInt();
            }

            String result = "Case #" + test_case + ": " + getResult(a);
            out.write(result + "\n");
            System.out.println(result);
        }

        out.flush();
        out.close();
        sc.close();
    }

    private String getResult(int[] array) {
        int count1 = 0;
        int count2 = 0;
        int max = 0;

        int diff;
        for (int i = 1; i < array.length; i++) {
            diff = array[i-1] - array[i];
            if (diff > 0) {
                count1 += diff;
            }
            if (diff > max) {
                max = diff;
            }
        }

        for (int i = 0; i < array.length-1; i++) {
            count2 += Math.min(array[i], max);
        }

        return count1 + " " + count2;
    }
}