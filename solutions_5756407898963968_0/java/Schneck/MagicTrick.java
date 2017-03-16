import java.io.*;
import java.util.*;

public class MagicTrick {
    public static final PrintStream out = System.out;
    public static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    public int numCases;
    
    public void doCase(int caseNumber) throws Exception {
        String line = in.readLine();
        int ans1 = Integer.parseInt(line);
        int[][] grid1 = new int[4][4];
        for (int i = 0; i < 4; i++) {
            line = in.readLine();
            Scanner scan = new Scanner(line);
            for (int j = 0; j < 4; j++) {
                grid1[i][j] = scan.nextInt();
            }
        }
        line = in.readLine();
        int ans2 = Integer.parseInt(line);
        int[][] grid2 = new int[4][4];
        for (int i = 0; i < 4; i++) {
            line = in.readLine();
            Scanner scan = new Scanner(line);
            for (int j = 0; j < 4; j++) {
                grid2[i][j] = scan.nextInt();
            }
        }
        int[] row1 = grid1[ans1-1];
        int[] row2 = grid2[ans2-1];
        List<Integer> poss = new ArrayList<Integer>();
        for (int x : row1) poss.add(Integer.valueOf(x));
        List<Integer> toRetain = new ArrayList<Integer>();
        for (int x : row2) toRetain.add(Integer.valueOf(x));
        poss.retainAll(toRetain);
        if (poss.size()==0) System.out.println("Volunteer cheated!");
        else if (poss.size() > 1) System.out.println("Bad magician!");
        else System.out.println(poss.get(0));
    }
    
    public void run() throws Exception {
        numCases = Integer.parseInt(in.readLine().trim());
        for (int i = 1; i <= numCases; i++) {
            out.print("Case #" + i + ": ");
            doCase(i);
        }
    }
    
    public static void main(String[] args) throws Exception {
        new MagicTrick().run();
    }

}
