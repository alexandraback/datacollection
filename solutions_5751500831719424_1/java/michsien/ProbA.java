import java.util.Scanner;


public class ProbA {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int t = scan.nextInt();
		
		for (int i = 1; i <= t; i++) {
			solve(i, scan);
		}
		
		scan.close();

	}
	

	
	public static void solve(int number, Scanner sc) {
		int n = sc.nextInt();
		String[] texts = new String[n];
		for (int i = 0; i < n; i++) {
			texts[i] = sc.next();
		}
		String[] texts2 = new String[n];
		for (int i = 0; i < n; i++) {
			int l = texts[i].length();
			StringBuilder s = new StringBuilder("");
			char last = '0';
			for (int j = 0; j < l; j++) {
				char current = texts[i].charAt(j);
				if (current != last) {
					s.append(current);
					last = current;
				}
			}
			texts2[i] = s.toString();
		}
		
		for (int i = 0; i < n; i++) {
			if (!texts2[i].equals(texts2[0])) {
				System.out.println("Case #" + number + ": Fegla Won");
				return;
			}
				
		}
		
		int[][] numbers = new int[n][101];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 101; j++) {
				numbers[i][j] = 0;
			}
		}
		
		for (int i = 0; i < n; i++) {
			char last = texts[i].charAt(0);
			int index = 0;
			for (int j = 0; j < texts[i].length(); j++) {
				if (texts[i].charAt(j) == last) {
					numbers[i][index]++;
				} else {
					index++;
					numbers[i][index]++;
					last = texts[i].charAt(j);
				}
			}
		}
		
		/*
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 100; j++) {
				int k = numbers[i][j];
				if (k == 0) {
					break;
				} else {
					System.out.print(k);
				}
			}
			System.out.println();
		}
		*/
		
		int result = 0;
		for (int i = 0; numbers[0][i] != 0; i++) {
			int resGroup = Integer.MAX_VALUE;
			for (int j = 1; j <= 100; j++) {
				int goal = j;
				int sum = 0;
				for (int k = 0; k < n; k++) {
					sum += Math.abs(numbers[k][i] - goal);
				}
				resGroup = Math.min(resGroup, sum);
			}
			result += resGroup;
		}
		
		System.out.println("Case #" + number + ": " + result);
		
	}
}