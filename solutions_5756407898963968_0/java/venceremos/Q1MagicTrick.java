package q1.magictrick;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.text.MessageFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 *
 * @author tjedziedrowski
 */
public class Q1MagicTrick {
    
    public static void main(String[] args) {
        try {
            BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
            int numOfCases = Integer.parseInt(stdin.readLine());
            for (int currentCase = 1; currentCase <= numOfCases; currentCase++) {
                List<String> potentialAnswers = getPotentialAnswers(stdin);
                List<String> answers = getPotentialAnswers(stdin);
                
                answers.retainAll(potentialAnswers);
                if (answers.isEmpty()) {
                    System.out.println(MessageFormat.format("Case #{0}: Volunteer cheated!", currentCase));
                } else if (answers.size() == 1) {
                    System.out.println(MessageFormat.format("Case #{0}: {1}", currentCase, answers.get(0)));
                } else {
                    System.out.println(MessageFormat.format("Case #{0}: Bad magician!", currentCase));
                }
            }
        } catch (IOException ex) {
            System.err.println("Ooops: " + ex.getMessage());
        }
    }

    private static List<String> getPotentialAnswers(BufferedReader stdin) throws IOException {
        List<String> interestingRow = null;
        int row = Integer.parseInt(stdin.readLine());
        for (int currRow = 1; currRow <= 4; currRow++) {
            String rowString = stdin.readLine();
            if (currRow == row) {
                interestingRow = new ArrayList<String>();
                interestingRow.addAll(Arrays.asList(rowString.split(" ")));
            } 
        }
        
        return interestingRow;
    }
    
}
