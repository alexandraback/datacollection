import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Scanner;

public class SenateEvacuation {
    private static final String ANSWER_PREFIX = "Case #";

    private static final char[] PARTIES       = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V',
            'W', 'X', 'Y', 'Z' };

    private static int sumSenate(int[] senate) {
        int sum = 0;
        for (int i = 0; i < senate.length; i++) {
            sum += senate[i];
        }
        return sum;
    }

    private static int getMajorityParty(int[] senate) {
        int max = 0;
        int party = -1;
        for (int i = 0; i < senate.length; i++) {
            if (senate[i] > max) {
                party = i;
                max = senate[i];
            }
        }
        return party;
    }

    private static boolean hasAbsoluteMajority(int[] senate) {
        int nbSenator = sumSenate(senate);
        boolean hasMajority = false;
        int i = 0;
        while (!hasMajority && i < senate.length) {
            hasMajority = senate[i] > (nbSenator / 2);
            i++;
        }
        return hasMajority;
    }

    public static void test(int caseNb, Scanner sc, PrintWriter pw) {
        String answer = ANSWER_PREFIX;

        int nbParty = sc.nextInt();
        int[] senate = new int[nbParty];
        for (int i = 0; i < nbParty; i++) {
            senate[i] = sc.nextInt();
        }
        int nbSenator = sumSenate(senate);
        answer = answer.concat(String.valueOf(caseNb)).concat(":");
        while (nbSenator > 0) {
            answer = answer.concat(" ");
            int party1 = getMajorityParty(senate);
            int[] tempSenate = senate.clone();
            tempSenate[party1]--;
            if (sumSenate(tempSenate) == 2) {
                if (!hasAbsoluteMajority(tempSenate)) {
                    senate = tempSenate;
                    answer = answer.concat(String.valueOf(PARTIES[party1]));
                } else {
                    System.out.println("PROBLEM (with only 2 remainings) !!!!!!!!!!!!!");
                    nbSenator = 0;
                    answer = answer.concat("BUG!!!!!!!!!!!!!!");
                }
            } else {
                int party2 = getMajorityParty(tempSenate);
                int[] tempSenateBis = tempSenate.clone();
                tempSenateBis[party2]--;
                if (!hasAbsoluteMajority(tempSenateBis)) {
                    senate = tempSenateBis;
                    answer = answer.concat(String.valueOf(PARTIES[party1])).concat(String.valueOf(PARTIES[party2]));
                } else {
                    System.out.println("PROBLEM!!!!!!!!!!!!!");
                    nbSenator = 0;
                    answer = answer.concat("BUG!!!!!!!!!!!!!!");
                }
            }
            nbSenator = sumSenate(senate);
        }
        pw.println(answer);
        System.out.println(answer);
    }

    public static void main(String[] args) {
        ClassLoader classLoader = CountigSheep.class.getClassLoader();
        File input = new File(classLoader.getResource("A-small-attempt0.in").getFile());
        Scanner sc;
        try {
            sc = new Scanner(new FileReader(input));
            PrintWriter pw = new PrintWriter(input.getPath().replaceAll("\\.in", ".out"));

            int T = Integer.parseInt(sc.nextLine());
            for (int i = 1; i <= T; i++) {
                test(i, sc, pw);
            }
            pw.close();
            sc.close();
        } catch (FileNotFoundException e) {
            System.err.println("Error reading/writing file.");
            e.printStackTrace();
        }

    }
}
