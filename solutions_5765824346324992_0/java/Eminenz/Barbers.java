import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Barbers {
	static long lcm(long n, long m) {
		long lcm = (n == m || n == 1) ? m : (m == 1 ? n : 0);
		/*
		 * this section increases the value of mm until it is greater / than or
		 * equal to nn, then does it again when the lesser / becomes the
		 * greater--if they aren't equal. If either value is 1, / no need to
		 * calculate
		 */
		if (lcm == 0) {
			long mm = m, nn = n;
			while (mm != nn) {
				while (mm < nn) {
					mm += m;
				}
				while (nn < mm) {
					nn += n;
				}
			}
			lcm = mm;
		}
		return lcm;
	}
	
	public static void main(String[] args) throws IOException {

		String file = "B-small-attempt0";
		boolean fromfile = true;

		File infile = new File(file + ".in");
		File outfile = new File(file + ".out");
		if (fromfile) {
			outfile.createNewFile();
		}

		InputStream stream = fromfile ? new FileInputStream(infile) : System.in;
		PrintStream outstream = fromfile ? new PrintStream(outfile)
				: System.out;

		try (Scanner sc = new Scanner(stream)) {

			int t = sc.nextInt();

			StringBuilder out = new StringBuilder();

			for (int c = 1; c <= t; c++) {

				int B = sc.nextInt();
				int N = sc.nextInt();
				
				int[] times = new int[B];
				long lcm = 1;
				for (int i = 0; i < B; i++) {
					times[i] = sc.nextInt();
					lcm = lcm(lcm, times[i]);
				}
				
				List<Integer> list = new ArrayList<>();
				for (int time = 0; time < lcm; time++) {
					for (int b = 0; b < B; b++) {
						if (time % times[b] == 0) {
							list.add(b);
						}
					}
				}
				
				int listindex = (int) ((N-1) % list.size());
				out.append("Case #").append(c).append(": ").append(list.get(listindex)+1).append("\n");
			}

			outstream.println(out);
		}

	}

}
