import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

public class SenateEvacuation {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new FileInputStream("senate_evacuation/A-small-attempt0.in"));
        PrintStream ps = new PrintStream("senate_evacuation/out.txt");
        System.setOut(ps);
        int cases = sc.nextInt();
        for (int i = 0; i < cases; i++) {
            System.out.printf("Case #%d:", i + 1);
            solve(sc);
        }
    }

    public static void solve(Scanner sc) {
        int parties = sc.nextInt();
        int[] numbers = new int[parties];
        for (int i = 0; i < parties; i++) {
            numbers[i] = sc.nextInt();
        }

        int sum = 0;
        for (int n : numbers) {
            sum += n;
        }

        while (sum > 0) {
            int p1 = getMax(numbers);
            numbers[p1] -= 1;
            System.out.print(" ");
            System.out.print((char) ('A' + p1));
            sum--;
            if (sum > 0 && sum != 2) {
                int p2 = getMax(numbers);
                numbers[p2] -= 1;
                System.out.print((char) ('A' + p2));
                sum--;
            }
        }
        System.out.println();
    }

    public static int getMax(int[] array) {
        int max = 0;
        for (int i = 0; i < array.length; i++) {
            if (array[i] > array[max]) {
                max = i;
            }
        }
        return max;
    }
}
