package gcj2;

import java.io.File;
import java.io.FileInputStream;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;

public class B {
	
	public static HashSet<Integer> hashes = new HashSet<>();

	public static void main(String[] args) throws Exception {
		Scanner s = new Scanner(new FileInputStream(new File("input_b.txt")));
		System.setOut(new PrintStream(new File("output_b.txt")));
		int numCases = s.nextInt();
		for (int ca = 0; ca < numCases; ca++) {
			int r = s.nextInt();
			int c = s.nextInt();
			int n = s.nextInt();
			hashes.clear();
			
			System.out.printf("Case #%d: %d%n", ca+1, compute(r, c, n));
		}
	}
	
	public static int compute(int r, int c, int n) {
		boolean[][] building = new boolean[r][c];
		return compute2(building, n);
	}
	
	public static boolean[][] copy(boolean[][] building) {
		boolean[][] tmp = new boolean[building.length][building[0].length];
		for (int i = 0; i < building.length; i++) {
			tmp[i] = Arrays.copyOf(building[i], building[i].length);
		}
		return tmp;
	}
	
	public static int unhappiness(boolean[][] building) {
		 int r = building.length;
		 int c = building[0].length;

		 int sum = 0;
		 for (int x = 0; x < r; x++) {
			 for (int y = 1; y < c; y++) {
				 if (building[x][y] && building[x][y-1]) {
					 sum++;
				 }
			 }
		 }
		 
		 for (int x = 1; x < r; x++) {
			 for (int y = 0; y < c; y++) {
				 if (building[x][y] && building[x-1][y]) {
					 sum++;
				 }
			 }
		 }
		 return sum;
	}
	
	public static int computehash(boolean[][] building) {
		int hash = 0;
		int count = 0;
		for (int x = 0; x < building.length; x++) {
			for (int y = 0; y < building[0].length; y++) {
				if (building[x][y]) {
					hash |= 1 << count;
				}
				count++;
			}
		}
		return hash;
	}
	
	public static int compute2(boolean[][] building, int n) {
		int hash = computehash(building);
		if (hashes.contains(hash)) {
			return Integer.MAX_VALUE;
		}
		if (n == 0) {
			return unhappiness(building);
		}
		hashes.add(hash);
		
		int min = Integer.MAX_VALUE;
		for (int x = 0; x < building.length; x++) {
			for (int y = 0; y < building[x].length; y++) {
				if (!building[x][y]) {
					boolean[][] next = copy(building);
					next[x][y] = true;
					min = Math.min(min, compute2(next, n-1));
				}
			}
		}
		return min;
	}
}
