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
	int y;
	int[] b;

	private void parse(Scanner in) {
		n = in.nextInt();
		y = in.nextInt();
		b = new int[n];
		for (int i = 0; i < n; i++)
			b[i] = in.nextInt();
	}

	private String operate() {
		int mult = 1;
		int magic = 0;
		for (int i = 0; i < n; i++) {
			mult *= b[i];
		}
		for (int i = 0; i < n; i++) {
			magic += mult / b[i];
		}
		y = y % magic;
		y = y == 0 ? magic : y;
		if (n >= y)
			return String.valueOf(y);
		int[] c = new int[n];
		for (int i = 0; i < n; i++)
			c[i] = b[i];
		for (int i = 0; i < n; i++) {
			c[i] = b[i];
		}
		int i = n;
		while (true) {
			int min = c[0];
			for (int j = 1; j < n; j++) {
				min = min < c[j] ? min : c[j];
			}
			for (int j = 0; j < n; j++) {
				c[j] -= min;
			}
			for (int j = 0; j < n; j++) {
				if(c[j] == 0) {
					i++;
					if (i == y)
						return String.valueOf(j+1);
					else
						c[j] = b[j];
				}
			}
		}
	}

}