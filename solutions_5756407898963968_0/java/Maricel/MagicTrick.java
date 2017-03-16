package A;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

class MagicTrick {

    Scanner in;
    BufferedWriter out;
    private int ty;
    private int tx;
    private boolean canBeDraw;

    MagicTrick(String input, String output) throws Exception {
        in = new Scanner(new File(input));
        FileWriter fstream = new FileWriter(output);
        out = new BufferedWriter(fstream);
    }

    public static void main(String[] args) throws Exception {
        MagicTrick tictactoe = new MagicTrick("src/A/in.txt", "src/A/out.txt");
        tictactoe.solve();
        tictactoe.close();
    }

    public void solve() throws IOException {
        int t = in.nextInt();

        for (int i = 1; i <= t; i++) {
            int line = in.nextInt();
            int[][] table = readTable();
            Set<Integer> values = getValuesFromLine(table, line - 1);
            line = in.nextInt();
            table = readTable();
            values.retainAll(getValuesFromLine(table, line - 1));
            
            if (values.size() > 1) {
                print(badMagician(i));
            } else if (values.isEmpty()) {
                print(cheatingVolunteer(i));
            } else {
                print(getCard(i, values));
            }
        }
    }
    
    private Set<Integer> getValuesFromLine(int[][] table, int line) {
        Set<Integer> set = new HashSet<>();
        for (int i = 0; i < table[line].length; i++) {
            set.add(table[line][i]);
        }
        return set;
    }

    private int[][] readTable() {
        int[][] table = new int[4][4];
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                table[i][j] = in.nextInt();
            }
        }
        return table;
    }

    private void print(String s) throws IOException {
        out.write(s);
    }

    private String badMagician(int test) {
        return "Case #" + test + ": Bad magician!\n";
    }

    public String cheatingVolunteer(int test) {
        return "Case #" + test + ": Volunteer cheated!\n";
    }

    public String getCard(int test, Set<Integer> cardSet) {
        int card = cardSet.iterator().next();
        return "Case #" + test + ": " + card + "\n";
    }

    private void close() throws IOException {
        this.in.close();
        this.out.close();
    }
}