
package C1;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

/**
 *
 * @author Jose Andres
 */
public class Ex1 {
    
    public final static String ROUND = "1c";
    public final static String PROBLEM = "1";
    public final static String DATASET = "s";
    public final static String BASEDIR = "D:/gcj/" + ROUND + "/" + PROBLEM + "/" + DATASET + "/";
    public final static String INPUTFILE = BASEDIR + "input.in";
    public final static String OUTPUTFILE = BASEDIR + "output.txt";

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new FileReader(INPUTFILE));
        PrintWriter pw = new PrintWriter(new FileWriter(OUTPUTFILE));
        int caseCnt = sc.nextInt();
        for (int caseNum = 0; caseNum < caseCnt; caseNum++) {
            System.out.println("Processing test case " + (caseNum + 1));
            pw.print("Case #" + (caseNum + 1) + ": ");
            solve(sc, pw);
        }
        pw.flush();
        pw.close();
        sc.close();
    }
    
    public static void solve(Scanner sc, PrintWriter pw) {
        int parties = sc.nextInt();
        int sum = 0;
        int[] senators = new int[parties];
        for (int i = 0; i < parties; i++) {
            senators[i] = sc.nextInt();
            sum += senators[i];
        }
        
        String evacuate = "";
        while (sum > 0) {
            int select = getMax(senators);
            senators[select]--;
            sum--;
            
            if (evacuate.length() == 1 || sum == 2) {
                evacuate += (char) ((char)select + 'A');
                pw.print(evacuate + " ");
                evacuate = "";
            }
            else {
                evacuate += (char) ((char)select + 'A');
                if (sum == 0)
                    pw.print(evacuate + " ");
            }
        }
        
        pw.println();
    }
    
    private static int getMax(int[] senators) {
        int max = 0;
        int maxi = 0;
        for (int i = 0; i < senators.length; i++) {
            if (senators[i] > max) {
                max = senators[i];
                maxi = i;
            }
        }
        return maxi;
    }
}
