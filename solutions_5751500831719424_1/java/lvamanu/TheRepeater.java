
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;
import java.util.Vector;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/**
 *
 * @author lvamanu
 */
public class TheRepeater {

    private static int[][] checkIfPossible(ArrayList<String> input) {
        int N = input.size();
        
        int nrLetters = 0;
        String first = input.get(0);
        char seq[] = new char[first.length()];
        int count[][] = new int[N][first.length()];
        seq[0] = first.charAt(0);
        int nrApp = 1;
        
        for (int i = 1; i < first.length(); i++) {
            if (seq[nrLetters] == first.charAt(i)) {
                nrApp++;
                continue;
            }
            count[0][nrLetters] = nrApp;
            nrApp = 1;
            nrLetters++;
            seq[nrLetters] = first.charAt(i);
        }
        count[0][nrLetters] = nrApp;

        boolean notPossible = false;
        for (int k = 1; k < input.size() && notPossible == false; k++) {
            String curr = input.get(k);

            int indexL = 0;
            nrApp = 0;
            for (int j = 0; j < curr.length(); j++) {
                if (curr.charAt(j) == seq[indexL]) {
                    nrApp++;
                    continue;
                }
                if (nrApp == 0) {
                    notPossible = true; 
                    break;
                }
                count[k][indexL] = nrApp;
                indexL++;
                if (indexL > nrLetters || curr.charAt(j) != seq[indexL]) {
                    nrApp = 0;
                    notPossible = true;
                    break;
                }
                nrApp = 1;
            }
            if (notPossible || indexL != nrLetters) {
                return null;
            }
            count[k][indexL] = nrApp;
        }

        return count;
    }

    private static int minTransforms(ArrayList<String> input) {
        int count[][] = checkIfPossible(input);

        if (count == null) {
            return -1; // not possible
        }

        int N = input.size();
        int nrTrans = 0;
        int minLength = input.get(0).length();
        for (int i = 0; i < minLength && count[0][i] > 0; i++) {
            Vector<Integer> app = new Vector<Integer>();
            for (int j = 0; j < N; j++) {
                app.add(count[j][i]);
            }
            Collections.sort(app);
            int minTr = Integer.MAX_VALUE;
            for (int k = 0; k < N; k++) {
                int currD = app.get(k);
                int sum = 0;
                for (int t = 0; t < N; t++) {
                    sum = sum + Math.abs(count[t][i] - currD);
                }
                minTr = Math.min(minTr, sum);
            }
            nrTrans += minTr;
        }

        return nrTrans;
    }

    public static void main(String[] args) throws FileNotFoundException {
      Scanner in = new Scanner(new File("A-large.in"));
        PrintWriter out = new PrintWriter(new File("Alarge.out"));
        int T = in.nextInt();
        for (int i = 1; i <= T; i++) {
            int N = in.nextInt();
            ArrayList<String> input = new ArrayList<String>();
            int minLength = Integer.MAX_VALUE;
            for (int j = 0; j < N; j++) {
                String s = in.next();
                input.add(s);
            }

            int res = minTransforms(input);
            if (res == -1) {
                out.println("Case #" + i + ": Fegla Won");
            } else {
                out.println("Case #" + i + ": " + res);
            }

        }
        in.close();
        out.close();
    }

}
