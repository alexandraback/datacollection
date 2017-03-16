package qr2014A;

import java.util.*;
import java.io.*;

import static java.lang.System.*;
import static java.lang.Math.*;

public class Main {

//	Scanner sc = new Scanner(in); 
	Scanner sc;
	
	void run() {
		try {
			sc = new Scanner(new File("/Users/ryo/Documents/procon/A-small-attempt0.in"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		int t = sc.nextInt();
		int[][] cards = new int[4][4];
		Set<Integer> set = new HashSet<Integer>();
		for (int z = 1; z <= t; z++) {
			int a1 = sc.nextInt()-1;
			set.clear();
			for (int i = 0; i < 4; i++)
				for (int j = 0; j < 4; j++)
					cards[i][j] = sc.nextInt();
			for (int i = 0; i < 4; i++)
				set.add(cards[a1][i]);
			
			int a2 = sc.nextInt()-1;
			for (int i = 0; i < 4; i++)
				for (int j = 0; j < 4; j++)
					cards[i][j] = sc.nextInt();
			int res = 0, count = 0;
			for (int i = 0; i < 4; i++) {
				if (set.contains(cards[a2][i])) {
					res = cards[a2][i];
					count++;
				}
			}
			
			if (count == 1) {
				out.printf("Case #%d: %d\n", z, res);
			} else if (count > 1) {
				out.printf("Case #%d: Bad magician!\n", z);
			} else {
				out.printf("Case #%d: Volunteer cheated!\n", z);
			}
			
		}
	}
	
	public static void main(String[] args) {
		new Main().run();
	}

}