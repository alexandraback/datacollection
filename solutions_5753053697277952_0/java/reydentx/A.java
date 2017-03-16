package Round1C;

import java.io.File;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class A {
	static Scanner scan;
	static PrintWriter writer;

	public static void main(String[] args) {
		File file = new File("D://A-small-attempt1.in");
		File out = new File("D://outA.txt");
		try {
			scan = new Scanner(file);
			writer = new PrintWriter(out);
			int t = scan.nextInt();
			for (int i = 1; i <= t; i++) {
				writer.print("Case #" + i + ": ");
				// input go here
				int P = scan.nextInt();
				List<Integer> list = new ArrayList<Integer>();

				for (int j = 0; j < P; j++) {
					list.add(scan.nextInt());
				}

				solve(list);
			}
		} catch (Exception ex) {

		} finally {
			writer.close();
		}
	}

	public static void solve(List<Integer> list) {
		if (list.size() == 2) {
			int min = 0;
			if (list.get(0) > list.get(1)) {
				min = list.get(1);
				for (int i = 0; i < list.get(0) - list.get(1); i++) {
					writer.print("A ");
				}
			} else {
				min = list.get(0);
				for (int i = 0; i < list.get(1) - list.get(0); i++) {
					writer.print("B ");
				}
			}
			for (int i = 0; i < min; i++) {
				writer.print("AB ");
			}
			writer.println();
		} else {

			while (true) {
				int max = -1, imax = -1;
				int sum = 0;
				for (int i = 0; i < list.size(); i++) {
					sum += list.get(i);
					if (list.get(i) > max) {
						max = list.get(i);
						imax = i;
					}
				}

				if (sum > 2) {
					writer.print((char) ('A' + imax) + " ");
					list.set(imax, list.get(imax) - 1);
				} else {
					for (int i = 0; i < list.size(); i++) {
						if (list.get(i) > 0) {
							writer.print((char) ('A' + i));
						}
					}
					writer.println("");
					break;
				}
			}
		}
	}

}
