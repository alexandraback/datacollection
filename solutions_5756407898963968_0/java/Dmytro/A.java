import java.io.*;
import java.util.*;


public class A {
	
	static Scanner in;
	static PrintWriter out;

	public static void main(String[] args) throws IOException {
		InputStream input = new FileInputStream(new File("src/A-small-attempt0.in"));
		PrintStream output = new PrintStream(new File("src/A-small-attempt0.out"));
		in = new Scanner(input);
		out = new PrintWriter(output);
		solveMultiTest();
		out.close();
	}
	
	static void solveMultiTest() throws IOException {
		int T = in.nextInt();
		for (int testCase = 1; testCase <= T; testCase++) {
			out.println("Case #" + testCase + ": " + solveOneTest());
		}
	}  
	
	static String solveOneTest() {
		int a1 = in.nextInt();
		HashSet<Integer> q1 = new HashSet<Integer>();
		for (int r = 1; r <= 4; r++) {
			for (int c = 0; c < 4; c++) {
				int tmp = in.nextInt();
				if (r == a1) {
					q1.add(tmp);
				}
			}
		}
		int a2 = in.nextInt();
		HashSet<Integer> q2 = new HashSet<Integer>();
		for (int r = 1; r <= 4; r++) {
			for (int c = 0; c < 4; c++) {
				int tmp = in.nextInt();
				if (r == a2) {
					q2.add(tmp);
				}
			}
		}
		q1.retainAll(q2);
		String answer = null;
		if (q1.size() == 0) answer = "Volunteer cheated!";
		else if  (q1.size() == 1) answer = q1.iterator().next().toString();
		else answer = "Bad magician!";
		return answer;
	}
}
