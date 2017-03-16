import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.PrintStream;
import java.util.Scanner;

public class TheRepeater {

	public static void main(String[] args) {
		try {
			Scanner in = new Scanner(new BufferedReader(new FileReader(new File("A-small-attempt1.in")), 256 << 10));
			PrintStream out = new PrintStream(new File("output.txt"));

			int testsNumber = in.nextInt();
			test:
			for (int testId = 1; testId <= testsNumber; testId++) {
				int n = in.nextInt();
				String s = in.next();
				String sample = "" + s.charAt(0);
				for (int j = 1; j < s.length(); j++)
					if (s.charAt(j) != s.charAt(j-1))
						sample += s.charAt(j);
				int[][] counts = new int[n][sample.length()];
				for (int j = 0, si = 0; j < sample.length(); j++) {
					while(si < s.length() && s.charAt(si) == sample.charAt(j)) {
						counts[0][j]++;
						si++;
					}
				}
				for (int i = 1; i < n; i++) {
					s = in.next();
					int si = 0;
					for (int j = 0; j < sample.length(); j++) {
						if (si >= s.length() || s.charAt(si) != sample.charAt(j)) {
							out.append("Case #" + testId + ": " + "Fegla Won" + "\n");
							continue test;
						}
						while(si < s.length() && s.charAt(si) == sample.charAt(j)) {
							counts[i][j]++;
							si++;
						}
					}
					if (si < s.length()) {
						out.append("Case #" + testId + ": " + "Fegla Won" + "\n");
						continue test;
					}
				}
				int total = 0;
				for (int j = 0; j < sample.length(); j++) {
					int minSum = Integer.MAX_VALUE;
					for (int c = 1; c <= 100; c++) {
						int sum = 0;
						for (int i = 0; i < n; i++) {
							sum += Math.abs(c - counts[i][j]);
						}
						if (minSum > sum) minSum = sum;
					}
					total += minSum;
				}
				out.append("Case #" + testId + ": " + total + "\n");
			}
			in.close();
			out.close();
		}
		catch (RuntimeException rte) {
			throw rte;
		}
		catch (Exception e) {
			System.err.println("Error:" + e.getMessage());
		}
	}
}
