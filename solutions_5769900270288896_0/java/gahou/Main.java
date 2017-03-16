import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;
import java.util.StringTokenizer;
import java.util.Arrays;

class Main
{
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static Scanner sc = new Scanner(new InputStreamReader(System.in));

	public static void main (String[] args) throws java.lang.Exception {
		int T = Integer.parseInt(br.readLine());
		for (int i=0; i<T; i++){
			solve(i);
		}
	}


	public static void solve(int num) throws IOException{
		StringTokenizer data = new StringTokenizer(br.readLine());
		int R = Integer.parseInt(data.nextToken());
		int C = Integer.parseInt(data.nextToken());
		int N = Integer.parseInt(data.nextToken());
		int[][] matrix = new int[R][C];
		for (int i=0; i<R; i++) {
			for (int j=0; j<C; j++) {
				matrix[i][j] = 0;
			}
		}

		System.out.println("Case #" + (num+1) + ": " + unhappy(matrix, N, R, C, 0, 0, 0));
	}

	public static int unhappy(int[][] matrix, int N, int R, int C, int current, int X, int Y) {
		if (current == N) return countUnhappiness(matrix, R, C);
		if (N == 0) return 0;
		int[][] fillMatrix = new int[R][C];
		int[][] unfillMatrix = new int[R][C];
		int nextX = X, nextY = Y;
		for(int i=0; i<R; i++) {
			fillMatrix[i] = Arrays.copyOf(matrix[i], C);
			unfillMatrix[i] = Arrays.copyOf(matrix[i], C);
		}
		fillMatrix[X][Y] = 1;

		if (X == R-1 && Y == C-1) {
			if (current < N-1) return Integer.MAX_VALUE;
			else return countUnhappiness(fillMatrix, R, C);
		}
		if (Y == C-1) {
			nextX++;
			nextY = 0;
		} else {
			nextY++;
		}
		return Math.min(unhappy(fillMatrix, N, R, C, current+1, nextX, nextY), unhappy(unfillMatrix, N, R, C, current, nextX, nextY));
	}

	public static int countUnhappiness(int[][] matrix, int R, int C) {
		int counter = 0;
		for (int i=0; i<R ; i++) {
			for (int j=0; j<C; j++) {
				if (matrix[i][j] == 0) continue;
				// up
				if (i != 0) {
					if (matrix[i-1][j] == 1) counter++;
				}
				// down
				if (i != R-1) {
					if (matrix[i+1][j] == 1) counter++;
				}
				// left
				if (j != 0) {
					if (matrix[i][j-1] == 1) counter++;
				}
				// right
				if (j != C-1) {
					if (matrix[i][j+1] == 1) counter++;
				}
			}
		}
		return counter/2;
	}
}
