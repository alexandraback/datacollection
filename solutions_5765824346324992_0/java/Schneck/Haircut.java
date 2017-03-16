import java.io.*;
import java.util.*;

public class Haircut {
    public static final PrintStream out = System.out;
    public static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    public int numCases;

    Scanner scan = new Scanner(in);

    public void doCase(int caseNumber) throws Exception {
        long B = scan.nextLong();
        long N = scan.nextLong();
        long[] M = new long[(int)B];
        long sumM = 0;
        double sumRecipM = 0;
        for (int i = 0; i < B; i++) {
            M[i] = scan.nextLong();
            sumM += M[i];
            sumRecipM += 1.0/M[i];
        }
        long myMinutesMin = (long)((N-1-B) / sumRecipM);
        if (myMinutesMin < 0) myMinutesMin = 0;
        long myMinutesMax = (long)((N-1+B) / sumRecipM) + 1;
        search(B, N, M, myMinutesMin, myMinutesMax);
    }
    
    private void search(long B, long N, long[] M, long min, long max) {
        long trial = (min + max) / 2;
        int ready = 0;
        long sum = 0;
        for (int i = 0; i < B; i++) {
            sum += trial / M[i];
            if (trial % M[i] == 0) ready++;
            else sum++;
        }
        if (sum < N && sum + ready >= N) {
            long count = N - sum;
            for (int i = 0; i < B; i++) {
                if (trial % M[i] == 0) {
                    count--;
                    if (count == 0) {
                        System.out.println(i + 1);
                        return;
                    }
                }
            }
        }
        else if (sum < N) {
            search(B, N, M, trial + 1, max);
        }
        else {
            search(B, N, M, min, trial - 1);
        }
    }

    public void run() throws Exception {
        numCases = scan.nextInt();
        for (int i = 1; i <= numCases; i++) {
            out.print("Case #" + i + ": ");
            doCase(i);
        }
    }
    
    public static void main(String[] args) throws Exception {
        new Haircut().run();
    }

}
