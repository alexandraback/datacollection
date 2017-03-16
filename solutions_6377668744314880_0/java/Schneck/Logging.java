import java.io.*;
import java.util.*;

public class Logging {
    public static final PrintStream out = System.out;
    public static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    public static final Scanner scan = new Scanner(in);
    public int numCases;
    
    int N;
    ArrayList<Point> points;
    int[] res;
    int handled;
    ArrayList<State> states;
    
    public void doCase(int caseNumber) throws Exception {
        N = scan.nextInt();
        points = new ArrayList<Point>(N);
        for (int i = 0; i < N; i++) {
            Point point = new Point(scan.nextInt(), scan.nextInt());
            points.add(point);
        }

        if (N <= 3) {
            for (int i = 0; i < N; i++) {
                System.out.println(0);
            }
            return;
        }
        
        ArrayList<Point> initialHull = hull(points);

        res = new int[N];
        handled = 0;
        for (int i = 0; i < N; i++) {
            res[i] = -1;
        }
        for (int i = 0; i < N; i++) {
            Point point = points.get(i);
            if (initialHull.contains(point)) {
                res[i] = 0;
                handled++;
            }
        }

        if (handled == N) {
            for (int i = 0; i < N; i++) {
                System.out.println(0);
            }
            return;
        }

        states = new ArrayList<State>();
        for (int i = 0; i < initialHull.size(); i++) {
            ArrayList<Point> removed = new ArrayList<Logging.Point>();
            removed.add(initialHull.get(i));
            State initialState = new State(initialHull, i, removed);
            states.add(initialState);
        }
        while(handled < N) {
            State state = states.get(0);
            states.remove(0);
            ArrayList<Point> pointsLeft = (ArrayList<Point>)points.clone();
            pointsLeft.removeAll(state.removed);
            ArrayList<Point> hull = hull(pointsLeft);
            for (int i = 0; i < N; i++) {
                Point point = points.get(i);
                if (res[i] < 0 && hull.contains(point)) {
                    res[i] = state.removed.size();
                    handled++;
                }
            }
            if (handled == N) break;
            outer:
            for (int i = 0; i < hull.size(); i++) {
                for (int j = 0; j < state.indexOfLastRemovalInHull; j++) {
                    if (state.hull.get(j).equals(hull.get(i))) continue outer;
                }
                ArrayList<Point> removed = (ArrayList<Point>)state.removed.clone();
                removed.add(hull.get(i));
                State nextState = new State(hull, i, removed);
                states.add(nextState);
            }
        }
        for (int i = 0; i < N; i++) {
            System.out.println(res[i]);
        }
    }
    
    static class State {
        ArrayList<Point> hull;
        int indexOfLastRemovalInHull;
        ArrayList<Point> removed;
        public State(ArrayList<Point> hull, int indexOfLastRemovalInHull, ArrayList<Point> removed) {
            this.hull = hull;
            this.indexOfLastRemovalInHull = indexOfLastRemovalInHull;
            this.removed = removed;
        }
    }
    
    public void run() throws Exception {
        numCases = scan.nextInt();
        for (int i = 1; i <= numCases; i++) {
            out.println("Case #" + i + ":");
            doCase(i);
        }
    }
    
    public static void main(String[] args) throws Exception {
        new Logging().run();
    }
    
    
// https://code.google.com/p/convex-hull/source/browse/Convex+Hull/src/algorithms/FastConvexHull.java
// modded to use longs and keep points between vertices
    
    public ArrayList<Point> hull(ArrayList<Point> points) 
    {
            ArrayList<Point> xSorted = (ArrayList<Point>) points.clone();
            Collections.sort(xSorted);
            
            int n = xSorted.size();
            
            Point[] lUpper = new Point[n];
            
            lUpper[0] = xSorted.get(0);
            lUpper[1] = xSorted.get(1);
            
            int lUpperSize = 2;
            
            for (int i = 2; i < n; i++)
            {
                    lUpper[lUpperSize] = xSorted.get(i);
                    lUpperSize++;
                    
                    while (lUpperSize > 2 && !rightTurn(lUpper[lUpperSize - 3], lUpper[lUpperSize - 2], lUpper[lUpperSize - 1]))
                    {
                            // Remove the middle point of the three last
                            lUpper[lUpperSize - 2] = lUpper[lUpperSize - 1];
                            lUpperSize--;
                    }
            }
            
            Point[] lLower = new Point[n];
            
            lLower[0] = xSorted.get(n - 1);
            lLower[1] = xSorted.get(n - 2);
            
            int lLowerSize = 2;
            
            for (int i = n - 3; i >= 0; i--)
            {
                    lLower[lLowerSize] = xSorted.get(i);
                    lLowerSize++;
                    
                    while (lLowerSize > 2 && !rightTurn(lLower[lLowerSize - 3], lLower[lLowerSize - 2], lLower[lLowerSize - 1]))
                    {
                            // Remove the middle point of the three last
                            lLower[lLowerSize - 2] = lLower[lLowerSize - 1];
                            lLowerSize--;
                    }
            }
            
            ArrayList<Point> result = new ArrayList<Point>();
            
            for (int i = 0; i < lUpperSize; i++)
            {
                    result.add(lUpper[i]);
            }
            
            for (int i = 1; i < lLowerSize - 1; i++)
            {
                    result.add(lLower[i]);
            }
            
            return result;
    }
    
    private boolean rightTurn(Point a, Point b, Point c)
    {
            return (b.x - a.x)*(c.y - a.y) - (b.y - a.y)*(c.x - a.x) >= 0;
    }

    static class Point implements Comparable<Point> {
        long x;
        long y;
        Point(long x, long y) {
            this.x = x;
            this.y = y;
        }
        @Override
        public int hashCode() {
            final int prime = 31;
            int result = 1;
            result = prime * result + (int) (x ^ (x >>> 32));
            result = prime * result + (int) (y ^ (y >>> 32));
            return result;
        }
        @Override
        public boolean equals(Object obj) {
            if (this == obj)
                return true;
            if (obj == null)
                return false;
            if (getClass() != obj.getClass())
                return false;
            Point other = (Point) obj;
            if (x != other.x)
                return false;
            if (y != other.y)
                return false;
            return true;
        }
        @Override
        public String toString() {
            return "Point [x=" + x + ", y=" + y + "]";
        }
        @Override
        public int compareTo(Point o) {
            int res = Long.compare(x, o.x);
            if (res != 0) return res;
            return Long.compare(y, o.y);
        }
    }
}
