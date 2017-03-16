package codejam.e2014;

import java.util.Scanner;

public class A {
	
	private static int[] readRow(Scanner scanner) {
		int[] ret = new int[4];
		
		int row = scanner.nextInt()-1;
		for(int i=0; i<4; i++) {
			for(int j=0; j<4; j++) {
				int n = scanner.nextInt();
				if (i == row)
					ret[j] = n;
			}
		}
		return ret;
	}
	
	private static void handleCase(int nr, Scanner scanner) {
		int[] row1 = readRow(scanner);
		int[] row2 = readRow(scanner);
		
		int found = -1;
		for(int i=0; i<row1.length; i++) {
			for(int j=0; j<row1.length; j++) {
				if (row1[i] != row2[j])
					continue;
				if (found != -1) {
					System.out.println("Case #"+nr+": "+"Bad magician!");
					return;
				}
				found = row1[i];
			}
		}
		
		if (found == -1) 
			System.out.println("Case #"+nr+": "+"Volunteer cheated!");
		else
			System.out.println("Case #"+nr+": "+found);
	}

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int cases = scanner.nextInt();
		
		for(int i=0;i<cases; i++)
			handleCase(i+1,scanner);
	}
}
