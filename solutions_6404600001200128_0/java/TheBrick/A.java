package round1a;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintStream;

public class A {

    private static int compute1(int[] nums) {
        int total = 0;
        for (int i = 0 ; i < nums.length - 1 ; i++) {
            total += Math.max(0 , nums[i] - nums[i + 1]);
        }
        return total;
    }

    private static int compute2(int[] nums) {
        int rate = 0;
        for (int i = 0 ; i < nums.length - 1 ; i++) {
            rate = Math.max(rate , nums[i] - nums[i + 1]);
        }
        
        int total = 0;
        for (int i = 0 ; i < nums.length - 1 ; i++) {
            total += Math.min(nums[i] , rate);
        }
        return total;
    }

    public static void main(String[] args) throws FileNotFoundException, IOException {
        BufferedReader input
                = new BufferedReader(new FileReader(System.getProperty("user.dir") +
                        "\\io\\r1a_a\\input.txt"));
        try (PrintStream output
                = new PrintStream(new File(System.getProperty("user.dir") +
                        "\\io\\r1a_a\\output.txt"))) {

            final int TESTS = Integer.parseInt(input.readLine());
            for (int t = 1; t <= TESTS; t++) {
                input.readLine();
                String[] vals = input.readLine().split(" ");
                int[] nums = new int[vals.length];
                for (int i = 0 ; i < nums.length ; i++) {
                    nums[i] = Integer.parseInt(vals[i]);
                }

                output.println("Case #" + t + ": " + compute1(nums) + " " + compute2(nums));
            }
        }
    }
    
}
