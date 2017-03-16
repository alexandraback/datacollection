import java.util.*;

public class A {
    static Scanner s;
    public static void main(String[] args) {
        s = new Scanner(System.in);
        int t = s.nextInt();
        for (int i = 0; i < t; i++) {
            solve(i+1);
        }
    }

    public static void solve(int x) {
        int n = s.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = s.nextInt();
        }
        // First Case
        int prev = arr[0];
        int first = 0;
        for (int i = 1; i < n; i++) {
            if (arr[i] < prev) {
                first += prev - arr[i];
            }
            prev = arr[i];
        }

        // Second Case
        prev = arr[0];
        int max = 0;
        for (int i = 1; i < n; i++) {
            if (arr[i] < prev) {
                if (max < prev - arr[i]) {
                    max = prev - arr[i];
                }
            }
            prev = arr[i];
        }
        int second = 0;
        for (int i = 0; i < n-1; i++) {
            second += Math.min(max, arr[i]);
        }
        System.out.println("Case #" + x + ": " + first + " " + second);
    }
}
