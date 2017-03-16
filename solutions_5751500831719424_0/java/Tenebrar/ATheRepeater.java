package codejam140503;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author peter
 */
public class ATheRepeater {

    public static final String IMPOSSIBLE = "Fegla Won";

    public static void main(String[] args) throws Exception {
        try (BufferedReader br = new BufferedReader(new FileReader("/Users/peter/Downloads/A-small-attempt0.in"));
                PrintStream ps = new PrintStream("/Users/peter/Downloads/A-small-attempt0.out")) {
            int amount = readOneLineInteger(br);
            for (int i = 1; i <= amount; i++) {
                int amountOfStrings = readOneLineInteger(br);
                List<String> strings = new ArrayList<>(amountOfStrings);
                for (int j = 0; j < amountOfStrings; j++) {
                    strings.add(br.readLine());
                }

                int result = caclulateOptimal(strings);

                System.out.print("Case #" + i + ": ");
                ps.print("Case #" + i + ": ");
                if (result >= 0) {
                    System.out.println(result);
                    ps.println(result);
                } else {
                    System.out.println(IMPOSSIBLE);
                    ps.println(IMPOSSIBLE);
                }
            }
        }
    }

    private static int readOneLineInteger(BufferedReader br) throws IOException {
        return Integer.valueOf(br.readLine());
    }

    private static int caclulateOptimal(List<String> strings) {
        int totalMoves = 0;

        while (strings.get(0).length() > 0) {
//            System.out.println(strings);
            int[] lengthDifferences = new int[strings.size()];
            char firstChar = strings.get(0).charAt(0);
            double count = 0;
            for (int i = 0; i < strings.size(); i++) {
                String s = strings.get(i);
                String newS = s.replaceFirst(firstChar + "*", "");
                strings.set(i, newS);
                lengthDifferences[i] = s.length() - newS.length();

                if (lengthDifferences[i] == 0) {
                    return -1;
                }

                count += lengthDifferences[i];
            }
            int roundedAvg = (int) Math.round(count / strings.size());
            for(int diff : lengthDifferences) {
                totalMoves += Math.abs(roundedAvg  - diff);
            }
        }
        
        for(String s : strings) {
            if(s.length() > 0) {
                return -1;
            }
        }

        return totalMoves;
    }
}
