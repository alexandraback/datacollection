import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Set;

/*----------------------------------------------------------------
 *  Author:        Fernando
 *  Written:       12/04/2014
 *  Last updated:  12/04/2014
 *
 *  Compilation:   javac MagicTrick.java
 *  Execution:     java  MagicTrick.java
 *  
 *  <Insert description here>
 *
 *  
 *
 *----------------------------------------------------------------*/

/**
 * @author Fernando
 *
 */
public class MagicTrick {

    private static String input = "A-small-attempt0";
    private static boolean testing = false;
    
    /**
     * @param args
     */
    public static void main(String[] args) throws Exception {
        // TODO Auto-generated method stub
        PrintWriter out = null;
        if (!testing) {
            System.setIn(new FileInputStream(input + ".in"));
            out = new PrintWriter(new FileWriter(input + ".out"));
        }
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

        int cases = Integer.parseInt(in.readLine());
        for (int i = 0; i < cases; i++) {
            Trick trick = read(in);
            if (testing)
                System.out.printf("Case #%d: %s\n", i+1, solve(trick));
            else
                out.printf("Case #%d: %s\n", i+1, solve(trick));
        }
        if (out != null)  out.close();
    }
    
    static class Trick {
        public static int SIZE = 4;
        Trick(int fi, int se, Set<Integer> b1, Set<Integer> b2) {
            first = fi;
            second = se;
            firstBoard = b1;
            secondBoard = b2;
        }
        public int first;
        public int second;
        public Set<Integer> firstBoard;
        public Set<Integer> secondBoard;        
    }
    
    private static Trick read(BufferedReader in) throws IOException {
        int first = Integer.parseInt(in.readLine());
        Set<Integer> b1 = new HashSet<>();
        
        for (int row = 1; row <= Trick.SIZE; row++) {
            String line = in.readLine();
            if (row == first) {
                for (String s: line.split(" ")) {
                    b1.add(Integer.parseInt(s));
                }
            }
        }

        int second = Integer.parseInt(in.readLine());
        Set<Integer> b2 = new HashSet<>();
        
        for (int row = 1; row <= Trick.SIZE; row++) {
            String line = in.readLine();
            if (row == second) {
                for (String s: line.split(" ")) {
                    b2.add(Integer.parseInt(s));
                }
            }
        }
        
        return new Trick(first, second, b1, b2);
    }
    
    private static String solve(Trick trick) {
        trick.firstBoard.retainAll(trick.secondBoard);
        if (trick.firstBoard.size() == 1) {
            return "" + trick.firstBoard.iterator().next();
        }
        else if (trick.firstBoard.size() > 1) {
            return "Bad magician!";
        }
        else {
            return "Volunteer cheated!";
        }
    }    
}
