import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;
import java.util.Stack;


public class start {

	private static int minHappiness;

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(new File("B-small-attempt0.in"));
		FileWriter fw = new FileWriter(new File("output.txt"));
		int numTestCases = sc.nextInt();
		for (int testCaseNum = 0; testCaseNum < numTestCases; testCaseNum++) {

			minHappiness = Integer.MAX_VALUE;
			
			// Parse test case
			int r = sc.nextInt();
			int c = sc.nextInt();
			int n = sc.nextInt();
			
			boolean[][] arr = new boolean[r][c];
			
			recurse(arr, 0, 0, 0, n);
			
			System.out.printf("Case #%d: %d%n", testCaseNum+1, minHappiness);
			fw.write(String.format("Case #%d: %d%n", testCaseNum+1, minHappiness));
		}
		
		fw.close();

	}

	private static void recurse(boolean[][] arr, int i, int j, int tenantsPlaced, int tenantsTarget) {
		
		if (tenantsPlaced == tenantsTarget) {
			int unhappyCount = 0;
			for (int a = 0; a < arr.length; a++) {
				for (int b = 0; b < arr[0].length; b++) {
					if (b < arr[0].length - 1 && arr[a][b] && arr[a][b+1]){
						unhappyCount++;
					}
					if (a < arr.length-1 && arr[a][b] && arr[a+1][b]){
						unhappyCount++;
					}
				}
			}
			
			if (minHappiness > unhappyCount) {
				minHappiness = unhappyCount;
				
				/*for (int a = 0; a < arr.length; a++) {
					for (int b = 0; b < arr[0].length; b++) {
						if (arr[a][b]) {
							System.out.print("x");
						}else{
							System.out.print(" ");
						}
					}
					System.out.println();
				}*/
			}
			
			return;
		}
		
		if (i >= arr.length) {
			return;
		}
		
		int newj = j+1;
		int newi = i;
		if (newj >= arr[0].length){
			newj = 0;
			newi++;
		}
		
		arr[i][j] = true;
		recurse(arr, newi, newj, tenantsPlaced+1, tenantsTarget);
		
		arr[i][j] = false;
		recurse(arr, newi, newj, tenantsPlaced, tenantsTarget);
	}

}
