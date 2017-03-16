import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;

public class CodeJamB {

    public static final String INPUT = "/opt/dev/TopCoder/src/B-small-attempt0.in";
    public static final String OUTPUT = "/opt/dev/TopCoder/src/out.txt";

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new FileReader(INPUT));
        PrintWriter writer = new PrintWriter(OUTPUT, "UTF-8");
        try {
            solve(br, writer);
        } finally {
            br.close();
            writer.close();
        }
    }

    private static void solve(BufferedReader reader, PrintWriter writer) throws Exception {
        int t = Integer.parseInt(reader.readLine().trim());
        for (int i = 0; i < t; i++) {
            String[] values = reader.readLine().split(" ");
            int r = Integer.parseInt(values[0]);
            int c = Integer.parseInt(values[1]);
            int n = Integer.parseInt(values[2]);
            writer.println("Case #" + (i + 1) + ": " + getResult(r, c, n));
        }
    }

    private static String getResult(int r, int c, int n) {
        boolean[] previousRow = new boolean[c];
        boolean[] previousUnHappy = new boolean[c];
        long unhappy = 0;
        boolean[] currentRow = new boolean[c];
        boolean[] currentUnHappy = new boolean[c];
        int currentRowNumber = 0;
        int currentDecided = 0;

        return Long.toString(getUnhappiness(previousRow, currentRow, r, c, currentRowNumber, currentDecided, 0L, n));
    }

    private static long getUnhappiness(boolean[] previousRow, boolean[] currentRow,
                                      int r, int c, int rowNumber, int decided,
                                      long currentUnhappiness, int remainingToLive) {
        if (decided == c) {
            if (rowNumber == (r - 1)) {
                if (remainingToLive == 0) {
                    return currentUnhappiness;
                } else {
                    return Long.MAX_VALUE;
                }
            } else {
                return getUnhappiness(currentRow, new boolean[c], r, c, rowNumber + 1, 0, currentUnhappiness, remainingToLive);
            }
        }

        int remainingPlaces = (c - decided) + (r - rowNumber - 1) * c;
        if (remainingPlaces < remainingToLive) {
            return Long.MAX_VALUE;
        }

        long notLive = getUnhappiness(previousRow, currentRow, r, c, rowNumber, decided + 1, currentUnhappiness, remainingToLive);


        boolean left;
        if (decided == 0) {
            left = false;
        } else {
            left = currentRow[decided - 1];
        }

        currentRow[decided] = true;
        // left live
        if (decided != 0 && currentRow[decided - 1]) {
            // upper and left live both
            if (rowNumber != 0 && previousRow[decided]) {
                currentUnhappiness++;
                currentUnhappiness++;
            } else {
                currentUnhappiness++;
            }
        } else {
            // left not live

            // upper live
            if (rowNumber != 0 && previousRow[decided]) {
                currentUnhappiness++;
            }
        }

        long toLive = getUnhappiness(previousRow, currentRow, r, c, rowNumber, decided + 1, currentUnhappiness, remainingToLive - 1);
        if (decided != 0) {
            currentRow[decided - 1] = left;
        }
        currentRow[decided] = false;

        return Math.min(notLive, toLive);
    }
}
