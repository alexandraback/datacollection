package y2015.contest.r1b;

import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

/**
 * @author ashevenkov
 */
public class ProblemB {

    public static final String TITLE = "B-small-attempt0";
    private static BufferedReader in = prodIn();
    private static BufferedWriter out = prodOut();

    private static BufferedWriter prodOut() {
        try {
            return new BufferedWriter(new FileWriter("codejam/output/" + TITLE + ".out"));
        } catch (IOException e) {
            e.printStackTrace();
        }
        return null;
    }

    private static BufferedReader prodIn() {
        try {
            return new BufferedReader(new FileReader("codejam/input/" + TITLE + ".in"));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        return null;
    }


    private static BufferedWriter testOut() {
        return new BufferedWriter(new OutputStreamWriter(System.out));
    }

    private static BufferedReader testIn() {
        return new BufferedReader(new InputStreamReader(System.in));
    }

    public static void main(String[] args) throws Exception {
        new ProblemB().solve(in, out);
        out.flush();
        out.close();
    }

    //implement
    private void solve(BufferedReader in, BufferedWriter out) throws Exception {
        Scanner scanner = new Scanner(in);
        int t = scanner.nextInt();
        for(int i = 0; i < t; i++) {
            int r = scanner.nextInt();
            int c = scanner.nextInt();
            int n = scanner.nextInt();
            out.write("Case #" + (i + 1) + ": " +  solveCase(r, c, n));
            out.newLine();
        }
    }

    private String solveCase(int r, final int c, int n) {
        final int[][] cellCount = new int[r][c];
        ArrayList<Integer> list = new ArrayList<>();
        for(int row = 0; row < r; row++) {
            for(int column = 0; column < c; column++) {
                int count = 4;
                if(column == 0) {
                    count--;
                }
                if(column == c - 1) {
                    count--;
                }
                if(row == 0) {
                    count--;
                }
                if(row == r - 1) {
                    count--;
                }
                cellCount[row][column] = count;
                list.add(row * c + column);
            }
        }
        for(int i = r * c; i > n; i--) {
            Collections.sort(list, new Comparator<Integer>() {
                @Override
                public int compare(Integer o1, Integer o2) {
                    return Integer.compare(cellCount[o1/c][o1%c], cellCount[o2/c][o2%c]);
                }
            });
            int lastIndex = list.size() - 1;
            Integer index = list.remove(lastIndex);
            int column = index % c;
            int row = index / c;
            cellCount[row][column] = 0;
            if(column > 0) {
                cellCount[row][column - 1]--;
            }
            if(column < c - 1) {
                cellCount[row][column + 1]--;
            }
            if(row > 0) {
                cellCount[row - 1][column]--;
            }
            if(row < r - 1) {
                cellCount[row + 1][column]--;
            }
        }
        int sum = 0;
        for(int row = 0; row < r; row++) {
            for(int column = 0; column < c; column++) {
                if(cellCount[row][column] > 0) {
                    sum += cellCount[row][column];
                }
            }
        }
        return Integer.toString(sum/2);
    }
}
