package magician;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.HashSet;
import java.util.Set;

/**
 * Created with IntelliJ IDEA.
 * User: thasner
 * Date: 4/11/14
 * Time: 7:04 PM
 * To change this template use File | Settings | File Templates.
 */
public class Magician {

    private static final String SPACE = " ";
    private static final String CHEATED = "Volunteer cheated!";
    private static final String MISTAKE = "Bad magician!";

    private static int nRead = 0;

    public static void main(String[] args) throws Exception {
        FileReader input = new FileReader("src/magician/A-small-attempt0.in");
//        FileReader input = new FileReader("src/minimumScalarProduct/A-large-practice.in");
        BufferedReader b = new BufferedReader(input);

        FileWriter output = new FileWriter("src/magician/A-small-attempt0.out");
//        FileWriter output = new FileWriter("src/minimumScalarProduct/A-large-practice.out");
        BufferedWriter w = new BufferedWriter(output);

        String nLines = b.readLine();
        int numCases = Integer.parseInt(nLines);

        String firstRowNum = null;
        int x;
        String firstRow = null;
        Set<Integer> s1 = null;
        String secondRowNum = null;
        int y;
        String secondRow = null;
        Set<Integer> s2 = null;

        for (int i = 0; i < numCases; i++) {
            firstRowNum = b.readLine();
            x = Integer.parseInt(firstRowNum);
            for (int four = 0; four < 4; four++) {
                String s = b.readLine();
                if ((four + 1) == x) {
                    firstRow = s;
                }
            }
            s1 = makeSet(firstRow);

            secondRowNum = b.readLine();
            y = Integer.parseInt(secondRowNum);
            for (int four = 0; four < 4; four++) {
                String s = b.readLine();
                if ((four + 1) == y) {
                    secondRow = s;
                }
            }
            s2 = makeSet(secondRow);

            Set<Integer> res = new HashSet<Integer>(4);

            for (Integer num : s1) {
                if (s2.contains(num)) {
                    res.add(num);
                }
            }

            nRead++;
            String report = "Case #" + nRead + ": ";
            if (res.isEmpty()) {
                report +=  CHEATED;
            } else if (res.size() == 1) {
                report += (res.toArray())[0];
            } else if (res.size() > 1) {
                report += MISTAKE;
            } else {
                throw new Exception();
            }

            w.write(report);
            w.newLine();
        }

        w.flush();
        w.close();
    }

    private static Set<Integer> makeSet(String s) {
        String[] nums = s.split(SPACE);
        Set<Integer> set = new HashSet<Integer>(4);
        for (int i = 0; i < nums.length; i++) {
            String j = nums[i];
            int k = Integer.parseInt(j);
            set.add(k);
        }
        return set;
    }
}
