import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;

public class CodeJamA {

    public static final String INPUT = "/opt/dev/TopCoder/src/A-small-attempt0.in";
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
            int n = Integer.parseInt(reader.readLine().trim());
            String[] pArr = reader.readLine().split(" ");
            int[] pieces = new int[n];
            for (int j = 0; j < n; j++) {
                pieces[j] = Integer.parseInt(pArr[j]);
            }

            writer.println("Case #" + (i + 1) + ": " + getResult(pieces, n));
        }
    }

    private static String getResult(int[] pieces, int count) {
        String base = Long.toString(getBaseCount(pieces, count));
        String complex = Long.toString(getComplexCount(pieces, count));
        return base + " " + complex;
    }

    private static long getBaseCount(int[] pieces, int count) {
        long res = 0L;
        for (int i = 0; i < (count - 1); i++) {
            int curr = pieces[i];
            int next = pieces[i + 1];
            if (next < curr) {
                res += (curr - next);
            }
        }
        return res;
    }

    private static long getComplexCount(int[] pieces, int count) {
        int speed = getMaxSpeed(pieces, count);
        return getEatenWithSpeed(pieces, count, speed);
    }

    private static int getMaxSpeed(int[] pieces, int count) {
        int maxSpeed = 0;
        for (int i = 0; i < (count - 1); i++) {
            int curr = pieces[i];
            int next = pieces[i + 1];
            if (next < curr) {
                int currSpeed = curr - next;
                if (currSpeed > maxSpeed) {
                    maxSpeed = currSpeed;
                }
            }
        }
        return maxSpeed;
    }

    private static long getEatenWithSpeed(int[] pieces, int count, int speed) {
        long res = 0L;
        for (int i = 0; i < (count - 1); i++) {
            int currPieces = pieces[i];
            res += Math.min(speed, currPieces);
        }
        return res;
    }
}
