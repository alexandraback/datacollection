import java.io.BufferedWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Scanner;

public class ProblemA {	

	private static BufferedWriter writer;
	private static Scanner scanner;
	
	private static int n;
	private static int[] m;

	private static int a;
	private static int b;
	
	private static void processCase(int i) throws IOException {
		readInput();
		solve();
		outputResults(i);
	}

	private static void outputResults(int testCase) throws IOException {
		String out = String.format("Case #%d: %d %d", testCase + 1, a, b);
		System.err.println(out);
		writer.write(out);
		writer.newLine();
	}

	private static void solve() {
		solveA();
		solveB();
	}
	
	static void solveA() {
		a = 0;
		for(int i = 1; i < m.length; i++) {
			if (m[i] < m[i-1]) {
				a += (-m[i] + m[i-1]);
			}
		}
	}

	static void solveB() {
		b = 0;
		int minIn10Secs =0;
		for(int i = 0; i < m.length-1;i++){
			int diff = m[i+1] -m[i];
			if (diff < 0)
			minIn10Secs = Math.max(minIn10Secs, -diff);
		}
		
		for(int i = 0; i < m.length -1; i++) {	
				b += Math.min(minIn10Secs, m[i]);
		}	
	}

	private static void readInput() {
		n = scanner.nextInt();
		m = new int[n];
		for(int i = 0; i< n;i++) {
			m[i] = scanner.nextInt(); 
		}
	}

	public static void main(String[] args) throws IOException {
		Path input = Paths.get("input.txt");
		Path output = Paths.get("output.txt");
		scanner = new Scanner(input);
		writer = Files.newBufferedWriter(output);
		int testCases = scanner.nextInt();
		for (int i = 0; i < testCases; i++) {
			processCase(i);
		}
		writer.close();

	}

}
