package repeater;

import deceitfulWar.DeceitfulWar;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;
import java.util.Locale;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

public class Repeater {

    static int getDist(String A, String B) {
        int posA = 0;
        int posB = 0;
        int diff = 0;
        while (posA < A.length() && posB < B.length()) {
            char let = A.charAt(posA);
            int lenA = 1;
            while (posA + lenA < A.length() && A.charAt(posA + lenA) == let)
                lenA++;
            if (B.charAt(posB) != let) {
                diff = -1;
                break;
            }

            int lenB = 1;
            while (posB + lenB < B.length() && B.charAt(posB + lenB) == let)
                lenB++;
            diff += Math.abs(lenA - lenB);
            posA += lenA;
            posB += lenB;
        }

        if (posA < A.length() || posB < B.length())
            diff = -1;

        return diff;
    }

    public static void main(String[] args) {
        try {
            Scanner s = new Scanner(new BufferedReader(new FileReader("A-small-attempt0.in")));
            Writer w = new BufferedWriter(new FileWriter("A-small-attempt0.out"));

            s.useLocale(Locale.US);

            int T = s.nextInt();
            for (int t = 0; t < T; ++t) {
                int N;
                N = s.nextInt();
                String[] strings = new String[N];
                for (int i = 0; i < N; ++i)
                    strings[i] = s.next();

                boolean over = false;
                for (int i = 0; i < N; ++i)
                    if (getDist(strings[0], strings[i]) == -1) {
                        w.write("Case #" + (t + 1) + ": Fegla Won\n");
                        over = true;
                    }

                if (over)
                    continue;

                int bestDiff = -1;

                for (int i = 0; i < N; ++i) {
                    int sum = 0;
                    for (int j = 0; j < N; ++j)
                        sum += getDist(strings[i], strings[j]);
                    if (bestDiff == -1 || sum < bestDiff)
                        bestDiff = sum;
                }

                w.write("Case #" + (t + 1) + ": " + bestDiff + "\n");
            }
            w.flush();
            w.close();
            s.close();
        } catch (IOException ex) {
            Logger.getLogger(DeceitfulWar.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
}
