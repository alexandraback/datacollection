package carol.r1B15;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class B {

	static final String TYPE = "B";
	static String inputFile;
	static String outputFile;

	
	static int a[][];
	
	private static void Name(String s) {
		inputFile = s + ".in";
		outputFile = s + ".out";
	}

	public static void main(String[] args) throws FileNotFoundException {

		String root = "data/R1B2015";

		// Test
//		Name(TYPE + "-large");
//		Name(TYPE + "-test");
		Name("B-small-attempt0");

		Scanner in = new Scanner(new File(root, inputFile));
		PrintWriter out = new PrintWriter(new File(root, outputFile));

		int T = in.nextInt();

		for (int i = 0; i < T; i++) {
			
			int R = in.nextInt();
			int C = in.nextInt();
			int N = in.nextInt();
			out.println("Case #" + (i + 1) + ": " + calculate(R, C, N));

		}

		in.close();
		out.close();

	}
	public static int calculate(int x, int y, int cnt, int z){
		int ans[] = new int[5];
		ans[0] = ans[1] = ans[2] = ans[3] = ans[4] = 0;
		for (int i = 0; i < x; ++i)
			for (int j = 0; j < y; ++j){
				if ((j + i) % 2 == z) continue;
				int c = 0;
				if (i != 0) ++c;
				if (i != x - 1) ++c;
				if (j != 0) ++c;
				if (j != y - 1) ++c;
				++ans[c];
			}
		ans[0] = x * y - ans[1] - ans[2] - ans[3] - ans[4];
		//System.out.println(z + " "  + " " + ans[0] + " " + ans[1] + " " + ans[2] + " " + ans[3] + " " + ans[4]);
		int ret = 0;
		for (int i = 0; i <  5; ++i){
			if (ans[i] >= cnt) return ret + cnt * i;
			ret += ans[i] * i;
			cnt -= ans[i];
		}
		return ret;
	}
	public static int calculate(int x, int y, int cnt){
		a = new int[x][y];
		int ans = calculate(x, y, cnt, 0);
		ans = Math.min(ans, calculate(x, y, cnt, 1));
		//ans = Math.min(ans, calculate(x, y, cnt, 0, 1));
		//ans = Math.min(ans, calculate(x, y, cnt, 1, 1));
		return ans;
	}

}