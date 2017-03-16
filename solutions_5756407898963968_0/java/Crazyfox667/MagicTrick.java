import java.io.*;
import java.util.ArrayList;
import java.util.Date;
import java.util.HashSet;

/**
 * Date: 12/04/2014
 * Time: 12:03
 */

public class MagicTrick {

    String bad = "Bad magician!";
    String cheat = "Volunteer cheated!";

    public static void main(String[] args) throws IOException {
        new MagicTrick().doSomething();
    }

    void doSomething() throws IOException {
        try {
            File test = new File("").getAbsoluteFile();
            File[] inList = test.listFiles(new FilenameFilter() {
                @Override
                public boolean accept(File dir, String name) {
                    return name.toLowerCase().contains(".in");
                }
            });
            File fIn = inList[0];
            for (int i = 1; i < inList.length; i++) {
                if (new Date(fIn.lastModified()).compareTo(new Date(inList[i].lastModified())) < 0) {
                    fIn = inList[i];
                }
            }
            File fOut = new File("MagicTrick.out");
            BufferedReader in = new BufferedReader(new FileReader(fIn));
            BufferedWriter out = new BufferedWriter(new FileWriter(fOut));
            int n = Integer.valueOf(in.readLine());
            for (int i = 1; i <= n; i++) {
                out.write("Case #" + i + ": " + solve(in));
                out.newLine();
            }
            in.close();
            out.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    String solve(BufferedReader in) throws IOException {
        int row = Integer.valueOf(in.readLine());
        for (int i = 0; i < row - 1; i++) {
            in.readLine();
        }
        HashSet<Integer> row1 = new HashSet<>();
        String[] read = in.readLine().split(" ");
        for (String s : read) {
            row1.add(Integer.valueOf(s));
        }
        for (int i = 0; i < 4 - row; i++) {
            in.readLine();
        }

        row = Integer.valueOf(in.readLine());
        for (int i = 0; i < row - 1; i++) {
            in.readLine();
        }
        HashSet<Integer> row2 = new HashSet<>();
        read = in.readLine().split(" ");
        for (String s : read) {
            row2.add(Integer.valueOf(s));
        }
        for (int i = 0; i < 4 - row; i++) {
            in.readLine();
        }

        row1.retainAll(row2);

        if (row1.size() == 0) {
            return cheat;
        } else if (row1.size() == 1) {
            return row1.iterator().next().toString();
        } else {
            return bad;
        }
    }
}
