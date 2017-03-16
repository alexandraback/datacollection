package at.jaki.round1B.A;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;

public class A {

    private static class Entity {
        List<Character> charArray;
        List<Integer> intArray;

        private Entity(List<Character> charArray, List<Integer> intArray) {
            this.charArray = charArray;
            this.intArray = intArray;
        }
    }

    //private static final String INPUT = "A-large.in";
    private static final String INPUT = "A-small-attempt0.in";
    //private static final String INPUT = "A-test.in";
    //private static final String OUTPUT = "A-large.out";
    private static final String OUTPUT = "A-small-attempt0.out";
    //private static final String OUTPUT = "A-test.out";

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader(INPUT));
        PrintWriter pw = new PrintWriter(OUTPUT);
        int totalTests = Integer.parseInt(br.readLine());
        for (int testNo = 1; testNo <= totalTests; testNo++) {
            int n = Integer.parseInt(br.readLine());

            List<Entity> list = new ArrayList<Entity>(n);
            for (int i = 0; i < n; i++) {
                String word = br.readLine();
                List<Character> charArray = new ArrayList<Character>();
                List<Integer> intArray = new ArrayList<Integer>();
                char currChar = '~';
                int j = -1;
                for (char ch : word.toCharArray()) {
                    if (ch == currChar) {
                        intArray.set(j, intArray.get(j) + 1);
                    } else {
                        charArray.add(ch);
                        intArray.add(1);
                        j++;
                        currChar = ch;
                    }
                }
                list.add(new Entity(charArray, intArray));
            }

            String result;
            if (!isValid(list)) {
                result = "Fegla Won";
            } else {
                int res = solve(list);
                result = "" + res;
            }

            pw.print("Case #" + testNo + ": ");
            pw.println(result);

            System.out.println(result);
        }

        pw.flush();
        pw.close();

    }

    private static int solve(List<Entity> list) {
        int[][] counts = new int[list.size()][list.get(0).intArray.size()];
        double[] avg = new double[list.get(0).intArray.size()];
        for (int i = 0; i < list.size(); i++) {
            for (int j = 0; j < list.get(i).intArray.size(); j++) {
                counts[i][j] += list.get(i).intArray.get(j);
                avg[j] += counts[i][j];
            }
        }
        for (int i = 0; i < list.get(0).intArray.size(); i++) {
            avg[i] /= (double) list.size();
        }
        int total = 0;
        for (int j = 0; j < list.get(0).intArray.size(); j++) {
            int down = (int) avg[j];
            int up = (int) avg[j] + 1;
            int subtotalUp = 0;
            int subtotalDown = 0;
            for (int i = 0; i < list.size(); i++) {
                subtotalDown += Math.abs(counts[i][j] - down);
                subtotalUp += Math.abs(counts[i][j] - up);
            }
            total += Math.min(subtotalDown, subtotalUp);
        }


        return total;  //To change body of created methods use File | Settings | File Templates.
    }

    private static boolean isValid(List<Entity> list) {
        List<Character> mainList = list.get(0).charArray;
        for (Entity x : list) {
            List<Character> secList = x.charArray;
            if (mainList.size() != secList.size()) {
                return false;
            }
            for (int i = 0; i < mainList.size(); i++) {
                if (!mainList.get(i).equals(secList.get(i))) {
                    return false;
                }
            }
        }
        return true;
    }


}
