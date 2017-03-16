import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.IdentityHashMap;
import java.util.Scanner;



public class ProblemA {
	enum Mode {SAMPLE,SMALL,LARGE}

	static Mode mode = Mode.SMALL;

	Scanner in;
	PrintStream out;

	public static void main(String[] args) throws FileNotFoundException {
		new ProblemA().run();
	}

	public void run() throws FileNotFoundException {

		switch (mode) {
			case SAMPLE:
				in = new Scanner(new BufferedReader(new FileReader("/Users/abaudoux/Documents/Taktik/Sources/problems/files/ina")));
				out = new PrintStream(new FileOutputStream("/Users/abaudoux/Documents/Taktik/Sources/problems/files/A-sample.out"));
				break;
			case SMALL:
				in = new Scanner(new BufferedReader(new FileReader("/Users/abaudoux/Downloads/A-small-attempt2.in")));
				out = new PrintStream(new FileOutputStream("/Users/abaudoux/Documents/Taktik/Sources/problems/files/A-small.out"));
				break;
			case LARGE:
				in = new Scanner(new BufferedReader(new FileReader("/Users/abaudoux/Downloads/A-large.in")));
				out = new PrintStream(new FileOutputStream("/Users/abaudoux/Documents/Taktik/Sources/problems/files/A-large.out"));
				break;
			default:
				throw new IllegalStateException();
		}

		int size = in.nextInt();

		for (int p = 0 ; p < size ; p++) {
			out.print("Case #" + (p+1) + ": ");
			int nb = in.nextInt();
			int[] parties = new int[nb];

			for (int i = 0 ; i < nb ; i++) {
				parties[i] = in.nextInt();
			}
			out.println(solve(parties));


		}
		out.close();
	}

	public String solve(int[] parties) {
		int sum = 0;
		for (int i = 0 ; i < parties.length ; i++) {
			sum += parties[i];
		}
		StringBuilder res = new StringBuilder();
		int[] max = max(parties);
		while (max[1] > 0) {
			if (max[1] == 2) {
				parties[max[0]]--;
				int[] lastmax = max(parties);
				parties[lastmax[0]]--;
				res.append(((char) ('A' + max[0])));
				res.append(((char) ('A' + lastmax[0]))).append(" ");
				sum -= 2;
				max = max(parties);

			}  else {
				res.append(((char) ('A' + max[0]))).append(" ");
				parties[max[0]]--;
				max = max(parties);
				sum --;
			}

		}
		return res.toString().trim();
	}

	public int[] max(int[] p) {
		int nbLeft =0;
		int max = 0;
		int maxi = -1;
		for (int i = 0 ; i < p.length ; i++) {
			if (p[i] > 0) {
				nbLeft++;
			}
			if (p[i] > max) {
				max = p[i];
				maxi = i;
			}
		}
		return new int[]{maxi, nbLeft};
	}

}
