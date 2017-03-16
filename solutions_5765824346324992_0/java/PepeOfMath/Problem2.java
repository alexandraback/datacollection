// Code by PepeOfMath
//
import java.awt.Point;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Comparator;
import java.util.Iterator;
import java.util.Scanner;
import java.util.TreeSet;

public class Problem2 {

    public static void main(String[] args) throws FileNotFoundException {

        //hard code the file location
        //open file
        //get number of test cases
        File f = new File("B-small-attempt1.in");
        Scanner s = new Scanner(f);
        String line = s.nextLine();
        int T = Integer.parseInt(line);

        //open output file
        File f2 = new File("twosmall.txt");
        PrintWriter p = new PrintWriter(f2);

        for (int i = 1; i <= T; i++) {
            String[] vals = s.nextLine().split(" ");
            int nbarb = Integer.parseInt(vals[0]);
            int place = Integer.parseInt(vals[1]);
            
            int[] times = new int[nbarb];
            int lcmval = 1;
            int count = 0;
            Scanner scan = new Scanner(s.nextLine());
            for (int j = 0; j < nbarb; j++) {
                times[j] = scan.nextInt();
                lcmval = lcm(lcmval, times[j]);
            }
            
            //calculate how many are handled in gcd time
            for (int j = 0; j < nbarb; j++) {
                count += lcmval/times[j];
            }
            //System.out.println(lcmval + " " + count);
            
            
            TreeSet<Point> tt = new TreeSet<Point>(new Comparator<Point>() {
                public int compare(Point o1, Point o2) {
                    if (o1.x < o2.x) return -1;
                    if (o1.x > o2.x) return 1;
                    if (o1.y < o2.y) return -1;
                    if (o1.y > o2.y) return 1;
                    return 0;
                }
            });
            
            
            for (int j = 0; j < nbarb; j++) {
                tt.add(new Point(0, j));
            }
            
            int lbarb = nbarb-1;
            if (count != 0) {
                place = place % count;
            } 
            //System.out.println(place);
            for (int j = 0; j < place; j++) {
                Point pp = (Point) tt.first();
                lbarb = (int) pp.y;
                tt.remove(pp);
                tt.add(new Point(pp.x+times[lbarb], lbarb));
            }
            
            p.println("Case #" + i + ": " + (lbarb + 1));
            //System.out.println("Case #" + i);
        }

        p.close();
        s.close();
    }
    
    public static int gcd(int a, int b) {
        if (a == b) return a;
        if (a < b) {
            return gcd(a,b-a);
        }
        return gcd(a-b, b);
    }
    
    public static int lcm(int a, int b) {
        return (a / gcd(a,b) * b);
    }
    
    
}
