import java.io.*;
import java.util.*;

public class Mushroom {
    public static final PrintStream out = System.out;
    public static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    public int numCases;
    
    public void doCase(int caseNumber) throws Exception {
        String line = in.readLine();
        Scanner scan = new Scanner(line);
        int N = scan.nextInt();
        line = in.readLine();
        scan = new Scanner(line);
        int prev = scan.nextInt();
        int max = 0;
        int sum = 0;
        int[] m = new int[N];
        m[0] = prev;
        for (int i = 1; i < N; i++) {
            int next = scan.nextInt();
            m[i] = next;
            int diff = prev - next;
            if (diff > 0) sum += diff;
            if (diff > max) max = diff;
            prev = next;
        }
        int res = 0;
        for (int i = 0; i < N-1; i++) {
            res += Math.min(max, m[i]);
        }
        System.out.println(sum + " " + res);
    }
    
    public void run() throws Exception {
        numCases = Integer.parseInt(in.readLine().trim());
        for (int i = 1; i <= numCases; i++) {
            out.print("Case #" + i + ": ");
            doCase(i);
        }
    }
    
    public static void main(String[] args) throws Exception {
        new Mushroom().run();
    }

}
