package Quali;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.HashSet;
import java.util.Locale;
import java.util.Scanner;


public class ProblemA {
	
	public static void solve(Scanner sc) {
		int answer1 = sc.nextInt() - 1;
		int[][] cards1 = new int[4][4];
		for (int i = 0; i < cards1.length; i++) {
			for (int j = 0; j < cards1[i].length; j++) {
				cards1[i][j] = sc.nextInt();
			}
		}

		int answer2 = sc.nextInt() - 1;
		int[][] cards2 = new int[4][4];
		for (int i = 0; i < cards2.length; i++) {
			for (int j = 0; j < cards2[i].length; j++) {
				cards2[i][j] = sc.nextInt();
			}
		}
		HashSet<Integer> temp = new HashSet<Integer>();
		for (int i = 0; i < cards1.length; i++) {
			temp.add(cards1[answer1][i]);
		}

		HashSet<Integer> sol = new HashSet<Integer>();
		for (int i = 0; i < cards2.length; i++) {
			if (temp.contains(cards2[answer2][i])) {
				sol.add(cards2[answer2][i]);
			}
		}
		if (sol.size() == 0) {
			System.out.println("Volunteer cheated!");
		}
		if (sol.size() > 1) {
			System.out.println("Bad magician!");
		}
		if (sol.size() == 1) {
			System.out.println(sol.toArray()[0]);
		}
	}
	
	
	
	
	public static void main(String[] args) throws FileNotFoundException {
//		 Scanner sc = new Scanner(new File("A-practice.in"));
		 Scanner sc = new Scanner(new File("A-small-attempt0.in"));
//		Scanner sc = new Scanner(new File("A-large.in"));
		sc.useLocale(Locale.US);
		int cases = sc.nextInt();

		for (int i = 1; i <= cases; i++) {
			System.out.format(Locale.US, "Case #%d: ", i);
			solve(sc);
		}
		sc.close();
	}
}
