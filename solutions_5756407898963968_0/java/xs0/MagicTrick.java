import javax.swing.*;
import java.io.*;
import java.util.HashSet;

public class MagicTrick {


    void process() throws IOException {
        int nCases = readInt();
        for (int c = 1; c <= nCases; c++) {
            int row = readInt() - 1;
            int[][] matrix = readIntMatrix(4);

            HashSet<Integer> first = new HashSet<>();
            for (int i : matrix[row])
                first.add(i);

            row = readInt() - 1;
            matrix = readIntMatrix(4);
            HashSet<Integer> second = new HashSet<>();
            for (int i : matrix[row])
                second.add(i);

            first.retainAll(second);

            String res;
            if (first.isEmpty()) {
                res = "Volunteer cheated!";
            } else
            if (first.size() > 1) {
                res = "Bad magician!";
            } else {
                res = first.iterator().next().toString();
            }

            writeln("Case #" + c + ": " + res);
        }

        done();
    }

    public MagicTrick(File inputFile) throws FileNotFoundException {
        this.inputFile = inputFile;
        this.outputFile = new File(inputFile.getParentFile(), inputFile.getName() + ".out");
        this.reader = new LineNumberReader(new FileReader(inputFile));
        this.result = new StringBuilder();
    }

    private StringBuilder result;
    private File inputFile;
    private LineNumberReader reader;
    private File outputFile;

    void done() throws IOException {
        FileOutputStream fos = new FileOutputStream(outputFile);
        fos.write(result.toString().getBytes("UTF-8"));
        fos.close();

        System.out.println(inputFile + " => " + outputFile);
    }

    void writeln(String s) {
        write(s + "\n");
    }

    void write(String s) {
        System.out.print(s);
        result.append(s);
    }

    int readInt() throws IOException {
        return readInts()[0];
    }

    int[][] readIntMatrix(int nLines) throws IOException {
        int[][] res = new int[nLines][];
        for (int a = 0; a < nLines; a++)
            res[a] = readInts();
        return res;
    }

    int[] readInts() throws IOException {
        String l = reader.readLine().trim();
        String[] parts = l.split(" ");
        int[] res = new int[parts.length];
        for (int a = 0; a < res.length; a++)
            res[a] = Integer.parseInt(parts[a]);
        return res;
    }

    public static void main(String[] args) throws Exception {
        JFileChooser jfc = new JFileChooser();
        jfc.setCurrentDirectory(new File("/home/mitja/codejam"));
        if (jfc.showOpenDialog(null) == JFileChooser.APPROVE_OPTION) {
            new MagicTrick(jfc.getSelectedFile()).process();
        }
    }
}
