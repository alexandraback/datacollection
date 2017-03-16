import java.io.*;

public class NoisyNeighbors {
    public static void main(String[] args) throws Exception {
        String filename = "B-small-attempt0.in";
        File file = new File("/Users/tanin/Downloads/" + filename);
        File outFile = new File("/Users/tanin/Downloads/" + filename + ".out");
        BufferedReader br = new BufferedReader(new FileReader(file));
        BufferedWriter bw = new BufferedWriter(new FileWriter(outFile));
        int testCases = Integer.parseInt(br.readLine());
        for(int t=1;t<=testCases;t++){
            String[] tokens = br.readLine().split(" ");
            int R = Integer.parseInt(tokens[0]);
            int C = Integer.parseInt(tokens[1]);
            int N = Integer.parseInt(tokens[2]);

            int result = solve(R, C, N);
            System.out.println("Case #" + t + ": " + result + "\n");
            bw.write("Case #" + t + ": " + result + "\n");
        }
        br.close();
        bw.close();
    }

    private static int solve(int R, int C, int N) {
        int left = R * C;
        int M = (1 << (R * C)) - 1;

        return chooseMin(0, R, C, 0, N, left);
    }

    private static int[][] adjacents = new int[][] {
        {0, -1},
        {0, 1},
        {1, 0},
        {-1, 0}
    };

    private static int chooseMin(int M, int R, int C, int index, int N, int left) {
        if (N == 0) {
            int cost = 0;
            for (int r=0;r<R;r++) {
                for (int c=0;c<C;c++) {
                    int pos = r * C + c;

                    for (int i=0;i<adjacents.length;i++) {
                        int neighborR = (r + adjacents[i][0]);
                        int neighborC = (c + adjacents[i][1]);

                        if (neighborR >= 0 && neighborR < R && neighborC >= 0 && neighborC < C) {
                            int neighborPos = neighborR * C + neighborC;

                            if (pos < neighborPos) {
                                if ((M & (1 << pos)) > 0 && (M & (1 << neighborPos)) > 0) {
                                    cost++;
                                }
                            }
                        }
                    }
                }
            }
            System.out.println(R + " x " + C + " " + M);
            return cost;
        }

        // choose the lowest bit
        int bitChosen = 1 << index;
        int resultFromChoosing = chooseMin(M | bitChosen, R, C, index + 1, N - 1, left - 1);

        // skip the lowest bit
        int resultFromSkipping = Integer.MAX_VALUE;
        if (N < left) {
            resultFromSkipping = chooseMin(M, R, C, index + 1, N, left - 1);
        }

        if (resultFromChoosing < resultFromSkipping) {
            return resultFromChoosing;
        } else {
            return resultFromSkipping;
        }
    }
}
