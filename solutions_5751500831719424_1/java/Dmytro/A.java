package A;
import java.util.*;
import java.io.*;


public class A {
	
	
	
	
	void solve() {
		System.out.println("-------------------------------------------------");
		
		int N = in.nextInt();
		String[] s = new String[N];
		for (int i = 0; i < N; i++) {
			s[i] = in.next();
			System.out.println("s[i]=" + s[i] );
		}
		
		String ss = "";
		char prev = 0;
		for (int j = 0; j < s[0].length(); j++) {
			char c = s[0].charAt(j);
			if (c != prev) {
				ss += c;
				prev = c;
			}
		}
		System.out.println("ss=" + ss );
		
		int M = ss.length();
		
		boolean ok = true;
		int[][] a = new int[N][];
		for (int i = 0; i < N; i++) {
			a[i] = new int[M];
			int k = 0;
			for (int j = 0; j < M; j++) {
				char c = ss.charAt(j);
				int cnt = 0;
				while (k < s[i].length() && s[i].charAt(k) == c) {
					cnt ++;
					k ++;
				}
				if (cnt == 0)
					ok = false;
				a[i][j] = cnt;
				System.out.print(a[i][j] + " ");
			}
			if (k < s[i].length())
				ok = false;
			System.out.println();
		}
		
		int res = 0;
		for (int j = 0; j < M; j++) {
			int min = Integer.MAX_VALUE;
			int xxx = 0;
			for (int x = 1; x <= 100; x++) {
				int sum = 0;
				for (int i = 0; i < N; i++) {
					sum += Math.abs(x - a[i][j]);
				}
				if (sum < min) {
					min = sum;
					xxx = x;
				}
			}
			res += min;
		}
		
		if (!ok) {
			out.println("Fegla Won"); 
			out.flush();
		} else {
			out.println(res); 
			out.flush();	
		}
	}
	
	/*************************************************************************/
	
	public static void main(String[] args) throws Exception {
		main1();
	}
	
	public static void main0() {
		String s = "3\r\n" + 
				"aaabbb\r\n" + 
				"ab\r\n" + 
				"aabb"; 
				
		solveProblem0(s);
	}
	
	public static void main1() throws Exception {

		String name = "A-large";
		
		String path = "/Users/dmytro/Workspace/GCJ/";
		String load = path + name + ".in";
		String save = path + name + ".out";
		//load = "1.in";
		//save = "1.out";
		
		solveProblem1(load, save);
	}
	
	/*************************************************************************/

	static void solveAllCases() {
		int T = in.nextInt();
		for (int t = 1; t <= T; t++) {
			out.print("Case #" + t + ": "); 
			out.flush();
			new A().solve();
		}
	}
	
	public static void solveProblem0(String s) {
		in = new Scanner(s);
		out = new PrintWriter(System.out);
		solveAllCases();
		out.flush();
		in.close();
	}
	
	public static void solveProblem1(String load, String save) throws FileNotFoundException {
		//System.out.close();
		in = new Scanner(new File(load));
		out = new PrintWriter(new File(save));
		solveAllCases();
		out.close();
		in.close();
	}

	static Scanner in;
	static PrintWriter out;
}
