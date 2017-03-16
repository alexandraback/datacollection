package qualification;

import java.io.File;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class MagicTrick {
    
    public static void main(String[] args) throws Exception {
        File inputFile = new File("A-small-attempt0.in");
        Scanner in = new Scanner(inputFile);
        File outputFile = new File("output.txt");
        PrintWriter out = new PrintWriter(outputFile);

        int T = in.nextInt();
        for (int t=0; t<T; t++) {
            List<Integer> candidates1 = new ArrayList<Integer>(4);
            List<Integer> candidates2 = new ArrayList<Integer>(4);
            int[] answer = new int[2];
            for (int round=0; round<=1; round++) {
                answer[round] = in.nextInt();
                for (int row = 1; row <= 4; row++) {
                    for (int column = 1; column <= 4; column++) {
                        int card = in.nextInt();
                        if (row == answer[round]) {
                            (round == 0 ? candidates1 : candidates2).add(card);
                        }
                    }
                }
            }
            candidates1.retainAll(candidates2);
            String result;
            if (candidates1.isEmpty()) {
                result = "Volunteer cheated!";
            } else if (candidates1.size() > 1) {
                result = "Bad magician!";
            } else {
                result = Integer.toString(candidates1.get(0));
            }
            
            out.println("Case #"+(t+1)+": "+result);
        }

        out.close();
    }
    
}
