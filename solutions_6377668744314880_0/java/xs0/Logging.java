package com.xs0;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.util.Arrays;
import java.util.List;
import java.util.function.Consumer;

public class Logging {
    public static void main(String[] args) throws Exception {
        for (File infile : new File("/home/mitja/codejam/logging").listFiles((dir, name)->name.endsWith(".in"))) {
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
                int nPoints = Integer.parseInt(lines.get(linePos++));

                Point[] points = new Point[nPoints];
                for (int b = 0; b < nPoints; b++) {
                    String[] tmp = lines.get(linePos++).split(" ");
                    points[b] = new Point(Long.parseLong(tmp[0]), Long.parseLong(tmp[1]));
                }

                int[] res = solve(points);

                out.accept("Case #" + a + ":\n");
                for (int r : res)
                    out.accept(r + "\n");
            }

            outWriter.close();
        }
    }

    private static int[] solve(Point[] points) {
        int nPoints = points.length;
        if (nPoints <= 3)
            return new int[nPoints];

        int[] res = new int[nPoints];
        Arrays.fill(res, Integer.MAX_VALUE);

        for (int a = 0; a < nPoints; a++) {
            for (int b = a + 1; b < nPoints; b++) {
                int sumLeft = 0, sumRight = 0;

                for (int c = 0; c < nPoints; c++) {
                    if (c == a || c == b)
                        continue;

                    long side = side(points[a], points[b], points[c]);
                    if (side < 0) sumLeft++;
                    if (side > 0) sumRight++;
                }

                int r = Math.min(sumLeft, sumRight);
                res[a] = Math.min(res[a], r);
                res[b] = Math.min(res[b], r);
            }
        }

        return res;
    }

    static class Point {
        private final long x;
        private final long y;

        Point(long x, long y) {
            this.x = x;
            this.y = y;
        }
    }

    private static long side(Point a, Point b, Point c) {
        return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    }
}
