import java.util.*;
import java.io.*;

public class A {

    public static void main(String[] args) {
        Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int t = in.nextInt();  // number of test cases
        for (int i = 1; i <= t; ++i) {
            int N = in.nextInt();
            int[] P = new int[N];
            int people = 0;
            for (int j=0; j<N; j++) {
                P[j] = in.nextInt();
                people += P[j];
                // System.out.print(P[j]);
            }
            // System.out.println("");
            System.out.println("Case #" + i + ": " + evacuate(N,P,people));
        }
    }  

    public static String evacuate(int N, int[] P, int people) {
        ArrayList<Integer> remainingParties = new ArrayList<Integer>();
        int max = 0;
        for (int i=0; i<N; i++) {
            if (P[i] > 0) {
                remainingParties.add(i);
                if (P[i] > P[max]) {
                    max = i;
                }
            }
        }
        // System.out.println("Max: " + max);
        if (remainingParties.size() == 2) {
            if (P[remainingParties.get(0)] == P[remainingParties.get(1)]) {
                StringBuilder s = new StringBuilder();
                for(int i=0; i<P[remainingParties.get(0)]; i++) {
                    char c1 = (char) ('A' + ((char) remainingParties.get(0).intValue()));
                    char c2 = (char) ('A' + ((char) remainingParties.get(1).intValue()));
                    String temp = c1 +  "" + c2 + " ";
                    s.append(temp);
                }
                return s.toString();
            } else {
                if (P[0] > P[1]) {
                    P[0]--;
                    return "A " + evacuate(N,P, people);
                }
            }
        } else {
            char c = (char) ('A' + ((char) max));
            P[max]--;
            return c + " " + evacuate(N,P,people);
        }
        return "";
    }
}

