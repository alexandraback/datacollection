import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;

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
		StringTokenizer dataB = new StringTokenizer(br.readLine(), " ");
		int B = Integer.parseInt(dataB.nextToken());
		int N = Integer.parseInt(dataB.nextToken());
		int[] bs = new int[B];
		int[][] matrix = new int[B+1][300000];
		int diff = Integer.MAX_VALUE;


		StringTokenizer dataM = new StringTokenizer(br.readLine(), " ");
		for (int i=0; i<B; i++) {
			bs[i] = Integer.parseInt(dataM.nextToken());
			matrix[i][0] = bs[i];
			diff = Math.min(diff, bs[i]);
		}

		if (N <= B) {
			System.out.println("Case #" + (num+1) + ": " + N);
			return;
		}

		int x = 1;
		int loop_time = 99;
		while(true) {
			int newdiff = Integer.MAX_VALUE;
			int count = 0;
			for (int i=0; i<B; i++) {
				if (matrix[i][x-1] == 0) {
					matrix[i][x] = matrix[i][0] - diff;
					if (matrix[i][0] == diff) {
						newdiff = Math.min(newdiff, matrix[i][0]);
					} else {
						newdiff = Math.min(newdiff, matrix[i][0] - diff);
					}
				} else {
					matrix[i][x] = matrix[i][x-1] - diff;
					if (matrix[i][x-1] == diff) {
						newdiff = Math.min(newdiff, matrix[i][x-1]);
					} else {
						newdiff = Math.min(newdiff, matrix[i][x-1] - diff);
					}
				}
				if (matrix[i][x] == 0) count++;
			}

			matrix[B][x] = matrix[B][x-1] + count;
			if (count == B) {
				loop_time = matrix[B][x];
				break;
			}
			x++;
			diff = newdiff;
		}

		int chance = (N - B) % loop_time;
		int getRow = 0;
		for (int i=0; i<x+2; i++) {
			if (matrix[B][i] >= chance) {
				getRow = i;
				break;
			}
		}

		if (chance == 0) {
			System.out.println("Case #" + (num+1) + ": " + B);
			return;
		}

		int currentCount = matrix[B][getRow-1];
		for (int i=0; i<B; i++) {
			if(matrix[i][getRow] == 0) {
				currentCount++;
				if(currentCount == chance) {
					System.out.println("Case #" + (num+1) + ": " + (i+1));
					return;
				}
			}
		}

	}
}
