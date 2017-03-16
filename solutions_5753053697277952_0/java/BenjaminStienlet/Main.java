package GCJ2016.round1C.problemA;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.util.Scanner;

public class Main {

    char[] ALPHABET = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

    public static void main(String[] args) throws Exception {
        new Main();
    }

    public Main() throws Exception {
        solve();
    }

    private void solve() throws Exception {
        System.out.println(">>> Input: ");
        Scanner sc = new Scanner(System.in);
        BufferedWriter out = new BufferedWriter(new FileWriter("output.txt"));

        int test_cases = sc.nextInt();

        for (int test_case = 1; test_case <= test_cases; test_case++) {
            int nrParties = sc.nextInt();
            int[] nrSenators = new int[nrParties];
            for (int i = 0; i < nrParties; i++) {
                nrSenators[i] = sc.nextInt();
            }

            String result = "Case #" + test_case + ": " + getResult(nrParties, nrSenators);
            out.write(result + "\n");
            System.out.println(result);
        }

        out.flush();
        out.close();
        sc.close();
    }

    private String getResult(int nrParties, int[] nrSenators) {
        StringBuilder builder = new StringBuilder();

        int senators = 0;
        for (int i = 0; i < nrParties; i++) {
            senators += nrSenators[i];
        }

        while (senators > 0) {
            int firstParty = getMaxIndex(nrSenators);
            nrSenators[firstParty] = nrSenators[firstParty] - 1;
            senators--;
            builder.append(ALPHABET[firstParty]);

            if (senators != 2 && senators != 0) {
                int secondParty = getMaxIndex(nrSenators);
                nrSenators[secondParty] = nrSenators[secondParty] - 1;
                senators--;
                builder.append(ALPHABET[secondParty]);
            }

            builder.append(" ");
        }

        return builder.toString().trim();
    }

    private int getMaxIndex(int[] list) {
        int maxIndex = 0;
        for (int i = 0; i < list.length; i++) {
            if (list[i] > list[maxIndex]) {
                maxIndex = i;
            }
        }
        return maxIndex;
    }
}