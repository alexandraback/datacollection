package codejam_round1_14;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class A {

	public static final int MAX = 101;

	public static void main(String[] args) throws NumberFormatException,
			IOException {

		BufferedReader br = new BufferedReader(
				new InputStreamReader(System.in), 1024 * 1024 * 2);

		int t = Integer.parseInt(br.readLine());

		StringBuilder sb = new StringBuilder();
		for (int x = 1; x <= t; x++) {
			int n = Integer.parseInt(br.readLine());
			int size[] = new int[n];
			char[][] strings = new char[n][MAX];
			int[][] ap = new int[n][MAX];

			int maxsize = 0;
			for (int i = 0; i < n; i++) {
				String a = br.readLine();
				int cur = 0;
				strings[i][cur] = a.charAt(0);
				ap[i][cur] = 1;
				for (int j = 1; j < a.length(); j++) {
					if (strings[i][cur] == a.charAt(j)) {
						ap[i][cur]++;
					} else {
						cur++;
						strings[i][cur] = a.charAt(j);
						ap[i][cur]++;
					}
				}
				size[i] = cur + 1;
				maxsize = Math.max(maxsize, size[i]);
			}

			boolean yep = true;
			for (int i = 0; i < maxsize; i++) {
				char c = strings[0][i];
				for (int j = 0; j < n; j++) {
					if (strings[j][i] != c) {
						yep = false;
						break;
					}
				}
				if (!yep) {
					break;
				}
			}
			if (!yep) {
				sb.append("Case #" + x + ": Fegla Won\n");
				continue;
			}
			int s = size[0];
			boolean ok = true;
			for (int i = 0; i < n; i++) {
				if (s != size[i]) {
					sb.append("Case #" + x + ": Fegla Won\n");
					ok = false;
					break;
				}
			}

			if (ok) {
				int ret = 0;
				for (int j = 0; j < s; j++) {
					List<Integer> a = new ArrayList<Integer>();
					for (int i = 0; i < n; i++) {
						a.add(ap[i][j]);
					}
					Collections.sort(a);
					if (n % 2 == 1) {
						ret += count(a, a.get(n / 2));
					} else {
						int r1 = count(a, a.get(n / 2));
						int r2 = count(a, a.get(n / 2 - 1));
						ret += Math.min(r1, r2);
					}
				}
				sb.append("Case #" + x + ": " + ret + "\n");
			}
		}
		BufferedWriter bw = new BufferedWriter(new FileWriter("ii/outAJam.txt"));
		bw.write(sb.toString());
		bw.close();
		System.out.println(sb.toString());
	}

	public static int count(List<Integer> vals, int x) {
		int c = 0;
		for (int a : vals) {
			c += Math.abs(a - x);
		}
		return c;
	}

	public static double[] readArrayLine(String line, int n) {
		double[] ret = new double[n];
		int start = 0;
		int end = line.indexOf(' ', start);
		for (int i = 0; i < n; i++) {
			if (end > 0)
				ret[i] = Double.parseDouble(line.substring(start, end));
			else
				ret[i] = Double.parseDouble(line.substring(start));
			start = end + 1;
			end = line.indexOf(' ', start);
		}
		return ret;
	}
}
