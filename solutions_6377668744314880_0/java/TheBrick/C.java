package round1a;

import java.awt.Point;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintStream;

public class C {

    private static int compute(Point[] verts , int index) {
        if (verts.length <= 3) {
            return 0;
        }
        Point a = verts[index];
        int min = Integer.MAX_VALUE;
        for (int i = 0 ; i < verts.length ; i++) {
            if (i == index) {
                continue;
            }
            Point b = verts[i];
            
            int r1 = 0 , r2 = 0;
            for (Point p : verts) {
                long x = ((long) p.y - a.y) * (b.x - a.x) - ((long) p.x - a.x) * (b.y - a.y);
                if (x > 0) {
                    r1++;
                } else if (x < 0) {
                    r2++;
                }
            }
            min = Math.min(min , Math.min(r1 , r2));
        }
        return min;
    }

    public static void main(String[] args) throws FileNotFoundException, IOException {
        BufferedReader input
                = new BufferedReader(new FileReader(System.getProperty("user.dir") +
                        "\\io\\r1a_c\\input.txt"));
        try (PrintStream output
                = new PrintStream(new File(System.getProperty("user.dir") +
                        "\\io\\r1a_c\\output.txt"))) {

            final int TESTS = Integer.parseInt(input.readLine());
            for (int t = 1; t <= TESTS; t++) {
                final int N = Integer.parseInt(input.readLine());
                Point[] verts = new Point[N];
                for (int i = 0 ; i < N ; i++) {
                    String[] vals = input.readLine().split(" ");
                    verts[i] = new Point(Integer.parseInt(vals[0]) , Integer.parseInt(vals[1]));
                }

                output.println("Case #" + t + ":");
                for (int i = 0 ; i < N ; i++) {
                    output.println(compute(verts , i));
                }
            }
        }
    }
    
}
