import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Hashtable;
import java.util.Scanner;

public class MagicTrick {
    public static void main(String[] arg) throws IOException {
        FileReader file = new FileReader("A-small-attempt0.in");
        FileWriter output = new FileWriter("output.out");
        Scanner in = new Scanner(file);
        int T, cas, tmp;
        T = in.nextInt();
        int[] row1 = new int[4];
        int[] row2 = new int[4];

        for (cas = 1; cas <= T; cas++) {
            int ans1, ans2;
            ans1 = in.nextInt();
            for (int i = 0; i < 4; i++) {
                if (i == ans1 - 1)
                    for (int j = 0; j < 4; j++) {
                        row1[j] = in.nextInt();
                    }
                else
                    for (int j = 0; j < 4; j++)
                        tmp = in.nextInt();
            }
            ans2 = in.nextInt();
            for (int i = 0; i < 4; i++) {
                if (i == ans2 - 1)
                    for (int j = 0; j < 4; j++) {
                        row2[j] = in.nextInt();
                    }
                else
                    for (int j = 0; j < 4; j++)
                        tmp = in.nextInt();
            }
            Hashtable<Integer, Integer> ret = new Hashtable<Integer, Integer>();
            for (int i = 0; i < 4; i++) {
                ret.put(row1[i], 1);
            }
            ArrayList<Integer> ans = new ArrayList<Integer>();
            for (int i = 0; i < 4; i++) {
                if (ret.containsKey(row2[i]))
                    ans.add(row2[i]);
            }
            if (ans.size() == 0) {
                output.append("Case #" + cas + ": Volunteer cheated!\n");
            } else if (ans.size() == 1) {
                output.append("Case #" + cas + ": " + ans.get(0) + "\n");
            } else {
                output.append("Case #" + cas + ": Bad magician!\n");
            }
        }
        file.close();
        output.close();
    }
}
