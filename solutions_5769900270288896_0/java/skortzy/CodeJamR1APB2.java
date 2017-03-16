import java.io.*;

/**
 * Created by skortzy on 02/05/15.
 */
public class CodeJamR1APB2 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("B-small-attempt0.in")));
        PrintWriter pw = new PrintWriter(new FileOutputStream("B.out"));
        String line = br.readLine();
        int T = Integer.parseInt(line);
        for (int i = 0; i < T; i++) {
            System.out.println("Case #" + (i + 1));

            line = br.readLine();
            String tokens[] = line.split(" ");
            pw.println("Case #" + (i+1) + ": " + solve(Integer.parseInt(tokens[0]), Integer.parseInt(tokens[1]), Integer.parseInt(tokens[2])));

        }
        pw.close();

    }

    private static int solve(int R, int C, int N) {
        int min = Integer.MAX_VALUE;
        int total = R * C;
        long max = 1 << total;
        for (long k = 0; k < max; k++) {
            boolean[][] building = new boolean[R][C];
            int count = 0;
            long value = k;
            for (int i = 0; i < R; i++) {
                for (int j = 0; j < C; j++) {
                    count += value % 2;
                    building[i][j] = (value % 2 == 1);
                    value /= 2;
                }
            }
            if (count != N) {
                continue;
            }
            count = 0;
            for (int i = 0; i < R; i++) {
                for (int j = 0; j < C - 1; j++) {
                    if (building[i][j] && building[i][j+1]) {
                        count++;
                    }
                }
            }
            for (int i = 0; i < R-1; i++) {
                for (int j = 0; j < C; j++) {
                    if (building[i][j] && building[i+1][j]) {
                        count++;
                    }
                }
            }
            if (min > count) {
                min = count;
            }


        }

        return min;


    }


}
