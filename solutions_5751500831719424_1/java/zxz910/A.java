import java.io.BufferedInputStream;
import java.util.Arrays;
import java.util.Scanner;


public class A {
	public static void main(String[] args) {
		
		//read in input
		Scanner scanner = new Scanner(new BufferedInputStream(System.in));
		int n = scanner.nextInt();
		
		for (int i = 0; i < n; i++) {
			System.out.print("Case #" + (i+1) + ": ");
			
			//read in all strings
			int num = scanner.nextInt();
			String[] orig = new String[num];
			for (int j = 0; j < num; j++) {
				orig[j] = scanner.next();
			}
			//char[] start = new char[];
			int count = 1;
			for (int j = 0; j < orig[0].length() - 1; j++) {
				if (orig[0].charAt(j) != orig[0].charAt(j+1)) {
					count++;
				}
			}
			//System.out.println(count);
			char[] plain = new char[count];
			int f = 1;
			plain[0] = orig[0].charAt(0);
			for (int j = 0; j < orig[0].length() - 1; j++) {
				if (orig[0].charAt(j) != orig[0].charAt(j+1)) {
					plain[f] = orig[0].charAt(j+1);
					f++;
				}
			}
			
			boolean possible = true;
			
			for (int j = 0; j < num; j++) {
				int s = 0;
				if (orig[j].charAt(0) != plain[0]) {
					possible = false;
				}
				for (int k = 0; k < orig[j].length(); k++) {
					if (orig[j].charAt(k) != plain[s]) {
						if (s+1 >= plain.length) {
							possible = false;
						}
						else if (orig[j].charAt(k) != plain[s+1]) {
							possible = false;
						}
						else {
							s++;
						}
					}
				}
				if (s != plain.length - 1) {
					possible = false;
				}
			}
			
			if (!possible) {
				System.out.println("Fegla Won");
			}
			else {
			
			
			//check to find the order of non-repeating letters and make sure it is same on all of them.
			
			//then to calculate distance, find median of each of the letters and calculate the total sum of the difference from each to median.
			int[][] field = new int[count][num];
			
			for (int j = 0; j < num; j++) {
				int s = 0;
				int t = 1;
				for (int k = 1; k < orig[j].length(); k++) {
					if (orig[j].charAt(k-1) != orig[j].charAt(k)) {
						field[s][j] = t;
						s++;
						t = 1;
					} 
					else {
						t++;
					}
				}
				field[s][j] = t;
			}
			
			for (int j = 0; j < count; j++) {
				Arrays.sort(field[j]);
			}
			int in = num/2;
			int sum = 0;
			for (int j = 0; j < num; j++) {
				for (int k = 0; k < count; k++) {
					sum += Math.abs(field[k][j] - field[k][in]);
				}
			}
			
			System.out.println(sum);
			}
		}
	}
}
