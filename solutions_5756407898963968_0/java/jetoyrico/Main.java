import java.util.Set;
import java.util.Scanner;
import java.io.OutputStream;
import java.io.IOException;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.util.Collection;
import java.util.HashSet;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream;
		try {
			inputStream = new FileInputStream("tc/A-small-attempt0.in");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("tc/output.txt");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		Scanner in = new Scanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		A solver = new A();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class A {
	public void solve(int testNumber, Scanner in, PrintWriter out) {
		int row1 = in.nextInt() - 1;
		Set<Integer> cand1 = new HashSet<>();
		for (int i = 0; i < 4; ++i)
			for (int j = 0; j < 4; ++j) {
				int n = in.nextInt();
				if (i == row1) cand1.add(n);
			}
		int row2 = in.nextInt() - 1;
		Set<Integer> cand2 = new HashSet<>();
		for (int i = 0; i < 4; ++i)
			for (int j = 0; j < 4; ++j) {
				int n = in.nextInt();
				if (i == row2) cand2.add(n);
			}
		cand1.retainAll(cand2);
		String res = null;
		if (cand1.size() > 1) res = "Bad magician!";
		else if (cand1.size() == 1) res = "" + cand1.toArray(new Integer[0])[0];
		else res = "Volunteer cheated!";
		String formattedResult = String.format("Case #%d: %s\n", testNumber, res);
		out.write(formattedResult);
	}
}

