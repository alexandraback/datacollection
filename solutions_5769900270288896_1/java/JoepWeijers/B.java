import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Locale;
import java.util.Scanner;

public class B {
	public static void main(String[] args) throws FileNotFoundException {
		Locale.setDefault(Locale.US);
//		try (Scanner scanner = new Scanner(new File("b_example.in"))) {
//		try (Scanner scanner = new Scanner(new File("b_small1.in"))) {
		try (Scanner scanner = new Scanner(new File("b_large.in"))) {
			int numberOfCases = scanner.nextInt();
			for (int i = 1; i <= numberOfCases; i++) {
				System.out.println("Case #" + i + ": " + solve(scanner));
			}
		}
	}
	
	private static int solve(Scanner scanner) {
		int R = scanner.nextInt();
		int C = scanner.nextInt();
		int N = scanner.nextInt();
		
		int[][] walls = new int[R][C];
		for (int[] wallRow : walls) {
			Arrays.fill(wallRow, 4);
		}
		for (int i = 0; i < R; i++) {
			walls[i][0] = 3;
			walls[i][C - 1] = 3;
		}
		for (int i = 0; i < C; i++) {
			walls[0][i] = 3;
			walls[R - 1][i] = 3;
		}
		
		walls[0][0] = 2;
		walls[R - 1][0] = 2;
		walls[0][C - 1] = 2;
		walls[R - 1][C - 1] = 2;
		
		if (R == 1 || C == 1) {
			for (int i = 0; i < R; i++) {
				for (int j = 0; j < C; j++) {
					walls[i][j] = walls[i][j] - 1;
				}
			}
		}
		
//		printWalls(walls);
		
		if (N <= Math.ceil(R * C / 2.0)) {
			return 0;
		}
		if (N == R * C) {
			return 2 * R * C - R - C;
		}
		
		int[][] walls2 = new int[R][C];
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				walls2[i][j] = walls[i][j];
			}
		}
		for (int i = (R * C) - N; i > 0; i--) {
			removeHighestWall(walls);
//			printWalls(walls);
		}
		
//		System.out.println("-----------");
		for (int i = (R * C) - N; i > 0; i--) {
			removeHighestWallButNotOnDiagonals(walls2);
//			printWalls(walls2);
		}
		
		return Math.min(countUnhappiness(walls), countUnhappiness(walls2));
	}
	
	private static void removeHighestWallButNotOnDiagonals(int[][] walls) {
		int x = 0;
		int y = 0;
		int max = 0;
		int R = walls.length;
		int C = walls[0].length;
		for (int i = 0; i < R; i++) {
			for (int j = (i + 1) % 2; j < C; j = j + 2) {
				if (walls[i][j] > max) {
					x = i;
					y = j;
					max = walls[i][j];
				}
			}
		}
		removeWalls(walls, x, y, R, C);
	}
	
	private static void removeHighestWall(int[][] walls) {
		int x = 0;
		int y = 0;
		int max = 0;
		int R = walls.length;
		int C = walls[0].length;
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (walls[i][j] > max) {
					x = i;
					y = j;
					max = walls[i][j];
				}
			}
		}
		removeWalls(walls, x, y, R, C);
	}
	
	private static void removeWalls(int[][] walls, int x, int y, int R, int C) {
		walls[x][y] = 0;
		if (x - 1 >= 0 && walls[x - 1][y] > 0) {
			walls[x - 1][y] = walls[x - 1][y] - 1;
		}
		if (x + 1 < R && walls[x + 1][y] > 0) {
			walls[x + 1][y] = walls[x + 1][y] - 1;
		}
		if (y - 1 >= 0 && walls[x][y - 1] > 0) {
			walls[x][y - 1] = walls[x][y - 1] - 1;
		}
		if (y + 1 < C && walls[x][y + 1] > 0) {
			walls[x][y + 1] = walls[x][y + 1] - 1;
		}
	}
	
	private static void printWalls(int[][] walls) {
		for (int[] row : walls) {
			for (int col : row) {
				System.out.print(col);
			}
			System.out.println();
		}
		System.out.println();
	}
	
	private static int countUnhappiness(int[][] walls) {
		int unhappiness = 0;
		int R = walls.length;
		int C = walls[0].length;
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (walls[i][j] > 0) {
					if (i + 1 < R && walls[i + 1][j] > 0) {
						unhappiness++;
					}
					if (j + 1 < C && walls[i][j + 1] > 0) {
						unhappiness++;
					}
				}
			}
		}
		return unhappiness;
	}
}