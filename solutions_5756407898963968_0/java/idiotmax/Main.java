import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class Main {

    public static void main(String[] args) {
        int roundCount = 0;

        BufferedReader br = null;
        BufferedWriter bw = null;
        try {
            br = new BufferedReader(new FileReader("A-small-attempt0.in"));
            bw = new BufferedWriter(new FileWriter("A-small-attempt0.out"));
            String line = br.readLine();

            roundCount = Integer.parseInt(line);
            for (int roundIndex = 0; roundIndex < roundCount; roundIndex++) {

                String[] roundInputs = new String[10];
                for (int i = 0; i < 10; i++) {
                    roundInputs[i] = br.readLine();
                }
                Round round = parseRound(roundInputs);
                if (round == null) {
                    break;
                }
                int result = doCompute(round);

                bw.write(String.format("Case #%d: %s\n", roundIndex + 1, mapResult(result)));
                println(String.format("Case #%d: %s", roundIndex + 1, mapResult(result)));
            }

        } catch (IOException e) {
        } catch (NumberFormatException e) {
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            if (br != null) {
                try {
                    br.close();
                } catch (IOException e) {
                }
            }
            if (bw != null) {
                try {
                    bw.close();
                } catch (IOException e) {
                }
            }
        }

    }

    private static String mapResult(int i) {
        if (i < 0) {
            return "Bad magician!";
        } else if (i == 0) {
            return "Volunteer cheated!";
        } else {
            // i>0
            return String.valueOf(i);
        }
    }

    private static Round parseRound(String[] args) {
        if (args == null || args.length != 10) {
            return null;
        }
        int row1;
        int row2;
        int[][] matrix1 = new int[4][4];
        int[][] matrix2 = new int[4][4];
        row1 = Integer.parseInt(args[0]);
        for (int i = 0; i < 4; i++) {
            String[] str = args[i + 1].split(" ", 4);
            for (int j = 0; j < str.length; j++) {
                matrix1[i][j] = Integer.parseInt(str[j]);
            }
        }
        row2 = Integer.parseInt(args[5]);
        for (int i = 0; i < 4; i++) {
            String[] str = args[i + 6].split(" ", 4);
            for (int j = 0; j < str.length; j++) {
                matrix2[i][j] = Integer.parseInt(str[j]);
            }
        }

        return new Round(row1, matrix1, row2, matrix2);
    }

    private static final class Round {
        final int row1;

        final int row2;

        final int[][] matrix1;

        final int[][] matrix2;

        Round(int row1, int[][] matrix1, int row2, int[][] matrix2) {
            this.row1 = row1;
            this.matrix1 = matrix1;
            this.row2 = row2;
            this.matrix2 = matrix2;
        }

        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder();
            sb.append(row1 + "\n");
            for (int[] a : matrix1) {
                sb.append(String.format("%2d %2d %2d %2d\n", a[0], a[1], a[2], a[3]));
            }
            sb.append(row2 + "\n");
            for (int[] a : matrix2) {
                sb.append(String.format("%2d %2d %2d %2d\n", a[0], a[1], a[2], a[3]));
            }

            return sb.toString();
        }

    }

    private static int doCompute(Round round) {
        int result = 0;
        int count = 0;
        int[] m1row = round.matrix1[round.row1 - 1];
        int[] m2row = round.matrix2[round.row2 - 1];

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (m1row[i] == m2row[j]) {
                    result = m1row[i];
                    count++;
                }
            }
        }

        if (count > 1) {
            return -1;
        }
        return result;
    }

    private static void println(String format, Object... args) {
        System.out.println(String.format(format, args));
    }

}
