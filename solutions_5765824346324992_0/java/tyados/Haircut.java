package haircut;

import static java.lang.Integer.parseInt;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Haircut {

	private static final boolean USE_SMALL = true;
	private static final String INPUT_FILE;
	private static final String OUTPUT_FILE;
	static {
		String problem = "haircut";
		if (USE_SMALL) {
			INPUT_FILE = problem + "/A-small.in";
			OUTPUT_FILE = problem + "/small.out";
		} else {
			INPUT_FILE = problem + "/A-large.in";
			OUTPUT_FILE = problem + "/large.out";
		}
	}

	public static void main(String[] args) throws IOException {

		BufferedReader in = new BufferedReader(new InputStreamReader(new FileInputStream(INPUT_FILE)));
		PrintWriter out = new PrintWriter(new FileOutputStream(OUTPUT_FILE));

		int T = Integer.parseInt(in.readLine());
		for (int CASE = 1; CASE <= T; CASE++) {
			StringTokenizer st = new StringTokenizer(in.readLine());
			int B = parseInt(st.nextToken());
			int N = parseInt(st.nextToken());
			st = new StringTokenizer(in.readLine());
			long[] minutes = new long[B];
			for (int i = 0; i < B; i++) {
				minutes[i] = parseInt(st.nextToken());
			}
			long a = findA(minutes, N);
			long[] now = new long[B];
			long total = 0;
			for (int i = 0; i < B; i++) {
				now[i] = (a / minutes[i]) + 1;
				total += now[i];
			}

			long barber = -1;
			long b = a + 1;

			if (N <= total) {
				if (a != 0) {
					throw new IllegalStateException("this shit happened, case: " + T);
				}
				barber = N - 1;
			} else {
				for (int i = 0; i < B; i++) {
					if ((b % minutes[i]) == 0)
						total++;
					if (total == N) {
						barber = i;
						break;
					}
				}
			}

			out.println("Case #" + CASE + ": " + (barber + 1));
			out.flush();
		}
		out.close();
		in.close();
	}

	static long findA(long[] minutes, long N) {
		long a = 0;
		long b = Integer.MAX_VALUE * 1000L;

		while (a < b - 1) {
			long t = (a + b) / 2;
			long total = 0;
			for (int i = 0; i < minutes.length; i++) {
				total += (t / minutes[i]) + 1;
			}
			if (total >= N)
				b = t;
			else
				a = t;
		}
		return a;

	}
}