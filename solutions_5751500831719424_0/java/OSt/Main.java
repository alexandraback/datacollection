package src;

import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.Scanner;


public class Main {

    Scanner in;
    PrintWriter out;

    void solve() {
        in.useLocale(Locale.US);
        int nTests = in.nextInt();
        for (int test = 1; test <= nTests; test++) {
            solveOne(test);
        }
    }

    void solveOne(int test) {
        int nWords = in.nextInt();
        String strings[] = new String[nWords];
        for (int i = 0; i < nWords; i++){
            strings[i] = in.next();
        }
        String reducteds[] = new String[nWords];
        for (int i = 0; i < nWords; i++){
            String st = strings[i];
            int idx = 0;
            StringBuilder reducted = new StringBuilder();
            while(idx<st.length()){
                if (idx==0){
                    reducted.append(st.charAt(idx));
                } else{
                    if (st.charAt(idx-1)!=st.charAt(idx)){
                        reducted.append(st.charAt(idx));
                    }
                }
                idx++;
            }
            reducteds[i] = reducted.toString();
        }
        if (canReduct(reducteds)){
            String etalon = reducteds[0];
            int nRepeats[][] = new int[nWords][etalon.length()];
            for (int i = 0; i < strings.length; i++){
                String cur = strings[i];
                int etalonIdx = 0;
                for (int j = 0; j < cur.length(); j++){
                    if (cur.charAt(j)==etalon.charAt(etalonIdx)){
                        nRepeats[i][etalonIdx]++;
                    }else{
                        etalonIdx++;
                        if (cur.charAt(j)==etalon.charAt(etalonIdx)){
                            nRepeats[i][etalonIdx]++;
                        }
                    }
                }
            }
            int totalPenalty = 0;
            for (int i = 0; i < etalon.length(); i++){
                int bestPenalty = Integer.MAX_VALUE/2;
                for (int nReps = 1; nReps<=100; nReps++){
                    int minPenalty = 0;
                    for (int j = 0; j < nRepeats.length; j++){
                        minPenalty+=Math.abs(nRepeats[j][i]-nReps);
                    }
                    bestPenalty = Math.min(bestPenalty, minPenalty);
                }
                totalPenalty+=bestPenalty;
            }
            out.printf(Locale.US, "Case #" + test + ": "+totalPenalty);
        }else{
            out.printf(Locale.US, "Case #" + test + ": "+"Fegla Won");
        }
        out.println();
    }

    private boolean canReduct(String[] reducteds) {
        for (int i = 0; i < reducteds.length-1; i++){
            for (int j = i+1; j < reducteds.length; j++){
                if (!reducteds[i].equals(reducteds[j])){
                    return false;
                }
            }
        }
        return true;
    }

    void run() {
        try {
            in = new Scanner(new FileReader("input.txt"));
            out = new PrintWriter("output.txt");
        } catch (IOException e) {
            throw new Error(e);
        }
        try {
            solve();
        } finally {
            out.close();
            ;
        }
    }

    public static void main(String[] args) {
        new Main().run();
    }

}
