import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Scanner;

public class Problem2 {
	public static void main(String[] args) {
		try {
			Scanner scanner = new Scanner(new FileReader(
					"B-small-attempt1.in"));
			int T = scanner.nextInt();
			int[] R = new int[T];
			int[] C = new int[T];
			int[] N = new int[T];
			for (int i = 0; i < T; i++) {
				R[i] = scanner.nextInt();
				C[i] = scanner.nextInt();
				N[i] = scanner.nextInt();
			}
			PrintWriter out = new PrintWriter(new FileWriter("output2.txt"));
			for (int i = 0; i < T; i++) {
				if (N[i] == R[i] * C[i]) {
					int sum = 0;
					if (R[i] >= 2) {
						sum += (R[i] - 1) * C[i];
					}
					if (C[i] >= 2) {
						sum += (C[i] - 1) * R[i];
					}
					out.println("Case #" + (i + 1) + ": " + sum);
				} else if (N[i] > 1) {
					currentMin = Integer.MAX_VALUE;
					boolean[][] array = new boolean[R[i]][C[i]];
					HashSet<Integer> set = new HashSet<Integer>();
					getHappy(array, 0, 0, N[i]);
					out.println("Case #" + (i + 1) + ": " + currentMin);
				} else {
					out.println("Case #" + (i + 1) + ": " + 0);
				}
			}
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	public static int currentMin = Integer.MAX_VALUE;

	public static void getHappy(boolean[][] array, int current, int pos, int N) {
		if (current > currentMin) {
			return;
		}
		if (N == 0) {
			currentMin = Math.min(currentMin, current);
			return;
		}
		int m = array.length;
		int n = array[0].length;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if(i*m + j < pos) {
					continue;
				}
				if (!array[i][j]) {
					boolean[][] newArray = new boolean[m][n];
					for (int p = 0; p < m; p++) {
						for (int q = 0; q < n; q++) {
							newArray[p][q] = array[p][q];
						}
					}
					newArray[i][j] = true;
					int temp = current;
					if (i > 0 && newArray[i - 1][j]) {
						temp++;
					}
					if (i < m - 1 && newArray[i + 1][j]) {
						temp++;
					}
					if (j > 0 && newArray[i][j - 1]) {
						temp++;
					}
					if (j < n - 1 && newArray[i][j + 1]) {
						temp++;
					}
					getHappy(newArray, temp, i*m+j, N - 1);
				}
			}
		}
	}
}
