package com.xs0;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.util.List;
import java.util.function.Consumer;

public class Mushrooms {
    public static void main(String[] args) throws Exception {
        for (File infile : new File("/home/mitja/codejam/mushrooms").listFiles((dir, name)->name.endsWith(".in"))) {
            File outfile = new File(infile.getParentFile(), infile.getName() + ".out");
            FileWriter outWriter = new FileWriter(outfile);
            Consumer<String> out = str -> {
                try {
                    outWriter.write(str);
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
                System.out.print(str);
            };

            List<String> lines = Files.readAllLines(infile.toPath());

            int linePos = 0;
            int nCases = Integer.parseInt(lines.get(linePos++));
            for (int a = 1; a <= nCases; a++) {
                linePos++;
                String[] tmp = lines.get(linePos++).split(" ");
                int[] nums = new int[tmp.length];
                for (int b = 0; b < nums.length; b++)
                    nums[b] = Integer.parseInt(tmp[b]);

                int[] res = solve(nums);

                out.accept("Case #" + a + ": " + res[0] + " " + res[1] + "\n");
            }

            outWriter.close();
        }
    }

    private static int[] solve(int[] nums) {
        int methodA = 0;
        int maxRate = 0;
        for (int a = 1; a < nums.length; a++) {
            if (nums[a] < nums[a - 1]) {
                int diff = nums[a - 1] - nums[a];
                methodA += diff;
                maxRate = Math.max(maxRate, diff);
            }
        }

        int methodB = 0;
        for (int a = 0; a + 1 < nums.length; a++) {
            methodB += Math.min(nums[a], maxRate);
        }

        return new int[] { methodA, methodB };
    }
}
