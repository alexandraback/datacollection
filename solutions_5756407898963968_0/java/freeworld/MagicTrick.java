import java.io.*;
import java.util.ArrayList;
import java.util.List;

/**
 * Created by freeworld on 4/11/14.
 */
public class MagicTrick {

    public static int FindCard(List<List<Integer>> grid1, List<List<Integer>> grid2, int row1, int row2) {
        List<Integer> list1 = grid1.get(row1 - 1);
        List<Integer> list2 = grid2.get(row2 - 1);
        List<Integer> list3 = new ArrayList<Integer>(list1);
        for (Integer a : list1) {
            if (!list2.contains(a))
                list3.remove(a);
        }
        if (list3.size() == 1)
            return list3.get(0);
        else if (list3.size() == 0)
            return 0;
        else
            return -1;
    }


    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new FileReader("A-small-attempt0.in"));
        BufferedWriter bw = new BufferedWriter(new FileWriter("A-small-result.out"));

        int caseNum = Integer.parseInt(br.readLine());
        int[] rowNum = new int[2];

        for (int i = 1; i <= caseNum; i++) {
            List<List<List<Integer>>> grids = new ArrayList<List<List<Integer>>>(2);
            grids.add(new ArrayList<List<Integer>>());
            grids.add(new ArrayList<List<Integer>>());
            for (int j = 0; j < 2; j++) {
                grids.get(j).add(new ArrayList<Integer>());
                grids.get(j).add(new ArrayList<Integer>());
                grids.get(j).add(new ArrayList<Integer>());
                grids.get(j).add(new ArrayList<Integer>());
                rowNum[j] = Integer.parseInt(br.readLine());
                for (int k = 0; k < 4; k++) {
                    String[] strs = br.readLine().split("\\s+");
                    for (int l = 0; l < 4; l++)
                        grids.get(j).get(k).add(Integer.parseInt(strs[l]));
                }
            }
            int res = FindCard(grids.get(0), grids.get(1), rowNum[0], rowNum[1]);
            if (res == 0) {
                bw.write("Case #" + i + ": " + "Volunteer cheated!");
            } else if (res == -1) {
                bw.write("Case #" + i + ": " + "Bad magician!");
            } else {
                bw.write("Case #" + i + ": " + res);
            }
            bw.newLine();
        }
        br.close();
        bw.close();
    }
}
