package gcj2015.round1a;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class B {
	public static void main(String args[]) throws FileNotFoundException {
		Scanner scanner = new Scanner(new File(args[0]));
		
		int T = scanner.nextInt();
		for(int t=1; t<=T; t++) {
			int R = scanner.nextInt();
			int C = scanner.nextInt();
			int N = scanner.nextInt();
			
			System.out.println("Case #" + t + ": " + solve(R, C, N));
		}
		
		scanner.close();
	}
	
	static int solve(int r, int c, int n) {
		if(n == r*c) {
			// Full
			return (c-1)*r + (r-1)*c;
		}
		
		boolean apps[][] = new boolean[r][c];
		for(int i=0; i < apps.length; i++) {
			for(int j=0; j < apps[i].length; j++) {
				apps[i][j] = true;
			}
		}
		
		int remain = r*c-n;
		
		for(int i=0; i < apps.length; i++) {
			for(int j=0; j < apps[i].length; j++) {
				if(apps[i][j] == true) {
					int h = unhappiness(apps, i, j);
					if(h >= 4) {
						apps[i][j] = false;
						remain--;
						if(remain == 0) {
							return unhappiness(apps);
						}
					}
				}
			}
		}
		
		for(int i=0; i < apps.length; i++) {
			for(int j=0; j < apps[i].length; j++) {
				if(apps[i][j] == true) {
					int h = unhappiness(apps, i, j);
					if(h >= 3) {
						apps[i][j] = false;
						remain--;
						if(remain == 0) {
							return unhappiness(apps);
						}
					}
				}
			}
		}
		
		for(int i=0; i < apps.length; i++) {
			for(int j=0; j < apps[i].length; j++) {
				if(apps[i][j] == true) {
					int h = unhappiness(apps, i, j);
					if(h >= 2) {
						apps[i][j] = false;
						remain--;
						if(remain == 0) {
							return unhappiness(apps);
						}
					}
				}
			}
		}
		
		for(int i=0; i < apps.length; i++) {
			for(int j=0; j < apps[i].length; j++) {
				if(apps[i][j] == true) {
					int h = unhappiness(apps, i, j);
					if(h >= 1) {
						apps[i][j] = false;
						remain--;
						if(remain == 0) {
							return unhappiness(apps);
						}
					}
				}
			}
		}
		
		for(int i=0; i < apps.length; i++) {
			for(int j=0; j < apps[i].length; j++) {
				if(apps[i][j] == true) {
					apps[i][j] = false;
					remain--;
					if(remain == 0) {
						return unhappiness(apps);
					}
				}
			}
		}
		
		return 99999999;
	}

	private static int unhappiness(boolean[][] apps, int i, int j) {
		int result = 0;
		
		if(i>0 && apps[i-1][j]) result++;
		if(i<apps.length-1 && apps[i+1][j]) result++;
		if(j>0 && apps[i][j-1]) result++;
		if(j<apps[i].length-1 && apps[i][j+1]) result++;
		
		return result;
	}

	static int solve1(int r, int c, int n) {
		if(n == r*c) {
			// Full
			return (c-1)*r + (r-1)*c;
		}
		
		boolean apps[][] = new boolean[r][c];
		return solve1(apps, 0, 0, n);
	}
	
	static int solve1(boolean apps[][], int i, int j, int remain) {
		if(remain == 0) {
			return unhappiness(apps);
		}
		
		if(j >= apps[i].length) {
			i++;
			j = 0;
			
			if(i >= apps.length) {
				return 999999999;
			}
		}
		
		int result = solve1(apps, i, j+1, remain);
		
		apps[i][j] = true;
		result = Math.min(result, solve1(apps, i, j+1, remain-1));
		apps[i][j] = false;
		
		return result;
	}

	static int unhappiness(boolean[][] apps) {
		int result = 0;
		for(int i=0; i < apps.length; i++) {
			for(int j=1; j < apps[i].length; j++) {
				if(apps[i][j-1] && apps[i][j]) {
					result++;
				}
			}
		}
		for(int j=0; j < apps[0].length; j++) {
			for(int i=1; i < apps.length; i++) {
				if(apps[i-1][j] && apps[i][j]) {
					result++;
				}
			}
		}
		return result;
	}
}
