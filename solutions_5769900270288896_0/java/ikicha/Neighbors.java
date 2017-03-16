import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Neighbors {

    public static void main(String[] args) {
        try (Scanner sc = new Scanner(new File("input.in"));
                BufferedWriter bw = new BufferedWriter(new FileWriter(new File("output.out")))) {
            int n = sc.nextInt();
            for (int i = 0; i < n; i++) {
                int r = sc.nextInt();
                int c = sc.nextInt();
                String answer = "Case #" + (i + 1) + ": " + solve(Math.min(r, c), Math.max(r, c), sc.nextInt());
                bw.write(answer);
                bw.newLine();
                System.out.println(answer);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static int solve(int r, int c, int n) {
        int[][] matrix = makeFullmatrix(r, c);
        System.out.println(r + " x " + c + " : " + n);
        print(matrix);
        for (int i = 0; i < r * c - n; i++) {
            delete(matrix, r, c);
        }
        return sum(matrix, r, c);
    }

    static int dx[] = { 0, 0, 1, -1 };
    static int dy[] = { 1, -1, 0, 0 };

    private static void delete(int[][] matrix, int r, int c) {
        int max = 0;
        int x = 0;
        int y = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (max < matrix[i][j]) {
                    max = matrix[i][j];
                    x = i;
                    y = j;
                }
            }
        }

        deleteXY(matrix, r, c, x, y);
        print(matrix);
    }

    private static void deleteXY(int[][] matrix, int r, int c, int x, int y) {
        if (matrix[x][y] == 0) {
            return;
        }
        matrix[x][y] = 0;
        for (int i = 0; i < 4; i++) {
            int tempX = x + dx[i];
            int tempY = y + dy[i];
            if (isValid(tempX, tempY, r, c)) {
                if (matrix[tempX][tempY] != 0) {
                    matrix[tempX][tempY]--;
                }
            }
        }
    }

    private static void print(int[][] matrix) {
        System.out.println();
        for (int[] row : matrix) {
            for (int item : row) {
                System.out.print(item + " ");
            }
            System.out.println();
        }
        System.out.println();
    }

    private static boolean isValid(int x, int y, int r, int c) {
        boolean xVaild = x >= 0 && x < r;
        boolean yValid = y >= 0 && y < c;
        return xVaild && yValid;
    }

    private static int sum(int[][] matrix, int r, int c) {
        int sum = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                int item = matrix[i][j];
                sum += item;
                deleteXY(matrix, r, c, i, j);
            }
        }
        return sum;
    }

    private static int[][] makeFullmatrix(int r, int c) {
        int[][] matrix = new int[r][c];
        switch (r) {
        case 1:
            if (c == 1) {
                return matrix;
            }
            for (int i = 0; i < c; i++) {
                matrix[0][i] = i == 0 || i == c - 1 ? 1 : 2;
            }
            break;
        default:
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    if (isCorner(i, j, r, c)) {
                        matrix[i][j] = 2;
                    } else if (isOnLine(i, j, r, c)) {
                        matrix[i][j] = 3;
                    } else {
                        matrix[i][j] = 4;
                    }
                }
            }
        }
        return matrix;
    }

    private static boolean isCorner(int x, int y, int r, int c) {
        boolean xOnCorner = x == 0 || x == r - 1;
        boolean yOnCorner = y == 0 || y == c - 1;
        return xOnCorner && yOnCorner;
    }

    private static boolean isOnLine(int x, int y, int r, int c) {
        boolean xOnCorner = x == 0 || x == r - 1;
        boolean yOnCorner = y == 0 || y == c - 1;
        return xOnCorner ^ yOnCorner;
    }
}
