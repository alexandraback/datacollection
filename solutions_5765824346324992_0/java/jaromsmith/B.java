import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

public class B {

    private static final String BASE = "C:\\cygwin\\home\\jsmith\\codejam\\2015\\Round1A\\B\\";
    private static final String PROBLEM = "B-small-attempt3";


    public static void main(String[] args) {
        String input = BASE + PROBLEM + ".in";
        String output = BASE + PROBLEM + ".out";

        try {
            Scanner sc = new Scanner(new FileReader(input));
            PrintWriter pw = new PrintWriter(output);

            int mumCases = sc.nextInt();
            sc.nextLine();
            for (int caseNumber = 0; caseNumber < mumCases; caseNumber++) {
                System.out.println("Test case " + (caseNumber + 1) + "...");
                pw.print("Case #" + (caseNumber + 1) + ": ");
                solve(sc, pw);
                pw.println();
            }
            pw.flush();
            pw.close();
            sc.close();
        } catch (FileNotFoundException ex) {
            Logger.getLogger(B.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

    private static void solve(Scanner sc, PrintWriter pw) {
        final int B = sc.nextInt();
        final int N = sc.nextInt();

        int[] minutesRequired = new int[B];
        for (int i = 0; i < B; i++) {
            minutesRequired[i] = sc.nextInt();
        }


        int[] timeRemaining = new int[B];

        int barber = 0;

        if (N <= B) {
            barber = N;
        } else {
            // assign clients to barbers and count down minutes until there is a zero.
            // then assign the next person(s) to that zero.
            // when you reach your spot in line, that's the barber you get.

            // naive approach is not fast enough so we need to employ some tricks
            // we determine the least common multiple of the times of all the barbers.
            // then we figure out how many clients can fit into one time chunk of that size.
            // we skip forward by that amount until we get down to the last part which we can do naively...
            long lcm = lcm(minutesRequired);
            int clientsInLCM = 0;
            for (int minutesRequiredThisBarber : minutesRequired) {
                clientsInLCM += lcm/minutesRequiredThisBarber;
            }

            // skip ahead by chunks of that many clients.
            int currentClient = 0;
            while (currentClient + clientsInLCM < N) {
                currentClient += clientsInLCM;
            }

            if (N - currentClient <= B) {
                barber = N-currentClient;
            } else {
                for (int i = 0; i < B; i++) {
                    timeRemaining[i] = minutesRequired[i];
                }
                currentClient += B;

                while (currentClient < N) {
                    List<Integer> availableBarbers = countdownTimeRemaining(timeRemaining);
                    if (availableBarbers.size() > 0) {
                        for (Integer availableBarber : availableBarbers) {
                            if (currentClient != N) {
                                timeRemaining[availableBarber] = minutesRequired[availableBarber];
                                currentClient++;
                                barber = availableBarber +1;
                            }
                        }
                    }
                }
            }
        }

        pw.print(barber);
    }

    private static List<Integer> countdownTimeRemaining(int[] timeRemaining) {
        List<Integer> result = new ArrayList<>();

        for (int i = 0; i < timeRemaining.length; i++) {
            timeRemaining[i]--;
            if (timeRemaining[i] == 0) {
                result.add(i);
            }
        }

        return result;
    }

    // stolen from http://stackoverflow.com/questions/4201860/how-to-find-gcf-lcm-on-a-set-of-numbers
    private static long gcd(long a, long b)
    {
        while (b > 0)
        {
            long temp = b;
            b = a % b; // % is remainder
            a = temp;
        }
        return a;
    }

    private static long gcd(long[] input)
    {
        long result = input[0];
        for(int i = 1; i < input.length; i++) result = gcd(result, input[i]);
        return result;
    }

    private static long lcm(long a, long b)
    {
        return a * (b / gcd(a, b));
    }

    private static long lcm(int[] input)
    {
        long result = input[0];
        for(int i = 1; i < input.length; i++) result = lcm(result, input[i]);
        return result;
    }
}
