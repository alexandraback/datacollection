import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;


public class MagicTrick {
    static Scanner input;
    static PrintWriter out;

    public static void main(String[] args) throws Exception {
        input = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        out = new PrintWriter(System.out);

        input = new Scanner(new BufferedReader(new FileReader("A-small-attempt0.in")));
        out = new PrintWriter(new FileWriter("A-small-attempt0.out"));

        int testCases = input.nextInt();
        for(int testCase = 1; testCase <= testCases; testCase++) {
            out.print("Case #" + testCase + ": ");
            solveCase();
        }
        out.close();
    }

    static void solveCase() {
        Set<Integer> possible = getPossible();
        possible.retainAll(getPossible());
        
        if (possible.size() == 1)
            out.println(possible.toArray()[0]);
        else if (possible.size() == 0)
            out.println("Volunteer cheated!");
        else
            out.println("Bad magician!");
    }
    
    static Set<Integer> getPossible() {
        int row = input.nextInt() - 1;
        Set<Integer> possible = new HashSet<Integer>();
        for(int i=0;i<4;i++) {
            for(int j=0;j<4;j++) {
                int value = input.nextInt();
                if(row == i)
                    possible.add(value);
            }
        }
        return possible;
    }
}
