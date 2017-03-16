package round1a;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintStream;

public class B {

    private static int compute(int b , int n , int[] nums) {
        if (n <= b) {
            return n;
        }
        n -= b;
        
        long min = 0;
        long max = (long) n * findMin(nums);
        while (min + 1 < max) {
            long curr = (min + max) / 2;
            long ppl = calcPeople(curr , nums);
            if (ppl < n) {
                min = curr;
            } else {
                max = curr;
            }
        }
        long wait = n - calcPeople(min , nums);
        for (int i = 0 ; i < nums.length ; i++) {
            if (max % nums[i] == 0) {
                wait--;
            }
            if (wait == 0) {
                return i + 1;
            }
        }
        return -1;
    }

    private static long calcPeople(long minutes , int[] nums) {
        long total = 0;
        for (int x : nums) {
            total += minutes / x;
        }
        return total;
    }

    private static int findMin(int[] nums) {
        int min = Integer.MAX_VALUE;
        for (int x : nums) {
            min = Math.min(min , x);
        }
        return min;
    }

    public static void main(String[] args) throws FileNotFoundException, IOException {
        BufferedReader input
                = new BufferedReader(new FileReader(System.getProperty("user.dir") +
                        "\\io\\r1a_b\\input.txt"));
        try (PrintStream output
                = new PrintStream(new File(System.getProperty("user.dir") +
                        "\\io\\r1a_b\\output.txt"))) {

            final int TESTS = Integer.parseInt(input.readLine());
            for (int t = 1; t <= TESTS; t++) {
                String[] params = input.readLine().split(" ");
                String[] vals = input.readLine().split(" ");
                final int B = Integer.parseInt(params[0]);
                final int N = Integer.parseInt(params[1]);
                int[] nums = new int[B];
                for (int i = 0 ; i < B ; i++) {
                    nums[i] = Integer.parseInt(vals[i]);
                }

                output.println("Case #" + t + ": " + compute(B , N , nums));
            }
        }
    }
    
}
