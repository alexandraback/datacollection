package Round1B_2015;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

public class B {

	public static int[][][] re;
	public static boolean m[][];
	public static int count(boolean[][] map) {
		int result = 0;
		for(int i = 0; i < map.length ; i++){
			for(int j = 0; j < map[i].length ; j++) {
				if (map[i][j])
				{
					if( i + 1 < map.length && map[i + 1][j])
						result ++;
					if(j + 1 < map[i].length && map[i][j + 1])
						result ++;
				}
			}
			
		}
		return result;
	}
	
	public static int countN() {
		int result = 0;
		for(int i = 0; i < m.length - 1; i++)
			for(int j = 0; j < m[i].length - 1; j++) {
				if (m[i][j])
					result ++;
			}
		return result;
	}
	public static int c(int R, int C, int a, int b, int n) {
		if (n == 0)
			return count(m);
		if (a >= R || b >= C)
			return Integer.MAX_VALUE;
		m[a][b] = false;
		int r1, r2;
		if (b + 1 == C)
			r1 = c(R,C, a + 1, 0, n);
		else
			r1 = c(R, C, a, b + 1, n);
		m[a][b] = true;
		
		if (b + 1 == C)
			r2 = c(R,C, a + 1, 0, n - 1);
		else
			r2 = c(R, C, a, b + 1, n - 1);
		
		return Math.min(r1, r2);
	}
	public static void main(String[] args) {
		File fin = new File("src/Round1B_2015/B_test.in.txt");
		Scanner scan;
		try {
			scan = new Scanner(fin);
		
			PrintWriter output = new PrintWriter("src/Round1B_2015/B_test.out.txt");
			int T = scan.nextInt();
			for(int i = 0; i < T; i++)
			{

				int R = scan.nextInt();
				int C = scan.nextInt();
				int N = scan.nextInt();
				m = new boolean[R][C];
				int result = c(R, C, 0, 0, N);
				output.println("Case #" + (i + 1) + ": " + result);
				System.out.println("Case #" + (i + 1) + ": " + result);
				
			}
			scan.close();
			output.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
