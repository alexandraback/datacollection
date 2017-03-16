import java.io.*;
import java.math.*;
import java.util.*;
import java.text.*;
import java.util.regex.*;

import static java.lang.Math.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;
import static java.lang.Integer.*;
import static java.lang.Double.*;
import static java.lang.Character.*;


public class B {
	
	static final int[] dx = new int[] {-1, 1, 0, 0}, dy = new int[] {0, 0, -1, 1};

	
	int R, C;
	
	void build(int k, boolean[][] m) {
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				m[i][j] = ((k&1) == 1);
				k /= 2;
			}
		}
	}
	
	int score(boolean[][] m) {
		int cnt = 0;
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (m[i][j]) {
					if (i < R-1 && m[i+1][j])
						cnt++;
					if (j < C-1 && m[i][j+1])
						cnt++;
				}
			}
		}
		return cnt;
	}

	
	Object solve() {
		R = sc.nextInt();
		C = sc.nextInt();
		int N = sc.nextInt();
		
		boolean[][] m = new boolean[R][C];

		int min = Integer.MAX_VALUE;
		
		int K = R*C;
		for (int bm = 0; bm < (1<<K); bm++) {
			if (Integer.bitCount(bm) == N) {
				build(bm, m);
//				System.out.println(Arrays.deepToString(m) + " " + score(m));
				min = min(min, score(m));
			}
		}
		
		return min;
	}

	private static Scanner sc; private static PrintWriter fw;

	public static void main(String[] args) throws Exception {
		String inFile = "input.txt", outFile = "output.txt";
//		inFile = "A-small-attempt0.in";
//		inFile = "A-large.in";
		if (args.length == 0) {
			sc = new Scanner(System.in);
	//		sc = new Scanner(new FileInputStream(inFile));
		} else {
			inFile = args[0];
			sc = new Scanner(new FileInputStream(inFile));
			if (args.length > 1)
				outFile = args[1];
			else if (inFile.endsWith(".in"))
				outFile = inFile.substring(0, inFile.length() - 2) + "out";
			System.out.println(inFile + " -> " + outFile);
		}
		
		fw = new PrintWriter(new FileWriter(outFile, false)) {
			public PrintWriter printf(String format, Object... args) {
				System.out.printf(format, args);
				return super.printf(format, args);
			}
		};
		
		int N = sc.nextInt();
		sc.nextLine();
		System.out.println(N + " cases.");
		
		int progress = 0, progress1;
		for (int cas = 1; cas <= N; cas++) {
			fw.printf("Case #" + cas + ": ");
//			fw.println("Case #" + cas + ": ");
			Object res = new B().solve();
			if (res instanceof Double) 
				fw.printf("%.10f\n", res);
			else
				fw.printf("%s\n", res);
			fw.flush();
			if ((progress1 = cas*10/N) > progress) { System.out.println("*" + progress1*10 + "% "); progress = progress1; };
		}
//		System.out.println(" done ");
		fw.close();
		sc.close();
	}
}
