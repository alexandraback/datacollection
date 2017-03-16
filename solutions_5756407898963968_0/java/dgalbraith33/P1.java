import java.util.Scanner;
import java.util.Arrays;

public class P1 {
    public static Scanner stdin = new Scanner(System.in);

    public static void main(String[] args) {
        int numCases = Integer.parseInt(stdin.nextLine());

        for(int i = 1; i <= numCases; i++) {
            execute(i);
        }
    }

    public static void execute(int runNum) {
        int firstAns = Integer.parseInt(stdin.nextLine());
        int[][] firstGrid = parseGrid();

        int secAns = Integer.parseInt(stdin.nextLine());
        int[][] secGrid = parseGrid();

        int result = compare(firstGrid[firstAns-1], secGrid[secAns-1]);

        System.out.print("Case #"+runNum+": ");
        switch(result) {
        case 0:
            System.out.println("Bad magician!");
            break;
        case -1:
            System.out.println("Volunteer cheated!");
            break;
        default:
            System.out.println(result);
        }
    }

    public static int[][] parseGrid() {
        int[][] grid = new int[4][4];
        for(int i = 0; i < 4; i++) {
            String[] row = stdin.nextLine().split(" ");
            for(int j = 0; j < 4; j++) {
                grid[i][j] = Integer.parseInt(row[j]);
            }
        }
        return grid;
    }

    public static int compare(int[] firstRow, int[] secondRow) {
        int result = -1;
        boolean found = false;

        for(int i = 0; i < firstRow.length; i++) {
            for(int j = 0; j < secondRow.length; j++) {
                if(firstRow[i] == secondRow[j]) {
                    if(found) {
                        return 0;
                    }
                    else {
                        result = firstRow[i];
                        found = true;
                    }
                }
            }
        }

        return result;
    }
}