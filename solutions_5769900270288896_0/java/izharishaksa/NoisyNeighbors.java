
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.Scanner;

/**
 *
 * @author izharishaksa
 */
public class NoisyNeighbors {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for (int t = 1; t <= T; t++) {
            int R = sc.nextInt();
            int C = sc.nextInt();
            int N = sc.nextInt();
            int ret = Integer.MAX_VALUE;
            boolean[][] used = new boolean[R][C];
            LinkedList<boolean[][]> list = new LinkedList<boolean[][]>();
            list.add(new boolean[R][C]);
            LinkedList<Integer> score = new LinkedList<Integer>();
            score.add(0);
            LinkedList<Integer> total = new LinkedList<Integer>();
            total.add(0);
            Map<String, Boolean> map = new HashMap<String, Boolean>();
            map.put("", true);
            while (!list.isEmpty()) {
                boolean[][] cur = list.poll();
                int curScore = score.poll();
                int curN = total.poll();
                if (curN == N) {
                    ret = Math.min(ret, curScore);
                } else if (curScore < ret) {
                    for (int i = 0; i < R; i++) {
                        for (int j = 0; j < C; j++) {
                            if (!cur[i][j]) {
                                boolean[][] temp = new boolean[R][C];
                                for (int k = 0; k < R; k++) {
                                    for (int l = 0; l < C; l++) {
                                        temp[k][l] = cur[k][l];
                                    }
                                }
                                temp[i][j] = true;
                                String x = "";
                                for (int k = 0; k < R; k++) {
                                    for (int l = 0; l < C; l++) {
                                        if (temp[k][l]) {
                                            x += k + "," + l + " ";
                                        }
                                    }
                                }
                                if (map.containsKey(x)) {
                                    continue;
                                }
                                map.put(x, true);
                                total.add(curN + 1);
                                list.add(temp);
                                int tempScore = 0;
                                if (i - 1 >= 0 && cur[i - 1][j]) {
                                    tempScore++;
                                }
                                if (i + 1 < R && cur[i + 1][j]) {
                                    tempScore++;
                                }
                                if (j - 1 >= 0 && cur[i][j - 1]) {
                                    tempScore++;
                                }
                                if (j + 1 < C && cur[i][j + 1]) {
                                    tempScore++;
                                }
                                score.add(curScore + tempScore);
                            }
                        }
                    }
                }
            }

            System.out.println("Case #" + t + ": " + ret);
        }
    }

}
