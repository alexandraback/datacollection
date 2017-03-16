package gcj2015.b1;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Arrays;
import java.util.Date;
import java.util.Scanner;

public class b1 {
	public static void main(String[] args) {
//		readAndSolve("resource/gcj2015/b1/b1/sample.in", "resource/gcj2015/b1/b1/sample.out");
//		readAndSolve("resource/gcj2015/b1/b1/samplelarge.in", "resource/gcj2015/b1/b1/samplelarge.out");
//		readAndSolve("resource/gcj2015/b1/b1/B-small-attempt0.in", "resource/gcj2015/b1/b1/B-small-attempt0.out");
//		readAndSolve("resource/gcj2015/b1/b1/B-small-attempt1.in", "resource/gcj2015/b1/b1/B-small-attempt1.out");
		readAndSolve("resource/gcj2015/b1/b1/B-small-attempt2.in", "resource/gcj2015/b1/b1/B-small-attempt2.out");
//		readAndSolve("resource/gcj2015/b1/b1/B-large.in", "resource/gcj2015/qr/b1/B-large.out");
	}

	/**
	 * @param inputName
	 * @param outputName
	 */
	private static void readAndSolve(String inputName, String outputName) {
		BufferedReader input = null;
		BufferedWriter output = null;
		Date d1 = new Date();
		try {
			input = new BufferedReader(new FileReader(inputName));
			output = new BufferedWriter(new FileWriter(outputName));
			String line1 = null;
			int expectedCases = 0;
			int actualCase = -1;
			line1=input.readLine();
			expectedCases = Integer.parseInt(line1);
			for (actualCase = 1; actualCase<=expectedCases; actualCase++) {
				line1=input.readLine();
				String result = solve(line1);
				output.write("Case #" + actualCase +": " + result + "\n");				
//				System.out.println("Case #" + actualCase +": " + result );				
			}
			input.close();
			output.close();
		} catch (Exception e) {
			e.printStackTrace();
		} finally {
			
		}
		Date d2 = new Date();
System.out.println(d1);
System.out.println(d2);
	}

	private static String solve(String line1) {
		Scanner sc = new Scanner(line1);
		int r = sc.nextInt();
		int c = sc.nextInt();
		int n = sc.nextInt();
//		System.out.println("r: " + r +", c: "+c + ", n: "+n);
		int maxI = (r/2)*(c/2) + ((r+1)/2) * ((c+1) /2);
//		System.out.println( "maxI: " + maxI);
		if (maxI >= n) {
			return "0";
		}
		maxI = (r-1)*c + (c-1)*r;
		if ((r*c) <=n) {
			
			return Integer.toString(maxI);
		}
		int unhappy = Math.min( newsol(r, c, n), oldSolution(r, c, n, maxI));
		
		return Integer.toString(unhappy);
	}

	private static int newsol(int r, int c, int n) {
		int unhappy = 0;
		int[][] rc = new int[r][];
		for (int i = 0; i< r; i++) {
			rc[i] = new int[c];
			for (int j = 0; j<c; j++) {
				rc[i][j] = 0;
			}
		}
		int actMax = 0;
		for (int i =1; i<=n; i++) {
			actMax = put(rc, actMax);
//			System.out.println(actMax);
			unhappy +=actMax;
		}
		return unhappy;
	}

	private static int put(int[][] rc, int actMax) {
		for (int i = actMax; i<=4; i++) {
			if (tryput(rc, i)) {
				return i;
			}
		}
		return 4;
	}

	private static boolean tryput(int[][] rc, int nb) {
		for (int i = 0; i<rc.length; i++) {
			for (int j = 0; j<rc[i].length; j++ ){
				if (rc[i][j] == 0) {
					int n = (i>0? rc[i-1][j] : 0) + (i<rc.length-1 ? rc[i+1][j]:0) +
							(j>0? rc[i][j-1] : 0) + (j<rc[i].length-1 ? rc[i][j+1]:0);
					if (n == nb) {
						rc[i][j] = 1;
						return true;
					}
				}
			}
		}
		return false;
	}

	private static int oldSolution(int r, int c, int n, int maxI) {
		int[][] rc = new int[r][];
		for (int i = 0; i< r; i++) {
			rc[i] = new int[c];
			for (int j = 0; j<c; j++) {
				if (i == 0 || i == r-1 ) {
					if (j == 0 || j == c-1) {
						rc[i][j] = 2;
					} else {
						rc[i][j] = 3;
					}
				} else {
					if (j == 0 || j == c-1) {
						rc[i][j] = 3;
					} else {
						rc[i][j] = 4;
					}					
				}
				if (c == 1) {
					rc[i][j]--;
				}
				if (r == 1) {
					rc[i][j]--;
				}
			}
		}
		int f = 2 + (c>1 ? 1 : 0) + (r>1 ? 1 : 0);
		for (int i = r*c; i>n; i--) {
//			System.out.println("now: " + i);
			boolean found = false;
			int  rf = f;
			while (! found && rf > 0) {
				found = find (rc, rf);
				rf --;
			}
			f = rf +1;
//			System.out.println(" discount: " + f);
			maxI -= f;			
		}
		return maxI;
	}

	private static boolean find(int[][] rc, int rf) {
		for (int i = 0; i< rc.length; i++) {
			for (int j = 0; j< rc[i].length; j++) {
				if (rc[i][j] == rf) {
					rc[i][j] = 0;
					if (i>0) {
						rc[i-1][j]--;
					}
					if (i<rc.length-1) {
						rc[i+1][j]--;
					}
					if (j>0) {
						rc[i][j-1]--;
					}
					if (j<rc[i].length-1) {
						rc[i][j+1]--;
					}
					return true;
				}
			}
		}
		
		return false;
	}

	
}
