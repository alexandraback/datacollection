import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;


public class ProblemA {
	String PROBLEM_ID = "problemA";

	enum TestType {
		EXAMPLE, SMALL, LARGE
	}

//	TestType TYPE = TestType.EXAMPLE;
//	 TestType TYPE = TestType.SMALL;
	TestType TYPE = TestType.LARGE;

	public String getFileName() {
		String result = PROBLEM_ID + "_";
		switch (TYPE) {
		case EXAMPLE:
			result += "example";
			break;
		case SMALL:
			result += "small";
			break;
		case LARGE:
			result += "large";
			break;
		}
		return result;
	}

	public String getInFileName() {
		return getFileName() + ".in";
	}

	public String getOutFileName() {
		return getFileName() + ".out";
	}

	public static void main(String[] args) throws Exception {
		new ProblemA();
	}

	public ProblemA() throws Exception {
		BufferedReader in = new BufferedReader(new FileReader(getInFileName()));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(
				getOutFileName())));
		Scanner scan = new Scanner(in);
		int tests = scan.nextInt();
		for (int test = 0; test < tests; test++) {
			int n = scan.nextInt();
			String[] words = new String[n];
			for ( int i = 0; i < n; i++) words[i] = scan.next();
			int[] index = new int[n];
			boolean failed = false;
			int answer = 0;
			while ( index[0] < words[0].length()) {
				char c = words[0].charAt(index[0]);
				int[] count = new int[n];
				int maxCount = 0;
				int minCount = 200;
				for ( int i = 0; i < n; i++) {
					while ( index[i] < words[i].length() && 
							words[i].charAt(index[i]) == c) {
						index[i]++; count[i]++;
					}
					if ( count[i] == 0) failed = true;
					maxCount = Math.max(maxCount, count[i]);
					minCount = Math.min(minCount, count[i]);
				}
				int best = Integer.MAX_VALUE;
				for ( int k = minCount; k <= maxCount; k++) {
					int score = 0;
					for ( int z: count) score += Math.abs(k-z);
					best = Math.min(best, score);
				}
				answer += best;
			}
			for ( int i = 0; i < n; i++) {
				if ( index[i] < words[i].length()) failed = true;
			}
			
			String resultStr = String.format("Case #%d: ", test + 1);
			if ( failed ) resultStr += "Fegla Won";
			else resultStr += answer;
			System.out.println(resultStr);
			out.println(resultStr);
		}
		out.close();
		System.out.println("*** in file =  " + getInFileName());
		System.out.println("*** out file = " + getOutFileName());
	}
}
