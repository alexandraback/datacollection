

import java.io.File;
import java.io.IOException;
import java.io.PrintStream;
import java.util.Scanner;

// Using the Google Guava library.
public class B {

	public static void main(String [] args) throws IOException {
		String inputFile = "src/B-small-0.in";
		Scanner in = new Scanner(new File(inputFile));
		PrintStream out = new PrintStream(inputFile.substring(0, inputFile.length()-2)+"out");
		int cases = in.nextInt();
		for (int cs = 1; cs <= cases; cs++) {
		    int r = in.nextInt();
		    int c = in.nextInt();
		    int n = in.nextInt();
	        int min = Integer.MAX_VALUE;
		    int maxI = 1 << (r*c);
//		    System.out.println(maxI);
            for (int i = 0; i <= maxI; i++) {
		        if (Long.bitCount(i) != n) { continue; }
		        boolean [][] complex = new boolean[r][c];
		        int unh = 0;
		        for (int j = 0; j < r*c; j++) {
		            complex[j/c][j%c] = (i & (1 << j)) > 0;
		        }
		        for (int x = 0; x < r-1; x++) {
		            for (int y = 0; y < c; y++) {
		                if (complex[x][y] && complex[x+1][y]) {
		                    unh++;
		                }
		            }
		        }
                for (int x = 0; x < r; x++) {
                    for (int y = 0; y < c-1; y++) {
                        if (complex[x][y] && complex[x][y+1]) {
                            unh++;
                        }
                    }
                }
                if (unh < min) {
                    min = unh;
                }
//                min = Math.min(min, unh);
		    }
			String ans = "Case #"+cs+": "+min;
			out.println(ans);
			System.out.println(ans);
		}
		out.close();
		in.close();
	}
}
