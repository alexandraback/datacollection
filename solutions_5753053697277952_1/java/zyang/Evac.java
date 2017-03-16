package Senate;

import java.io.File;
import java.io.IOException;
import java.util.Scanner;

public class Evac {
	
	public static int[] party;
	public static int N, sum;

	public static void main(String[] args) throws IOException {

		File input = new File("input.txt");
		Scanner scanner = new Scanner(input);
		
		int T = scanner.nextInt();
		for (int i = 0; i < T; i++) {
			
			N = scanner.nextInt();
			party = new int[N];
			sum = 0;
			
			for (int j = 0; j < N; j++) {

				party[j] = scanner.nextInt();
				sum += party[j];
			}

			System.out.printf("Case #%d: ", i + 1);
			if (N == 2) {
				for (int j = 1; j < party[0]; j++)
					System.out.print("AB ");
				System.out.println("AB");
			}
			else
				calc();
		}
		
		scanner.close();
	}

	public static void calc() {
		
		while (sum > 0) {
			
			int gold, silver, bronze;
			gold = silver = bronze = -1;
			for (int i = 0; i < N; i++)
				if (gold == -1 || party[i] > party[gold]) {
					bronze = silver;
					silver = gold;
					gold = i;
				}
				else if (silver == -1 || party[i] > party[silver]) {
					bronze = silver;
					silver = i;
				}
				else if (bronze == -1 || party[i] > party[bronze])
					bronze = i;
			
			if (max(party[gold] - 1, party[bronze]) > (sum - 2) / 2) {
				
				sum--;
				party[gold]--;
				System.out.print((char) ((int) 'A' + gold));
			}
			else {
				
				sum -= 2;
				party[gold]--;
				party[silver]--;
				System.out.print((char) ((int) 'A' + gold));
				System.out.print((char) ((int) 'A' + silver));
			}
			
			if (sum == 0)
				System.out.println();
			else
				System.out.print(' ');
		}
	}
	
	public static int max(int x, int y) {
		
		return x > y ? x : y;
	}

}
