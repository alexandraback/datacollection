import java.io.*;
import java.util.*;

class Main {

	public static String INPUT = "input.txt";
	public static String OUTPUT = "output.txt";

	public static void main(String[] args) throws IOException {
		File inputFile = new File(INPUT);
		File outputFile = new File(OUTPUT);

		Scanner in = new Scanner(inputFile);
		PrintWriter out = new PrintWriter(outputFile);

		Main main = new Main();

		int tests = in.nextInt();
		int completed = 0;

		for (int i = 0; i < tests; i++) {
			main.parse(in);
			out.println("Case #" + (i+1) + ": " + main.operate());
			completed++;
		}

		System.out.println(completed + "/" + tests);

		in.close();
		out.close();
	}

	int n;
	int h[];

	private void parse(Scanner in) {
		n = in.nextInt();
		h = new int[n];
		for (int i = 0; i < n; i++)
			h[i] = in.nextInt();
	}

	private String operate() {
		return String.valueOf(first()) + " " + String.valueOf(second());
	}

	private int first() {
		int e = 0;
		for (int i = 1; i < n; i++) {
			if(h[i-1] > h[i])
				e += h[i-1] - h[i];
		}
		return e;
	}

	private int second() {
		int rate = 0;
		for (int i = 1; i < n; i++) {
			int t = h[i-1] - h[i];
			rate = rate > t ? rate : t;
		}
		int e = 0;
		for (int i = 0; i < (n - 1); i++) {
			if (h[i] < rate)
				e += h[i];
			else
				e += rate;
		}
		return e;
	}

}