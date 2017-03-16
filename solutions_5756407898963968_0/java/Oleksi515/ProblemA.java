import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.InputStreamReader;
import java.util.Scanner;

public class ProblemA {

    static int T = 1;
    final static int WIDTH = 4;

    public static void main(String args[]) throws Exception {
        Scanner scanner = new Scanner(new InputStreamReader(System.in));
        scanner = new Scanner(new FileReader("ProblemA.txt"));
        FileWriter fileWriter = new FileWriter("ProblemA.out");
        BufferedWriter bw = new BufferedWriter(fileWriter);

        T = scanner.nextInt();
        for (int testNumber = 1; testNumber <= T; ++testNumber) {
            int[] data1 = getRow(scanner);
            int[] data2 = getRow(scanner);

            String answer = "";
            int duplicateCount = 0;
            for (int i = 0; i < WIDTH; ++i) {
                for (int j = 0; j < WIDTH; ++j) {
                    if (data1[i] == data2[j]) {
                        ++duplicateCount;
                        answer = String.valueOf(data1[i]);
                    }
                }
            }
            if (duplicateCount == 0) {
                answer = "Volunteer cheated!";
            } else if (duplicateCount > 1) {
                answer = "Bad magician!";
            }
            bw.write("Case #" + testNumber + ": " + answer);
            bw.newLine();
            //System.out.println("Case #" + testNumber + ": " + answer);
        }
        bw.close();
    }

    private static int[] getRow(Scanner scanner) {
        int[] data = new int[WIDTH];
        int rowId = scanner.nextInt();
        scanner.nextLine();
        for (int i = 0; i < WIDTH; ++i) {
            if (i == rowId - 1) {
                for (int j = 0; j < WIDTH; ++j) {
                    data[j] = scanner.nextInt();
                }
                scanner.nextLine();
            } else {
                scanner.nextLine();
            }
        }
        return data;
    }
}