import java.io.*;
import java.util.*;
import java.lang.*;

class Point {
    long x;
    long y;
    int i;
}

/*
class OComp implements Comparable<Point> {
    Point p;

    public OComp(Point start) {
        p = start;
    }

    public int compare(Point p1, Point p2) {
        // return if p1 is before p2 in rotary order
        if (p1
    }
}
*/

public class Tree {

    public static void print(Object o) {
        System.out.println(o);
    }

    public static int otd(Point a, Point b, Point c) {
        long de = (a.x - c.x) * (b.y-c.y) - (a.y-c.y) * (b.x-c.x);
        if (de < 0) return -1;
        if (de > 0) return 1;
        return 0;
    }

    public static long dist(Point p1, Point p2) {
        return (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y);
    }

    // debugging
    public static void printArray(int[] arr) {
        for (int i : arr) {
            System.out.print(i + " ");
        }
        System.out.println();
    }

    public static ArrayList<Integer> outputHull(Point[] points, int n) {
        if (n < 3) {
            ArrayList<Integer> out = new ArrayList<Integer>();
            for (Point p : points) {
                out.add(p.i);
            }
            return out;
        }
        int best = 0;
        for (int i =1; i < n; i++) {
            if (points[i].x < points[best].x) {
                best = i;
            }
        }
        // best = leftmost
        ArrayList<Integer> al = new ArrayList<Integer>();
        HashSet<Integer> inhull = new HashSet<Integer>();
        int start = best;
        al.add(best);

        int last = best;
        int next = -1;
        do {
            for (int i = 0; i < n; i++) {
                if (i == last || inhull.contains(i)) {
                    continue;
                }
                if (al.size() == 2 && i == start) {
                    continue;
                }
                if (next == -1) next = i;

                int ori = otd(points[last], points[next], points[i]);
                if (ori < 0) {
                    next = i;
                } else if (ori == 0) {
                    if (dist(points[last], points[next]) > dist(points[last], points[i])) {
                        next = i;
                    }
                }
            }
            al.add(next);
            inhull.add(next);
            last = next;
            next = -1;
        } while (last != best);
        al.remove(al.size()-1);
        // now turn back
        ArrayList<Integer> out = new ArrayList<Integer>();
        for (int ind : al) {
            out.add(points[ind].i);
        }
        return out;
    }


    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int cases = Integer.parseInt(br.readLine());
        for (int i = 1; i <= cases; i++) {
            int n = Integer.parseInt(br.readLine());
            Point[] points = new Point[n];
            for (int j = 0; j < n; j++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                points[j] = new Point();
                points[j].x = Long.parseLong(st.nextToken());
                points[j].y = Long.parseLong(st.nextToken());
                points[j].i = j;
            }
            // try all subsets
            int[] output = new int[n];
            for (int j = 0; j < n; j++) {
                output[j] = 2 * n;
            }

            for (int ss = 0; ss < (1 << n); ss++) {
                // generate points
                int sss = ss;
                ArrayList<Point> ps = new ArrayList<Point>();
                Point[] t = new Point[0];
                int k = 0;
                while (sss > 0) {
                    if (sss % 2 == 1) { ps.add(points[k]); }
                    k++;
                    sss /= 2;
                }
                for (int p : outputHull(ps.toArray(t), ps.size())) {
                    output[p] = Math.min(output[p], n - ps.size());
                }
            }
            print("Case #"+i+":");
            for (int val : output) {
                print(val);
            }
        }
    }
}
