import java.io.*;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.List;

/**
 * Template to read multiple tasks and solve them
 */
public class Solver {

    private class Task {
        int x;
        int y;
        int filled;
    }

    private class Solution {
        int unhappiness;

        public Solution(int unhappiness) {
            this.unhappiness = unhappiness;
        }

        @Override
        public String toString() {

            return Integer.toString(unhappiness);
        }
    }

    final InputStream in;
    final PrintStream out;

    public Solver(InputStream in, PrintStream out) {
        this.in = in;
        this.out = out;
    }

    /**
     * Read input.
     * First line is number of tasks.
     * Parse tasks and solve them.
     * @throws IOException if reading fails
     */
    public void solveAll() throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(in));
        int cases = Integer.parseInt(reader.readLine());
        for(int i=0;i<cases;i++) {
            Task task = parseTask(reader);
            out.println("Case #" + (i + 1) + ": " + solve(task).toString());
        }
    }

    private Task parseTask(BufferedReader reader) throws IOException {
        Task task = new Task();
        int[] params = parseIntArray(reader.readLine());
        task.x = params[0];
        task.y = params[1];
        task.filled = params[2];
        return task;
    }

    // cells
    byte life[];
    private Task task;

    private Solution solve(Task task) {
        this.task = task;
        int totalCells = task.x * task.y;
        life = new byte[totalCells];
        minUnhappy = Integer.MAX_VALUE;
        solveLevel(task.filled, 0);
        return new Solution(minUnhappy);
    }

    private void solveLevel(int leftToFill, int from) {
        if (leftToFill==0) {
            checkLife();
        } else {
            for(int i=from;i<=(life.length-leftToFill);i++) {
                life[i] = 1;
                solveLevel(leftToFill-1, i+1);
                life[i] = 0;
            }
        }
    }

    int minUnhappy;

    void checkLife() {
//        for(int i=0;i<life.length;i++) {
//            System.out.print(life[i]);
//        }
        int bad = 0;
        // for each column
        int x;
        for(x=0;x<task.x-1;x++) {
            // check column
            int y;
            for(y=0;y<task.y-1;y++) {
                // to the right
                if (life[y*task.x+x]+life[y*task.x+x+1]>1) bad++;
                // to lower
                if (life[y*task.x+x]+life[(y+1)*task.x+x]>1) bad++;
            }
            // last row to right
            if (life[y*task.x+x]+life[y*task.x+x+1]>1) bad++;
        }
        // check last column
        for(int y=0;y<task.y-1;y++) {
            // to lower
            if (life[y*task.x+x]+life[(y+1)*task.x+x]>1) bad++;
        }
//        System.out.println(" bad = " + bad);
        if (bad<minUnhappy) {
            minUnhappy = bad;
        }
    }

    // read descriptors (matrix sizes etc)
    public static int[] parseIntArray(String line) {
        String[] parts = line.trim().split(" +");
        int[] result = new int[parts.length];
        for(int i=0;i<parts.length;i++) {
            result[i] = Integer.parseInt(parts[i]);
        }
        return result;
    }

    public static double[] parseDoubleArray(String line) {
        String[] parts = line.trim().split(" +");
        double [] result = new double[parts.length];
        for(int i=0;i<parts.length;i++) {
            result[i] = Double.parseDouble(parts[i]);
        }
        return result;
    }

    public static BigInteger[] parseBigIntArray(String line) {
        String[] parts = line.trim().split(" +");
        BigInteger [] result = new BigInteger[parts.length];
        for(int i=0;i<parts.length;i++) {
            result[i] = new BigInteger(parts[i]);
        }
        return result;
    }

    // <id> <size> <elements>
    // data: s, i, d, b, c,  - string integer double bigint char
    // size: nnn - number of elements
    //       @nn - backreference to tuple for size
    //       +   - read till the end of line
    // returns: list of arrays. each array corresponds to format specifier
    //          arrays contain specified number of elements and of the format primitive type
    //
    // example:
    //   format:  i s@0 b2 i+   = string array size, array of strings, array of ints till the end of line
    //   data:    2 a b 1 2 3 4 5
    //   result:  List<Object> [0] = Integer(2)
    //                         [1] = String[] {"a", "b"}
    //                         [2] = BigInteger[] {1, 2}
    //                         [3] = int[] {3, 4, 5}
    public static List<Object> parseFormat(String format, String line) {
        String[] parts = line.trim().split(" +");
        String[] types = format.trim().split(" +");
        int partCount = 0;
        List<Object> result = new ArrayList<Object>(types.length);
        for(String type : types) {
            char valueType = type.charAt(0);
            if (type.length()==1) {
                // read single value
                result.add(parseType(valueType, parts[partCount]));
                partCount++;
            } else {
                int size;
                if (type.charAt(1)=='@') {
                    // read array with backref size
                    int ptr = Integer.parseInt(type.substring(2));
                    size = (Integer)result.get(ptr);
                } else if (type.charAt(1)=='+') {
                    // read reminder of arguments
                    size = parts.length - partCount;
                } else {
                    // read array with immediate size
                    size = Integer.parseInt(type.substring(1));
                }
                result.add(parseArray(valueType, size, parts, partCount));
                partCount+=size;
            }
        }
        return result;
    }

    private static Object parseArray(char type, int count, String[] parts, int from) {
        switch (type) {
            case 's':
                String[] resStr = new String[count];
                System.arraycopy(parts, from, resStr, 0, count);
                return resStr;
            case 'i':
                int[] resInt = new int[count];
                for(int i=0;i<count;i++) {
                    resInt[i] = Integer.parseInt(parts[i+from]);
                }
                return resInt;
            case 'd':
                double[] resDouble = new double[count];
                for(int i=0;i<count;i++) {
                    resDouble[i] = Double.parseDouble(parts[i+from]);
                }
                return resDouble;
            case 'b':
                BigInteger[] resBigInt = new BigInteger[count];
                for(int i=0;i<count;i++) {
                    resBigInt[i] = new BigInteger(parts[i+from]);
                }
                return resBigInt;
            default:
                throw new IllegalArgumentException("Unknown type " + type);
        }
    }

    private static Object parseType(char type, String value) {
        switch(type) {
            case 's':
                return value;
            case 'i':
                return Integer.parseInt(value);
            case 'd':
                return Double.parseDouble(value);
            case 'b':
                return new BigInteger(value);
            default:
                throw new IllegalArgumentException("Unknown type " + type);
        }
    }

    public static void main(String[] args) throws IOException {
        InputStream in;
        PrintStream out;
        if (args.length>0) {
            in = new FileInputStream(args[0]);
        } else {
            in = System.in;
        }
        if (args.length>1) {
            out = new PrintStream(new FileOutputStream(args[1]));
        } else {
            out = System.out;
        }
        new Solver(in, out).solveAll();
    }
}
