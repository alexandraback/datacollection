package com.xs0;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.function.Consumer;

public class Barbers {
    public static void main(String[] args) throws Exception {
        for (File infile : new File("/home/mitja/codejam/barbers").listFiles((dir, name)->name.endsWith(".in"))) {
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
                String[] tmp = lines.get(linePos++).split(" ");
                int N = Integer.parseInt(tmp[1]);
                tmp = lines.get(linePos++).split(" ");
                int[] nums = new int[tmp.length];
                for (int b = 0; b < nums.length; b++)
                    nums[b] = Integer.parseInt(tmp[b]);

                long res = solve(N, nums);

                out.accept("Case #" + a + ": " + res + "\n");
            }

            outWriter.close();
        }
    }

    private static long solve(int N, int[] nums) {
        long time = N * 1000000L;
        long sub = Long.highestOneBit(time);
        while (sub > 0) {
            if (sub <= time && cutInTime(nums, time - sub) >= N)
                time -= sub;
            sub = sub >>> 1;
        }

        long prev = cutInTime(nums, time - 1);

        ArrayList<Barber> starters = new ArrayList<>();
        for (int a = 0; a < nums.length; a++) {
            int num = nums[a];
            if (time % num == 0) {
                Barber b = new Barber();
                b.index = a + 1;
                b.time = num;
                starters.add(b);
            }
        }

        Collections.sort(starters, (a, b) -> Integer.compare(a.index, b.index));

        return starters.get((int) (N - 1 - prev)).index;
    }

    static class Barber {
        int index;
        int time;
    }

    static long cutInTime(int[] nums, long time) {
        if (time < 0)
            return 0;

        long res = 0;
        for (int len : nums) {
            res += (time + len)/ len;
        }
        return res;
    }
}
