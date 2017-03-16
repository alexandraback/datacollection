import java.io.File;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class A {
	public static void main (String[] args) throws Exception {
		Scanner sc = new Scanner(new File("A-large.in.txt"));
		PrintWriter writer = new PrintWriter("A-large.out.txt", "UTF-8");
//		Scanner sc = new Scanner(System.in);
		
		int T = sc.nextInt();
		for (int t = 1; t <= T; ++t) {
			int N = sc.nextInt();
			sc.nextLine();
			String[] strings = new String[N];
			for (int n = 0; n < N; ++n) {
				strings[n] = sc.nextLine();
			}
			int ans = solve(strings);
//			System.out.println(
			writer.println(
				"Case #" + t + ": " + (ans == -1 ? "Fegla Won" : ans));
		}
		writer.close();
		
//		System.out.println(solve(new String[]{
//			"mmaw",
//			"maw"	
//		}) == 1);
//		System.out.println(solve(new String[]{
//			"gcj",
//			"cj"
//		}) == -1);
//		System.out.println(solve(new String[]{
//			"aaabbb",
//			"ab",
//			"aabb"
//		}) == 4);
//		System.out.println(solve(new String[]{
//			"abc",
//			"abc"
//		}) == 0);
//		System.out.println(solve(new String[]{
//			"aabc",
//			"abbc",
//			"abcc"
//		}) == 3);
//		System.out.println(solve(new String[]{
//			"aaabbb",
//			"adb",
//			"aabb"
//		}) == -1);
//		System.out.println(solve(new String[]{
//			"aaa",
//			"aaa",
//			"aaa"
//		}) == 0);
	}
	
	private static int solve(String[] strings) {
		int n = strings.length;
		int[] inds = new int[n];
		int result = 0;
		
		while(true) {
			int done = 0;
			char ch = '.';
			int[] cnts = new int[n];
			
			for (int i = 0; i < n; ++i) {
				if (inds[i] >= strings[i].length()) {
					++done;
				} else {
					if (i == 0) {
						ch = strings[0].charAt(inds[0]);
					}
					
					int nextInd = inds[i];
					for (; 
						 nextInd < strings[i].length() && 
						 	strings[i].charAt(nextInd) == ch; 
						++nextInd);
					if (nextInd == inds[i]) {
						return -1;
					} else {
						cnts[i] = nextInd - inds[i];
						inds[i] = nextInd;
					}
				}
				
				if (i == n - 1) {
					if (done == 0) {
						Arrays.sort(cnts);
						int median = cnts[(n - 1) / 2];
						for (int j = 0; j < n; ++j) {
							result += Math.abs(cnts[j] - median);
						}
					} else if (done == n) {
						return result;
					} else {
						return -1;
					}
				}
			}
		}
	}
}
