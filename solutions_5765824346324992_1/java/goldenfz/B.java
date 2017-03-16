package R1_2015;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class B {
	public static void main(String args[]) throws NumberFormatException,
			IOException {

		Stdin in = new Stdin();
		PrintWriter out = new PrintWriter("B-large.out");
		int t = in.readInt();
		int b, n;
		int m[];
		int cur[];
		int min, index, id;
		for (int i = 1; i <= t; i++) {
			b = in.readInt();
			n = in.readInt();
			m = new int[b];
			cur = new int[b];
			min = 10000000;
			index = 0;
			for (int j = 0; j < b; j++) {
				m[j] = in.readInt();
				if (m[j] < min) {
					min = m[j];
					index = j;
				}
			}
			if (n <= b)
				print(out, n, i);
			else {
				long left = 1, right = n;
				long mid = (1 + n) / 2;
				long cut, adj;
				long time1;
				while (left + 1 < right) {
					mid = (left + right) / 2;
					cut = 0;
					time1 = mid * m[index];
					adj = 0;
					for (int j = 0; j < b; j++) {
						cut += time1 / m[j];
						adj += time1 % m[j] == 0 ? 0 : 1;
					}
					if (cut + adj >= n) {
						right = mid;
					} else {
						left = mid;
					}
				}
				
				for (long j = left; j <= right + 2; j++) {
					time1 = j * m[index];
					cut = 0;
					adj = 0;
					for (int k = 0; k < b; k++) {
						cut += time1 / m[k];
						adj += time1 % m[k] == 0 ? 0 : 1;
					}
					id = 0;
					for (int k = 0; k < b; k++) {
						cur[k] = (int) (time1 % m[k]);
						id += (time1 % m[k] == 0 ? 0 : 1) + time1 / m[k];
					}
					for (int k = 0; k <= m[index]&&id<n; k++) {
						for (int h = 0; h < b&&id<n; h++) {
							if (cur[h] == m[h] || cur[h] == 0) {
								cur[h] = 1;
								id++;
								if (id == n) {
									print(out, h + 1, i);
									break;
								}
							} else {
								cur[h]++;
							}
						}
					}
				}
			}
		}

		out.flush();
		out.close();

	}

	private static void print(PrintWriter out, Object t, int cases) {
		out.println("Case #" + cases + ": " + t);
	}

	private static class Stdin {
		BufferedReader br;

		StringTokenizer st = new StringTokenizer("");

		private Stdin() throws FileNotFoundException {
			br = new BufferedReader(new FileReader("B-large.in"));

		}

		private String readNext() throws IOException {

			while (!st.hasMoreTokens())
				st = new StringTokenizer(br.readLine());
			return st.nextToken();
		}

		private int readInt() throws IOException, NumberFormatException {

			return Integer.parseInt(readNext());

		}

		private long readLong() throws IOException, NumberFormatException {

			return Long.parseLong(readNext());

		}

		private double readDouble() throws IOException, NumberFormatException {

			return Double.parseDouble(readNext());

		}
	}
}
