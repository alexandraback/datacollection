package googleContest.Jam2015;

import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStream;
import java.io.PrintStream;
import java.util.Scanner;

public class MagicTrick {

    public static void main(String[] args) throws FileNotFoundException {
        System.setOut(new PrintStream(args[0]+".out"));
        new MagicTrick().solve(args);
    }
    /**
     * read the selected row of data
     * @param firstRow
     * @param row
     * @param scanner
     */
    private void readSelectedRow(int[] rowData, int row, Scanner scanner) {
        for (int i=1;i<=4;i++) {
            if (i!=row) {
                for (int j=0;j<4;j++)
                    scanner.nextInt();
            }

            else {
                for (int j=0;j<4;j++)
                    rowData[j]=scanner.nextInt();
            }
        }
    }

    /**
     * solve the given riddle
     * first read the amount of riddles in the data, then solve each of it
     * @param scanner to read the input data from
     */
    public void solve(Scanner scanner) {
        int numCases = scanner.nextInt();
        for (int i = 1; i <= numCases; i++) {
            System.out.print("Case #" + i + ": ");
            solveCase(scanner);
        }
    }

    /**
     * solve the given riddle
     * if the args array is not empty, get the input data file from the first value
     * otherwise read the input data from the stdin
     * @param args
     */
    public void solve(String[] args) throws FileNotFoundException {
        InputStream is;
        if (args.length > 0)
            is = new BufferedInputStream(new FileInputStream(args[0]));
        else
            is = System.in;
        Scanner scanner = new Scanner(is);
        solve(scanner);
    }

    /**
     * solve a given case of the underlying riddle
     * @param scanner to get the input data from
     */
    public void solveCase(Scanner scanner) {
        int row = scanner.nextInt();
        int[] firstRow = new int[4];
        readSelectedRow(firstRow,row,scanner);
        row = scanner.nextInt();
        int[] secondRow = new int[4];
        readSelectedRow(secondRow,row,scanner);
        int count=0;
        int guess=0;
        for (int num : secondRow) {
            for (int j=0;j<4;j++) {
                if (num==firstRow[j]) {
                    count++;
                    guess=firstRow[j];
                    break;
                }
            }
        }
        if (count==1)
            System.out.println(guess);
        else if (count==0)
            System.out.println("Volunteer cheated!");
        else
            System.out.println("Bad magician!");
    }
}
